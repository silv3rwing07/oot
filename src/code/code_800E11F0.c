#include <ultra64.h>
#include <global.h>

#define AS_F32(x) (*(f32*)&(x)->unk_04)
#define AS_U8(x) (*(u8*)&(x)->unk_04)
#define AS_S8(x) (*(s8*)&(x)->unk_04)
#define AS_U16(x) (*(u16*)&(x)->unk_04)
#define AS_U32(x) (*(u32*)&(x)->unk_04)
#define AS_S32(x) (*(s32*)&(x)->unk_04)

typedef enum {
    SEQUENCE_TABLE,
    BANK_TABLE,
    AUDIO_TABLE
} AudioTableType;

typedef enum {
    CHAN_UPD_UNK_0,             // 0
    CHAN_UPD_VOL_SCALE,         // 1
    CHAN_UPD_VOL,               // 2
    CHAN_UPD_PAN_SIGNED,        // 3
    CHAN_UPD_FREQ_SCALE,        // 4
    CHAN_UPD_REVERB,            // 5
    CHAN_UPD_SCRIPT_IO,         // 6
    CHAN_UPD_PAN_UNSIGNED,      // 7
    CHAN_UPD_STOP_SOMETHING2,   // 8
    CHAN_UPD_MUTE_BEHAVE,       // 9
    CHAN_UPD_VIBE_X8,           // 10
    CHAN_UPD_VIBE_X32,          // 11
    CHAN_UPD_UNK_0F,            // 12
    CHAN_UPD_UNK_20,            // 13
    CHAN_UPD_REVERB_FLG         // 14
} ChannelUpdateType;

//extern s32 D_8014A6CC;
extern u32 D_8014A6C8;
extern u32 D_8014A6C4;
extern f32 D_80149480;
extern f32 D_80149484;
extern f32 D_80149488;
extern u8 gSequenceTable[];
extern u8 gAudioBankTable[];
extern u8 gAudioTable[];
extern u8 D_80155340[];
extern void(*D_801755D0)(void); // not sure about arguments yet.

void func_800E3FB4(unk_1770_s *arg0, u32 size);
void func_800E4044(u32 devAddr, void* ramAddr, u32 size, s16 arg3);
void *func_800E27F8(s32 tableType);
u32 func_800E2768(u32, u32);
void *func_800E27A4(s32 poolIdx, s32 id);
u32 func_800E2318(u32 arg0, u32 *arg1);
u32 func_800E2338(u32 arg0, u32 *arg1, s32 arg2);
void func_800E6300(SequenceChannel *channel, unk_5C50_s *arg1);
void func_800E59AC(s32 playerIdx, u32 fadeTimer);
void func_800E6818(void);
u32 func_800E5000(void);
void *func_800E2558(u32 arg0, u32 arg1, s32 *arg2);
void func_800E2BCC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800E2AA8(u32 tableOffset, u8* addr, u32 size, u32 arg3);

// like audio_load in sm64, but completely rewritten

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E11F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E12DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1618.s")

s32 Audio_IsBankLoadComplete(s32 bankId) {
    if (bankId == 0xFF) {
        return true;
    } else if (gAudioContext.gBankLoadStatus[bankId] >= 2) {
        return true;
    } else if(gAudioContext.gBankLoadStatus[func_800E2768(1, bankId)] >= 2) {
        return true;
    } else {
        return false;
    }
}

s32 Audio_IsSeqLoadComplete(s32 seqId) {
    if (seqId == 0xFF) {
        return 1;
    } else if (gAudioContext.gSeqLoadStatus[seqId] >= 2) {
        return 1;
    } else if (gAudioContext.gSeqLoadStatus[func_800E2768(0, seqId)] >= 2) {
        return true;
    } else {
        return false;
    }
}

s32 func_800E19A0(s32 arg0) {
    if (arg0 == 0xFF) {
        return true;
    } else if (gAudioContext.gUnusedLoadStatus[arg0] >= 2) {
        return true;
    } else if (gAudioContext.gUnusedLoadStatus[func_800E2768(2, arg0)] >= 2) {
        return true;
    } else {
        return false;
    }
}

void Audio_SetBankLoadStatus(s32 bankId, s32 status) {
    if ((bankId != 0xFF) && (gAudioContext.gBankLoadStatus[bankId] != 5)) {
        gAudioContext.gBankLoadStatus[bankId] = status;
    }
}

void Audio_SetSeqLoadStatus(s32 seqId, s32 status) {
    if ((seqId != 0xFF) && (gAudioContext.gSeqLoadStatus[seqId] != 5)) {
        gAudioContext.gSeqLoadStatus[seqId] = status;
    }
}

void func_800E1A78(s32 arg0, s32 arg1) {
    if (arg0 != 0xFF) {
        if (gAudioContext.gUnusedLoadStatus[arg0] != 5) {
            gAudioContext.gUnusedLoadStatus[arg0] = arg1;
        }

        if ((gAudioContext.gUnusedLoadStatus[arg0] == 5) || (gAudioContext.gUnusedLoadStatus[arg0] == 2)) {
            func_800E0E90(arg0);
        }
    }
}

void func_800E1AD8(s32 arg0, s32 arg1) {
    if ((arg0 != 0xFF) && (gAudioContext.gUnusedLoadStatus[arg0] != 5)) {
        gAudioContext.gUnusedLoadStatus[arg0] = arg1;
    }
}

// InitTable
void func_800E1B08(SequenceTable *seqTable, u32 romAddr, u16 arg2) {
    s32 i;

    seqTable->header.unk_02 = arg2;
    seqTable->header.romAddr = romAddr;

    for(i = 0; i < seqTable->header.entryCnt; i++){
        if((seqTable->entries[i].size != 0) && (seqTable->entries[i].unk_08 == 2)){
            seqTable->entries[i].tableOffset += romAddr;
        }
    }
}

s32 func_800E1B68(s32 arg0, u32 *arg1) {
    char pad[0x8];
    s32 phi_s0;
    u32 sp28;
    s32 phi_s1;
    s32 phi_s2;
    s32 i;

    if (arg0 >= gAudioContext.unk_2840) {
        return 0;
    }
     /**
      * struct at 283C is probably something like 
      * struct {
      *  u16 cnt;
      *  char data[1];
      * }
     */
    phi_s2 = 0xFF;
    phi_s0 = gAudioContext.unk_283C[arg0]; // ofset into unk_283C for cnt?
    phi_s1 = *(phi_s0 + gAudioContext.unk_283Cb);
    phi_s0++;
    while(phi_s1 > 0){
        phi_s2 = *(phi_s0 + gAudioContext.unk_283Cb);
        
        phi_s0++;
        sp28 = func_800E2454(phi_s2);
        phi_s1--;

    }
    *arg1 = phi_s2;
    return sp28;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1C18.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1C78.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1D64.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1E34.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1E6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1EB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1EF4.s")

u8* func_800E1F38(s32 arg0, u32 *arg1) {
    s32 temp_v1;

    temp_v1 = gAudioContext.unk_283C[arg0]; 

    *arg1 = *(temp_v1 + gAudioContext.unk_283Cb);
    temp_v1++;
    if (*arg1 == 0) {
        return NULL;
    }
    return &gAudioContext.unk_283Cb[temp_v1];
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E1F7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E202C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E20D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2124.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E217C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E22C4.s")

u32 func_800E2318(u32 arg0, u32 *arg1) {
    return func_800E2338(arg0, arg1, 1);
}

u32 func_800E2338(u32 arg0, u32 *arg1, s32 arg2) {
    void *temp_v0;
    AudioTable *audioTable;
    u32 temp_s0;
    s8 tmp;

    temp_s0 = func_800E2768(2, arg0);
    audioTable = func_800E27F8(2);
    if (temp_v0 = func_800E27A4(2, temp_s0), temp_v0 != NULL) {
        if (gAudioContext.gUnusedLoadStatus[temp_s0] != 1) {
            func_800E1AD8(temp_s0, 2);
        }
        *arg1 = 0;
        return temp_v0;
    } else if (tmp = audioTable->entries[arg0].unk_09, tmp == 4 || arg2 == 1) {
        *arg1 = audioTable->entries[arg0].unk_08;
        return audioTable->entries[temp_s0].tableOffset;
    } else if (temp_v0 = func_800E2558(2, arg0, &arg2), temp_v0 != NULL) {
        *arg1 = 0;
        return temp_v0;
    } else {
        *arg1 = audioTable->entries[arg0].unk_08;
        return audioTable->entries[temp_s0].tableOffset;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2454.s")

#ifdef NON_MATCHING
void *func_800E2558(u32 tableType, u32 bankId, s32 *arg2) {
    u32 size;
    AudioTable *table;
    s32 sp40;
    u32 tableOffset;
    u32 id;
    s32 sp24;
    void* phi_s0;
    s32 status;
    s32 t;

    id = func_800E2768(tableType, bankId);
    phi_s0 = func_800E27A4(tableType, id);
    if (phi_s0 != NULL) {
        *arg2 = 0;
        status = 2;
    } else {
        table = func_800E27F8(tableType);
        size = ALIGN16(table->entries[id].size);
        sp40 = table->entries[bankId].unk_08;
        sp24 = table->entries[bankId].unk_09;
        tableOffset = table->entries[id].tableOffset;
        switch(sp24){
            case 0:
                phi_s0 = func_800E0540(tableType, id, size);
                if (phi_s0 == 0) {
                    return phi_s0;
                }
                break;
                
            case 1:
                phi_s0 = Audio_AllocBankOrSeq(tableType, size, 1, id);
                if (phi_s0 == 0) {
                    return phi_s0;
                }
                break;
            case 2:
                phi_s0 = Audio_AllocBankOrSeq(tableType, size, 0, id);
                if (phi_s0 == 0) {
                    return phi_s0;
                }
                break;
            case 3:
            case 4:
            default:
                phi_s0 = Audio_AllocBankOrSeq(tableType, size, 2, id);
                if (phi_s0 == 0) {
                    return phi_s0;
                }
                break;

        }

        *arg2 = 1;
        if (sp40 == 1) {
            func_800E2BCC(tableOffset, phi_s0, size, table->header.unk_02);
        } else {
            func_800E2AA8(tableOffset, phi_s0, size, sp40);
        }

        status = sp24 == 0 ? 5 : 2;
    }

    switch(tableType){
        case 0:
            Audio_SetSeqLoadStatus(id, status);
            break;
        case 1:
            Audio_SetBankLoadStatus(id, status);
            break;
        case 2:
            func_800E1A78(id, status);
            break;
        default:
            break;

    }

    return phi_s0;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2558.s")
void *func_800E2558(u32 tableType, u32 bankId, s32 *arg2);
#endif

// returns a bankIdx? 
u32 func_800E2768(u32 poolIdx, u32 bankId) {
    u8 *phi_a1;
    AudioTable *table = func_800E27F8(poolIdx);

    if (table->entries[bankId].size == 0) {
        bankId = (s32)table->entries[bankId].tableOffset;
    }

    return bankId;
}

void *func_800E27A4(s32 poolIdx, s32 id) {
    void *ret;

    ret = func_800E04E8(poolIdx, id);
    if (ret != NULL) {
        return ret;
    }

    ret = func_800DF074(poolIdx, 2, id);
    if (ret != NULL) {
        return ret;
    }

    return NULL;
}

void *func_800E27F8(s32 tableType) {
    void* ret;
    switch(tableType){
        case SEQUENCE_TABLE:
            ret = gAudioContext.sequenceTable;
            break;
        case BANK_TABLE:
            ret = gAudioContext.audioBankTable;
            break;
        default:
            ret =  NULL;
            break;
        case AUDIO_TABLE:
            ret = gAudioContext.audioTable;
            break;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E283C.s")

#ifdef NON_MATCHING
// matching, but data.
void func_800E2AA8(u32 tableOffset, u8* addr, u32 size, u32 direction) {
    OSMesgQueue* msgQueue = &gAudioContext.unk_25E8;
    OSIoMesg* ioMesg = &gAudioContext.unk_2604;
    size = ALIGN16(size);

    func_800E6840(addr, size);

    while(true){
        if(size < 0x400){
            break;
        }
        func_800E2BE0(ioMesg, OS_MESG_PRI_NORMAL, OS_READ, tableOffset, addr, 0x400, msgQueue, direction, "FastCopy");
        osRecvMesg(msgQueue, NULL, OS_MESG_BLOCK);
        size -= 0x400;
        tableOffset += 0x400;
        addr += 0x400;
    }

    if (size != 0) {
        func_800E2BE0(ioMesg, OS_MESG_PRI_NORMAL, OS_READ, tableOffset, addr, size, msgQueue, direction, "FastCopy");
        osRecvMesg(msgQueue, NULL, OS_MESG_BLOCK);
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2AA8.s")
#endif
#undef NON_MATCHING


void func_800E2BCC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

s32 (*D_801304D0)(OSPiHandle* handle, OSIoMesg* mb, s32 direction) = osEPiStartDma;
s32 func_800E2BE0(OSIoMesg *mesg, u32 priority, s32 direction, u32 devAddr, void* ramAddr, u32 size, OSMesgQueue *reqQueue, s32 arg7, char *arg8) {
    OSPiHandle *handle;

    if (gAudioContext.unk_2984 >= 0x11) {
        return -1;
    }

    switch(arg7){
        case 2:
            handle = gAudioContext.cartHandle;
            break;
        case 3:
            handle = gAudioContext.unk_1E1C;
            break;
        default:
            return 0;
    }

    if ((size % 0x10) != 0) {
        size = ALIGN16(size);
    }

    mesg->hdr.pri = priority;
    mesg->hdr.retQueue = reqQueue;
    mesg->dramAddr = ramAddr;
    mesg->devAddr = devAddr;
    mesg->size = size;
    handle->transferInfo.cmdType = 2;
    D_801304D0(handle, mesg, direction);
    return 0;
}

void func_800E2CB8(void) {
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2CC0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2CE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E2FEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E301C.s")

u32 D_801304D4 = 0;
void func_800E3028(u32 arg0) {
    D_801304D4 = arg0;
}

void func_800E3034(s32 arg0) {
    CtlEntry *temp_v0 = &gAudioContext.gCtlEntries[arg0];
    AudioBankTableEntry *temp_v1 = &gAudioContext.audioBankTable->entries[arg0];

    temp_v0->unk_02 = (temp_v1->unk_0A >> 8) & 0xFF;
    temp_v0->unk_03 = (temp_v1->unk_0A) & 0xFF;
    temp_v0->numInstruments = (temp_v1->unk_0C >> 8) & 0xFF;
    temp_v0->numDrums = (temp_v1->unk_0C) & 0xFF;
    temp_v0->numSfx = temp_v1->unk_0E;  
}

u32 D_801304D8 = 0;

#ifdef NON_MATCHING
// AudioContext_Init
void func_800E3094(void *heap, u32 heapSize) {
    static s32 D_8014A6CC = 48352;
    static s32 D_8014A6C8 = 57568;
    s32 sp24;
    s16 temp_v1_2;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_v1;
    s32 temp_v1_3;
    u32 temp_s0_2;
    u32 temp_v0;
    u32 temp_v0_2;
    u8 *temp_t7;
    void *temp_v0_3;
    AudioContext *phi_v0;
    s32 phi_v1;
    u32 phi_v0_2;
    s32 phi_v0_3;
    s32 phi_s0;
    u32 phi_s0_2;
    s32 phi_v1_2;
    s32 phi_s0_3;
    s32 i;
    u64* heapP;
    u8* ctxP;
    s16* u2974p;

    D_801755D0 = 0;
    gAudioContext.unk_2984 = 0;
    ctxP = &gAudioContext;
    for(i = sizeof(gAudioContext); i >= 0; i--){
        *ctxP++ = 0;
    }

    switch(osTvType){
        case 0:
            gAudioContext.unk_2960 = D_80149480;
            gAudioContext.gRefreshRate = 50;
            break;
        case 2:
            gAudioContext.unk_2960 = D_80149484;
            gAudioContext.gRefreshRate = 60;
            break;
        case 1:
        default:
            gAudioContext.unk_2960 = D_80149488;
            gAudioContext.gRefreshRate = 60;
    }

    func_800E6818();

    for(u2974p = &gAudioContext; u2974p < &((s16*)(&gAudioContext))[3]; u2974p++){
        u2974p[0x14BA] = 0xA0;
    }

    gAudioContext.unk_289C = 0;
    gAudioContext.unk_28A4 = NULL;
    gAudioContext.unk_28A8 = 0;
    gAudioContext.gSoundMode = 0;
    gAudioContext.unk_28B8 = 0;
    gAudioContext.unk_28F4 = 0;
    gAudioContext.unk_2944 = 0;
    osCreateMesgQueue(&gAudioContext.unk_25E8, &gAudioContext.unk_2600, 1);
    osCreateMesgQueue(&gAudioContext.unk_1ED0, &gAudioContext.unk_1EE8, 0x40);
    osCreateMesgQueue(&gAudioContext.unk_1E20, &gAudioContext.unk_1E38, 0x10);
    osCreateMesgQueue(&gAudioContext.unk_1E78, &gAudioContext.unk_1E90, 0x10);
    gAudioContext.unk_28A0 = NULL;
    gAudioContext.gSampleDmaNumListItems = 0;
    gAudioContext.cartHandle = osCartRomInit();

    if (heap == NULL) {
        gAudioContext.gAudioHeap = gAudioHeap;
        gAudioContext.gAudioHeapSize = D_8014A6C4;
    } else {
        void** hp = &heap;
        gAudioContext.gAudioHeap = *hp;
        gAudioContext.gAudioHeapSize = heapSize;
    }


    for(i = 0; i < (s32)gAudioContext.gAudioHeapSize / 8; i++) {
        ((u64*)gAudioContext.gAudioHeap)[i] = 0;
    }

    Audio_InitMainPools(D_8014A6C8);

    for(i = 0; i < 3; i++){
        gAudioContext.unk_2968[i] = Audio_AllocZeroed(&gAudioContext.gAudioInitPool, 0xB00);
    }
    
    gAudioContext.sequenceTable = &gSequenceTable;
    gAudioContext.audioBankTable = &gAudioBankTable;
    gAudioContext.audioTable = &gAudioTable;
    gAudioContext.unk_283C = &D_80155340;
    gAudioContext.unk_2840 = gAudioContext.sequenceTable->entries;

    gAudioContext.gAudioResetPresetIdToLoad = 0;
    gAudioContext.gAudioResetStatus = 1;
    
    Audio_ResetStep();
    func_800E1B08(gAudioContext.sequenceTable, _AudioseqSegmentRomStart, 0);
    func_800E1B08(gAudioContext.audioBankTable, _AudiobankSegmentRomStart, 0);
    func_800E1B08(gAudioContext.audioTable, _AudiotableSegmentRomStart, 0);
    sp24 = gAudioContext.audioBankTable->entries;
    gAudioContext.gCtlEntries = Audio_Alloc(&gAudioContext.gAudioInitPool, sp24 * sizeof(CtlEntry));

    for(i = 0; i < sp24; i++){
        func_800E3034(i);
    }

    if (temp_v0_3 = Audio_Alloc(&gAudioContext.gAudioInitPool, D_8014A6CC), temp_v0_3 == NULL)
    {
        D_8014A6CC = 0;
    }

    Audio_SoundAllocPoolInit(&gAudioContext.unk_2D50, temp_v0_3, D_8014A6CC);
    D_801304D8 = 1;
    osSendMesg(gAudioContext.unk_5BE8, (void*)gAudioContext.unk_289C, 0);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3094.s")
void func_800E3094(void *heap, u32 heapSize);
#endif

void func_800E3400(void) {
    gAudioContext.unk_1D64 = 0;
    gAudioContext.unk_1DC8 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3414.s")

AudioBankSample *func_800E35E0(s32 bankId, s32 sfxId) {    
    AudioBankSample *ret;

    if (sfxId < 0x80) {
        Instrument *instrument = Audio_GetInstrumentInner(bankId, sfxId);
        if (instrument == NULL) {
            return NULL;
        }
        ret = instrument->normalNotesSound.sample;
    } else if (sfxId < 0x100) {
        Drum *drum = Audio_GetDrum(bankId, sfxId - 0x80);
        if (drum == NULL) {
            return NULL;
        }
        ret = drum->sound.sample;
    } else {
        AudioBankSound *bankSound = Audio_GetSfx(bankId, sfxId - 0x100);
        if (bankSound == NULL) {
            return NULL;
        }
        ret = bankSound->sample;
    }
    return ret;
}

void func_800E3670(void) {
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3678.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E36EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3874.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E38F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E390C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3A14.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3A44.s")

unk_1770_s *func_800E3AC8(s32 devAddr, void* ramAddr, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    unk_1770_s *phi_v1;
    s32 i;

    for(i = 0; i < 0x10; i++){
        if(gAudioContext.unk_1770[i].unk_00 == 0){
            phi_v1 = &gAudioContext.unk_1770[i];
            break;
        }
    }

    if (i == 0x10) {
        return NULL;
    }
    
    phi_v1->unk_00 = 1;
    phi_v1->devAddr = devAddr;
    phi_v1->unk_04 = ramAddr;
    phi_v1->ramAddr = ramAddr;
    phi_v1->unk_10 = arg2;

    if (arg4 == 0) {
        phi_v1->unk_14 = 0x1000;
    } else if (arg4 == 1) {
        phi_v1->unk_14 = arg2;
    } else {
        phi_v1->unk_14 = ((arg2 / arg4) + 0xFF) & ~0xFF;
        if (phi_v1->unk_14 < 0x100) {
            phi_v1->unk_14 = 0x100;
        }
    }

    phi_v1->unk_20 = arg5;
    phi_v1->unk_01 = 3;
    phi_v1->unk_02 = arg3;
    phi_v1->unk_1C = arg6;
    osCreateMesgQueue(&phi_v1->msgQueue, &phi_v1->msg, 1);
    return phi_v1;
}

#ifdef NON_MATCHING
void func_800E3BEC(s32 arg0) {
    u32 sp34;
    AudioContext *audCtx = &gAudioContext;
    s32 i;

    if (audCtx->unk_2984 != 1) {
        if (audCtx->unk_2984 == 0) {
            if (arg0 != 0) {
                while((osRecvMesg(&audCtx->unk_queue_1CF0, &sp34, 0) != -1));
            } else if (osRecvMesg(&audCtx->unk_queue_1CF0, &sp34, 0) == -1) {
                audCtx->unk_1D48 = 0;
            } else {
                audCtx->unk_1D48 = sp34;
            }
        }

        if (audCtx->unk_1D48 != 0) {
            func_800E3D10(audCtx->unk_1D48, arg0);
        }

        for(i = 0; i < ARRAY_COUNT(audCtx->unk_1770); i++){
            if (audCtx->unk_1770[i].unk_00 == 1) {
                if (audCtx->unk_1770[i].unk_02 != 1) {
                    func_800E3E58(&audCtx->unk_1770[i], arg0);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3BEC.s")
#endif

void func_800E3D10(u32 arg0, s32 arg1) {
}


#ifdef NON_MATCHING
void func_800E3D1C(unk_1770_s *arg0) {
    u32 sp5C;
    s32 sp48;
    u32 sp44;
    u32 sp40;
    u8 *sp3C;
    u8 *sp38;
    s32 sp34;
    s32 sp30;
    s32 sp28;
    CtlEntry *temp_v0_2;
    s32 temp_t7;
    u32 temp_a1;
    u32 temp_v0;
    u8 temp_a0;
    u8 temp_a2;
    void *phi_a1;

    temp_a1 = arg0->unk_1C;
    switch((arg0->unk_1C >> 0x10) & 0xFF){
        case 0:
            Audio_SetSeqLoadStatus((arg0->unk_1C >> 8) & 0xFF, arg0->unk_1C & 0xFF);
            break;
        case 2:
            func_800E1A78((arg0->unk_1C >> 8) & 0xFF, arg0->unk_1C & 0xFF);
            break;
        case 1:
            temp_v0_2 = &gAudioContext.gCtlEntries[(temp_a1 >> 8) & 0xFF];
            temp_a0 = temp_v0_2->unk_02;
            temp_a2 = temp_v0_2->unk_03;
            sp30 = temp_a0;
            sp34 = temp_a2;
            if (sp30 != 0xFF) {
                sp38 = func_800E2318(sp30, &sp40);
            } else {
                sp38 = NULL;
            }

            if (sp34 != 0xFF) {
                sp3C = func_800E2318(sp34, &sp44);
            } else {
                sp3C = NULL;
            }
            Audio_SetBankLoadStatus((temp_a1 >> 8) & 0xFF, arg0->unk_1C & 0xFF);
            func_800E4198((temp_a1 >> 8) & 0xFF, arg0->unk_04, &sp30, 1);
            break;
        default:
            break;

    }

    arg0->unk_00 = 0;
    osSendMesg(arg0->unk_20, arg0->unk_1C, 0);
}
#else
void func_800E3D1C(unk_1770_s* arg0);
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E3D1C.s")
#endif

void func_800E3E58(unk_1770_s *arg0, s32 arg1) {
    AudioTable *audioTable = gAudioContext.audioTable;
    if (arg0->unk_01 >= 2) {
        arg0->unk_01--;
        return;
    }

    if (arg0->unk_01 == 1) {
        arg0->unk_01 = 0;
    } else if (arg1 != 0) {
        osRecvMesg(&arg0->msgQueue, NULL, 1);
        arg0->unk_00 = 0;
        return;
    } else if (osRecvMesg(&arg0->msgQueue, NULL, 0) == -1) {
        return;
    }

    if (arg0->unk_10 == 0) {
        func_800E3D1C(arg0);
        return;
    }

    if (arg0->unk_10 < arg0->unk_14) {
        if (arg0->unk_02 == 1) {
            func_800E4044(arg0->devAddr, arg0->ramAddr, arg0->unk_10, audioTable->header.unk_02);
        } else {
            func_800E3FB4(arg0, arg0->unk_10);
        }
        arg0->unk_10 = 0;
        return;
    }

    if (arg0->unk_02 == 1) {
        func_800E4044(arg0->devAddr, arg0->ramAddr, arg0->unk_14, audioTable->header.unk_02);
    } else {
        func_800E3FB4(arg0, arg0->unk_14);
    }

    arg0->unk_10 -= arg0->unk_14;
    arg0->devAddr += arg0->unk_14;
    arg0->ramAddr = (void *) ((u32)arg0->ramAddr + arg0->unk_14);
}

extern char D_80149450[];
void func_800E3FB4(unk_1770_s *arg0, u32 size) {
    size = ALIGN16(size);
    func_800E6840(arg0->ramAddr, size); // invalDCache
    osCreateMesgQueue(&arg0->msgQueue, &arg0->msg, 1);
    func_800E2BE0(&arg0->ioMesg, 0, 0, arg0->devAddr, arg0->ramAddr, size, &arg0->msgQueue, arg0->unk_02, D_80149450);
}

void func_800E4044(u32 devAddr, void* ramAddr, u32 size, s16 arg3) {
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4058.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4198.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4590.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4744.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E478C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E48C0.s")

// large
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4918.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4D94.s")

void func_800E4ED4(void) {
}

void func_800E4EDC(void) {
}

void func_800E4EE4(void) {
}

u32 D_801304DC = 0;
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E4EEC.s")

extern u8* D_8016B738[];
extern OSMesgQueue D_8016B6E0;
extern OSMesg D_8016B6F8;
void func_800E4F58(void) {
    u32 pad;
    u32 sp20;
    u8 *temp_v0;

    if (osRecvMesg(&D_8016B6E0, &sp20, OS_MESG_NOBLOCK) != -1) {
        pad = sp20 >> 0x18;
        temp_v0 = D_8016B738[pad];
        if (temp_v0 != NULL) {
            *temp_v0 = 0;
        }
    }
}

void func_800E4FB0(void) {
    osCreateMesgQueue(&D_8016B6E0, &D_8016B6F8, 0x10);
}

void func_800E4FE0(void) {
    func_800E5000();
}

u32 D_801304E0 = 0x80;
u32 D_801304E4 = 0;
//large
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5000.s")

void func_800E1C18(u8 channelIdx,u8 scriptIOIdx);
void func_800E20D4(u8 playerIdx, u8, u8);
void func_800E2124(u8,u8, void*);
void func_800E5958(s32 arg0, u32 arg1);
void func_800E1D64(u8,u8,u8);
void func_800E1EB0(u8,u8,u8,OSMesgQueue*);
void func_800E1EB0(u8,u8,u8,OSMesgQueue*);
void func_800E1E6C(u8,u8,u8,OSMesgQueue*);
void func_800E1F7C(u8);

#ifdef NON_MATCHING
// matches, but data.
void func_800E5584(unk_5C50_s *arg0) {
    s32 i;
    s32 pad;
    s32 pad2;
    u32 temp_a1_5;
    u32 temp_t7;

    switch(arg0->bytes.b0){
        case 0x81:
            func_800E1C18(arg0->bytes.b2, arg0->bytes.b3);
            return;
        case 0x82:
            func_800E20D4(arg0->bytes.b1, arg0->bytes.b2, arg0->bytes.b3);
            func_800E59AC(arg0->bytes.b1, arg0->unk_04);
            return;
        case 0x85:
            func_800E2124(arg0->bytes.b1, arg0->bytes.b2, arg0->unk_04);
            return;

        case 0x83:
            if (gAudioContext.gSequencePlayers[arg0->bytes.b1].enabled) {
                temp_a1_5 = arg0->unk_04;
                if (temp_a1_5 == 0) {
                    Audio_SequencePlayerDisableAsFinished(&gAudioContext.gSequencePlayers[arg0->bytes.b1]);
                } else {
                    func_800E5958(arg0->bytes.b1, temp_a1_5);
                }
            }
            return;

        case 0xF0:
            gAudioContext.gSoundMode = AS_U32(arg0);
            return;

        case 0xF1:
            for(i = 0; i < gAudioContext.gAudioBufferParameters.numSequencePlayers; i++){
                SequencePlayer* seqPlayer = &gAudioContext.gSequencePlayers[i];
                seqPlayer->muted = 1;
                seqPlayer->recalculateVolume = 1;
            }
            return;

        case 0xF2:
            if (AS_U32(arg0) == 1) {
                for(i = 0; i < gAudioContext.gMaxSimultaneousNotes; i++){
                    Note* note = &gAudioContext.gNotes[i];
                    NoteSubEu *subEu = &note->noteSubEu.bitField0;
                    if (subEu->bitField0.s.enabled && note->playbackState.unk_04 == 0) {                        
                        if (note->playbackState.parentLayer->seqChannel->muteBehavior & 8) {
                            subEu->bitField0.s.finished = 1;
                        }
                    }
                }
            }

            for(i = 0; i < gAudioContext.gAudioBufferParameters.numSequencePlayers; i++){
                SequencePlayer* seqPlayer = &gAudioContext.gSequencePlayers[i];
                seqPlayer->muted = 0;
                seqPlayer->recalculateVolume = 1;
            }

            return;
        case 0xF3:
            func_800E1D64(arg0->bytes.b1, arg0->bytes.b2, arg0->bytes.b3);
            return;
        case 0xF4:
            func_800E1EB0(arg0->bytes.b1, arg0->bytes.b2, arg0->bytes.b3, &gAudioContext.unk_1E20);
            return;
        case 0xF5:
            func_800E1EF4(arg0->bytes.b1, arg0->bytes.b2, arg0->bytes.b3, &gAudioContext.unk_1E20);
            return;
        case 0xFC:
            func_800E1E6C(arg0->bytes.b1, arg0->bytes.b2, arg0->bytes.b3, &gAudioContext.unk_1E20);
            return;
        case 0xF6:
            func_800E1F7C(arg0->bytes.b2);
            return;
        case 0x90:
            gAudioContext.unk_5BDC[arg0->bytes.b1] =  AS_U16(arg0);
            return;
        case 0xF9:
            gAudioContext.gAudioResetStatus = 5;
            gAudioContext.gAudioResetPresetIdToLoad = AS_U32(arg0);
            return;
        case 0xFB:
            D_801755D0 = AS_U32(arg0);
            return;

        case 0xE0:
        case 0xE1:
        case 0xE2:
            func_800E7744(arg0->bytes.b0 - 0xE0, arg0->bytes.b1, arg0->bytes.b2, arg0->unk_04);
            return;

        case 0xFE:
            temp_t7 = AS_U32(arg0);
            if (temp_t7 == 1) {
                for(i = 0; i < gAudioContext.gAudioBufferParameters.numSequencePlayers; i++){
                    SequencePlayer* seqPlayer = &gAudioContext.gSequencePlayers[i];
                    if(seqPlayer->enabled){
                        Audio_SequencePlayerDisableAsFinished(seqPlayer);
                    }
                }
            }
            func_800E66C0(temp_t7);
            return;
        case 0xE3:
            func_800DE4B0(AS_S32(arg0));
            return;
        default:
            return;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5584.s")
void func_800E5584(unk_5C50_s *arg0);
#endif

#ifdef NON_MATCHING
void func_800E5958(s32 arg0, u32 arg1) {
    SequencePlayer* seqPlayer;
    s32 temp_t7;
    void *temp_v0;
    s16 phi_a1;
    f32 a1;

    if (arg1 == 0) {
        arg1 = 1;
    }
    seqPlayer = &gAudioContext.gSequencePlayers[arg0];
    seqPlayer->state = 2;
    seqPlayer->fadeTimer = arg1;
    seqPlayer->fadeVelocity = -(seqPlayer->fadeVolume / seqPlayer->fadeTimer);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5958.s")
#endif

void func_800E59AC(s32 playerIdx, u32 fadeTimer) {
    SequencePlayer* seqPlayer;
    if (fadeTimer != 0) {
        seqPlayer = &gAudioContext.gSequencePlayers[playerIdx];
        seqPlayer->state = 1;
        seqPlayer->fadeTimerUnkEu = fadeTimer;
        seqPlayer->fadeTimer = fadeTimer;
        seqPlayer->fadeVolume = 0.0f;
        seqPlayer->fadeVelocity = 0.0f;
    }
}

extern OSMesgQueue D_80174D70;
extern OSMesgQueue D_80174D88;
extern OSMesgQueue D_80174DA0;
extern OSMesg D_80174DB8;
extern OSMesg D_80174DC0;
extern OSMesg D_80174DBC;
#ifdef NON_MATCHING
// init msgqueues
void func_800E59F4(void) {
    gAudioContext.unk_5BD8 = 0;
    gAudioContext.unk_5BD9 = 0;
    gAudioContext.unk_5BDA = 0;
    gAudioContext.unk_5BE8 = &D_80174D70;
    gAudioContext.unk_5BEC = &D_80174D88;
    gAudioContext.unk_5BE4 = &D_80174DA0;
    osCreateMesgQueue(gAudioContext.unk_5BE8, &D_80174DB8, 1);
    osCreateMesgQueue(gAudioContext.unk_5BEC, &D_80174DC0, 4);
    osCreateMesgQueue(gAudioContext.unk_5BE4, &D_80174DBC, 1);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E59F4.s")
#endif

#ifdef NON_MATCHING
void func_800E5A8C(u32 arg0, void **arg1) {
    unk_5C50_s *t = &gAudioContext.unk_5C50[gAudioContext.unk_5BD8];

    t->unk_00 = arg0;
    t->unk_04 = *arg1;

    gAudioContext.unk_5BD8++;

    if (gAudioContext.unk_5BD8 == gAudioContext.unk_5BD9) {
        gAudioContext.unk_5BD8--;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5A8C.s")
#endif

void func_800E5AD8(u32 arg0, f32 arg1) {
    func_800E5A8C(arg0, &arg1);
}

void func_800E5AFC(u32 arg0, u32 arg1) {
    func_800E5A8C(arg0, &arg1);
}

void func_800E5B20(u32 arg0, s8 arg1) {
    u32 sp1C;

    sp1C = arg1 << 0x18;
    func_800E5A8C(arg0, &sp1C);
}

void func_800E5B50(u32 arg0, u16 arg1) {
    u32 sp1C = arg1 << 0x10;
    func_800E5A8C(arg0, &sp1C);
}

u32 D_801304E8 = 0;
#ifdef NON_MATCHING
s32 func_800E5B80(void) {
    u8 temp_a0;
    u8 temp_a3;
    u8 temp_v0;

    temp_v0 = gAudioContext.unk_5BD8;
    temp_a3 = gAudioContext.unk_5BD9;
    temp_a0 = ((temp_v0 - temp_a3) + 0x100);
    if (D_801304E8 < temp_a0) {
        D_801304E8 = temp_a0;
    }

    if (osSendMesg(gAudioContext.unk_5BEC, (void*)(((temp_a3 & 0xFF) << 8) | (temp_v0 & 0xFF)), OS_MESG_NOBLOCK) != -1) {
        gAudioContext.unk_5BD9 = gAudioContext.unk_5BD8;
        return 0;
    } else {
        return -1;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5B80.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5C10.s")

void func_800E5C28(unk_5C50_s *arg01) {
    unk_5c50_b* arg0 = arg01;
    SequencePlayer *seqPlayer;
    u16 phi_v0;
    s32 i;

    if ((arg0->b0 & 0xF0) == 0xF0) {
        func_800E5584(arg0);
        return;
    }

    if (arg0->b1 < gAudioContext.gAudioBufferParameters.numSequencePlayers) {
        seqPlayer = &gAudioContext.gSequencePlayers[arg0->b1];
        if ((arg0->b0 & 0x80) != 0) {
            func_800E5584(arg0);
            return;
        }
        if ((arg0->b0 & 0x40) != 0) {
            func_800E6128(seqPlayer, arg0);
            return;
        }

        if (arg0->b2 < 0x10) {
            func_800E6300(seqPlayer->channels[arg0->b2], arg0);
            return;
        }
        if (arg0->b2 == 0xFF) {
            phi_v0 = gAudioContext.unk_5BDC[arg0->b1];
            for(i = 0; i < 0x10; i++){
                if(phi_v0 & 1){
                    func_800E6300(seqPlayer->channels[i], arg0);
                }
                phi_v0 = phi_v0 >> 1;
            }
        }
    }
}

void func_800E5D6C(u32 arg0) {
    static u8 D_801304EC = 0;
    unk_5c50_b* s;
    u8 tmp;

    if (gAudioContext.unk_5BDA == 0) {
        D_801304EC = arg0 >> 8;
    }


    while(true){
        tmp = arg0 & 0xFF;
        if(D_801304EC == tmp){
            gAudioContext.unk_5BDA = 0;
            return;
        }

        s = &gAudioContext.unk_5C50[D_801304EC++ & 0xFF].bytes;
        if (s->b0 == 0xF8) {
            gAudioContext.unk_5BDA = 1;
            return;
        }

        func_800E5C28(s);
        s->b0 = 0;

    }
}

u32 func_800E5E20(u32 *arg0) {
    u32 sp1C;

    if (osRecvMesg(&gAudioContext.unk_1E20, &sp1C, 0) == -1) {
        *arg0 = 0;
        return 0;
    }
    *arg0 = sp1C & 0xFFFFFF;
    return sp1C >> 0x18;
}

void func_800E5E84(s32 arg0, u32 *arg1) {
    func_800E1F38(arg0, arg1);
}

void func_800E5EA4(s32 arg0, u32 *arg1, u32 *arg2) {
    *arg1 = gAudioContext.gCtlEntries[arg0].unk_02;
    *arg2 = gAudioContext.gCtlEntries[arg0].unk_03;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5EDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5F34.s")

#ifdef NON_MATCHING
s32 func_800E5F88(u32 arg0) {
    s32 sp24;
    u32 sp20;
    u8 temp_v0;

    func_800E5F34();
    temp_v0 = gAudioContext.gAudioResetStatus;
    if (temp_v0 != 0) {
        func_800E5C10();
        if (arg0 == gAudioContext.gAudioResetPresetIdToLoad) {
            return -2;
        }
        if (temp_v0 >= 3) {
            gAudioContext.gAudioResetPresetIdToLoad = arg0;
            return -3;
        }
        osRecvMesg(gAudioContext.unk_5BE4, &sp20, 1);
    }
    func_800E5F34();
    func_800E5AFC(0xF9000000U, arg0);
    return func_800E5B80();
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E5F88.s")
s32 func_800E5F88(u32 arg0);
#endif

#ifdef NON_MATCHING
extern u32 D_801304D8;
void func_800E6024(void) {
    gAudioContext.unk_2984 = 1;
    if (D_801304D8 != 0) {
        func_800E5F88(0);
        gAudioContext.gAudioResetStatus = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E6024.s")
#endif

s8 func_800E6070(s32 playerIdx, s32 channelIdx, s32 scriptIdx) {
    SequencePlayer* seqPlayer = &gAudioContext.gSequencePlayers[playerIdx];
    SequenceChannel* channel;
    if (seqPlayer->enabled) {
        channel = seqPlayer->channels[channelIdx];
        return channel->soundScriptIO[scriptIdx];
    } else {
        return -1;
    }
}

s8 func_800E60C4(s32 arg0, s32 arg1) {
    return gAudioContext.gSequencePlayers[arg0].unk_158[arg1];
}

void func_800E60EC(void *memAddr, u32 size) {
    Audio_SoundAllocPoolInit(&gAudioContext.gUnkPool, memAddr, size);
}

void func_800E611C(void) {
    gAudioContext.gUnkPool.start = NULL;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E6128.s")

#ifdef NON_MATCHING
// matching, but data
void func_800E6300(SequenceChannel *channel, unk_5C50_s *arg1) {
    f32 floatData;
    s8 s8Data;

    switch(arg1->bytes.b0){
        case CHAN_UPD_VOL_SCALE:
            floatData = AS_F32(arg1);
            if (floatData != channel->volumeScale) {
                channel->volumeScale = floatData;
                channel->changes.s.volume = 1;
            }
            return;
        case CHAN_UPD_VOL:
            floatData = AS_F32(arg1);
            if (floatData != channel->volume) {
                channel->volume = floatData;
                channel->changes.s.volume = 1;
            }
            return;
        case CHAN_UPD_PAN_SIGNED:
            s8Data = AS_S8(arg1);
            if (s8Data != channel->newPan) {
                channel->newPan = s8Data;
                channel->changes.s.pan = 1;
            }
            return;
        case CHAN_UPD_PAN_UNSIGNED:
            s8Data = AS_U8(arg1);
            if (s8Data != channel->newPan) {
                channel->panChannelWeight = s8Data;
                channel->changes.s.pan = 1;
            }
            return;
        case CHAN_UPD_FREQ_SCALE:
            floatData = AS_F32(arg1);
            if (floatData != channel->freqScale) {
                channel->freqScale = floatData;
                channel->changes.s.freqScale = 1;
            }
            return;
        case CHAN_UPD_REVERB:
            s8Data = AS_S8(arg1);
            if (s8Data != channel->reverb) {
                channel->reverb = s8Data;
            }
            return;
        case CHAN_UPD_SCRIPT_IO:
            if (arg1->bytes.b3 < 8) {
                channel->soundScriptIO[arg1->bytes.b3] = AS_S8(arg1);
            }
            return;
        case CHAN_UPD_STOP_SOMETHING2:
            channel->stopSomething2 = AS_S8(arg1);
            return;
        case CHAN_UPD_MUTE_BEHAVE:
            channel->muteBehavior = AS_S8(arg1);
            return;
        case CHAN_UPD_VIBE_X8:
            channel->vibratoExtentTarget = AS_U8(arg1) * 8;
            channel->vibratoExtentChangeDelay = 1;
            return;
        case CHAN_UPD_VIBE_X32:
            channel->vibratoRateTarget = AS_U8(arg1) * 32;
            channel->vibratoRateChangeDelay = 1;
            return;
        case CHAN_UPD_UNK_0F:
            channel->unk_0F = AS_U8(arg1);
            return;
        case CHAN_UPD_UNK_20:
            channel->unk_20 = AS_U16(arg1);
            return;
        case CHAN_UPD_REVERB_FLG:
            channel->reverbBits.asByte = AS_U8(arg1);
            return;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E6300.s")
void func_800E6300(SequenceChannel *channel, unk_5C50_s *arg1);
#endif

void func_800E64B0(s32 arg0, s32 arg1, s32 arg2) {
    func_800E5AFC(((arg0 & 0xFF) << 0x10) | 0xFA000000 | ((arg1 & 0xFF) << 8) | (arg2 & 0xFF), 1);
}

void func_800E64F8(void) {
    func_800E5AFC(0xFA000000, 0);
}

void func_800E651C(u32 arg0, s32 arg1) {
    func_800E5AFC((arg1 & 0xFF) | 0xFD000000, arg0);
}

extern OSMesgQueue* D_80174D68;
void func_800E6550(void) {
    osRecvMesg(D_80174D68, NULL, OS_MESG_NOBLOCK);
    osRecvMesg(D_80174D68, NULL, OS_MESG_BLOCK);
}

#ifdef NON_MATCHING
s32 func_800E6590(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_v1_2;
    AudioBankSound *temp_a0;
    Note *temp_a0_2;
    SequenceChannelLayer *temp_v0;
    SequenceChannel *temp_v1;
    SequencePlayer *seqPlayer;

    seqPlayer = &gAudioContext.gSequencePlayers[arg0];
    if (seqPlayer->enabled) {
        temp_v1 = seqPlayer->channels[arg1];
        if (temp_v1->enabled) {
            temp_v0 = temp_v1->layers[arg2];
            if (temp_v0 == NULL) {
                return 0;
            }

            if (temp_v0->enabled) {
                temp_a0_2 = temp_v0->note;
                if (temp_a0_2 == NULL) {
                    return 0;
                }

                if (!temp_v0->bit3) {
                    return 0;
                }

                if (temp_v0 == temp_a0_2->playbackState.parentLayer) {
                    temp_a0 = temp_a0_2->noteSubEu.sound.audioBankSound;
                    if (temp_a0 == 0) {
                        return 0;
                    }
                    return temp_a0->sample->loop->end - temp_a0_2->synthesisState.samplePosInt;
                }
                return 0;
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E6590.s")
#endif

void func_800E6680(void) {
    func_800E66C0(0);
}

void func_800E66A0(void) {
    func_800E66C0(2);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800E11F0/func_800E66C0.s")

u32 Audio_RandUInt(void) {
    static u32 audRand = 0x12345678;

    audRand = ((osGetCount() + 0x1234567) * (audRand + gAudioContext.unk_289C));
    audRand += gAudioContext.gAudioRandom;
    return audRand;
}

void func_800E6818(void) {
    func_800E59F4();
}
