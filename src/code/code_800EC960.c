#include "ultra64.h"
#include "global.h"

//"Detectable" song copies, used for:
//- Real-time detection of song being played
//- Drawing song in menu (but not the demo where you play it)
typedef struct {
    u8 len;
    u8 notesIdx[8];
} OcarinaDetectableSong;

typedef struct {
    u8 noteIdx;
    u8 state;
    u8 pos;
} OcarinaStaff;

typedef struct {
    f32 unk_00;
    f32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
} unk_s1;

typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
} unk_s2;

void func_800FA240(u8, u8, u8, u8);
void func_800F5550(u16);
void func_800F5E18(u8 arg0, u16 arg1, u8 arg2, s8 arg3, s8 arg4);
void func_800F4784(unk_s2 *arg0);
void func_800F56A8(void);
void func_800F6FB4(u8);

// stick float vals
extern f32 D_8012F6B4[];
extern s32 sOcarinaAllowedBtnMask; // 80130EFC 
extern s32 sOcarinaABtnMap; // 80130F00
extern s32 sOcarinaCUPBtnMap; // 80130F04
extern s32 sOcarinaCDownBtnMap; // 80130F08
extern u8 D_80131F64;
extern u8 D_80133408;
extern s8 D_8013060C;
extern u8 D_80130604;
extern s8 D_80130614;
extern f32 D_80130620;
extern s8 D_80130624;
extern u8 D_80131878;
extern u32 D_80130F3C;
extern u8 sCurOcarinaBtnVal; // 80130F14
extern u8 sPrevOcarinaNoteVal; // 80130F18
extern u8 sCurOcarinaBtnIdx; // note index?
extern u8 D_80130F20;
extern u8 sOcarinaInpEnabled; // D_80130F0C
extern u8 sPlaybackSomeCounter;
extern u16 sStaffPlaybackPos;
extern s8 sOcarinaInstrument; // ocarina active?
extern u8 sNoteValueIndexMap[];
extern u8 D_80130618;
extern u8 D_8013061C;
extern u8 D_8013063C;
extern u8 D_80130640;
extern u8 D_80130644;
extern u8 D_80130648;
extern s8 D_801306C8[];
extern u8 D_80133414;
extern u8 D_80130610;
extern u8 D_80130600;
extern u8 D_801305F8[];
extern s8 D_80130608;
extern u8 D_801305FF;
extern Vec3f* D_8013064C;
extern u8 D_801305CC;
extern u8 D_8013062C;
extern u8 D_80130630;
extern u8 D_80130658[];
extern u8 D_80133418;
extern u16 D_80130628;
extern s8 sCurOcarinaRawPitch; // pitch? 
extern f32 D_80130650;
extern s8 D_801305B8;
extern s8 D_801305BC;
extern s8 D_801305C0;
extern f32 D_801305E4[];
extern u8 D_801305E0;
extern f32 D_801305F4;
extern u32 D_801305B0;
extern u32 D_801305B4;
extern f32 D_80131C8C;
extern u8 D_80131C98;
extern u8 D_80131C9C;
extern u8 D_80131CA0;
extern u8 D_80131CA8;
extern u16 D_80131E08[];
extern u8 D_8013340C;
extern u8 D_80131EEE;
extern s8 D_80131EBC;
extern s8 D_80131EC0;
extern s8 D_80131EC4;
extern s8 D_80131EC8[];
extern s16 D_80131E20[];
extern u8 D_80131CA4;
extern u8 sOcaMinigameEndPos;
extern u8 sOcaMinigameApndPos;
extern u8 sOcaMinigameNoteCnts[];
extern u16 D_80130F3E;
extern u8 sOcarinaNoteValues[5];
extern u8 D_8013170C;
/** bit field of songs that can be played 
 * 0x0800 storms
 * 0x0400 song of time
 * 0x0200 suns
 * 0x0100 lullaby
 * 0x0080 epona
 * 0x0040 sarias
 * 0x0020 prelude
 * 0x0010 nocturne
 * 0x0008 requiem
 * 0x0004 serenade
 * 0x0002 bolero
 * 0x0001 minuet
*/
extern u8 D_8013187C;
extern u16 D_80130F4C;
extern u8 D_80131880;
extern u8 sOcarinaRecordMode;
extern f32 sCurOcarinaFloatPitch;
extern s8 sCurOcarinaVibrato;
extern u32 sOcarinaDefaultVolume;
extern u8 D_80131F4C[];
extern u8 D_80131F50;
extern OcarinaTeachSong sOcarinaTeachSongs[]; // 80130F80
extern OcarinaDetectableSong sOcarinaDetectableSongs[]; // D_80131C00
extern u32 sNotePlaybackTimer;
extern u16 sPlaybackNotePos;
extern u32 sOcarinaNoteStartT;
extern u8 D_8013186;
extern u8 sLastOcarinaVolume;
extern u8 sLastOcarinaVibrato;
extern s8 sLastOcarinaRawPitch;
extern u8 sLastOcarinaBtnIdx;
extern u8 sRecordSongPos;
extern u8 sLastOcarinaBtnVal;
extern s8 sCurOcarinaVolume;
extern OcarinaTeachSong *sPlaybackSong;
extern OcarinaTeachSong sPierresSong;
extern u8 sDisplayedNoteValue; // Note to display on screen?
extern s32 sOcarinaLastTime;
extern OcarinaTeachNote* D_80131BE4;
extern OcarinaTeachSong* D_80131BEC;
/**
 * BSS
*/
u32 sOcarinaUpdateStartTime; // 8016B7A0
u32 sOcarinaUpdateEndTime;
f32 D_8016B7A8;
f32 D_8016B7AC; // maybe padding? 
f32 D_8016B7B0;
f32 D_8016B7B4;
unk_s2 D_8016B7B8;
unk_s2 D_8016B7C8;
f32 D_8016B7D8;
s8 D_8016B7DC;
f32 D_8016B7E0;
u16 D_8016B7E4;
typedef struct {
    s8 unk_00[6];
    s16 unk_06;
} unk_D_8016B7E8;
unk_D_8016B7E8 D_8016B7E8[0x19];
u8 D_8016B8B0;
u8 D_8016B8B1;
u8 D_8016B8B2;
u8 D_8016B8B3;
u8 D_8016B8B4;
unk_s1 D_8016B8B8[0x10];

// maybe a struct?
u8 D_8016B9B8[0x20];
u8 D_8016B9D8[0x8]; // probably array.
u8 D_8016B9E0[0x12];
u8 D_8016B9F2;
u8 D_8016B9F3;
u8 D_8016B9F4;
u16 D_8016B9F6;

OcarinaStaff D_8016B9F8; // playing along staff? 
OcarinaStaff sDisplayedStaff; // displayed staff?
OcarinaStaff D_8016BA00; // ?? note and status not updated, pos updated as you play
u32 sOcarinaCurTime;
s8 sOcarinaStickX;
s8 sOcarinaStickY;
u32 sCurOcarinaBtnPress;
s32 D_8016BA10;
u32 sPrevOcarinaBtnPress;
s32 D_8016BA18;
s32 D_8016BA1C;
u8 sCurOcarinaSong[8];
u8 sOcarinaSongAppendPos;
u8 sOcarinaHasStartedSong;
u8 sOcarinaSongNotestartIdx;
u8 sOcarinaSongCnt;
u16 sOcarinaAvailSongs;
u8 sRecordSongLen;
u16 D_8016BA30[0x10];
u16 D_8016BA50[0x10];
u16 D_8016BA70[0x10];
u8 D_8016BA90[0x10];
OcarinaTeachNote D_8016BAA0;
u8 D_8016BAA8;
f32 D_8016BAAC;
u32 D_8016BAB0;
u32 sDebugPadPressRaw;
u32 sDebugPadPress;
s32 sOcarinaUpdateTaskCntStart;
s32 sOcarinaUpdateTaskCntEnd;

void AudioOcarina_SetAltControl(u8 custom) {
    if (!custom) {
        osSyncPrintf("AUDIO : Ocarina Control Assign Normal\n");
        sOcarinaAllowedBtnMask = (BTN_A | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
        sOcarinaABtnMap = BTN_A;
        sOcarinaCUPBtnMap = BTN_CUP;
        sOcarinaCDownBtnMap = BTN_CDOWN;
    } else {
        osSyncPrintf("AUDIO : Ocarina Control Assign Custom\n");
        sOcarinaAllowedBtnMask = (BTN_A | BTN_B | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
        sOcarinaABtnMap = BTN_B;
        sOcarinaCUPBtnMap = BTN_CDOWN;
        sOcarinaCDownBtnMap = BTN_A;
    }
}

void PadMgr_RequestPadData(PadMgr* padmgr, Input* inputs, s32 mode);

#ifdef NON_MATCHING
//Small reordering but could not figure out. lui shared by sOcarinaStickX and Y.
//Seems like their data type is wrong, but putting them in a struct made things
//worse.
void func_800ECA00(){
    Input inputs[4];
    u32 temp2;
    u32 temp = sCurOcarinaBtnPress;
    PadMgr_RequestPadData(&gPadMgr, inputs, 0);
    sCurOcarinaBtnPress = inputs[0].cur.button;
    sPrevOcarinaBtnPress = temp;
    sOcarinaStickX = inputs[0].rel.stick_x;
    sOcarinaStickY = inputs[0].rel.stick_y;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECA00.s")
#endif

// adju stick input f32
f32 AudioOcarina_NormalizePitch(s8 inp) {
    s8 inpAdj;
    f32 ret;

    if (inp > 0x40) {
        inpAdj = 127;
    } else if (inp < -0x40) {
        inpAdj = -128;
    } else if (inp >= 0) {
        inpAdj = (inp * 127) / 64;
    } else {
        inpAdj = (inp * 128) / 64;
    }
    ret = D_8012F6B4[inpAdj];
    return ret;
}

u8 func_800ECAF0(void) {
    u8 ret;

    if (D_80131878 != 0) {
        ret = D_80131878 - 1;
        D_80131878 = 0;
    } else if (D_80130F3C != 0) {
        ret = 0xFE;
    } else {
        ret = 0xFF;
    }

    return ret;
}

u8 AudioOcarina_MapNoteValue(u8 arg0) {
    u8 temp_v1;

    temp_v1 = sNoteValueIndexMap[arg0 & 0x3F];
    if (temp_v1 == 5) { //note is A#/Bb
        if (arg0 & 0x80) { //sharp
            return 2; //return A (C-right)
        }
        return 3; //return B (C-left)
    }
    return temp_v1;
}

// Convert OCA_SONG_SHORTSCARECROW or OCA_SONG_MEMORYGAME from playback format
// (OcarinaTeachSong) to detectable format.
void AudioOcarina_ConvertTeachToDetectable(u8 songNum) {
    u8 savedSongIdx;
    u8 scarecrowSongIdx;
    u8 noteIdx;

    savedSongIdx = 0; 
    scarecrowSongIdx = 0;
    while(savedSongIdx < 8 && scarecrowSongIdx < 0x10){
        noteIdx = sOcarinaTeachSongs[songNum].notes[scarecrowSongIdx++].noteIdx;
        if(noteIdx != 0xFF){
            sOcarinaDetectableSongs[OCA_SONG_SHORTSCARECROW].notesIdx[savedSongIdx++] = sNoteValueIndexMap[noteIdx];
        }
    }
}

// start ocarina.
void func_800ECC04(u16 arg0) {
    u8 i;

    if ((sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[1].volume != 0xFF) && ((arg0 & 0xFFF) == 0xFFF)) {
        arg0 |= 0x1000;
    }

    if ((arg0 == 0xCFFF) && (sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[1].volume != 0xFF)) {
        arg0 = 0xDFFF;
    }

    if ((arg0 == 0xFFF) && (sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[1].volume != 0xFF)) {
        arg0 = 0x1FFF;
    }

    if (arg0 != 0xFFFF) {
        D_80130F3C = 0x80000000 + (u32)arg0;
        sOcarinaSongNotestartIdx = 0;
        sOcarinaSongCnt = 0xE;
        if (arg0 != 0xA000) {
            sOcarinaSongCnt--;
        }
        sOcarinaAvailSongs = arg0 & 0x3FFF;
        D_8013187C = 8;
        sOcarinaHasStartedSong = 0;
        D_80131878 = 0;
        sRecordSongLen = 0;
        D_8016B9F8.state = func_800ECAF0();
        sOcarinaInpEnabled = 1;
        D_80130F4C = 0;
        for(i = 0; i < 0xE; i++){
            D_8016BA30[i] = 0;
            D_8016BA50[i] = 0;
            D_8016BA70[i] = 0;
            D_8016BA90[i] = 0;
        }

        if (arg0 & 0x8000) {
            D_8013187C = 0;
        }

        if (arg0 & 0x4000) {
            sOcarinaSongAppendPos = 0;
        }

        if (arg0 & 0xD000) {
            AudioOcarina_ConvertTeachToDetectable(OCA_SONG_SHORTSCARECROW);
            return;
        }
    } else {
        D_80130F3C = 0;
        sOcarinaInpEnabled = 0;
    }
}

void func_800ECDBC(void) {
    if (sCurOcarinaBtnVal != 0xFF && sOcarinaHasStartedSong == 0) {
        sOcarinaHasStartedSong = 1;
        D_80130F20 = 0xFF;
    }
}

void func_800ECDF8(void);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECDF8.s")

void func_800ED200(void);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ED200.s")

#define OCARINA_CUP (0xE)
#define OCARINA_CDOWN (0x5)
#define OCARINA_CLEFT (0xB)
#define OCARINA_CRIGHT (0x9)
#define OCARINA_A (0x2)

#ifdef NON_MATCHING
void func_800ED458(s32 arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s8 temp_v0_5;
    u8 temp_a0;
    u8 temp_t5;
    u8 temp_v0;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 phi_v0;
    u8 phi_v1;
    s32 phi_v1_2;
    u8 phi_v0_2;

    if (D_80130F3C != 0) {
        if (D_80131880 != 0) {
            D_80131880--;
            return;
        }
    }

    if ((D_8016BA10 == 0) || ((sCurOcarinaBtnPress & sOcarinaAllowedBtnMask) != (D_8016BA10 & sOcarinaAllowedBtnMask))) {
        D_8016BA10 = 0;
        sCurOcarinaBtnVal = 0xFF;
        sCurOcarinaBtnIdx = 0xFF;
        if (!(D_8016BA18 & (sCurOcarinaBtnPress & sOcarinaAllowedBtnMask & sPrevOcarinaBtnPress & sOcarinaAllowedBtnMask)) && (sCurOcarinaBtnPress != 0)) {
            D_8016BA18 = sCurOcarinaBtnPress;
        } else {
            D_8016BA18 = D_8016BA18 & (sCurOcarinaBtnPress & sOcarinaAllowedBtnMask & sPrevOcarinaBtnPress & sOcarinaAllowedBtnMask);
        }

        if (D_8016BA18 & sOcarinaABtnMap) {
            osSyncPrintf("Presss NA_KEY_D4 %08x\n", sOcarinaABtnMap);
            sCurOcarinaBtnVal = 2;
            sCurOcarinaBtnIdx = 0;
        } else if (D_8016BA18 & sOcarinaCDownBtnMap) {
            osSyncPrintf("Presss NA_KEY_F4 %08x\n", sOcarinaCDownBtnMap);
            sCurOcarinaBtnVal = 5;
            sCurOcarinaBtnIdx = 1;
        } else if (D_8016BA18 & BTN_CRIGHT) {
            osSyncPrintf("Presss NA_KEY_A4 %08x\n", BTN_CRIGHT);
            sCurOcarinaBtnVal = 9;
            sCurOcarinaBtnIdx = 2;
        } else if (D_8016BA18 & BTN_CLEFT) {
            osSyncPrintf("Presss NA_KEY_B4 %08x\n", BTN_CLEFT);
            sCurOcarinaBtnVal = 0xB;
            sCurOcarinaBtnIdx = 3;
        } else if (D_8016BA18 & sOcarinaCUPBtnMap) {
            osSyncPrintf("Presss NA_KEY_D5 %08x\n", sOcarinaCUPBtnMap);
            sCurOcarinaBtnVal = 0xE;
            sCurOcarinaBtnIdx = 4;
        }

        if ((sCurOcarinaBtnVal != 0xFF) && (sCurOcarinaBtnPress & BTN_R) && (sOcarinaRecordMode != 2)) {
            sCurOcarinaBtnVal++;
            sCurOcarinaBtnIdx += 0x80;
        }

        if ((sCurOcarinaBtnVal != 0xFF) && (sCurOcarinaBtnPress & BTN_Z) && (sOcarinaRecordMode != 2)) {
            //sCurOcarinaBtnVal = sOcarinaRecordMode - 1;
            sCurOcarinaBtnVal--;
            sCurOcarinaBtnIdx += 0x40;
        }
        if (sOcarinaRecordMode != 2) {
            sCurOcarinaRawPitch = sOcarinaStickY;
            sCurOcarinaFloatPitch = AudioOcarina_NormalizePitch(sCurOcarinaRawPitch);
            sCurOcarinaVibrato = (sOcarinaStickX < 0 ? -sOcarinaStickX : sOcarinaStickX) >> 2;
            Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x06), sCurOcarinaVibrato);
        } else {
            sCurOcarinaRawPitch = 0;
            sCurOcarinaFloatPitch = 1.0f;
        }

        if ((sCurOcarinaBtnVal != 0xFF) && (sCurOcarinaBtnVal != sPrevOcarinaNoteVal)) {
            Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x07), sOcarinaInstrument - 1);
            Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x05), sCurOcarinaBtnVal);
            Audio_PlaySoundGeneral(0x5800, &D_801333D4, 4, &sCurOcarinaFloatPitch, &sOcarinaDefaultVolume, &D_801333E8);
        } else if ((sPrevOcarinaNoteVal != 0xFF) && (sCurOcarinaBtnVal == 0xFF)) {
            Audio_StopSFX(0x5800);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ED458.s")
#endif

void func_800ED848(u8 inputEnabled) {
    sOcarinaInpEnabled = inputEnabled;
}

void AudioOcarina_SetInstrument(u8 arg0) {
    if (sOcarinaInstrument == arg0) {
        return;
    }

    Audio_SetBGM(arg0 | 0x82010D00);
    sOcarinaInstrument = arg0;
    if (arg0 == 0) {
        sCurOcarinaBtnPress = 0;
        sPrevOcarinaBtnPress = 0;
        D_8016BA18 = 0;
        D_8016BA10 = 0xFFFF;
        func_800ED458(0);
        Audio_StopSFX(0x5800);
        func_800F7260(0);
        sPlaybackSomeCounter = 0;
        sStaffPlaybackPos = 0;
        sOcarinaInpEnabled = 0;
        D_80130F3C = 0;
        Audio_ClearSomeBit(0xD);
    } else {
        sCurOcarinaBtnPress = 0;
        func_800ECA00();
        D_8016BA10 = sCurOcarinaBtnPress;
        Audio_SetSomeBit(0xD);
    }
}

void AudioOcarina_SetSong(s8 songIdx, s8 counter) {
    s32 temp_a0;
    s32 temp_a0_2;
    u16 temp_t5;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 phi_v0;

    if (songIdx == 0) {
        sPlaybackSomeCounter = 0;
        Audio_StopSFX(0x5800);
        return;
    }

    if (songIdx < 0xF) {
        sPlaybackSong = &sOcarinaTeachSongs[songIdx - 1];
    } else {
        sPlaybackSong = &sPierresSong;
    }

    sPlaybackSomeCounter = counter;
    sNotePlaybackTimer = 0;
    sDisplayedNoteValue = 0xFF;
    sPlaybackNotePos = 0;
    sStaffPlaybackPos = 0;
    while(sPlaybackSong->notes[sPlaybackNotePos].noteIdx == 0xFF){
        sPlaybackNotePos++;
    }
}

extern u8 sNotePlaybackVolume;
extern f32 sNormalizedNotePlaybackVolume;
extern u8 sNotePlaybackVibrato;
extern s8 sNotePlaybackPitch;
extern f32 sNormalizedNotePlaybackPitch;
 
void AudioOcarina_PlaybackSong(void) {
    s32 noteTimerStep;
    s32 nextNoteTimerStep;

    if (sPlaybackSomeCounter != 0) {
        if (sStaffPlaybackPos == 0) {
            noteTimerStep = 3;
        } else {
            noteTimerStep = sOcarinaCurTime - sOcarinaLastTime;
        }

        if (noteTimerStep < sNotePlaybackTimer) {
            sNotePlaybackTimer -= noteTimerStep;
        } else {
            nextNoteTimerStep = noteTimerStep - sNotePlaybackTimer;
            sNotePlaybackTimer = 0;
        }

        if (sNotePlaybackTimer == 0) {

            sNotePlaybackTimer = sPlaybackSong->notes[sPlaybackNotePos].time;

            if (sPlaybackNotePos == 1) {
                sNotePlaybackTimer++;
            }

            if (sNotePlaybackTimer == 0) {
                sPlaybackSomeCounter--;
                if (sPlaybackSomeCounter != 0) {
                    sPlaybackNotePos = 0;
                    sStaffPlaybackPos = 0;
                    sDisplayedNoteValue = 0xFF;
                } else {
                    Audio_StopSFX(0x5800);
                }
                return;
            } else {
                sNotePlaybackTimer -= nextNoteTimerStep;
            }
            
            if (sNotePlaybackVolume != sPlaybackSong->notes[sPlaybackNotePos].volume) {
                sNotePlaybackVolume = sPlaybackSong->notes[sPlaybackNotePos].volume;
                sNormalizedNotePlaybackVolume = sNotePlaybackVolume / 127.0f;
            }


            if (sNotePlaybackVibrato != sPlaybackSong->notes[sPlaybackNotePos].vibrato) {
                sNotePlaybackVibrato = sPlaybackSong->notes[sPlaybackNotePos].vibrato;
                Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x06), sNotePlaybackVibrato);
            }
        
            if (sNotePlaybackPitch != sPlaybackSong->notes[sPlaybackNotePos].pitch) {
                sNotePlaybackPitch = sPlaybackSong->notes[sPlaybackNotePos].pitch;
                sNormalizedNotePlaybackPitch = AudioOcarina_NormalizePitch(sNotePlaybackPitch);
            }

            if ((sPlaybackSong->notes[sPlaybackNotePos].volume == sPlaybackSong->notes[sPlaybackNotePos - 1].volume && (sPlaybackSong->notes[sPlaybackNotePos].vibrato == sPlaybackSong->notes[sPlaybackNotePos - 1].vibrato) && (sPlaybackSong->notes[sPlaybackNotePos].pitch == sPlaybackSong->notes[sPlaybackNotePos - 1].pitch))) {
                sDisplayedNoteValue = 0xFE;
            }

            if (sDisplayedNoteValue != sPlaybackSong->notes[sPlaybackNotePos].noteIdx) {
                u8 tmp = sPlaybackSong->notes[sPlaybackNotePos].noteIdx;
                if (tmp == 0xA) {
                    sDisplayedNoteValue = tmp + sPlaybackSong->notes[sPlaybackNotePos].semitone;
                } else {
                    sDisplayedNoteValue = tmp;
                }
                
                if (sDisplayedNoteValue != 0xFF) {
                    sStaffPlaybackPos++;
                    Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x07), sOcarinaInstrument - 1);
                    Audio_SendMsg_s8(AUDIO_CMD(0x06, 0x02, 0x0D, 0x05), sDisplayedNoteValue & 0x3F);
                    Audio_PlaySoundGeneral(0x5800, &D_801333D4, 4, &sNormalizedNotePlaybackPitch, &sNormalizedNotePlaybackVolume, &D_801333E8);
                } else {
                    Audio_StopSFX(0x5800);
                }
            }
            sPlaybackNotePos++;
        }
    }
}

#ifdef NON_MATCHING
void AudioOcarina_RecordStep(u8 save) {
    OcarinaTeachSong *phi_a0;
    u16 i;
    u8 j;
    u8 k;
    u8 t;

    phi_a0 = sOcarinaRecordMode == 1 ? gScarecrowCustomSongPtr : D_80131BEC;

    phi_a0->notes[sRecordSongPos].noteIdx = sLastOcarinaBtnVal;
    phi_a0->notes[sRecordSongPos].time = sOcarinaCurTime - sOcarinaNoteStartT;
    phi_a0->notes[sRecordSongPos].volume = sLastOcarinaVolume;
    phi_a0->notes[sRecordSongPos].vibrato = sLastOcarinaVibrato;
    phi_a0->notes[sRecordSongPos].pitch = sLastOcarinaRawPitch;
    phi_a0->notes[sRecordSongPos].semitone = sLastOcarinaBtnIdx & 0xC0;

    sLastOcarinaBtnVal = sCurOcarinaBtnVal;
    sLastOcarinaVolume = sCurOcarinaVolume;
    sLastOcarinaVibrato = sCurOcarinaVibrato;
    sLastOcarinaRawPitch = sCurOcarinaRawPitch;
    sLastOcarinaBtnIdx = sCurOcarinaBtnIdx;
    sRecordSongPos++;

    if ((sRecordSongPos == 0x6B) || save) {
        // Get ending null notes.
        i = sRecordSongPos;
        if(i != 0) {
            do {
                i--;
                t = phi_a0->notes[i].noteIdx;
            } while(i != 0 && t == 0xFF);
        }

        if((i + 1) != sRecordSongPos) {
            sRecordSongPos = i + 2;
            phi_a0->notes[sRecordSongPos - 1].time = 0;
        }

        phi_a0->notes[sRecordSongPos].time = 0;
    
        if (sOcarinaRecordMode == 2) {
            if (sRecordSongLen >= 8) {
                for(i = 0; i < sRecordSongPos; i++) {
                    phi_a0->notes[i] = phi_a0->notes[i + 1];
                }

                AudioOcarina_ConvertTeachToDetectable(OCA_SONG_MEMORYGAME);
                
                for(i = 0; i < OCA_SONG_SHORTSCARECROW; i++) {
                    for(j = 0; j < 9 - sOcarinaDetectableSongs[i].len; j++) {

                        for(k = 0; 
                            k < sOcarinaDetectableSongs[i].len && 
                                (k + j) < 8 && 
                                sOcarinaDetectableSongs[i].notesIdx[k] == sOcarinaDetectableSongs[OCA_SONG_SHORTSCARECROW].notesIdx[j + k];
                            k++) {

                            }

                        if (k == sOcarinaDetectableSongs[i].len) {
                            sOcarinaRecordMode = 0xFF;
                            sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[1].volume = 0xFF;
                            return;
                        }

                    }
                }

                for(i = 1; i < 8; i++) {
                    if (sOcarinaDetectableSongs[OCA_SONG_SHORTSCARECROW].notesIdx[0] != sOcarinaDetectableSongs[OCA_SONG_SHORTSCARECROW].notesIdx[i]) {
                        i = 9;
                    }
                }

                if (i == 8) {
                    i = 0;
                    sOcarinaRecordMode = 0xFF;
                    sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[i].volume = 0xFF;
                    return;
                }

                for(i = 0; i < sRecordSongPos; i++) {
                    sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[i] = sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[i];
                }
                sOcarinaInpEnabled = 0;
            } else {
                sOcarinaTeachSongs[OCA_SONG_SHORTSCARECROW].notes[1].volume = 0xFF;
            }
        }
        sOcarinaRecordMode = 0;
    }
}
#else
void AudioOcarina_RecordStep(u8 arg0);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/AudioOcarina_RecordStep.s")
#endif

// start custom song?
/**
 * mode = 0: not recording
 * mode = 1: recording long scarecrow song
 * mode = 2: recording short scarecrow song
 * mode = 0xFF: error? ran out of space for song?
*/
void AudioOcarina_SetRecordMode(u8 mode) {
    if ((u32)mode == sOcarinaRecordMode) {
        return;
    }
    
    if (mode != 0) {
        sOcarinaNoteStartT = sOcarinaCurTime;
        sLastOcarinaBtnVal = 0xFF;
        sLastOcarinaVolume = 0x57;
        sLastOcarinaVibrato = 0;
        sLastOcarinaRawPitch = 0;
        sLastOcarinaBtnIdx = 0;
        sRecordSongPos = 0;
        sOcarinaInpEnabled = 1;
        sRecordSongLen = 0;
        D_8016BAA0 = sPierresSong.notes[1];
    } else {
        if (sRecordSongPos == 0) {
            sPierresSong.notes[1] = D_8016BAA0;
        } else {
            if (sOcarinaRecordMode == 2) {
                sRecordSongLen = 1;
            }
            
            AudioOcarina_RecordStep(1);
        }

        sOcarinaInpEnabled = 0;
        sRecordSongLen = 0;
    }

    sOcarinaRecordMode = mode;
}

void func_800EE29C(void) {
    D_8016BA00.state = sOcarinaRecordMode;
    D_8016BA00.pos = sRecordSongLen;
    if (sOcarinaRecordMode == 0xFF) {
        sOcarinaRecordMode = 0;
    }
}

void func_800EE2D4(void) {
    D_8016B9F8.noteIdx = sCurOcarinaBtnIdx & 0x3F;
    D_8016B9F8.state = func_800ECAF0();
    D_8016B9F8.pos = sRecordSongLen;
}

void func_800EE318(void) {
    if ((sDisplayedNoteValue & 0x3F) < 0x10) {
        sDisplayedStaff.noteIdx = AudioOcarina_MapNoteValue(sDisplayedNoteValue);
    }
    
    sDisplayedStaff.state = sPlaybackSomeCounter;

    if (sPlaybackSong != &sPierresSong) {
        sDisplayedStaff.pos = sStaffPlaybackPos;
    } else if(sStaffPlaybackPos == 0) {
        sDisplayedStaff.pos = 0;
    } else {
        sDisplayedStaff.pos = ((sStaffPlaybackPos - 1) % 8) + 1;
    }
}


OcarinaStaff *func_800EE3C8(void) {
    return &D_8016BA00;
}

OcarinaStaff *func_800EE3D4(void) {
    if (D_8016B9F8.state < 0xFE) {
        D_80130F3C = 0;
    }
    return &D_8016B9F8;
}

OcarinaStaff *AudioOcarina_GetDisplayedStaff(void) {
    return &sDisplayedStaff;
}

void AudioOcarina_RecordingCheckChange(void) {
    s32 noteChanged;

    if ((sOcarinaRecordMode != 0) && ((sOcarinaCurTime - sOcarinaNoteStartT) >= 3)) {
        noteChanged = false;
        if (sLastOcarinaBtnVal != sCurOcarinaBtnVal) {
            if (sCurOcarinaBtnVal != 0xFF) {
                D_8016BA00.noteIdx = sCurOcarinaBtnIdx & 0x3F;
                sRecordSongLen++;
            } else if ((sOcarinaRecordMode == 2) && (sRecordSongLen == 8)) {
                AudioOcarina_RecordStep(1);
                return;
            }

            if (sRecordSongLen > 8) {
                if (sOcarinaRecordMode == 2) {
                    // notes played are over 8 and in recording mode.
                    AudioOcarina_RecordStep(1);
                    return;
                }
                sRecordSongLen = 1;
            }

            noteChanged = true;
        } else if (sLastOcarinaVolume != sCurOcarinaVolume) {
            noteChanged = true;
        } else if (sLastOcarinaVibrato != sCurOcarinaVibrato) {
            noteChanged = true;
        } else if (sLastOcarinaRawPitch != sCurOcarinaRawPitch) {
            noteChanged = true;
        }

        if (noteChanged) {
            AudioOcarina_RecordStep(0);
            sOcarinaNoteStartT = sOcarinaCurTime;
        }
    }
}

s32 AudioOcarina_MinigameGenNote(void);

void AudioOcarina_MinigameInit(u8 minigameIdx) {
    u8 i;

    if (minigameIdx > 2) {
        minigameIdx = 2;
    }

    sOcaMinigameApndPos = 0;
    sOcaMinigameEndPos = sOcaMinigameNoteCnts[minigameIdx];

    for(i = 0; i < 3; i++){
        AudioOcarina_MinigameGenNote();
    }
}

s32 AudioOcarina_MinigameGenNote(void) {
    u32 rnd;
    u8 rndNote;

    if (sOcaMinigameApndPos == sOcaMinigameEndPos) {
        return 1;
    }

    rnd = Audio_NextRandom();
    rndNote = sOcarinaNoteValues[rnd % 5];

    if (sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos - 1].noteIdx == rndNote) {
        rndNote = sOcarinaNoteValues[(rnd + 1) % 5];
    }

    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].noteIdx = rndNote;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].time = 0x2D;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].volume = 0x50;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].vibrato = 0;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].pitch = 0;

    sOcaMinigameApndPos++;

    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].noteIdx = 0xFF;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos].time = 0;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos + 1].noteIdx = 0xFF;
    sOcarinaTeachSongs[OCA_SONG_MEMORYGAME].notes[sOcaMinigameApndPos + 1].time = 0;
    if (1) { } 
    return 0;
}

// input update? 
void func_800EE6F4(void) {
    sOcarinaCurTime = gAudioContext.totalTaskCnt;
    if (sOcarinaInstrument != 0) {
        if (sOcarinaInpEnabled == 1) {
            func_800ECA00();
        }
        if ((sPlaybackSomeCounter == 0) && (sOcarinaInpEnabled == 1)) {
            func_800ED458(0);
        }
        if (D_80130F3C != 0) {
            if (D_80130F3C & 0x4000) {
                func_800ED200();
            } else {
                func_800ECDF8();
            }
        }
        
        AudioOcarina_PlaybackSong();
        sOcarinaLastTime = sOcarinaCurTime;

        if (sPlaybackSomeCounter == 0) {
            AudioOcarina_RecordingCheckChange();
        }

        if ((D_80130F3C != 0) && (sPrevOcarinaNoteVal != sCurOcarinaBtnVal)) {
            D_80131880 = 1;
        }

        sPrevOcarinaNoteVal = sCurOcarinaBtnVal;
    }

    func_800EE2D4();
    func_800EE318();
    func_800EE29C();
}

extern u8 D_80131C80;
extern u8 D_80131C84;
extern u16 D_80131C88;

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE824.s")

void func_800EE930(void) {
    D_8016B9F8.noteIdx = 0xFF;
    D_8016B9F8.state = 0xFF;
    D_8016B9F8.pos = 0;
    sDisplayedStaff.noteIdx = 0xFF;
    sDisplayedStaff.state = 0;
    sDisplayedStaff.pos = 0;
    D_8016BA00.noteIdx = 0xFF;
    D_8016BA00.state = 0xFF;
    D_8016BA00.pos = 0;
    D_80131880 = 0;
}


// DebugAudio_InputUpdate
void func_800EE97C(void) {
    Input inputs[4];
    u32 btn;

    PadMgr_RequestPadData(&gPadMgr, &inputs, 0);
    btn = inputs[3].cur.button;
    D_8016BAB0 = btn & 0xFFFF;
    sDebugPadPress = (btn ^ sDebugPadPressRaw) & btn;
    sDebugPadPressRaw = btn;
}

u8* func_800EE9D0(s32 arg0, u8 arg1) {
    s32 temp_a1;
    s32 temp_v1;
    u8 *temp_a3;
    s32 phi_v0;
    s32 phi_t0;
    s32 phi_v1;
    u8 i;
    u32 flg = 1;

    for(i = 0; i < arg1; flg *= 2, i++){
        if(arg0 & flg){
            D_8016B9B8[arg1 - i - 1] = 0x31;
        } else {
            D_8016B9B8[arg1 - i - 1] = 0x30;
        }
    }

    D_8016B9B8[arg1] = 0;
    return D_8016B9B8;
}

// Debug Print
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EEA50.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F1BDC.s")

void func_800F2150(void) {
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CUP)) {
        D_80131EC0--;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CDOWN)) {
        D_80131EC0++;
    }
    
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CLEFT)) {
        D_80131EBC--;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CRIGHT)) {
        D_80131EBC++;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
        D_80131EBC = 0;
        D_80131EC0 = 0;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP) && D_80131EC4 > 0) {
        D_80131EC4--;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN) && D_80131EC4 < 6) {
        D_80131EC4++;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DLEFT) && D_80131EC8[D_80131EC4] > 0) {
        D_80131EC8[D_80131EC4]--;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DRIGHT) && D_80131EC8[D_80131EC4] < 4) {
        D_80131EC8[D_80131EC4]++;
    }
}

extern u8 D_80131ED0;
extern u8 D_80131ED4;
extern u8 D_80131ED8;
extern s8 D_80131EDC;
extern s8 D_80131EE0;
extern u8 D_80131EE4[];
extern u8 D_80131EF0[];
extern u8 D_801333F0;

void func_800F227C(void) {

    if (D_80131EE4[0] != 0) {
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_CUP)) {
            D_80131EE0--;
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_CDOWN)) {
            D_80131EE0++;
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_CLEFT)) {
            D_80131EDC--;
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_CRIGHT)) {
            D_80131EDC++;
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_A)) {
            D_80131EDC = 0x1A;
            D_80131EE0 = 1;
            D_80131EE4[2] = 6;
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
            D_80131ED4 = 0;
            D_80131ED8 = 0;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP)) {
        if (D_80131ED0 > 0) {
            D_80131ED0--;
        } else {
            D_80131ED0 = 10;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
        if (D_80131ED0 < 0xA) {
            D_80131ED0++;
        } else {
            D_80131ED0 = 0;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DLEFT)) {
        if (D_80131EE4[D_80131ED0] > 0) {
            D_80131EE4[D_80131ED0]--;
        } else {
            D_80131EE4[D_80131ED0] = D_80131EF0[D_80131ED0] - 1;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DRIGHT)) {
        if (D_80131EE4[D_80131ED0] < D_80131EF0[D_80131ED0] - 1) {
            D_80131EE4[D_80131ED0]++;
        } else {
            D_80131EE4[D_80131ED0] = 0;
        }
    }

    D_801333F0 = D_80131EE4[3] + (D_80131EE4[4] * 2) + (D_80131EE4[5] * 4) + (D_80131EE4[6] * 8) + (D_80131EE4[7] * 0x10) + (D_80131EE4[8] * 32);
}

extern u8 D_80131F00;
extern u8 D_80131F04;
extern u8 D_80131F08;
extern u16 D_8016E2E0[];
extern u16 D_8016E2F8[];
extern u8 D_801333F4;
extern u8 D_8016E310[];

#ifdef NON_MATCHING
void func_800F2464(void) {
    s16 sp6;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a2_2;
    s32 temp_t3;
    s32 temp_t3_2;
    u16 temp_a3_2;
    u16 temp_t0;
    u32 temp_v0;
    u32 temp_v0_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a2;
    u8 temp_a2_3;
    u8 temp_a2_4;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    void *temp_a3;
    void *temp_t0_2;
    void *temp_v0_3;
    u8 phi_v1;
    s16 phi_t1;
    s16 phi_t1_2;
    u32 phi_v0;

    if (D_80131F00 == 0) {
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP)) {
            if (D_80131F04 > 0) {
                D_80131F04--;
            } else {
                D_80131F04 = 9;
            }
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
            temp_v1_2 = D_80131F04;
            if (D_80131F04 < 9) {
                D_80131F04++;
            } else {
                D_80131F04 = 0;
            }
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_A)) {
            D_80131F00 = 1;
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
            D_8016E2E0[D_80131F04] = 0;
            D_8016E2F8[D_80131F04] = 0;
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_START)) {
            phi_v1 = D_80131F04;
            if (phi_v1 != 0) {
                phi_v1--;
            } else {
                phi_v1 = 9;
            }

            D_8016E2E0[D_80131F04] = D_8016E2E0[phi_v1];
            D_8016E2F8[D_80131F04] = D_8016E2F8[phi_v1];
        }
    } else {
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_DLEFT)) {
            temp_a0 = D_80131F08;
            if (D_80131F08 > 0) {
                D_80131F08--;
            } else {
                D_80131F08 = 7;
            }
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_DRIGHT)) {
            temp_a0_2 = D_80131F08;
            if (D_80131F08 < 7) {
                D_80131F08++;
            } else {
                D_80131F08 = 0;
            }
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP) || CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
            if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP)) {
                phi_t1 = D_8016BAB0 & 8 ? 8 : 1;
            }

            if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
                phi_t1 = D_8016BAB0 & 8 ? -8 : -1;
            }

            if (D_80131F08 < 4) {
                D_8016E2E0[D_80131F04] = (D_8016E2E0[D_80131F04] & ((0xF << ((-D_80131F08 * 4) + 0xC)) ^ 0xFFFF)) + ((u16)(((D_8016E2E0[D_80131F04] >> ((-D_80131F08 * 4) + 0xC)) + phi_t1) & 0xF) << ((-D_80131F08 * 4) + 0xC));
            } else {
                D_8016E2E0[D_80131F04] = (D_8016E2E0[D_80131F04] & ((0xF << ((-D_80131F08 * 4) + 0xC)) ^ 0xFFFF)) + ((u16)(((D_8016E2E0[D_80131F04] >> ((-D_80131F08 * 4) + 0xC)) + phi_t1) & 0xF) << ((-D_80131F08 * 4) + 0xC));
            }
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_A)) {
            D_80131F00 = 0;
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
            if (D_80131F08 < 4) {
                D_8016E2E0[D_80131F04] = 0;
            } else {
                D_8016E2F8[D_80131F04] = 0;
            }
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CLEFT)) {
        D_801333F4 ^= 1;
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_CDOWN)) {
        D_8016E310[D_80131F04] ^= 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2464.s")
#endif

typedef struct {
    char unk_00[0x38];
} unk_dstruct;

extern u8 D_80131EFC;
extern unk_dstruct D_801337CE[];
extern u8 D_80131F28;
extern u8 D_80131F2C;
extern u8 D_80131F30[];
void func_800F27A0(void) {
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
        if (D_80131F28 != 0) {
            D_80131F28--;
        } else {
            D_80131F28 = D_801337CE[D_80131EFC].unk_00[0] - 1;
        }
    }
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP)) {
        if (D_80131F28 < D_801337CE[D_80131EFC].unk_00[0] - 1) {
            D_80131F28++;
        } else {
            D_80131F28 = 0;
        }
    }
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DLEFT)) {
        D_80131F2C = (D_80131F2C - 1) & 0xF;
    }
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DRIGHT)) {
        D_80131F2C = (D_80131F2C + 1) & 0xF;
    }
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_START)) {
        D_80131F30[D_80131F28] = 0;
    }
}

void func_800F28AC(void) {
}

void func_800F28B4(void) {
    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DUP)) {
        if (D_80131F50 > 0) {
            D_80131F50--;
        } else {
            D_80131F50 = 1;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DDOWN)) {
        if (D_80131F50 <= 0) {
            D_80131F50++;
        } else {
            D_80131F50 = 0;
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DLEFT)) {
        D_80131F4C[D_80131F50]--;
        if (D_80131F50 == 1) {
            func_800F5E90(D_80131F4C[1]);
            ; // might be a fake match? 
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_DRIGHT)) {
        D_80131F4C[D_80131F50]++;
        if (D_80131F50 == 1) {
            func_800F5E90(D_80131F4C[1]);
        }
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_A)) {
        Audio_SendMsg_s8(AUDIO_CMD(0x46, 0x00, 0x00 , 0x00), D_80131F4C[1]);
        Audio_SetBGM(D_80131F4C[0] | 0x10000);
    }

    if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
        Audio_SetBGM(0x100100FF);
    }
}

void func_800F29FC(void) {
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2A04.s")

void func_800F2D6C(s8 *arg0, u16 arg1) {
    u8 i = 0;

    D_8016B7E8[D_80131ED4].unk_06 = arg1;
    
    while(arg0[i] != 0) {
        D_8016B7E8[D_80131ED4].unk_00[i] = arg0[i];
        i++;
    }

    while(i < 5) {
        D_8016B7E8[D_80131ED4].unk_00[i] = 0;
        i++;
    }

    if (D_80131ED4 < 0x18) {
        D_80131ED4++;
    } else {
        D_80131ED4 = 0;
        D_80131ED8 = 1;
    }
}

void func_800F1BDC(void);
void func_800F2150(void);
void func_800F227C(void);
void func_800F2464(void);
void func_800F27A0(void);
void func_800F28AC(void);
void func_800F2A04(void);

void func_800F2E28(void) {
    if (D_80131C98 != 0) {
        if (D_80131C9C != 0) {
            func_800F7260(0x6F);
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_L)) {
            // goto next page.
            if (D_80131CA0 < 0xE) {
                D_80131CA0++;
            } else {
                D_80131CA0 = 0;
            }
        }
        if (CHECK_BTN_ANY(sDebugPadPress, BTN_R)) {
            // goto previous page
            if (D_80131CA0 > 0) {
                D_80131CA0--;
            } else {
                D_80131CA0 = 0xE;
            }
        }

        if (CHECK_BTN_ANY(sDebugPadPress, BTN_Z)) {
            // change text color
            D_80131CA8 = (u32)(++D_80131CA8) % 8;
        }
        
        switch(D_80131CA0){
            case 0:
                if (CHECK_BTN_ANY(sDebugPadPress, BTN_A)) {
                    D_80131E08[5] ^= 0x1;
                    Audio_SetBGM(D_80131E08[5] | 0xE0000100);
                    if (func_800FA0B4(0) != 1) {
                        Audio_SetBGM(0x100000FF);
                    }
                    Audio_SetBGM(0x110000FF);
                    Audio_SetBGM(0x130000FF);
                }

                if (CHECK_BTN_ANY(sDebugPadPress, BTN_B)) {
                    D_80131C9C ^= 0x1;
                    if (D_80131C9C == 0) {
                        func_800F7260(0);
                    }
                }
                break;
            case 1:
                func_800F1BDC();
                break;
            case 7:
                func_800F2150();
                break;
            case 13:
                func_800F227C();
                break;
            case 8:
                func_800F2464();
                break;
            case 5:
                func_800F27A0();
                break;
            case 3:
                func_800F28AC();
                break;
            case 9:
                func_800F28B4();
                break;
            case 11:
                func_800F29FC();
                break;
            case 12:
                func_800F2A04();
                break;
            case 14:
            default:
                break;
        }

        D_8013340C = D_80131EEE;
    }
}

void func_800F50CC(void);
void func_800F4A70(void);
void func_800F5CF8(void);

void OcarinaAudio_Update(void) {
    if (func_800FAD34() == 0) {
        sOcarinaUpdateTaskCntStart = gAudioContext.totalTaskCnt;
        sOcarinaUpdateStartTime = osGetTime();
        func_800EE6F4();
        func_800F4784(&D_8016B7B8);
        func_800F4784(&D_8016B7C8);
        func_800F4A70();
        func_800F56A8();
        func_800F5CF8();
        if (D_80133414 == 7) {
            func_800F50CC();
        }
        func_800F8E3C();
        func_800FA034();
        func_800F8F88();
        func_800FA3DC();
        func_800EE97C();
        func_800F2E28();
        func_800E5B80();
        sOcarinaUpdateTaskCntEnd = gAudioContext.totalTaskCnt;
        sOcarinaUpdateEndTime = osGetTime();
    }
}

void func_800F3138(UNK_TYPE arg0) {
}

void func_800F3140(UNK_TYPE arg0, UNK_TYPE arg1) {
}

#ifdef NON_MATCHING
void func_800F314C(u32 arg0) {
    Audio_SendMsg_u32(AUDIO_CMD(0x82, 0x00, arg0, 0x00), 1);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F314C.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3188.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F32F0.s")

s8 func_800F3468(f32 arg0, f32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3468.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F35EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F37B8.s")

s8 func_800F3990(f32 arg0, s32 arg1) {
    s8 ret = 0;

    if(arg0 >= 0.0f){
        if(arg0 > 625.0f){
            ret = 0x7F;
        } else {
            ret = (arg0 / 625.0f) * 126.0f;
        }
    }
    return ret | 1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3A08.s")

void func_800F3ED4(void) {
    u8 i;
    unk_s1* t;

    for(i = 0; i < 16; i++){
        t = &D_8016B8B8[i];
        t->unk_00 = 1.0f;
        t->unk_04 = 1.0f;
        t->unk_08 = 0;
        t->unk_09 = 0x40;
        t->unk_0A = 0;
        t->unk_0B = 0xFF;
        t->unk_0C = 0xFF;
    }

    D_8016B8B8[0xD].unk_0C = 0;
    D_8013061C = 0;
    D_80130618 = 0;
}

void func_800F3F3C(u8 arg0) {
    if (D_8016E264[0] != 1) {
        Audio_SetBGM(0x300006DU);
        Audio_SetBGM(arg0 | 0x83000000);
    }
}

f32 func_800F3F84(f32);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3F84.s")

void func_800F4010(Vec3f *arg0, u16 arg1, f32 arg2) {
    f32 sp24;
    f32 phi_f0;
    u8 phi_v0;
    u16 phi_a0;

    D_80131C8C = arg2;
    sp24 = func_800F3F84(arg2);
    Audio_PlaySoundGeneral(arg1, arg0, 4, &D_8016B7B0, &D_8016B7A8, &D_801333E8);
    
    if ((arg1 & 0xF0) == 0xB0) {
        phi_f0 = 0.3f;
        phi_v0 = 1;
        sp24 = 1.0f;
    } else {
        phi_f0 = 1.1f;
        phi_v0 = gAudioContext.gAudioRandom % 2;
    }

    if ((phi_f0 < arg2) && (phi_v0 != 0)) {
        if ((arg1 & 0x80) != 0) {
            phi_a0 = 0x867;
        } else {
            phi_a0 = 0x866;
        }
        D_8016B7AC = (sp24 * 0.7) + 0.3;
        Audio_PlaySoundGeneral(phi_a0, arg0, 4U, &D_8016B7B0, &D_8016B7AC, &D_801333E8);
    }
}

void func_800F4138(Vec3f *pos, u16 sfxId, f32 arg2) {
    func_800F3F84(arg2);
    Audio_PlaySoundGeneral(sfxId, pos, 4U, &D_8016B7B0, &D_8016B7A8, &D_801333E8);
}

void func_800F4190(Vec3f *pos, u16 sfxId) {
    Audio_PlaySoundGeneral(sfxId, pos, 4, &D_801305B0, &D_801333E0, &D_801305B4);
}
void func_800F41E0(Vec3f *pos, u16 baseSfx, u8 arg2) {
    u8 offset = Audio_NextRandom() % arg2;
    Audio_PlaySoundGeneral(baseSfx + offset, pos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_800F4254(Vec3f *pos, u8 arg1) {
    arg1 = arg1 & 3;
    if (arg1 != D_801305E0) {
        D_801305F4 = D_801305E4[arg1];
        switch(arg1){
            case 1:
                Audio_PlaySoundGeneral(0x86D, pos, 4, &D_801305F4, &D_801333E0, &D_801333E8);
                break;
            case 2:
                Audio_PlaySoundGeneral(0x86DU, pos, 4, &D_801305F4, &D_801333E0, &D_801333E8);
                break;

        }
        
        D_801305E0 = arg1;
    }
    if (arg1 != 0) {
        Audio_PlaySoundGeneral(0x1022, pos, 4, &D_801305F4, &D_801333E0, &D_801333E8);
    }
}

void func_800F436C(Vec3f* pos, u16 sfxId, f32 arg2) {
    if (arg2 < 0.75f) {
        D_8016B7D8 = ((arg2 / 0.75f) * 0.25f) + 0.5f;
    } else {
        D_8016B7D8 = arg2;
    }

    if (D_8016B7D8 > 0.5f) {
        Audio_PlaySoundGeneral(sfxId, pos, 4, &D_8016B7D8, &D_801333E0, &D_801333E8);
    }
}

void func_800F4414(s32 *pos, u16 sfxId, f32 arg2) {
    D_801305B8--;
    if (D_801305B8 == 0) {
        Audio_PlaySoundGeneral(sfxId, pos, 4, &D_8016B7D8, &D_801333E0, &D_801333E8);

        if (arg2 > 2.0f) {
            arg2 = 2.0f;
        }
        D_801305B8 = (s8)((D_801305C0 - D_801305BC) * (1.0f - arg2)) + D_801305C0;
    }
}

void func_800F4414(s32*, u16, f32);


void func_800F44EC(s8 arg0, s8 arg1) {
    D_801305B8 = 1;
    D_801305BC = arg1;
    D_801305C0 = arg0;
}

void func_800F4524(Vec3f *arg0, u16 arg1, s8 arg2) {
    D_8016B7DC = arg2;
    Audio_PlaySoundGeneral(arg1, arg0, 4, &D_801333E0, &D_801333E0, &D_8016B7DC);
}

void func_800F4578(Vec3f *arg0, u16 arg1, f32 arg2) {
    D_8016B7E0 = arg2;
    Audio_PlaySoundGeneral(arg1, arg0, 4, &D_801333E0, &D_8016B7E0, &D_801333E8);
}

void func_800F45D0(f32 arg0) {
    func_800F4414(&D_801333D4, 0x103D, arg0);
    func_800F436C(&D_801333D4, 0, (0.15f * arg0) + 1.4f);
}

void func_800F4634(Vec3f *pos, f32 arg1) {
    if (func_800F8FF4(0x2006) == 0) {
        D_8016B7B8.unk_00 = arg1;
    } else if (arg1 != D_8016B7B8.unk_00) {
        D_8016B7B8.unk_04 = arg1;
        D_8016B7B8.unk_0C = 0x28;
        D_8016B7B8.unk_08 = (D_8016B7B8.unk_04 - D_8016B7B8.unk_00) / 40.0f;
    }
    Audio_PlaySoundGeneral(0x2006, pos, 4, &D_8016B7B8, &D_801333E0, &D_801333E8);
}

void func_800F46E0(Vec3f *pos, f32 arg0) {
    if (func_800F8FF4(0x2007) == 0) {
        D_8016B7C8.unk_00 = arg0;
    } else if (arg0 != D_8016B7C8.unk_00) {
        D_8016B7C8.unk_04 = arg0;
        D_8016B7C8.unk_0C = 0x28;
        D_8016B7C8.unk_08 = (D_8016B7C8.unk_04 - D_8016B7C8.unk_00) / 40.0f;
    }
    Audio_PlaySoundGeneral(0x2007, pos, 4, &D_8016B7C8, &D_8016B7C8, &D_801333E8);
}

void func_800F4784(unk_s2 *arg0) {
    if (arg0->unk_0C != 0) {
        arg0->unk_0C--;
        if (arg0->unk_0C != 0) {
            arg0->unk_00 = arg0->unk_00 + arg0->unk_08;
        } else {
            arg0->unk_00 = arg0->unk_04;
        }
    }
}

void func_800F47BC(void) {
    func_800FA240(0, 1, 0, 0xA);
    func_800FA240(3, 1, 0, 0xA);
}

void func_800F47FC(void) {
    func_800FA240(0, 1, 0x7F, 3);
    func_800FA240(3, 1, 0x7F, 3);
}

void func_800F483C(u8 arg0, u8 arg1) {
    func_800FA240(0, 0, arg0, arg1);
}

s32 func_800F491C(u8 arg0);

void func_800F4870(u8 arg0) {
    s8 phi_s1;
    u8 i;

    phi_s1 = 0;
    if(arg0 == 0){
        phi_s1 = 0x7F;
    }

    i = 0;
    do{
        Audio_SendMsg_s8(AUDIO_CMD(0x07, 0x00, (u32)i, 0x00), phi_s1);
        i++;
    } while (i < 16);

    if (arg0 == 7) {
        D_80130600 = 2;
    } else {
        func_800F491C(D_801305F8[arg0 & 7]);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F491C.s")

void func_800F4A54(u8 arg0) {
    D_8016B8B0 = arg0;
    D_8016B8B2 = 1;
}

void func_800F4A70(void) {
    if (D_8016B8B2 == 1) {
        if (D_8016B8B1 != D_8016B8B0) {
            func_800FA240(0, 0, D_8016B8B0, 0xA);
            D_8016B8B1 = D_8016B8B0;
            D_8016B8B3 = 1;
        }
        D_8016B8B2 = 0;
    } else if (D_8016B8B3 == 1 && D_80130608 == 0) {
        func_800FA240(0, 0, 0x7F, 0xA);
        D_8016B8B1 = 0x7F;
        D_8016B8B3 = 0;
    }
    
    if(D_80130600 != 0)
    {
        D_80130600--;
        if(D_80130600 == 0){
            func_800F491C(D_801305FF);
        }
    }
}

void func_800F4B58(Vec3f *arg0, u16 arg1, u8* arg2) {
    Audio_PlaySoundGeneral(arg1, arg0, 4, &gNoteFrequencies[arg2[D_801305CC] + 39], &D_801333E0, &D_801333E8);
    
    if (D_801305CC < 15) {
        D_801305CC++;
    }
}

void func_800F4BE8(void) {
    D_801305CC = 0;
}

void func_800F4BF4(Vec3f *arg0, u16 arg1, s8 arg2) {
    Audio_PlaySoundGeneral(arg1, arg0, 4, &gNoteFrequencies[arg2 + 39], &D_801333E0, &D_801333E8);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4C58.s")

#ifdef NON_MATCHING
void func_800F4E30(f32* arg0, f32 arg1) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_s0;
    s32 temp_v0;
    f32 *phi_v0;
    f32 phi_f0;
    s32 phi_v0_2;
    f32 phi_f22;
    s32 phi_s0;
    s8 phi_s4;
    u8 i;

    phi_v0 = D_8013064C;
    if (D_8013064C == 0) {
        D_80130650 = arg1;
        D_8013064C = arg0;
        phi_v0 = arg0;
        phi_f0 = D_80130650;
    } else if (arg0 != D_8013064C) {
        phi_v0 = D_8013064C;
        phi_f0 = D_80130650;
        if (arg1 < temp_f0) {
            D_80130650 = arg1;
            D_8013064C = arg0;
            phi_v0 = arg0;
            phi_f0 = D_80130650;
        }
    } else {
        D_80130650 = arg1;
        phi_v0 = D_8013064C;
        phi_f0 = D_80130650;
    }

    temp_f2 = *phi_v0;
    if (100.0f < temp_f2) {
        phi_s4 = 0x7F;
    } else if (temp_f2 < -100.0f) {
        phi_s4 = 0;
    } else {
        phi_s4 = ((temp_f2 / 100.0f) * 64.0f) + 64.0f;
    }

    if (400.0f < phi_f0) {
        phi_f22 = 0.1f;
    } else if (phi_f0 < 120.0f) {
        phi_f22 = 1.0f;
    } else {
        phi_f22 = ((1.0f - ((phi_f0 - 120.0f) / 280.0f)) * 0.9f) + 0.1f;
    }

    for(i = 0; i < 0x10; i++){
        if (i != 9) {
            Audio_SetBGM(AUDIO_CMD(0x60, 0x02, i, ((u32) (127.0f * phi_f22))));
            Audio_SendMsg_s8(AUDIO_CMD(0x30, 0x00, (u32)i, 0x00), phi_s4);
        }
    }
}
#else
void func_800F4E30(f32* arg0, f32 arg1);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4E30.s")
#endif


void func_800F50CC(void) {
    if (D_8013064C != NULL) {
        D_8013064C = NULL;
    }
}

void *func_800F50EC(Vec3f* arg0) {
    if (D_8013064C == arg0) {
        D_8013064C = NULL;
    }
}

#ifdef NON_MATCHING
extern u16 D_80131F6C;
// regalloc 
void func_800F510C(s8 arg0) {
    u8 phi_a2;
    u16 phi_a1;
    u8 sp40[2];
    u8 i;
    u8 j;

    *((u16*)&sp40[0]) = D_80131F6C;
    if ((func_800FA0B4(1) == 0xFFFF) && (func_800FA0B4(3) != 0x2F)) {
        for(i = 0; i < 2; i++){
            phi_a2 = i == 0 ? arg0 : 0x7F - arg0;

            // regalloc around here.
            if (phi_a2 > 0x64) {
                phi_a2 = 0xB;
            } else if (phi_a2 < 0x14) {
                phi_a2 = 2;
            } else {
                phi_a2 = ((phi_a2 - 0x14) / 0xA) + 2;
            }

            phi_a1 = 0;
            for(j = 0; j < 0x10; j++){
                if (gAudioContext.gSequencePlayers[sp40[i]].channels[j]->notePriority < phi_a2) {
                    phi_a1 += (1 << j);
                }
            }
            Audio_SetBGM((sp40[i] << 0x18) | 0xA0000000 | phi_a1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F510C.s")
#endif

void func_800F510C(s8);
void func_800F52A0(Vec3f *arg0, u16 arg1, u16 arg2) {
    f32 phi_f2;
    f32 phi_f14;
    u8 phi_a2;
    f32 temp_f0;

    if (D_8016B9F3 != 0) {
        D_8016B9F3--;
        return;
    }

    phi_f14 = sqrtf(SQ(arg0->z) + SQ(arg0->x));
    if (D_8013064C == NULL) {
        D_8013064C = arg0;
        func_800F5E18(3, arg1, 0, 7, 2);
    } else {
        temp_f0 = sqrtf(SQ(D_8013064C->z) + SQ(D_8013064C->x));
        if (phi_f14 < temp_f0) {
            D_8013064C = arg0;
        } else {
            phi_f14 = temp_f0;
        }
    }

    if (arg0->y < 0.0f) {
        phi_f2 = -arg0->y;
    } else {
        phi_f2 = arg0->y;
    }

    if((arg2 / 15.0f) < phi_f2){
        phi_a2 = 0;
    } else if (phi_f14 < arg2){
        phi_a2 = (1.0f - (phi_f14 / arg2)) * 127.0f;
    } else {
        phi_a2 = 0;
    }

    if (arg1 != 0x28) {
        func_800F510C(phi_a2);
    }

    func_800FA240(3, 3, phi_a2, 0);
    func_800FA240(0, 3, (0x7F - phi_a2), 0);
}

void func_800F5504(void) {
    D_8013064C = NULL;
}

void func_800F5510(u16 arg0) {
    func_800F5550(arg0);
    func_800F5E18(0, arg0, 0, 0, 1);
}

void func_800F5550(u16 arg0) {
    u8 sp27 = 0;
    u16 nv;

    if (func_800FA0B4(0) != 0x4C) {
        if (func_800FA0B4(3) == 0x2F) {
            func_800F9474(3, 0);
            Audio_SendMsg_u32(AUDIO_CMD(0xF8, 0, 0, 0), 0);
        }
        
        //t = arg0 & 0xFF;
        if (D_80130658[D_80130630] & 0x20 && D_80130658[(arg0 & 0xFF) & 0xFF] & 0x10) {
            
            if ((D_8013062C & 0x3F) != 0) {
                sp27 = 0x1E;
            }

            func_800F5E18(0, arg0, sp27, 7, D_8013062C);

            D_8013062C = 0;
        } else {
            nv = D_80130658[(arg0 & 0xFF) & 0xFF] & 0x40 ? 1 : 0xFF;
            func_800F5E18(0, arg0, 0, 7, nv);
            if (!(D_80130658[arg0] & 0x20)) {
                D_8013062C = 0xC0;
            }
        }
        D_80130630 = arg0 & 0xFF;
    }
}

void func_800F56A8(void) {
    u16 temp_v0;
    u8 bvar;

    temp_v0 = func_800FA0B4(0);
    bvar = temp_v0 & 0xFF;
    if ((temp_v0 != 0xFFFF) && ((D_80130658[bvar] & 0x10) != 0)) {
        if (D_8013062C != 0xC0) {
            D_8013062C = gAudioContext.gSequencePlayers->unk_158[3];
        } else {
            D_8013062C = 0;
        }
    }
}

void func_800F5718(void) {
    if (func_800FA0B4(0) != 0x4C) {
        Audio_SetBGM(0x4C);
    }
}

void func_800F574C(f32 arg0, u8 arg2) {
    if (arg0 == 1.0f) {
        Audio_SetBGM((arg2 << 0x10) | 0xB0004000);
    } else {
        Audio_SetBGM((arg2 << 8) | 0xC1300000 | (u8)(arg0 * 100.0f));
    }
    Audio_SetBGM((arg2 << 8) | 0xC1A00000 | (u8)(arg0 * 100.0f));
}

void func_800F5918(void) {
    if (func_800FA0B4(0) == 0x6C && func_800FA11C(0, 0xF0000000)) {
        Audio_SetBGM(0xB00500D2);
    }
}

void func_800F595C(u16 arg0) {
    u8 arg0b = arg0 & 0xFF;
    
    if (D_80130658[arg0b] & 2) {
        func_800F5C64(arg0);
    } else if (D_80130658[arg0b] & 4) {
        Audio_SetBGM(0x1000000 | arg0);
        
    } else {
        func_800F5E18(0, arg0, 0, 7, -1);
        Audio_SetBGM(0x110000FF);
    }
}

void func_800F59E8(u16 arg0) {
    u8 arg0b = arg0 & 0xFF;

    if (D_80130658[arg0b] & 2) {
        Audio_SetBGM(0x110000FF);
    } else if (D_80130658[arg0b] & 4) {
        Audio_SetBGM(0x110000FF);
    } else {
        Audio_SetBGM(0x100000FF);
    }
}

s32 func_800F5A58(u8 arg0) {
    u8 phi_a1 = 0;

    if (D_80130658[arg0 & 0xFF] & 2){
        phi_a1 = 1;
    } else if(D_80130658[arg0 & 0xFF] & 4) {
        phi_a1 = 1;
    }

    if (arg0 == (u8)func_800FA0B4(phi_a1)) {
        return 1;
    } else {
        return 0;
    }
}

void func_800F5ACC(u16 arg0) {
    u16 temp_v0;

    temp_v0 = func_800FA0B4(0);
    if ((temp_v0 & 0xFF) != 0x2E && (temp_v0 & 0xFF) != 0x62 && temp_v0 != arg0) {
        func_800F5E90(3);
        if (temp_v0 != 0xFFFF) {
            D_80130628 = temp_v0;
        } else {
            osSyncPrintf("Middle Boss BGM Start not stack \n");
        }
        Audio_SetBGM(arg0 & 0xFFFFFFFF);
    }
}

void func_800F5B58(void) {
    if ((func_800FA0B4(0) != 0xFFFF) && 
        (D_80130628 != 0xFFFF) && 
        (D_80130658[func_800FA0B4(0) & 0xFF] & 8)) {

        if (D_80130628 == 0xFFFF) {
            Audio_SetBGM(0x100000FF);
        } else {
            Audio_SetBGM(D_80130628 & 0xFFFFFFFF);
        }
        D_80130628 = 0xFFFF;
    }
}

void func_800F5BF0(u8 arg0) {
    u16 temp_v0;

    temp_v0 = func_800FA0B4(0);
    if (temp_v0 != 1) {
        D_80130628 = temp_v0;
    }
    func_800F6FB4(arg0);
}

void func_800F5C2C(void) {
    if (D_80130628 != 0xFFFF) {
        u32 t = D_80130628;
        Audio_SetBGM(t);
    }
    D_80130628 = 0xFFFF;
}

void func_800F5C64(u16 arg0) {
    u16 sp26;
    s32 sp20;
    u8 *sp1C;
    u8 *sp18;

    sp26 = func_800FA0B4(1);
    sp1C = func_800E5E84(sp26 & 0xFF, &sp20);
    sp18 = func_800E5E84(arg0 & 0xFF, &sp20);
    if ((sp26 == 0xFFFF) || (*sp1C == *sp18)) {
        D_8016B9F4 = 1;
    } else {
        D_8016B9F4 = 5;
        Audio_SetBGM(0x110000FF);
    }
    D_8016B9F6 = arg0;
}

void func_800F5CF8(void) {
    u16 sp26;
    u16 sp24;
    u16 sp22;

    if (D_8016B9F4 != 0) {
        D_8016B9F4--;
        if (D_8016B9F4 == 0) {
            Audio_SendMsg_u32(AUDIO_CMD(0xE3, 0, 0, 0), 0);
            Audio_SendMsg_u32(AUDIO_CMD(0xE3, 0, 0, 0), 1);
            func_800FA0B4(0);
            sp26 = func_800FA0B4(1);
            sp22 = func_800FA0B4(3);
            if (sp26 == 0xFFFF) {
                func_800FA240(0, 1, 0, 5);
                func_800FA240(3, 1, 0, 5);
                Audio_SetBGM(0xC180010A);
                Audio_SetBGM(0xC183010A);
                Audio_SetBGM(0xC1900000);
                if (sp22 != 0x2F) {
                    Audio_SetBGM(0xC1930000);
                }
            }
            Audio_SetBGM(D_8016B9F6 | 0x1010000);
            Audio_SetBGM(0xA000FFFF);
            if (sp22 != 0x2F) {
                Audio_SetBGM(0xA300FFFF);
            }
        }
    }
}

void func_800F5E18(u8 arg0, u16 arg1, u8 arg2, s8 arg3, s8 arg4) {
    Audio_SetBGM(0x70000000 | (arg0 << 0x18) | ((arg3 & 0xFF) << 0x10) | (u8)arg4);
    Audio_SetBGM((arg0 << 0x18) | (arg2 << 0x10) | arg1);
}
extern u8 D_80130654;
extern u32 D_80130634;
extern u32 D_80130638;
void func_800F5E90(u8 arg0) {
    s32 phi_t0;
    u16 phi_t1;
    u8 phi_a3;

    D_80130654 = arg0;
    if (D_80130628 == 0xFFFF) {
        if (D_8013060C != 0) {
            arg0 = 3;
        }
        phi_t1 = D_8016E750[0].unk_254;
        if (phi_t1 == 2 && func_800FA0B4(3) == 0x81A) {
            arg0 = 3;
        }
        
        phi_a3 = phi_t1 & 0xFF;
        if ((phi_t1 == 0xFFFF) || ((D_80130658[phi_a3] & 1) != 0) || ((D_8013061C & 0x7F) == 1)) {
            if (arg0 != (D_8013061C & 0x7F)) {
                if (arg0 == 1) {
                    if(D_8016E750[3].unk_0E[1] - D_80130624 < 0) {
                        phi_t0 = -(D_8016E750[3].unk_0E[1] - D_80130624);
                    } else {
                        phi_t0 = D_8016E750[3].unk_0E[1] - D_80130624;
                    }
                    func_800FA240(3, 3, D_80130624, phi_t0);
                    Audio_SetBGM(0x30A081AU);
                    if (phi_t1 != 1) {
                        func_800FA240(0, 3, (0x7F - D_80130624) & 0xFF, 0xA);
                        func_800F510C(D_80130624);
                    }
                } else {
                    if ((D_8013061C & 0x7F) == 1) {
                        Audio_SetBGM(0x130A00FF);
                        if(arg0 == 3) { 
                            phi_a3 = 0;
                        } else {
                            phi_a3 = 10;
                        }

                        func_800FA240(0, 3, 0x7F, phi_a3);
                        func_800F510C(0);
                    }
                }

                D_8013061C = arg0 + 0x80;
            }
        } else {
            if (arg0 == 0) {
                if (D_8013061C == 2) {
                    D_80130638 = 0;
                }
                D_80130634 = 0;
                D_80130638++;
            } else {
                D_80130634++;
            }

            if (arg0 == 2 && D_80130634 < 0x1E && D_80130638 >= 0x15) {
                arg0 = 0;
            }

            D_8013061C = arg0;
            Audio_SetBGM(arg0 | 0x70020000);
        }
    }
}

void func_800F6114(f32 arg0) {
    f32 phi_f0;

    if (D_8013061C == 0x81) {
        if (arg0 != D_80130620) {
            if (arg0 < 150.0f) {
                phi_f0 = 0.0f;
            } else if (arg0 > 500.0f) {
                phi_f0 = 350.0f;
            } else {
                phi_f0 = arg0 - 150.0f;
            }

            D_80130624 = ((350.0f - phi_f0) * 127.0f) / 350.0f;
            func_800FA240(3, 3, D_80130624, 0xA);
            if (D_8016E750[0].unk_254 != 1) {
                func_800FA240(0, 3, (0x7F - D_80130624), 0xA);
            }
        }
        if (D_8016E750[0].unk_254 != 1) {
            func_800F510C(D_80130624);
        }
    }
    D_80130620 = arg0;
}

#ifdef NON_MATCHING
void func_800F6268(f32 arg0, u16 arg1) {
    s32 temp_v1;
    s8 phi_v1;
    s8 temp_a0;

    D_8016BAA8 = 1;
    D_8016BAAC = arg0;
    temp_v1 = arg1 & 0xFF;
    if (D_8016B9F2 == 0) {
        temp_a0 = func_800FA0B4(0) & 0xFF;
        if (temp_a0 == temp_v1) {
            if (temp_v1 == 0x2F) {
                if(arg0 > 2000.0f) {
                    phi_v1 = 0x7F;
                } else if(arg0 < 200.0f) {
                    phi_v1 = 0;
                } else {
                    phi_v1 = ((arg0 - 200.0f) * 127.0f) / 1800.0f;
                }
                Audio_SetBGM(0x60030000 | (0x7F - phi_v1));
                Audio_SetBGM(0x60030100 | (0x7F - phi_v1));
                Audio_SetBGM(0x60030D00 | (phi_v1 & 0xFF));

                if (*D_8016B9D8 == 0) {
                    (*D_8016B9D8)++;
                }
            }
        } else if ((temp_a0 == 1) && (temp_v1 == 0x2F)) {
            temp_a0 = func_800FA0B4(3) & 0xFF;
            if ((temp_a0 != temp_v1) && (*D_8016B9D8 < 0xA)) {
                func_800F5E18(3, 0x2F, 0, 0, 0);
                Audio_SetBGM(0xA300FFFC);
                *D_8016B9D8 = 0xA;
            }

            if(arg0 > 2000.0f) {
                phi_v1 = 0x7F;
            } else if(arg0 < 200.0f) {
                phi_v1 = 0;
            } else {
                phi_v1 = ((arg0 - 200.0f) * 127.0f) / 1800.0f;
            }


            Audio_SetBGM(0x63030000 | (0x7F - phi_v1));
            Audio_SetBGM(0x63030100 | (0x7F - phi_v1));
        }

        if (*D_8016B9D8 < 0xA) {
            (*D_8016B9D8)++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6268.s")
#endif

void func_800F64E0(u8 arg0) {
    D_80130608 = arg0;
    if (arg0 != 0) {
        Audio_PlaySoundGeneral(0x4800, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        Audio_SendMsg_u32(AUDIO_CMD(0xF1, 0, 0, 0), 0);
    } else {
        Audio_PlaySoundGeneral(0x4801, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        Audio_SendMsg_u32(AUDIO_CMD(0xF2, 0, 0, 0), 0);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6584.s")

void func_800F66C0(s8 arg0) {
    D_80130614 = arg0 & 0x7F;
}

void func_800F66DC(s8 arg0) {
    if (arg0 != 0) {
        D_80130618 = arg0 & 0x7F;
    }
}

#ifdef NON_MATCHING
void func_800F6700(s8 arg0) {
    u8 sp1F;

    switch(arg0){
        case 0:
            sp1F = 0;
            D_80130604 = 0;
            break;
        case 1:
            sp1F = 3;
            D_80130604 = 3;
            break;
        case 2:
            sp1F = 1;
            D_80130604 = 1;
            break;
        case 3:
            sp1F = 0;
            D_80130604 = 2;
            break;

    }
    Audio_SetBGM(0xE0000000 | sp1F);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6700.s")
#endif

void func_800F67A0(u8 arg0) {
    if (D_8013063C != arg0) {
        if (arg0 == 0) {
            Audio_StopSFX(0x86B);
        } else if (D_8013063C == 0) {
            Audio_PlaySoundGeneral(0x86B, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    }
    D_8013063C = arg0;
    D_80130644 = arg0;
}

void func_800F6828(u8 arg0) {
    u32 t;
    u8 i;

    D_80130648 = arg0;
    D_80130640 = arg0;
    if (D_8016E750[0].unk_254 == 1) {
        for(i = 0; i < 16; i++){
            t = i;
            Audio_SendMsg_s8(AUDIO_CMD(0x06, 0, t, 6), arg0);
        }
    }
}

void func_800F68BC(s8 arg0) {
    D_8013060C = arg0;
}

void func_800F68D4(u16 arg0, Vec3f *arg1, u8 arg2, u32 *arg3, u32* arg4, u32* arg5) {
    if (D_8013060C == 0) {
        Audio_PlaySoundGeneral(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

void func_800F691C(u16 arg0) {
    func_800F68D4(arg0, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

#ifdef NON_MATCHING
void func_800F6964(u16 arg0) {
    s32 sp3C;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0;
    s32 phi_v0;
    s32 phi_v1;
    s32 phi_s0;
    u8 i;

    sp3C = (((s32) (arg0 * 3) / 2) & 0xFF) << 0x10;
    Audio_SetBGM(sp3C | 0x100000FF);
    Audio_SetBGM((u32) (sp3C | 0x110000FF));
    for(i = 0; i < 0x10; i++){
        if ((0xB != i) && (i != 0xC)) {
            if (i != 0xD) {
                phi_v1 = 0;
            } else {
    block_7:
                phi_v1 = 1;
            }
        } else {
            phi_v1 = 0;
            if (0xA == D_80133414) {
                goto block_7;
            }
        }

        if (phi_v1 == 0) {
            Audio_SetBGM((((arg0 >> 1) & 0xFF) << 0x10) | 0x62000000 | (i << 8));
        }
    }
    Audio_SetBGM((u32) (sp3C | 0x130000FF));
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6964.s")
#endif

void func_800F6AB0(u16 arg0) {
    Audio_SetBGM(((arg0 & 0xFF) << 0x10) | 0x100000FF);
    Audio_SetBGM(((arg0 & 0xFF) << 0x10) | 0x110000FF);
    Audio_SetBGM(((arg0 & 0xFF) << 0x10) | 0x130000FF);
    func_800FA240(0, 3, 0x7F, 0);
    func_800FA240(0, 1, 0x7F, 0);
}

void func_800F6B3C(void) {
    func_800F9280(2, 0, 0xFF, 5);
}

void func_800F6B68(void) {
    Audio_SendMsg_u32(AUDIO_CMD(0x83, 0, 0, 0), 0);
    Audio_SendMsg_u32(AUDIO_CMD(0x83, 1, 0, 0), 0);
    Audio_SendMsg_u32(AUDIO_CMD(0x83, 2, 0, 0), 0);
    Audio_SendMsg_u32(AUDIO_CMD(0x83, 3, 0, 0), 0);
    func_800E5B80();
}

s8 func_800F6BB8(void) {
    return func_800E6680();
}

void func_800F6BDC(void) {
    func_800F6B68();
    func_800E5B80();
    while(true){
        if(!func_800F6BB8()){
            return; 
        }
    }
}

// AudioMgr_PreNMI
void func_800F6C14(void) {
    func_800E6024();
}

void func_800F6C34(void) {
    D_8013061C = 0;
    D_8016B7A8 = 1.0f;
    D_8016B7B0 = 1.0f;
    D_8013063C = 0;
    D_80130640 = 0;
    D_80130644 = 0;
    D_80130648 = 0;
    AudioOcarina_SetInstrument(0);
    D_8016B7B8.unk_0C = 0;
    D_8016B7C8.unk_0C = 0;
    D_8016B7B8.unk_00 = 1.0f;
    D_8016B7C8.unk_00 = 1.0f;
    D_8016B7D8 = 1.0f;
    D_8016B8B0 = 0x7F;
    D_8016B8B1 = 0x7F;
    D_8016B8B2 = 0;
    D_8016B8B3 = 0;
    D_8016B8B4 = 0xFF;
    D_8016B9D8[0] = 0;
    D_80130610 = D_801306C8[D_80133414];
    D_80130608 = 0;
    D_80130628 = 0xFFFF;
    Audio_SendMsg_s8(AUDIO_CMD(0x46, 0, 0, 0), -1);
    D_8013064C = NULL;
    D_8016B9F4 = 0;
    D_8016B9F3 = 1;
    D_8016B9F2 = 0;
}

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[0x64];
} D_801306DC_s;

extern D_801306DC_s D_801306DC[];

void func_800F6D58(u8 arg0, u8 arg1, u8 arg2);
#ifdef NON_MATCHING
void func_800F6D58(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp34;
    u8 temp_a0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    u8 phi_v1;
    s32 phi_a1;
    s32 phi_s1;
    s32 phi_s0;
    u8 i;

    if ((D_8016E750[0].unk_254 != 1) && (func_800FA11C(1U, 0xF00000FFU) != 0)) {
        D_80131F64 = (u8)1U;
        return;
    }

    if (((arg0 << 8) + arg1) == 0x101) {
        if (func_800FA0B4(3) != 0x2F) {
            *D_8016B9D8 = 0;
        }
    }

    temp_a0 = arg0 & 0xF;
    phi_v1 = arg0 >> 4;
    if (phi_v1 == 0) {
        phi_v1 = temp_a0;
    }

    for(i = temp_a0; i <= phi_v1; i++){
        Audio_SetBGM((arg1 << 0x10) | 0x80000000 | (i << 8) | arg2);
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6D58.s")
#endif

void func_800F6E7C(u16 arg0, u16 arg1) {
    u8 i;
    u32 t;

    if (func_800FA0B4(0) == 0x4C) {
        func_800F3F3C(0xF);
        return;
    }
    Audio_SetBGM(0x70000001);
    Audio_SetBGM(0x70040000 | ((arg0 >> 8) & 0xFF));
    Audio_SetBGM(0x70050000 | (arg0 & 0xFF) & 0xFF);
    func_800FA240(0, 0, 0x7F, 1);

    i = 0;
    if (D_80133408 != 0) {
        i = 1;
        Audio_SetBGM(0xE0000100);
    }

    Audio_SetBGM(0x00000001);

    if (i != 0) {
        Audio_SetBGM(0xE0000101);
    }

    for(i = 0; i < 0x10; i ++){
        if (!(arg1 & (1 << i)) && (arg0 & (1 << i))) {
            Audio_SetBGM(0x80010000 | (i << 8) | 1);
        }
    }
}

void func_800F6FB4(u8 arg0) {
    u8 i = 0;
    u8 b0;
    u8 b1;
    u8 b2;

    if ((D_8016E750[0].unk_254 == 0xFFFF) || ((D_80130658[((u8)D_8016E750[0].unk_254) & 0xFFFF] & 0x80) == 0)) {
        func_800F6E7C(D_801306DC[arg0].unk_00, D_801306DC[arg0].unk_02);
        while((D_801306DC[arg0].unk_04[i] != 0xFF) && (i < 0x64)){
            b0 = D_801306DC[arg0].unk_04[i++];
            b1 = D_801306DC[arg0].unk_04[i++];
            b2 = D_801306DC[arg0].unk_04[i++];
            Audio_SetBGM(0x80000000 | (b1 << 0x10) | (b0 << 8) | b2);
        }

        Audio_SetBGM(0x80070D00 | D_80130604);
    }
}

void func_800F70F8(void) {
    func_800E3094(0, 0);
}

void func_800F711C(void) {
    func_800F6C34();
    func_800EE930();
    func_800F3ED4();
    func_800FAEB4();
    func_800F905C();
    func_800F9280(2, 0, 0x70, 0xA);
}

void func_800F7170(void) {
    func_800F9280(2, 0, 0x70, 1);
    Audio_SendMsg_u32(AUDIO_CMD(0xF2, 0, 0, 0), 1);
    func_800E5B80();
    Audio_SendMsg_u32(AUDIO_CMD(0xF8, 0, 0, 0), 0);
}

void func_800F71BC(s32 arg0) {
    D_80133418 = 1;
    func_800F6C34();
    func_800EE930();
    func_800F3ED4();
    func_800FADF8();
    func_800F905C();
}

void func_800F7208(void) {
    func_800FADF8();
    Audio_SendMsg_u32(AUDIO_CMD(0xF2, 0, 0, 0), 1);
    func_800F6C34();
    func_800F3ED4();
    func_800F9280(2, 0, 0x70, 1);
}
