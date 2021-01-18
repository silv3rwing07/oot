#include "ultra64.h"
#include "global.h"
#include "vt.h"

// external segments
extern Gfx D_08089BF8[];
extern Gfx D_08089C48[];
extern u8 D_0C000000[];
extern u8 D_0C000800[];
extern u8 D_0C001000[];
extern u8 D_0C001800[];

// .data
s16 D_8082A6E0[] = {
    100, 255, 0, 0, 0, 0, 0, 0,
};

UNK_PTR D_8082A6F0[] = {
    0x0D008680, 0x080613C0, 0x0806A9C0, 0x08073FC0, 0x0807D5C0, 0x0D009080, 0x08061DC0, 0x0806B3C0,
    0x080749C0, 0x0807DFC0, 0x0D009A80, 0x080627C0, 0x0806BDC0, 0x080753C0, 0x0807E9C0,
};

UNK_PTR D_8082A72C[] = {
    0x0D00A480, 0x080631C0, 0x0806C7C0, 0x08075DC0, 0x0807F3C0, 0x0D00AE80, 0x08063BC0, 0x0806D1C0,
    0x080767C0, 0x0807FDC0, 0x0D00B880, 0x080645C0, 0x0806DBC0, 0x080771C0, 0x080807C0,
};

UNK_PTR D_8082A768[] = {
    0x0805D7C0, 0x08064FC0, 0x0806E5C0, 0x08077BC0, 0x080811C0, 0x0D00C280, 0x080659C0, 0x0806EFC0,
    0x080785C0, 0x08081BC0, 0x0805E1C0, 0x080663C0, 0x0806F9C0, 0x08078FC0, 0x080825C0,
};

UNK_PTR D_8082A7A4[] = {
    0x0805EBC0, 0x08066DC0, 0x080703C0, 0x080799C0, 0x08082FC0, 0x0D00CC80, 0x080677C0, 0x08070DC0,
    0x0807A3C0, 0x080839C0, 0x0805F5C0, 0x080681C0, 0x080717C0, 0x0807ADC0, 0x080843C0,
};

UNK_PTR D_8082A7E0[] = {
    0x0D00D680, 0x08068BC0, 0x080721C0, 0x0807B7C0, 0x08084DC0, 0x0D00E080, 0x080695C0, 0x08072BC0,
    0x0807C1C0, 0x080857C0, 0x0D00EA80, 0x08069FC0, 0x080735C0, 0x0807CBC0, 0x080861C0,
};

UNK_PTR D_8082A81C[] = {
    0x0D008780, 0x080613C0, 0x0806A9C0, 0x08073FC0, 0x0807D5C0, 0x0D009180, 0x08061DC0, 0x0806B3C0,
    0x080749C0, 0x0807DFC0, 0x0D009B80, 0x080627C0, 0x0806BDC0, 0x080753C0, 0x0807E9C0,
};

UNK_PTR D_8082A858[] = {
    0x0D00A580, 0x080631C0, 0x0806C7C0, 0x08075DC0, 0x0807F3C0, 0x0D00AF80, 0x08063BC0, 0x0806D1C0,
    0x080767C0, 0x0807FDC0, 0x0D00B980, 0x080645C0, 0x0806DBC0, 0x080771C0, 0x080807C0,
};

UNK_PTR D_8082A894[] = {
    0x0805D7C0, 0x08064FC0, 0x0806E5C0, 0x08077BC0, 0x080811C0, 0x0D00C380, 0x080659C0, 0x0806EFC0,
    0x080785C0, 0x08081BC0, 0x0805E1C0, 0x080663C0, 0x0806F9C0, 0x08078FC0, 0x080825C0,
};

UNK_PTR D_8082A8D0[] = {
    0x0805EBC0, 0x08066DC0, 0x080703C0, 0x080799C0, 0x08082FC0, 0x0D00CD80, 0x080677C0, 0x08070DC0,
    0x0807A3C0, 0x080839C0, 0x0805F5C0, 0x080681C0, 0x080717C0, 0x0807ADC0, 0x080843C0,
};

UNK_PTR D_8082A90C[] = {
    0x0805FFC0, 0x08068BC0, 0x080721C0, 0x0807B7C0, 0x08084DC0, 0x0D00D780, 0x080695C0, 0x08072BC0,
    0x0807C1C0, 0x080857C0, 0x0D00E180, 0x08069FC0, 0x080735C0, 0x0807CBC0, 0x080861C0,
};

UNK_PTR D_8082A948[] = {
    0x0805C3C0, 0x080613C0, 0x0806A9C0, 0x08073FC0, 0x0807D5C0, 0x0D008280, 0x08061DC0, 0x0806B3C0,
    0x080749C0, 0x0807DFC0, 0x0805CDC0, 0x080627C0, 0x0806BDC0, 0x080753C0, 0x0807E9C0,
};

UNK_PTR D_8082A984[] = {
    0x0D008C80, 0x080631C0, 0x0806C7C0, 0x08075DC0, 0x0807F3C0, 0x0D009680, 0x08063BC0, 0x0806D1C0,
    0x080767C0, 0x0807FDC0, 0x0D00A080, 0x080645C0, 0x0806DBC0, 0x080771C0, 0x080807C0,
};

UNK_PTR D_8082A9C0[] = {
    0x0805D7C0, 0x08064FC0, 0x0806E5C0, 0x08077BC0, 0x080811C0, 0x0D00AA80, 0x080659C0, 0x0806EFC0,
    0x080785C0, 0x08081BC0, 0x0805E1C0, 0x080663C0, 0x0806F9C0, 0x08078FC0, 0x080825C0,
};

UNK_PTR D_8082A9FC[] = {
    0x0D00B480, 0x08066DC0, 0x080703C0, 0x080799C0, 0x08082FC0, 0x0D00BE80, 0x080677C0, 0x08070DC0,
    0x0807A3C0, 0x080839C0, 0x0D00C880, 0x080681C0, 0x080717C0, 0x0807ADC0, 0x080843C0,
};

UNK_PTR D_8082AA38[] = {
    0x0805FFC0, 0x08068BC0, 0x080721C0, 0x0807B7C0, 0x08084DC0, 0x0D00D280, 0x080695C0, 0x08072BC0,
    0x0807C1C0, 0x080857C0, 0x080609C0, 0x08069FC0, 0x080735C0, 0x0807CBC0, 0x080861C0,
};

UNK_PTR D_8082AA74[] = {
    0x0805FFC0, 0x08068BC0, 0x080721C0, 0x0807B7C0, 0x08084DC0, 0x08086BC0, 0x080695C0, 0x08072BC0,
    0x0807C1C0, 0x080857C0, 0x080609C0, 0x08069FC0, 0x080735C0, 0x0807CBC0, 0x080861C0,
};

UNK_PTR D_8082AAB0[] = {
    D_8082A948,
    D_8082A81C,
    D_8082A6F0,
};

UNK_PTR D_8082AABC[] = {
    D_8082A984,
    D_8082A858,
    D_8082A72C,
};

UNK_PTR D_8082AAC8[] = {
    D_8082A9C0,
    D_8082A894,
    D_8082A768,
};

UNK_PTR D_8082AAD4[] = {
    D_8082A9FC,
    D_8082A8D0,
    D_8082A7A4,
};

UNK_PTR D_8082AAE0[] = {
    D_8082AA38,
    D_8082A90C,
    D_8082A7E0,
};

s16 D_8082AAEC[] = {
    32, 112, 32, 48, 32, 32, 32, 48, 32, 64, 32, 48, 48, 48, 48, 64, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 80, 64,
};

s16 D_8082AB2C[] = {
    24, 72, 13, 22, 19, 20, 19, 27, 14, 26, 22, 21, 49, 32, 45, 60, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 32, 8,
};

u8 D_8082AB6C[][5] = {
    { BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED },
    { BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED },
    { BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED },
    { BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED },
    { BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED },
    { BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED },
};

s16 D_8082AB8C = 0;
s16 D_8082AB90 = 0;
s16 D_8082AB94 = 0;
s16 D_8082AB98 = 255;
s16 D_8082AB9C = 255;
s16 D_8082ABA0 = 0;
s16 D_8082ABA4 = 0;

s16 D_8082ABA8 = 0;

f32 D_8082ABAC[] = {
    -4.0f, 4.0f, 4.0f, 4.0f, 4.0f, -4.0f, -4.0f, -4.0f,
};

f32 D_8082ABCC[] = {
    -4.0f, -4.0f, -4.0f, 4.0f, 4.0f, 4.0f, 4.0f, -4.0f,
};

u16 D_8082ABEC[] = { 1, 3, 2, 0, 3, 1, 0, 2 };

//D_8082ABFC
u8 gSlotAgeReqs[] = {
    //clang-format off
    1, 9, 9, 0, 0, 9,
    1, 9, 9, 0, 0, 9,
    1, 9, 1, 0, 0, 9,
    9, 9, 9, 9, 0, 1,
    0, 1, 0, 0, 
    9, 1, 9, 0, 
    0, 9, 0, 0, 
    9, 9, 0, 0,
    //clang-format on
};

//D_8082AC24
u8 gItemAgeReqs[] = {
    1, 9, 9, 0, 0, 9, 1, 9, 9, 9, 0, 0, 0, 9, 1, 9, 1, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
    9, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 1, 9, 0, 9, 0, 0, 9, 0, 0, 1, 1, 1, 0, 0, 0, 9, 9, 9, 1, 0, 0, 9, 9, 0,
};

u8 D_8082AC7C[] = {
    0x0F, 0x1F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x03, 0x0F,
    0x07, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x03, 0x0F, 0x00, 0x00,
};

void* D_8082AC94[] = {
    0x0805C1C0,
    0x0805C240,
    0x0805C2C0,
    0x0805C340,
};

s16 D_8082ACA4[][3] = {
    { 255, 255, 255 },
    { 255, 255, 0 },
    { 0, 255, 50 },
};

UNK_PTR D_8082ACB8[] = {
    0x0D006880,
    0x0D006D80,
    0x0D006C80,
};

UNK_PTR D_8082ACC4[] = {
    0x0D007200,
    0x0D007700,
    0x0D007600,
};

UNK_PTR D_8082ACD0[] = {
    0x0C002000,
    0x0C002980,
    0x0C003300,
};

UNK_PTR D_8082ACDC[][2] = {
    { 0x0D007B80, 0x0D007E80 },
    { 0x0D008080, 0x0D008380 },
    { 0x0D007F80, 0x0D008280 },
};

// .bss
s16 D_808321A0;
s16 D_808321A2;
s16 D_808321A4;
s16 D_808321A6;
u8 D_808321A8[5];
PreRenderContext D_808321B0;
void* D_80832200;

void func_8081F1F0(GlobalContext* globalCtx) {
    Gfx* gfx;
    Gfx* gfxRef;
    void* fbuf;

    fbuf = globalCtx->state.gfxCtx->curFrameBuffer;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 496);

    gfxRef = POLY_OPA_DISP;
    gfx = Graph_GfxPlusOne(gfxRef);
    gSPDisplayList(WORK_DISP++, gfx);

    PreRender_SetValues(&D_808321B0, 64, 112, fbuf, NULL);
    func_800C1F20(&D_808321B0, &gfx);
    func_800C20B4(&D_808321B0, &gfx);

    gSPEndDisplayList(gfx++);
    Graph_BranchDlist(gfxRef, gfx);
    POLY_OPA_DISP = gfx;

    SREG(33) |= 1;

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 509);
}

void func_8081F2FC(void) {
    Sleep_Msec(50);
    PreRender_Calc(&D_808321B0);
    PreRender_Destroy(&D_808321B0);
}

Gfx* func_8081F334(Gfx* gfx, void* texture, s16 width, s16 height, u16 arg4) {
    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_IA, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(gfx++, arg4, arg4 + 2, arg4 + 3, arg4 + 1, 0);

    return gfx;
}

Gfx* func_8081F50C(Gfx* gfx, void* texture, s16 width, s16 height, u16 arg4) {
    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle(gfx++, arg4, arg4 + 2, arg4 + 3, arg4 + 1, 0);

    return gfx;
}

void func_8081F6E4(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 temp1;
    s32 temp2;

    arg2 &= 0xF;
    arg3 &= 0xF;

    if ((arg1 == 0) || (arg2 == arg3) || (arg0 == 0)) {
        return;
    }

    for (i = 0; i < arg1; i++) {
        temp1 = temp2 = arg0[i];

        temp1 = (temp1 >> 4) & 0xF;
        temp2 = temp2 & 0xF;

        if (temp1 == arg2) {
            temp1 = arg3;
        }

        if (temp2 == arg2) {
            temp2 = arg3;
        }

        arg0[i] = (temp1 << 4) | temp2;
    }
}

void KaleidoScope_MoveCursorToSpecialPos(GlobalContext* globalCtx, u16 specialPos) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;

    pauseCtx->cursorSpecialPos = specialPos;
    pauseCtx->unk_23A = 0;

    Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_8081F87C(GraphicsContext* gfxCtx, void* texture, u16 width, u16 height, u16 arg4) {
    OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 748);

    gDPLoadTextureBlock(POLY_OPA_DISP++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSP1Quadrangle(POLY_OPA_DISP++, arg4, arg4 + 2, arg4 + 3, arg4 + 1, 0);

    CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 758);
}

void func_8081FABC(GlobalContext* globalCtx) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    s16 s;
    s16 i;

    switch (pauseCtx->kscpPos) {
        case 0:
            s = pauseCtx->cursorSlotCopy[0];
            if (gSaveContext.inventory.items[s] == ITEM_NONE) {
                i = s + 1;
                while (true) {
                    if (gSaveContext.inventory.items[i] != ITEM_NONE) {
                        break;
                    }
                    i++;
                    if (i >= 24) {
                        i = 0;
                    }
                    if (i == s) {
                        pauseCtx->cursorItem[0] = pauseCtx->unk_23C = 999;
                        return;
                    }
                }
                pauseCtx->cursorItem[0] = gSaveContext.inventory.items[i];
                pauseCtx->cursorSlotCopy[0] = i;
            }
            break;
        case 1:
        case 2:
        case 3:
            break;
    }
}

void func_8081FB7C(PauseContext* pauseCtx, u8 pt) {
    pauseCtx->unk_1E4 = 1;
    pauseCtx->unk_1EA = 0;

    if (!pt) {
        pauseCtx->mode = pauseCtx->kscpPos * 2 + 1;
        Audio_PlaySoundGeneral(NA_SE_SY_WIN_SCROLL_LEFT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        pauseCtx->cursorSpecialPos = KSCP_CURSOR_SPECIAL_PAGERIGHT;
    } else {
        pauseCtx->mode = pauseCtx->kscpPos * 2;
        Audio_PlaySoundGeneral(NA_SE_SY_WIN_SCROLL_RIGHT, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        pauseCtx->cursorSpecialPos = KSCP_CURSOR_SPECIAL_PAGELEFT;
    }

    gSaveContext.buttonStatus[1] = D_8082AB6C[pauseCtx->kscpPos + pt][1];
    gSaveContext.buttonStatus[2] = D_8082AB6C[pauseCtx->kscpPos + pt][2];
    gSaveContext.buttonStatus[3] = D_8082AB6C[pauseCtx->kscpPos + pt][3];
    gSaveContext.buttonStatus[4] = D_8082AB6C[pauseCtx->kscpPos + pt][4];

    osSyncPrintf("kscope->kscp_pos+pt = %d\n", pauseCtx->kscpPos + pt);

    gSaveContext.unk_13EA = 0;
    Interface_ChangeAlpha(50);
}

void func_8081FCF4(PauseContext* pauseCtx, Input* input) {
    if ((pauseCtx->flag == 0) && CHECK_BTN_ALL(input->press.button, BTN_L)) {
        pauseCtx->flag = 1;
        return;
    }

    if (CHECK_BTN_ALL(input->press.button, BTN_R)) {
        func_8081FB7C(pauseCtx, 2);
        return;
    }

    if (CHECK_BTN_ALL(input->press.button, BTN_Z)) {
        func_8081FB7C(pauseCtx, 0);
        return;
    }

    if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_SPECIAL_PAGELEFT) {
        if (pauseCtx->stickRelX < -30) {
            pauseCtx->unk_23A++;
            if ((pauseCtx->unk_23A >= 10) || (pauseCtx->unk_23A == 0)) {
                func_8081FB7C(pauseCtx, 0);
            }
        } else {
            pauseCtx->unk_23A = -1;
        }
    } else if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_SPECIAL_PAGERIGHT) {
        if (pauseCtx->stickRelX > 30) {
            pauseCtx->unk_23A++;
            if ((pauseCtx->unk_23A >= 10) || (pauseCtx->unk_23A == 0)) {
                func_8081FB7C(pauseCtx, 2);
            }
        } else {
            pauseCtx->unk_23A = -1;
        }
    }
}

void func_8081FE30(GlobalContext* globalCtx, u16 arg1) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    u16 temp;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 955);

    temp = pauseCtx->unk_1E4;

    if ((((pauseCtx->unk_1E4 == 0) || (temp == 8)) && (pauseCtx->state == 6)) ||
        ((pauseCtx->kscpPos == 2) && ((temp < 3) || (temp == 5) || (temp == 8)))) {

        if (pauseCtx->kscpPos == arg1) {
            s16 i;
            s16 j;

            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082ACA4[pauseCtx->unk_260 >> 2][0],
                            D_8082ACA4[pauseCtx->unk_260 >> 2][1], D_8082ACA4[pauseCtx->unk_260 >> 2][2], 255);
            gDPSetEnvColor(POLY_OPA_DISP++, D_8082AB8C, D_8082AB90, D_8082AB94, 255);
            gSPVertex(POLY_OPA_DISP++, pauseCtx->vtx_168, 16, 0);

            for (i = j = 0; i < 4; i++, j += 4) {
                gDPLoadTextureBlock_4b(POLY_OPA_DISP++, D_8082AC94[i], G_IM_FMT_IA, 16, 16, 0,
                                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                       G_TX_NOLOD, G_TX_NOLOD);
                gSP1Quadrangle(POLY_OPA_DISP++, j, j + 2, j + 3, j + 1, 0);
            }
        }

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 985);
}

Gfx* func_8082018C(Gfx* gfx, Vtx* vertices, void** textures) {
    s32 i;
    s32 j;

    gSPVertex(gfx++, vertices, 32, 0);

    i = 0;
    j = 0;
    while (i < 32) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, textures[j], G_IM_FMT_IA, G_IM_SIZ_8b, 80, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(gfx++, i, i + 2, i + 3, i + 1, 0);

        if (1) {}

        i += 4;
        j++;
    }

    gSPVertex(gfx++, vertices + 32, 28, 0);

    i = 0;
    while (i < 28) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, textures[j], G_IM_FMT_IA, G_IM_SIZ_8b, 80, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP1Quadrangle(gfx++, i, i + 2, i + 3, i + 1, 0);

        if (1) {}

        i += 4;
        j++;
    }

    return gfx;
}

void func_80820434(GlobalContext* globalCtx, GraphicsContext* gfxCtx) {
    static s16 D_8082ACF4[][3] = {
        { 0, 0, 0 }, { 0, 0, 0 },     { 0, 0, 0 },    { 0, 0, 0 }, { 255, 255, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 255, 255, 0 }, { 0, 255, 50 }, { 0, 0, 0 }, { 0, 0, 0 },     { 0, 255, 50 },
    };
    static s16 D_8082AD3C = 20;
    static s16 D_8082AD40 = 0;
    static s16 D_8082AD44 = 0;
    static s16 D_8082AD48 = 0;
    static s16 D_8082AD4C = 0;
    static s16 D_8082AD50 = 0;
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    s16 temp1;
    s16 temp2;
    s16 temp3;

    OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 1100);

    if ((pauseCtx->state < 8) || (pauseCtx->state > 0x11)) {
        if (pauseCtx->state != 7) {
            temp1 = ABS(D_8082AB8C - D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][0]) / D_8082AD3C;
            temp2 = ABS(D_8082AB90 - D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][1]) / D_8082AD3C;
            temp3 = ABS(D_8082AB94 - D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][2]) / D_8082AD3C;
            if (D_8082AB8C >= D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][0]) {
                D_8082AB8C -= temp1;
            } else {
                D_8082AB8C += temp1;
            }
            if (D_8082AB90 >= D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][1]) {
                D_8082AB90 -= temp2;
            } else {
                D_8082AB90 += temp2;
            }
            if (D_8082AB94 >= D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][2]) {
                D_8082AB94 -= temp3;
            } else {
                D_8082AB94 += temp3;
            }

            D_8082AD3C--;
            if (D_8082AD3C == 0) {
                D_8082AB8C = D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][0];
                D_8082AB90 = D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][1];
                D_8082AB94 = D_8082ACF4[pauseCtx->unk_260 + D_8082AD40][2];
                D_8082AD3C = ZREG(28 + D_8082AD40);
                D_8082AD40++;
                if (D_8082AD40 >= 4) {
                    D_8082AD40 = 0;
                }
            }

            if (pauseCtx->stickRelX < -30) {
                if (D_8082AD4C == -1) {
                    if (--D_8082AD44 < 0) {
                        D_8082AD44 = XREG(6);
                    } else {
                        pauseCtx->stickRelX = 0;
                    }
                } else {
                    D_8082AD44 = XREG(8);
                    D_8082AD4C = -1;
                }
            } else if (pauseCtx->stickRelX > 30) {
                if (D_8082AD4C == 1) {
                    if (--D_8082AD44 < 0) {
                        D_8082AD44 = XREG(6);
                    } else {
                        pauseCtx->stickRelX = 0;
                    }
                } else {
                    D_8082AD44 = XREG(8);
                    D_8082AD4C = 1;
                }
            } else {
                D_8082AD4C = 0;
            }

            if (pauseCtx->stickRelY < -30) {
                if (D_8082AD50 == -1) {
                    if (--D_8082AD48 < 0) {
                        D_8082AD48 = XREG(6);
                    } else {
                        pauseCtx->stickRelY = 0;
                    }
                } else {
                    D_8082AD48 = XREG(8);
                    D_8082AD50 = -1;
                }
            } else if (pauseCtx->stickRelY > 30) {
                if (D_8082AD50 == 1) {
                    if (--D_8082AD48 < 0) {
                        D_8082AD48 = XREG(6);
                    } else {
                        pauseCtx->stickRelY = 0;
                    }
                } else {
                    D_8082AD48 = XREG(8);
                    D_8082AD50 = 1;
                }
            } else {
                D_8082AD50 = 0;
            }
        }

        if (pauseCtx->kscpPos) {
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

            Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, -(f32)WREG(3) / 100.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateX(-pauseCtx->unk_1F4 / 100.0f, MTXMODE_APPLY);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1173),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_144, D_8082AABC[gSaveContext.language]);

            func_80819E6C(globalCtx);
        }

        if (pauseCtx->kscpPos != 3) {
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

            Matrix_Translate(-(f32)WREG(3) / 100.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateZ(pauseCtx->unk_1F8 / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(1.57f, MTXMODE_APPLY);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1196),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_148, D_8082AAB0[gSaveContext.language]);

            func_80818340(globalCtx);
        }

        if (pauseCtx->kscpPos != 2) {
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetTextureFilter(POLY_OPA_DISP++, G_TF_BILERP);
            gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

            Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, (f32)WREG(3) / 100.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateX(pauseCtx->unk_200 / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(3.14f, MTXMODE_APPLY);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1220),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_150, D_8082AAD4[gSaveContext.language]);

            func_80813820(globalCtx, gfxCtx);
        }

        if (pauseCtx->kscpPos != 1) {
            gDPPipeSync(POLY_OPA_DISP++);

            gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

            Matrix_Translate((f32)WREG(3) / 100.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateZ(-pauseCtx->unk_1FC / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(-1.57f, MTXMODE_APPLY);

            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1243),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_14C, D_8082AAC8[gSaveContext.language]);

            if (D_8082ABA8 != 0) {
                func_8081BB10(globalCtx, gfxCtx);
                func_800949A8(gfxCtx);

                gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                if (CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, gSaveContext.mapIndex)) {
                    PauseMapMark_Draw(globalCtx);
                }
            } else {
                func_8081D398(globalCtx, gfxCtx);
            }
        }

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

        switch (pauseCtx->kscpPos) {
            case 0:
                Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, -(f32)WREG(3) / 100.0f, 0);
                Matrix_Scale(0.78f, 0.78f, 0.78f, 1);
                Matrix_RotateX(-pauseCtx->unk_1F4 / 100.0f, 1);

                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1281),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_144, D_8082AABC[gSaveContext.language]);

                func_80819E6C(globalCtx);
                break;

            case 1:
                Matrix_Translate((f32)WREG(3) / 100.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
                Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
                Matrix_RotateZ(-pauseCtx->unk_1FC / 100.0f, MTXMODE_APPLY);
                Matrix_RotateY(-1.57f, MTXMODE_APPLY);

                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1303),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_14C, D_8082AAC8[gSaveContext.language]);

                if (D_8082ABA8 != 0) {
                    func_8081BB10(globalCtx, gfxCtx);
                    func_800949A8(gfxCtx);

                    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                    if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
                        func_8081FE30(globalCtx, 1);
                    }

                    if (CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, gSaveContext.mapIndex)) {
                        PauseMapMark_Draw(globalCtx);
                    }
                } else {
                    func_8081D398(globalCtx, gfxCtx);
                }
                break;

            case 2:
                gDPSetTextureFilter(POLY_OPA_DISP++, G_TF_BILERP);

                Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, (f32)WREG(3) / 100.0f, MTXMODE_NEW);
                Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
                Matrix_RotateX(pauseCtx->unk_200 / 100.0f, MTXMODE_APPLY);
                Matrix_RotateY(3.14f, MTXMODE_APPLY);

                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1343),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_150, D_8082AAD4[gSaveContext.language]);

                func_80813820(globalCtx, gfxCtx);

                if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
                    func_8081FE30(globalCtx, 2);
                }
                break;

            case 3:
                Matrix_Translate(-(f32)WREG(3) / 100.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
                Matrix_Scale(0.78f, 0.78f, 0.78f, 1);
                Matrix_RotateZ(pauseCtx->unk_1F8 / 100.0f, 1);
                Matrix_RotateY(1.57f, 1);

                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1367),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_148, D_8082AAB0[gSaveContext.language]);

                func_80818340(globalCtx);

                if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
                    func_8081FE30(globalCtx, 3);
                }
                break;
        }
    }

    func_800949A8(gfxCtx);

    if ((pauseCtx->state == 7) || ((pauseCtx->state >= 8) && (pauseCtx->state < 0x12))) {
        func_8081EFF0(globalCtx);

        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

        if (!pauseCtx->kscpPos) {
            pauseCtx->unk_1F4 = pauseCtx->unk_204 + 314.0f;

            Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, -pauseCtx->unk_1F0 / 10.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateX(-pauseCtx->unk_204 / 100.0f, MTXMODE_APPLY);
        } else if (pauseCtx->kscpPos == 1) {
            pauseCtx->unk_1FC = pauseCtx->unk_204 + 314.0f;

            Matrix_Translate(pauseCtx->unk_1F0 / 10.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateZ(-pauseCtx->unk_204 / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(-1.57f, MTXMODE_APPLY);
        } else if (pauseCtx->kscpPos == 2) {
            pauseCtx->unk_200 = pauseCtx->unk_204 + 314.0f;

            Matrix_Translate(0.0f, (f32)WREG(2) / 100.0f, pauseCtx->unk_1F0 / 10.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateX(pauseCtx->unk_204 / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(3.14f, MTXMODE_APPLY);
        } else {
            pauseCtx->unk_1F8 = pauseCtx->unk_204 + 314.0f;

            Matrix_Translate(-pauseCtx->unk_1F0 / 10.0f, (f32)WREG(2) / 100.0f, 0.0f, MTXMODE_NEW);
            Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
            Matrix_RotateZ(pauseCtx->unk_204 / 100.0f, MTXMODE_APPLY);
            Matrix_RotateY(1.57f, MTXMODE_APPLY);
        }

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(gfxCtx, "../z_kaleido_scope_PAL.c", 1424),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((pauseCtx->state >= 8) && (pauseCtx->state <= 0x11)) {
            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_16C, D_8082AA74);
        } else {
            POLY_OPA_DISP = func_8082018C(POLY_OPA_DISP, pauseCtx->vtx_16C, D_8082AAE0[gSaveContext.language]);
        }

        gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_16C[60], 32, 0);

        if (((pauseCtx->state == 7) && (pauseCtx->unk_1EC < 4)) || (pauseCtx->state == 0xE)) {
            POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACB8[gSaveContext.language], 0x98, 0x10, 0);

            gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0,
                              0, PRIMITIVE, 0);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 255, 100, VREG(61));

            if (pauseCtx->unk_262 == 0) {
                gSPDisplayList(POLY_OPA_DISP++, D_08089BF8);
            } else {
                gSPDisplayList(POLY_OPA_DISP++, D_08089C48);
            }

            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);

            POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACDC[gSaveContext.language][0], 0x30, 0x10, 0xC);

            POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACDC[gSaveContext.language][1], 0x30, 0x10, 0x10);
        } else if ((pauseCtx->state != 7) || (pauseCtx->unk_1EC < 4)) {
            if ((pauseCtx->state != 0xF) && ((pauseCtx->state == 0x10) || (pauseCtx->state == 0x11))) {
                POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACD0[gSaveContext.language], 0x98, 0x10, 0);

                gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0,
                                  TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 255, 100, VREG(61));

                if (pauseCtx->unk_262 == 0) {
                    gSPDisplayList(POLY_OPA_DISP++, D_08089BF8);
                } else {
                    gSPDisplayList(POLY_OPA_DISP++, D_08089C48);
                }

                gDPPipeSync(POLY_OPA_DISP++);
                gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);

                POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACDC[gSaveContext.language][0], 0x30, 0x10, 0xC);

                POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, D_8082ACDC[gSaveContext.language][1], 0x30, 0x10, 0x10);
            }
        }

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

        if ((pauseCtx->state != 0x10) && (pauseCtx->state != 0x11)) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 0, pauseCtx->unk_208);
            gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
        }
    }

    CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 1577);
}

// unsorted
s32 D_8082AD54[] = {
    0x0D003C00,
    0x0D003C00,
    0x0D003C00,
};
s32 D_8082AD60[] = {
    0x0D003F80,
    0x0D004180,
    0x0D004100,
};
s32 D_8082AD6C[] = {
    0x0D004380,
    0x0D004700,
    0x0D004580,
};
s32 D_8082AD78[] = {
    0x0D006080, 0x0D006580, 0x0D006480, 0x0D004880, 0x0D004D80, 0x0D004C80,
    0x0D005080, 0x0D005580, 0x0D005480, 0x0D005880, 0x0D005D80, 0x0D005C80,
};
s32 D_8082ADA8[] = {
    0x0D005080, 0x0D005580, 0x0D005480, 0x0D005880, 0x0D005D80, 0x0D005C80,
    0x0D006080, 0x0D006580, 0x0D006480, 0x0D004880, 0x0D004D80, 0x0D004C80,
};
s32 D_8082ADD8[] = {
    0x00380058,
    0x00500000,
};
s32 D_8082ADE0[] = {
    0x00400058,
    0x00480000,
};
s32 D_8082ADE8[] = {
    0x00500068,
    0x00700000,
};
s32 D_8082ADF0[] = {
    0x00B400D2,
    0x00FF00DC,
    0x00640064,
    0x009600DC,
};
s32 D_8082AE00[] = {
    0x00140000,
};
s32 D_8082AE04[] = {
    0x00000000, 0x000A0010, 0x00100011, 0x000C000D, 0x00120011, 0x00110013,
    0x000D0015, 0x00140015, 0x000E000F, 0x000F000F, 0x000B000E,
};
s32 D_8082AE30[] = {
    0x00150014, 0x00130012, 0x000B000E, 0x000A000F, 0x0010000D, 0x000C0011,
};
s32 D_8082AE48[] = {
    0x0A46460A, 0x0A5A5A0A, 0x508C8C50, 0x50787850, 0x508C8C50, 0x326E6E32,
};
s32 D_8082AE60[] = {
    0x32646432, 0x32646432, 0x283C3C28, 0x50787850, 0x283C3C28, 0x326E6E32,
};
s32 D_8082AE78[] = {
    0x50828250, 0x283C3C28, 0x1E3C3C1E, 0x32464632, 0x1E3C3C1E, 0x326E6E32,
};
s32 D_8082AE90[] = {
    0x00000000,
};
s32 D_8082AE94[] = {
    0x00000000,
};
s32 D_8082AE98[] = {
    0xFFDC000C, 0xFFEE0046, 0x00460046, 0xFFA8FFA8, 0xFFA8FFA8, 0xFFA8FFA8, 0xFFA8FFA8, 0xFF96FFC2, 0xFFD80000,
};
s32 D_8082AEBC[] = {
    0x00000000,
};
s32 D_8082AEC0[] = {
    0x002FFFCF, 0xFFEFFFF1, 0xFFF70018, 0x002B000E, 0x00090026, 0x00520047, 0xFFB4FFA9, 0xFF94FFCA,
    0xFFA3FFBD, 0xFFC8FFDF, 0xFFF60001, 0x000E0018, 0x0023003A, 0x004A0059, 0x0000FFC6, 0x0013001C,
};
s32 D_8082AF00[] = {
    0xFFB4FFC6,
    0x000AFFC6,
    0x000A0000,
};
s32 D_8082AF0C[] = {
    0x00000000,
};
s32 D_8082AF10[] = {
    0x00000000,
};
s32 D_8082AF14[] = {
    0x00300030, 0x00600018, 0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00100010, 0x00180000,
};
s32 D_8082AF38[] = {
    0x00000000,
};
s32 D_8082AF3C[] = {
    0x00980030,
    0x00300030,
    0x00300000,
};
s32 D_8082AF48[] = {
    0x00000000,
};
s32 D_8082AF4C[] = {
    0x00000000,
};
s32 D_8082AF50[] = {
    0x001C001C, 0x002E001C, 0xFFFEFFE0, 0x00320024, 0x00160008, 0xFFFAFFEC, 0xFFDEFFD0, 0x00120012, 0x00320000,
};
s32 D_8082AF74[] = {
    0x00000000,
};
s32 D_8082AF78[] = {
    0x000F0028, 0x000B002D, 0x00340025, 0x00240039, 0x00360021, 0x001F002D, 0x0020002A, 0x0031FFF6,
    0x001F001B, 0x000FFFCF, 0x00080026, 0x0007002F, 0x001E0001, 0xFFF70019, 0x00000001, 0xFFE0FFE6,
};
s32 D_8082AFB8[] = {
    0x0024000A,
    0x000AFFFA,
    0xFFFA0000,
};
s32 D_8082AFC4[] = {
    0x00000000,
};
s32 D_8082AFC8[] = {
    0x00000000,
};
s32 D_8082AFCC[] = {
    0x00550055, 0x00100018, 0x00180018, 0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00180000,
};
s32 D_8082AFF0[] = {
    0x00000000,
};
s32 D_8082AFF4[] = {
    0x00100030,
    0x00300010,
    0x00100000,
};

UNK_PTR D_8082B000[] = {
    D_8082AE90, D_8082AE94, D_8082AE98, D_8082AEBC, D_8082AEC0, D_8082AF00,
};

UNK_PTR D_8082B018[] = {
    D_8082AF0C, D_8082AF10, D_8082AF14, D_8082AF38, D_8082AAEC, D_8082AF3C,
};

UNK_PTR D_8082B030[] = {
    D_8082AF48, D_8082AF4C, D_8082AF50, D_8082AF74, D_8082AF78, D_8082AFB8,
};

UNK_PTR D_8082B048[] = {
    D_8082AFC4,
    D_8082AFC8,
    D_8082AFCC,
    D_8082AFF0,
};

UNK_PTR D_8082B058[] = {
    D_8082AB2C,
    D_8082AFF4,
};

s32 D_8082B060[] = {
    0xFFC6000B, 0x001E001E, 0x000F0026, 0xFFC2003C, 0x003DFFB2, 0xFED4FFAA,
    0xFFBFFED4, 0xFED4FFEB, 0x000E000D, 0x0014FFDE, 0xFED40000,
};
s32 D_8082B08C[] = {
    0x00590014, 0x000E0023, 0x00200011, 0x00320010, 0x00150014, 0xFFFF0020,
    0x0010FFFF, 0xFFFF0013, 0x00130015, 0x00100014, 0xFFFF0000,
};
s32 D_8082B0B8[] = {
    0x0001000F, 0x00140009, 0xFFE2FFEF, 0xFFDE000F, 0x001E0001, 0xFED4002A,
    0x0007FED4, 0xFED40018, 0x00240035, 0x0025FFF3, 0xFED40000,
};
s32 D_8082B0E4[] = {
    0x0024000F, 0x00100017, 0x00170010, 0x0018000D, 0x00110012, 0x00010019,
    0x000D0001, 0x0001000D, 0x0015000F, 0x000D000C, 0x00010000,
};

s16 D_8082B110 = 0;

s16 D_8082B114 = 1;

s16 D_8082B118 = 0;

s32 D_8082B11C[] = {
    0x00000004,
    0x0008000C,
    0x00180020,
    0x00380000,
};
s32 D_8082B12C[] = {
    0xFF8E000C,
    0x002C004C,
};
s32 D_8082B134[] = {
    0x0105090D,
};
s32 D_8082B138[] = {
    0x004A004A, 0x002E0012, 0x0012002E, 0xFF94FFA6, 0xFFB8FFCA, 0xFFDCFFEE, 0xFF94FFA6, 0xFFB8FFCA,
    0xFFDCFFEE, 0x0014002E, 0x0048FF92, 0xFFAAFF92, 0xFFCAFF9E, 0xFFAAFFB6, 0xFFC2FFCE, 0xFFDAFFE6,
    0xFFF2FF9E, 0xFFAAFFB6, 0xFFC2FFCE, 0xFFDAFFE6, 0xFFF2FFA8, 0xFFAFFFB8, 0xFFA6FFAD, 0xFFB60000,
};
s32 D_8082B198[] = {
    0x00260006, 0xFFF40006, 0x00260038, 0xFFECFFEC, 0xFFECFFEC, 0xFFECFFEC, 0x00020002, 0x00020002,
    0x00020002, 0xFFD2FFD2, 0xFFD2003A, 0x003A0022, 0x003AFFCC, 0xFFCCFFCC, 0xFFCCFFCC, 0xFFCCFFCC,
    0xFFCCFFCC, 0xFFCCFFCC, 0xFFCCFFCC, 0xFFCCFFCC, 0xFFCC0022, 0x00220022, 0x00240024, 0x00240000,
};
s32 D_8082B1F8[] = {
    0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00180018,
    0x00180018, 0x00180018, 0x00180018, 0x00180018, 0x00300010, 0x00100010, 0x00100010, 0x00100010,
    0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00100010, 0x00100000,
};

void func_80821C10(GlobalContext* globalCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80821C10.s")

void func_80823548(GlobalContext* globalCtx) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    u16 sp2A;

    if ((pauseCtx->unk_23C != pauseCtx->cursorItem[pauseCtx->kscpPos]) ||
        ((pauseCtx->kscpPos == 1) && (pauseCtx->cursorSpecialPos != KSCP_CURSOR_NORMAL))) {

        pauseCtx->unk_23C = pauseCtx->cursorItem[pauseCtx->kscpPos];
        sp2A = pauseCtx->unk_23C;

        osCreateMesgQueue(&pauseCtx->loadQueue, &pauseCtx->loadMsg, 1);

        if (pauseCtx->unk_23C != 999) {
            if ((pauseCtx->kscpPos == 1) && (D_8082ABA8 == 0)) {
                if (gSaveContext.language) {
                    sp2A += 12;
                }
                if (gSaveContext.language == 2) {
                    sp2A += 12;
                }

                DmaMgr_SendRequest1(pauseCtx->unk_138, (u32)_map_name_staticSegmentRomStart + (sp2A * 0x400), 0x400,
                                    "../z_kaleido_scope_PAL.c", 2093);
            } else {
                osSyncPrintf("zoom_name=%d\n", pauseCtx->unk_23C);

                if (gSaveContext.language) {
                    sp2A += 123;
                }
                if (gSaveContext.language == 2) {
                    sp2A += 123;
                }

                osSyncPrintf("J_N=%d  point=%d\n", gSaveContext.language, sp2A);

                DmaMgr_SendRequest1(pauseCtx->unk_138, (u32)_item_name_staticSegmentRomStart + (sp2A * 0x400), 0x400,
                                    "../z_kaleido_scope_PAL.c", 2120);
            }

            pauseCtx->unk_25C = 0;
        }
    } else if (pauseCtx->unk_25E == 0) {
        if (((pauseCtx->kscpPos == 2) && (pauseCtx->cursorSlotCopy[2] >= 6) && (pauseCtx->cursorSlotCopy[2] <= 0x11) &&
             (pauseCtx->unk_1E4 == 8)) ||
            (pauseCtx->kscpPos == 0) || ((pauseCtx->kscpPos == 3) && (pauseCtx->cursorX[3] != 0))) {
            if (pauseCtx->unk_23C != 44) {
                pauseCtx->unk_25C++;
                if (pauseCtx->unk_25C > WREG(88)) {
                    pauseCtx->unk_25C = 0;
                }
            }
        } else {
            pauseCtx->unk_25C = 0;
        }
    } else {
        pauseCtx->unk_25C = 0;
    }
}

void func_808237B4(GlobalContext* globalCtx, Input* input) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    s32 cond = false;
    s32 mode;

    if (ZREG(13) && !CHECK_BTN_ALL(input->press.button, BTN_L)) {
        cond = true;
    }

    if (!cond) {
        mode = pauseCtx->mode;
        pauseCtx->eye.x += D_8082ABAC[mode];
        pauseCtx->eye.z += D_8082ABCC[mode];

        if (pauseCtx->unk_1EA < 32) {
            WREG(16) -= WREG(25) / WREG(6);
            WREG(17) -= WREG(26) / WREG(6);
        } else {
            WREG(16) += WREG(25) / WREG(6);
            WREG(17) += WREG(26) / WREG(6);
        }

        pauseCtx->unk_1EA += 4;

        if (pauseCtx->unk_1EA == 64) {
            pauseCtx->unk_1EA = 0;
            pauseCtx->kscpPos = D_8082ABEC[pauseCtx->mode];
            pauseCtx->unk_1E4 = 0;
        }
    }
}

void func_80823994(PauseContext* pauseCtx, f32 x, f32 y, f32 z) {
    Vec3f eye;
    Vec3f lookAt;
    Vec3f up;

    eye.x = x;
    eye.y = y;
    eye.z = z;
    lookAt.x = lookAt.y = lookAt.z = 0.0f;
    up.x = up.z = 0.0f;
    up.y = 1.0f;

    func_800AA358(&pauseCtx->view, &eye, &lookAt, &up);
    func_800AAA50(&pauseCtx->view, 127);
}

void func_80823A0C(GlobalContext* globalCtx, Vtx* vtx, s16 arg2, s16 arg3);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80823A0C.s")

void func_8082409C(GlobalContext* globalCtx, GraphicsContext* gfxCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8082409C.s")

void func_80825C14(GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 3122);

    func_800944C4(gfxCtx);

    gDPSetCycleType(POLY_OPA_DISP++, G_CYC_2CYCLE);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_XLU_SURF2);
    gDPSetCombineLERP(POLY_OPA_DISP++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT,
                      COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);

    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x50, D_8082AB8C, D_8082AB90, D_8082AB94, D_8082AB98);
    gDPSetEnvColor(POLY_OPA_DISP++, D_8082AB9C, D_8082ABA0, D_8082ABA4, 255);

    VREG(89) -= 2;

    gDPLoadMultiBlock(POLY_OPA_DISP++, D_0C000000, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR,
                      G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPLoadMultiBlock(POLY_OPA_DISP++, D_0C001800, 256, 1, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0,
                      G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, 5, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetTileSize(POLY_OPA_DISP++, 1, 0, VREG(89) & 0x7F, 252, (VREG(89) & 0x7F) + 0x7C);

    gSPTextureRectangle(POLY_OPA_DISP++, VREG(87) << 2, VREG(88) << 2, (VREG(87) + 64) << 2, (VREG(88) + 32) << 2,
                        G_TX_RENDERTILE, 0, 0, 1024, 1024);

    gDPLoadMultiBlock(POLY_OPA_DISP++, D_0C000800, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0,
                      G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                      G_TX_NOLOD);

    gSPTextureRectangle(POLY_OPA_DISP++, (VREG(87) + 64) << 2, VREG(88) << 2, (VREG(87) + 128) << 2,
                        (VREG(88) + 32) << 2, G_TX_RENDERTILE, 0, 0, 1024, 1024);

    gDPLoadMultiBlock(POLY_OPA_DISP++, D_0C001000, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0,
                      G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                      G_TX_NOLOD);
    gSPTextureRectangle(POLY_OPA_DISP++, (VREG(87) + 128) << 2, VREG(88) << 2, (VREG(87) + 192) << 2,
                        (VREG(88) + 32) << 2, G_TX_RENDERTILE, 0, 0, 1024, 1024);

    CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 3169);
}

void KaleidoScope_Draw(GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input[0];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 3188);

    pauseCtx->stickRelX = input->rel.stick_x;
    pauseCtx->stickRelY = input->rel.stick_y;

    gSPSegment(POLY_OPA_DISP++, 0x02, interfaceCtx->parameterSegment);
    gSPSegment(POLY_OPA_DISP++, 0x07, pauseCtx->unk_13C);
    gSPSegment(POLY_OPA_DISP++, 0x08, pauseCtx->unk_128);
    gSPSegment(POLY_OPA_DISP++, 0x09, pauseCtx->unk_12C);
    gSPSegment(POLY_OPA_DISP++, 0x0A, pauseCtx->unk_138);
    gSPSegment(POLY_OPA_DISP++, 0x0C, pauseCtx->unk_130);
    gSPSegment(POLY_OPA_DISP++, 0x0D, pauseCtx->unk_134);

    if (pauseCtx->flag == 0) {
        func_80823994(pauseCtx, pauseCtx->eye.x, pauseCtx->eye.y, pauseCtx->eye.z);
        func_800949A8(globalCtx->state.gfxCtx);
        func_8082409C(globalCtx, globalCtx->state.gfxCtx);
        func_80820434(globalCtx, globalCtx->state.gfxCtx);
        func_800949A8(globalCtx->state.gfxCtx);

        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

        func_80823994(pauseCtx, 0.0f, 0.0f, 64.0f);

        if (!((pauseCtx->state >= 8) && (pauseCtx->state <= 17))) {
            func_80821C10(globalCtx);
        }
    }

    if ((pauseCtx->state >= 11) && (pauseCtx->state <= 17)) {
        func_80825C14(globalCtx);
    }

    if ((pauseCtx->flag == 1) || (pauseCtx->flag == 2)) {
        func_808161AC(globalCtx);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 3254);
}

void func_8082650C(u32* arg0, u16 arg1) {
    u32 temp1;
    u16 temp2;
    u16 i;

    for (i = 0; i < arg1; i++) {
        if (arg0[i] & 0xFFFFFF00) {
            temp1 = arg0[i] >> 8;
            temp2 = ((((temp1 & 0xFF0000) >> 16) + ((temp1 & 0xFF00) >> 7) + (temp1 & 0xFF)) / 7) & 0xFF;
            temp1 = temp2;
            temp1 <<= 8;
            temp1 |= temp2;
            temp1 <<= 8;
            temp1 |= temp2;
            arg0[i] = (temp1 << 8) | (arg0[i] & 0xFF);
        }
    }
}

void func_808265BC(GlobalContext* globalCtx) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;

    pauseCtx->eye.x += D_8082ABAC[pauseCtx->mode] * ZREG(46);
    pauseCtx->eye.z += D_8082ABCC[pauseCtx->mode] * ZREG(46);
    pauseCtx->unk_1EA += 4 * ZREG(46);

    if (pauseCtx->unk_1EA == (64 * ZREG(47))) {
        func_80084BF4(globalCtx, 1);
        gSaveContext.buttonStatus[0] = D_8082AB6C[pauseCtx->kscpPos][0];
        gSaveContext.buttonStatus[1] = D_8082AB6C[pauseCtx->kscpPos][1];
        gSaveContext.buttonStatus[2] = D_8082AB6C[pauseCtx->kscpPos][2];
        gSaveContext.buttonStatus[3] = D_8082AB6C[pauseCtx->kscpPos][3];
        gSaveContext.buttonStatus[4] = D_8082AB6C[pauseCtx->kscpPos][4];
        pauseCtx->kscpPos = D_8082ABEC[pauseCtx->mode];
        pauseCtx->unk_1E4 = 0;
        pauseCtx->state++;
        pauseCtx->unk_208 = 0xFF;
        Interface_LoadActionLabelB(globalCtx, 0xE);
    } else if (pauseCtx->unk_1EA == 64) {
        pauseCtx->kscpPos = D_8082ABEC[pauseCtx->mode];
        pauseCtx->mode = (u16)(pauseCtx->kscpPos * 2) + 1;
    }
}

void func_808267AC(GlobalContext* globalCtx) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;

    if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
        temp1 = -1;
        temp2 = 1;
        temp3 = 14;
        temp4 = 14;
        if (pauseCtx->kscpPos == 1) {
            if (D_8082ABA8 == 0) {
                temp1 = -6;
                temp2 = 6;
                temp3 = 4;
                temp4 = 4;
            } else if (pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] >= 3) {
                temp1 = -6;
                temp2 = 5;
                temp4 = 7;
                temp3 = 19;
            } else {
                temp1 = -3;
                temp2 = 3;
                temp3 = 13;
                temp4 = 13;
            }
        } else if (pauseCtx->kscpPos == 2) {
            temp1 = -4;
            temp2 = 4;
            temp3 = 12;
            temp4 = 12;
            if (pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] == 0x18) {
                temp1 = -2;
                temp2 = 2;
                temp3 = 32;
                temp4 = 32;
            } else if (pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] == 0x17) {
                temp1 = -4;
                temp2 = 4;
                temp4 = 13;
                temp3 = 34;
            } else if (pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] < 6) {
                temp1 = -1;
                temp2 = 1;
                temp3 = 10;
                temp4 = 10;
            } else if ((pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] >= 6) && (pauseCtx->cursorSlotCopy[pauseCtx->kscpPos] < 0x12)) {
                temp1 = -5;
                temp2 = 3;
                temp3 = 8;
                temp4 = 8;
            }
        }
    } else {
        temp1 = -4;
        temp2 = 4;
        temp3 = 16;
        temp4 = 16;
    }

    pauseCtx->vtx_168[0].v.ob[0] = pauseCtx->vtx_168[2].v.ob[0] = pauseCtx->vtx_168[0].v.ob[0] + temp1;
    pauseCtx->vtx_168[1].v.ob[0] = pauseCtx->vtx_168[3].v.ob[0] = pauseCtx->vtx_168[0].v.ob[0] + 16;
    pauseCtx->vtx_168[0].v.ob[1] = pauseCtx->vtx_168[1].v.ob[1] = pauseCtx->vtx_168[0].v.ob[1] + temp2;
    pauseCtx->vtx_168[2].v.ob[1] = pauseCtx->vtx_168[3].v.ob[1] = pauseCtx->vtx_168[0].v.ob[1] - 16;

    pauseCtx->vtx_168[4].v.ob[0] = pauseCtx->vtx_168[6].v.ob[0] = pauseCtx->vtx_168[0].v.ob[0] + temp3;
    pauseCtx->vtx_168[5].v.ob[0] = pauseCtx->vtx_168[7].v.ob[0] = pauseCtx->vtx_168[4].v.ob[0] + 16;
    pauseCtx->vtx_168[4].v.ob[1] = pauseCtx->vtx_168[5].v.ob[1] = pauseCtx->vtx_168[0].v.ob[1];
    pauseCtx->vtx_168[6].v.ob[1] = pauseCtx->vtx_168[7].v.ob[1] = pauseCtx->vtx_168[4].v.ob[1] - 16;

    pauseCtx->vtx_168[8].v.ob[0] = pauseCtx->vtx_168[10].v.ob[0] = pauseCtx->vtx_168[0].v.ob[0];
    pauseCtx->vtx_168[9].v.ob[0] = pauseCtx->vtx_168[11].v.ob[0] = pauseCtx->vtx_168[8].v.ob[0] + 16;
    pauseCtx->vtx_168[8].v.ob[1] = pauseCtx->vtx_168[9].v.ob[1] = pauseCtx->vtx_168[0].v.ob[1] - temp4;
    pauseCtx->vtx_168[10].v.ob[1] = pauseCtx->vtx_168[11].v.ob[1] = pauseCtx->vtx_168[8].v.ob[1] - 16;

    pauseCtx->vtx_168[12].v.ob[0] = pauseCtx->vtx_168[14].v.ob[0] = pauseCtx->vtx_168[0].v.ob[0] + temp3;
    pauseCtx->vtx_168[13].v.ob[0] = pauseCtx->vtx_168[15].v.ob[0] = pauseCtx->vtx_168[12].v.ob[0] + 16;
    pauseCtx->vtx_168[12].v.ob[1] = pauseCtx->vtx_168[13].v.ob[1] = pauseCtx->vtx_168[0].v.ob[1] - temp4;
    pauseCtx->vtx_168[14].v.ob[1] = pauseCtx->vtx_168[15].v.ob[1] = pauseCtx->vtx_168[12].v.ob[1] - 16;
}

void func_80826AEC(GlobalContext* globalCtx) {
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    u8* romStart = _map_48x85_staticSegmentRomStart;

    DmaMgr_SendRequest1(interfaceCtx->mapSegment, (u32)_map_48x85_staticSegmentRomStart + (VREG(13) * 0x7F8), 0x7F8,
                        "../z_kaleido_scope_PAL.c", 3467);

    DmaMgr_SendRequest1(interfaceCtx->mapSegment + 0x800,
                        (u32)_map_48x85_staticSegmentRomStart + ((VREG(13) + 1) * 0x7F8), 0x7F8,
                        "../z_kaleido_scope_PAL.c", 3471);
}

void func_80826BA8(GlobalContext* globalCtx) {
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

    osSyncPrintf("ＭＡＰ ＤＭＡ = %d\n", globalCtx->interfaceCtx.mapPaletteNum);

    func_80826AEC(globalCtx);
    Map_SetFloorPalettesData(globalCtx, pauseCtx->unk_236 - 3);

    if ((globalCtx->sceneNum >= SCENE_YDAN) && (globalCtx->sceneNum <= SCENE_TAKARAYA)) {
        if ((VREG(30) + 3) == pauseCtx->cursorSlot[1]) {
            func_8081F6E4(interfaceCtx->mapSegment, 0x7F8, interfaceCtx->mapPaletteNum, 0xE);
        }
    }

    if ((globalCtx->sceneNum >= SCENE_YDAN) && (globalCtx->sceneNum <= SCENE_TAKARAYA)) {
        if ((VREG(30) + 3) == pauseCtx->cursorSlot[1]) {
            func_8081F6E4(interfaceCtx->mapSegment + 0x800, 0x7F8, interfaceCtx->mapPaletteNum, 0xE);
        }
    }
}

void KaleidoScope_Update(GlobalContext* globalCtx) {
    static s16 D_8082B258 = 0;
    static s16 D_8082B25C = 10;
    static s16 D_8082B260 = 0;
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    Input* input = &globalCtx->state.input[0];
    Player* player = PLAYER;
    u16* unk_10A20 = &globalCtx->unk_10A20;
    u32 size;
    u32 size0;
    u32 size1;
    u32 size2;
    u16 i;
    s16 temp1;
    s16 temp2;
    s16 temp3;
    s16 temp4;
    s32 pad;

    if ((R_PAUSE_MENU_MODE >= 3) && (((pauseCtx->state >= 4) && (pauseCtx->state <= 7)) ||
                                     ((pauseCtx->state >= 0xA) && (pauseCtx->state <= 0x12)))) {
        if ((!pauseCtx->unk_1E4 || (pauseCtx->unk_1E4 == 8)) && (pauseCtx->state == 6)) {
            pauseCtx->stickRelX = input->rel.stick_x;
            pauseCtx->stickRelY = input->rel.stick_y;
            func_808267AC(globalCtx);
            func_8081FCF4(pauseCtx, input);
        } else if ((pauseCtx->kscpPos == 2) && ((pauseCtx->unk_1E4 < 3) || (pauseCtx->unk_1E4 == 5))) {
            func_808267AC(globalCtx);
        }

        if (pauseCtx->state == 6) {
            func_80823548(globalCtx);
        }
    }

    switch (pauseCtx->state - 3) {
        case 0:
            D_808321A8[0] = gSaveContext.buttonStatus[0];
            D_808321A8[1] = gSaveContext.buttonStatus[1];
            D_808321A8[2] = gSaveContext.buttonStatus[2];
            D_808321A8[3] = gSaveContext.buttonStatus[3];
            D_808321A8[4] = gSaveContext.buttonStatus[4];

            pauseCtx->cursorX[1] = 0;
            pauseCtx->cursorSlotCopy[1] = pauseCtx->cursorSlot[1] = pauseCtx->unk_236 = VREG(30) + 3;

            WREG(16) = -175;
            WREG(17) = 155;

            pauseCtx->unk_204 = -314.0f;

            pauseCtx->unk_13C = (void*)(((u32)globalCtx->objectCtx.spaceStart + 0x30) & ~0x3F);

            size1 = func_80091738(globalCtx, pauseCtx->unk_13C, &pauseCtx->skelAnime);
            osSyncPrintf("プレイヤー size1＝%x\n", size1);

            pauseCtx->unk_128 = (void*)(((u32)pauseCtx->unk_13C + size1 + 0xF) & ~0xF);

            size0 = (u32)_icon_item_staticSegmentRomEnd - (u32)_icon_item_staticSegmentRomStart;
            osSyncPrintf("icon_item size0=%x\n", size0);
            DmaMgr_SendRequest1(pauseCtx->unk_128, (u32)_icon_item_staticSegmentRomStart, size0,
                                "../z_kaleido_scope_PAL.c", 3662);

            gSegments[8] = VIRTUAL_TO_PHYSICAL(pauseCtx->unk_128);

            for (i = 0; i < ARRAY_COUNTU(gItemAgeReqs); i++) {
                if ((gItemAgeReqs[i] != 9) && (gItemAgeReqs[i] != ((void)0, gSaveContext.linkAge))) {
                    func_8082650C(SEGMENTED_TO_VIRTUAL(gItemIcons[i]), 0x400);
                }
            }

            pauseCtx->unk_12C = (void*)(((u32)pauseCtx->unk_128 + size0 + 0xF) & ~0xF);

            size = (u32)_icon_item_24_staticSegmentRomEnd - (u32)_icon_item_24_staticSegmentRomStart;
            osSyncPrintf("icon_item24 size=%x\n", size);
            DmaMgr_SendRequest1(pauseCtx->unk_12C, (u32)_icon_item_24_staticSegmentRomStart, size,
                                "../z_kaleido_scope_PAL.c", 3675);

            pauseCtx->unk_130 = (void*)(((u32)pauseCtx->unk_12C + size + 0xF) & ~0xF);

            switch (globalCtx->sceneNum) {
                case SCENE_YDAN:
                case SCENE_DDAN:
                case SCENE_BDAN:
                case SCENE_BMORI1:
                case SCENE_HIDAN:
                case SCENE_MIZUSIN:
                case SCENE_JYASINZOU:
                case SCENE_HAKADAN:
                case SCENE_HAKADANCH:
                case SCENE_ICE_DOUKUTO:
                case SCENE_YDAN_BOSS:
                case SCENE_DDAN_BOSS:
                case SCENE_BDAN_BOSS:
                case SCENE_MORIBOSSROOM:
                case SCENE_FIRE_BS:
                case SCENE_MIZUSIN_BS:
                case SCENE_JYASINBOSS:
                case SCENE_HAKADAN_BS:
                    D_8082ABA8 = 1;
                    size2 = (u32)_icon_item_dungeon_staticSegmentRomEnd - (u32)_icon_item_dungeon_staticSegmentRomStart;
                    osSyncPrintf("icon_item_dungeon dungeon-size2=%x\n", size2);
                    DmaMgr_SendRequest1(pauseCtx->unk_130, (u32)_icon_item_dungeon_staticSegmentRomStart, size2,
                                        "../z_kaleido_scope_PAL.c", 3712);

                    interfaceCtx->unk_140[28] = 6;
                    interfaceCtx->unk_140[29] = 99;
                    func_80826BA8(globalCtx);
                    break;

                default:
                    D_8082ABA8 = 0;
                    size2 = (u32)_icon_item_field_staticSegmentRomEnd - (u32)_icon_item_field_staticSegmentRomStart;
                    osSyncPrintf("icon_item_field field-size2=%x\n", size2);
                    DmaMgr_SendRequest1(pauseCtx->unk_130, (u32)_icon_item_field_staticSegmentRomStart, size2,
                                        "../z_kaleido_scope_PAL.c", 3726);
                    break;
            }

            pauseCtx->unk_134 = (void*)(((u32)pauseCtx->unk_130 + size2 + 0xF) & ~0xF);

            if (gSaveContext.language == 0) {
                size = (u32)_icon_item_nes_staticSegmentRomEnd - (u32)_icon_item_nes_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, _icon_item_nes_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 3739);
            } else if (gSaveContext.language == 1) {
                size = (u32)_icon_item_ger_staticSegmentRomEnd - (u32)_icon_item_ger_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, (u32)_icon_item_ger_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 3746);
            } else {
                size = (u32)_icon_item_fra_staticSegmentRomEnd - (u32)_icon_item_fra_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, (u32)_icon_item_fra_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 3753);
            }

            pauseCtx->unk_138 = (void*)(((u32)pauseCtx->unk_134 + size + 0xF) & ~0xF);

            osSyncPrintf("サイズ＝%x\n", size2 + size1 + size0 + size);
            osSyncPrintf("item_name I_N_PT=%x\n", 0x800);
            Interface_SetDoAction(globalCtx, 6);
            osSyncPrintf("サイズ＝%x\n", size2 + size1 + size0 + size + 0x800);

            if (((void)0, gSaveContext.worldMapArea) < 0x16) {
                if (gSaveContext.language == 0) {
                    DmaMgr_SendRequest1(pauseCtx->unk_138 + 0x400,
                                        (u32)_map_name_staticSegmentRomStart +
                                            (((void)0, gSaveContext.worldMapArea) * 0xA00) + 0x9000,
                                        0xA00, "../z_kaleido_scope_PAL.c", 3776);
                } else if (gSaveContext.language == 1) {
                    DmaMgr_SendRequest1(pauseCtx->unk_138 + 0x400,
                                        (u32)_map_name_staticSegmentRomStart +
                                            (((void)0, gSaveContext.worldMapArea) * 0xA00) + 0x16C00,
                                        0xA00, "../z_kaleido_scope_PAL.c", 3780);
                } else {
                    DmaMgr_SendRequest1(pauseCtx->unk_138 + 0x400,
                                        (u32)_map_name_staticSegmentRomStart +
                                            (((void)0, gSaveContext.worldMapArea) * 0xA00) + 0x24800,
                                        0xA00, "../z_kaleido_scope_PAL.c", 3784);
                }
            }

            D_80832200 = (void*)(((u32)pauseCtx->unk_138 + 0xE00 + 0xF) & ~0xF);
            PreRender_Init(&D_808321B0);
            PreRender_SetValuesSave(&D_808321B0, 64, 112, pauseCtx->unk_13C, NULL, D_80832200);
            func_8081819C(globalCtx);
            func_8081F1F0(globalCtx);

            for (i = 0; i < 20; i++) {
                pauseCtx->unk_266[i] = 0;
            }

            if (CHECK_QUEST_ITEM(QUEST_GERUDO_CARD)) {
                pauseCtx->unk_266[0] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT)) {
                pauseCtx->unk_266[0] = 1;
            }

            if (INV_CONTENT(ITEM_LONGSHOT) == ITEM_LONGSHOT) {
                pauseCtx->unk_266[1] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_GERUDO_CARD)) {
                pauseCtx->unk_266[1] = 1;
            }

            if (gSaveContext.eventChkInf[11] & 4) {
                pauseCtx->unk_266[2] = 1;
            }

            if (INV_CONTENT(ITEM_LONGSHOT) == ITEM_LONGSHOT) {
                pauseCtx->unk_266[2] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_GERUDO_CARD)) {
                pauseCtx->unk_266[2] = 1;
            }

            if (CUR_UPG_VALUE(UPG_SCALE)) {
                pauseCtx->unk_266[3] = 1;
            }

            if (CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1)) {
                pauseCtx->unk_266[3] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_WATER)) {
                pauseCtx->unk_266[3] = 1;
            }

            if (gSaveContext.eventChkInf[0] & 0x200) {
                pauseCtx->unk_266[4] = 1;
            }

            if (INV_CONTENT(7) != ITEM_NONE) {
                pauseCtx->unk_266[4] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_EPONA)) {
                pauseCtx->unk_266[4] = 1;
            }

            if (gSaveContext.eventChkInf[6] & 0x400) {
                pauseCtx->unk_266[4] = 2;
            }

            if (gSaveContext.eventChkInf[1] & 0x100) {
                pauseCtx->unk_266[4] = 1;
            }

            if (gSaveContext.eventChkInf[0] & 0x200) {
                pauseCtx->unk_266[5] = 2;
            }

            if (gSaveContext.eventChkInf[4] & 1) {
                pauseCtx->unk_266[5] = 1;
            }

            if (INV_CONTENT(ITEM_OCARINA_TIME) == ITEM_OCARINA_TIME) {
                pauseCtx->unk_266[5] = 2;
            }

            if (gSaveContext.eventChkInf[4] & 0x20) {
                pauseCtx->unk_266[5] = 1;
            }

            if (INV_CONTENT(ITEM_ARROW_LIGHT) == ITEM_ARROW_LIGHT) {
                pauseCtx->unk_266[5] = 2;
            }

            if (gSaveContext.eventChkInf[0] & 0x200) {
                pauseCtx->unk_266[6] = 1;
            }

            if (gSaveContext.eventChkInf[4] & 1) {
                pauseCtx->unk_266[7] = 2;
            }

            if (gSaveContext.eventChkInf[2] & 0x20) {
                pauseCtx->unk_266[7] = 1;
            }

            if (INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT) {
                pauseCtx->unk_266[7] = 2;
            }

            if (gSaveContext.eventChkInf[4] & 0x200) {
                pauseCtx->unk_266[7] = 1;
            }

            if (gBitFlags[1] & gSaveContext.worldMapAreaData) {
                pauseCtx->unk_266[8] = 1;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_LULLABY)) {
                pauseCtx->unk_266[8] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_SUN)) {
                pauseCtx->unk_266[8] = 1;
            }

            if (gSaveContext.eventChkInf[4] & 0x20) {
                pauseCtx->unk_266[8] = 2;
            }

            if (INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT) {
                pauseCtx->unk_266[8] = 1;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_STORMS)) {
                pauseCtx->unk_266[8] = 2;
            }

            if (gSaveContext.eventChkInf[6] & 0x80) {
                pauseCtx->unk_266[8] = 1;
            }

            if (gSaveContext.eventChkInf[10] & 0x400) {
                pauseCtx->unk_266[8] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW)) {
                pauseCtx->unk_266[8] = 1;
            }

            if (gBitFlags[10] & gSaveContext.worldMapAreaData) {
                pauseCtx->unk_266[9] = 1;
            }

            if (gSaveContext.eventChkInf[0] & 0x8000) {
                pauseCtx->unk_266[9] = 2;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_SARIA)) {
                pauseCtx->unk_266[9] = 1;
            }

            if (INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT) {
                pauseCtx->unk_266[9] = 2;
            }

            if (gSaveContext.eventChkInf[4] & 0x100) {
                pauseCtx->unk_266[9] = 1;
            }

            pauseCtx->unk_266[10] = 2;

            if (gSaveContext.eventChkInf[0] & 0x200) {
                pauseCtx->unk_266[10] = 1;
            }

            if (gSaveContext.eventChkInf[6] & 0x4000) {
                pauseCtx->unk_266[10] = 2;
            }

            if (gSaveContext.eventChkInf[0] & 0x8000) {
                pauseCtx->unk_266[10] = 1;
            }

            if (CHECK_QUEST_ITEM(QUEST_SONG_LULLABY)) {
                pauseCtx->unk_266[11] = 1;
            }

            if (gSaveContext.eventChkInf[2] & 0x20) {
                pauseCtx->unk_266[11] = 2;
            }

            if (gSaveContext.eventChkInf[3] & 0x80) {
                pauseCtx->unk_266[11] = 1;
            }

            if (INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT) {
                pauseCtx->unk_266[11] = 2;
            }

            if (CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1)) {
                pauseCtx->unk_266[11] = 1;
            }

            pauseCtx->unk_27A = 0xFF;

            i = INV_CONTENT(ITEM_TRADE_ADULT);
            if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
                if ((i <= ITEM_POCKET_CUCCO) || (i == ITEM_ODD_MUSHROOM)) {
                    pauseCtx->unk_27A = 8;
                }
                if ((i == ITEM_COJIRO) || (i == ITEM_ODD_POTION)) {
                    pauseCtx->unk_27A = 9;
                }
                if (i == ITEM_SAW) {
                    pauseCtx->unk_27A = 2;
                }
                if ((i == ITEM_SWORD_BROKEN) || (i == ITEM_EYEDROPS)) {
                    pauseCtx->unk_27A = 7;
                }
                if (i == ITEM_PRESCRIPTION) {
                    pauseCtx->unk_27A = 11;
                }
                if (i == ITEM_FROG) {
                    pauseCtx->unk_27A = 3;
                }
                if ((i == ITEM_CLAIM_CHECK) && (gSaveContext.bgsFlag == 0)) {
                    pauseCtx->unk_27A = 7;
                }
            }

            pauseCtx->state = 4;
            break;

        case 1:
            if (pauseCtx->unk_1F4 == 160.0f) {
                func_8081FABC(globalCtx);
                func_8081F2FC();
            }

            pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 -= (160.0f / WREG(6));
            pauseCtx->unk_25A += (40 / WREG(6));
            interfaceCtx->startAlpha += (255 / WREG(6));
            WREG(16) += WREG(25) / WREG(6);
            WREG(17) += WREG(26) / WREG(6);
            XREG(5) += (150 / WREG(6));
            pauseCtx->unk_208 += (u16)(255 / (WREG(6) + WREG(4)));

            if (pauseCtx->unk_1F4 == 0) {
                interfaceCtx->startAlpha = 255;
                WREG(2) = 0;
                pauseCtx->state = 5;
            }

            func_808265BC(globalCtx);
            break;

        case 2:
            pauseCtx->unk_208 += (u16)(255 / (WREG(6) + WREG(4)));
            func_808265BC(globalCtx);
            if (pauseCtx->state == 6) {
                func_80823548(globalCtx);
            }
            break;

        case 3:
            switch (pauseCtx->unk_1E4) {
                case 0:
                    if (CHECK_BTN_ALL(input->press.button, BTN_START)) {
                        Interface_SetDoAction(globalCtx, 10);
                        pauseCtx->state = 0x12;
                        WREG(2) = -6240;
                        func_800F64E0(0);
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
                        pauseCtx->mode = 0;
                        pauseCtx->unk_262 = 0;
                        Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                        gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                            gSaveContext.buttonStatus[3] = BTN_DISABLED;
                        gSaveContext.buttonStatus[4] = BTN_ENABLED;
                        gSaveContext.unk_13EA = 0;
                        Interface_ChangeAlpha(50);
                        pauseCtx->unk_1EC = 0;
                        pauseCtx->state = 7;
                    }
                    break;

                case 1:
                    func_808237B4(globalCtx, globalCtx->state.input);
                    break;

                case 2:
                    pauseCtx->unk_194 = func_800EE3F8();
                    if (pauseCtx->unk_194[1] == 0) {
                        pauseCtx->unk_1E4 = 4;
                        func_800ED858(0);
                    }
                    break;

                case 3:
                    func_8081AD44(globalCtx);
                    break;

                case 4:
                    break;

                case 5:
                    pauseCtx->unk_194 = func_800EE3D4();

                    if (CHECK_BTN_ALL(input->press.button, BTN_START)) {
                        func_800ED858(0);
                        Interface_SetDoAction(globalCtx, 10);
                        pauseCtx->state = 0x12;
                        WREG(2) = -6240;
                        func_800F64E0(0);
                        pauseCtx->unk_1E4 = 0;
                        break;
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
                        func_800ED858(0);
                        pauseCtx->unk_1E4 = 0;
                        pauseCtx->mode = 0;
                        pauseCtx->unk_262 = 0;
                        Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                        gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                            gSaveContext.buttonStatus[3] = BTN_DISABLED;
                        gSaveContext.buttonStatus[4] = BTN_ENABLED;
                        gSaveContext.unk_13EA = 0;
                        Interface_ChangeAlpha(50);
                        pauseCtx->unk_1EC = 0;
                        pauseCtx->state = 7;
                    } else if (pauseCtx->unk_194[1] == pauseCtx->unk_264) {
                        Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                        D_8082B258 = 0;
                        D_8082B25C = 30;
                        pauseCtx->unk_1E4 = 6;
                    } else if (pauseCtx->unk_194[1] == 0xFF) {
                        Audio_PlaySoundGeneral(NA_SE_SY_OCARINA_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                        D_8082B258 = 4;
                        D_8082B25C = 20;
                        pauseCtx->unk_1E4 = 6;
                    }
                    break;

                case 6:
                    D_8082B25C--;
                    if (D_8082B25C == 0) {
                        pauseCtx->unk_1E4 = D_8082B258;
                        if (pauseCtx->unk_1E4 == 0) {
                            func_800ED858(0);
                        }
                    }
                    break;

                case 7:
                    break;

                case 8:
                    if (CHECK_BTN_ALL(input->press.button, BTN_START)) {
                        func_800ED858(0);
                        Interface_SetDoAction(globalCtx, 10);
                        pauseCtx->state = 0x12;
                        WREG(2) = -6240;
                        func_800F64E0(0);
                        pauseCtx->unk_1E4 = 0;
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_B)) {
                        func_800ED858(0);
                        pauseCtx->unk_1E4 = 0;
                        pauseCtx->mode = 0;
                        pauseCtx->unk_262 = 0;
                        Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                        gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                            gSaveContext.buttonStatus[3] = BTN_DISABLED;
                        gSaveContext.buttonStatus[4] = BTN_ENABLED;
                        gSaveContext.unk_13EA = 0;
                        Interface_ChangeAlpha(50);
                        pauseCtx->unk_1EC = 0;
                        pauseCtx->state = 7;
                    }
                    break;

                case 9:
                    break;

                default:
                    pauseCtx->unk_1E4 = 0;
                    break;
            }
            break;

        case 4:
            switch (pauseCtx->unk_1EC) {
                case 0:
                    pauseCtx->unk_204 -= 314.0f / WREG(6);
                    WREG(16) -= WREG(25) / WREG(6);
                    WREG(17) -= WREG(26) / WREG(6);
                    if (pauseCtx->unk_204 <= -628.0f) {
                        pauseCtx->unk_204 = -628.0f;
                        pauseCtx->unk_1EC = 1;
                    }
                    break;

                case 1:
                    if (CHECK_BTN_ALL(input->press.button, BTN_A)) {
                        if (pauseCtx->unk_262 != 0) {
                            Interface_SetDoAction(globalCtx, 10);
                            gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                                gSaveContext.buttonStatus[3] = BTN_ENABLED;
                            gSaveContext.unk_13EA = 0;
                            Interface_ChangeAlpha(50);
                            pauseCtx->unk_1EC = 2;
                            WREG(2) = -6240;
                            YREG(8) = pauseCtx->unk_204;
                            func_800F64E0(0);
                        } else {
                            Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &D_801333E8);
                            Gameplay_SaveSceneFlags(globalCtx);
                            gSaveContext.savedSceneNum = globalCtx->sceneNum;
                            Sram_WriteSave(&globalCtx->sramCtx);
                            pauseCtx->unk_1EC = 4;
                            D_8082B25C = 3;
                        }
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_START) ||
                               CHECK_BTN_ALL(input->press.button, BTN_B)) {
                        Interface_SetDoAction(globalCtx, 10);
                        pauseCtx->unk_1EC = 2;
                        WREG(2) = -6240;
                        YREG(8) = pauseCtx->unk_204;
                        func_800F64E0(0);
                        gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                            gSaveContext.buttonStatus[3] = BTN_ENABLED;
                        gSaveContext.unk_13EA = 0;
                        Interface_ChangeAlpha(50);
                    }
                    break;

                case 4:
                    if (CHECK_BTN_ALL(input->press.button, BTN_B) || CHECK_BTN_ALL(input->press.button, BTN_A) ||
                        CHECK_BTN_ALL(input->press.button, BTN_START) || (--D_8082B25C == 0)) {
                        Interface_SetDoAction(globalCtx, 10);
                        gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] =
                            gSaveContext.buttonStatus[3] = BTN_ENABLED;
                        gSaveContext.unk_13EA = 0;
                        Interface_ChangeAlpha(50);
                        pauseCtx->unk_1EC = 5;
                        WREG(2) = -6240;
                        YREG(8) = pauseCtx->unk_204;
                        func_800F64E0(0);
                    }
                    break;

                case 3:
                case 6:
                    pauseCtx->unk_204 += 314.0f / WREG(6);
                    WREG(16) += WREG(25) / WREG(6);
                    WREG(17) += WREG(26) / WREG(6);
                    if (pauseCtx->unk_204 >= -314.0f) {
                        pauseCtx->state = 6;
                        pauseCtx->unk_1EC = 0;
                        pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 = 0.0f;
                        pauseCtx->unk_204 = -314.0f;
                    }
                    break;

                case 2:
                case 5:
                    if (pauseCtx->unk_204 != (YREG(8) + 160.0f)) {
                        pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 +=
                            160.0f / WREG(6);
                        pauseCtx->unk_204 += 160.0f / WREG(6);
                        pauseCtx->unk_25A -= 40 / WREG(6);
                        WREG(16) -= WREG(25) / WREG(6);
                        WREG(17) -= WREG(26) / WREG(6);
                        XREG(5) -= 150 / (WREG(6));
                        pauseCtx->unk_208 -= (u16)(255 / WREG(6));
                        if (pauseCtx->unk_204 == (YREG(8) + 160.0f)) {
                            pauseCtx->unk_208 = 0;
                        }
                    } else {
                        pauseCtx->flag = 0;
                        pauseCtx->state = 0x13;
                        pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 = 160.0f;
                        pauseCtx->unk_23C = 999;
                        pauseCtx->unk_1E4 = 0;
                        pauseCtx->unk_204 = -434.0f;
                    }
                    break;
            }
            break;

        case 7:
            pauseCtx->cursorSlotCopy[1] = pauseCtx->cursorSlot[1] = pauseCtx->unk_236 = VREG(30) + 3;
            WREG(16) = -175;
            WREG(17) = 155;
            pauseCtx->unk_204 = -434.0f;
            Interface_ChangeAlpha(1);

            pauseCtx->unk_128 = (void*)(((u32)globalCtx->objectCtx.spaceStart + 0x30) & ~0x3F);
            size0 = (u32)_icon_item_staticSegmentRomEnd - (u32)_icon_item_staticSegmentRomStart;
            osSyncPrintf("icon_item size0=%x\n", size0);
            DmaMgr_SendRequest1(pauseCtx->unk_128, (u32)_icon_item_staticSegmentRomStart, size0,
                                "../z_kaleido_scope_PAL.c", 4356);

            pauseCtx->unk_12C = (void*)(((u32)pauseCtx->unk_128 + size0 + 0xF) & ~0xF);
            size = (u32)_icon_item_24_staticSegmentRomEnd - (u32)_icon_item_24_staticSegmentRomStart;
            osSyncPrintf("icon_item24 size=%x\n", size);
            DmaMgr_SendRequest1(pauseCtx->unk_12C, (u32)_icon_item_24_staticSegmentRomStart, size,
                                "../z_kaleido_scope_PAL.c", 4363);

            pauseCtx->unk_130 = (void*)(((u32)pauseCtx->unk_12C + size + 0xF) & ~0xF);
            size2 = (u32)_icon_item_gameover_staticSegmentRomEnd - (u32)_icon_item_gameover_staticSegmentRomStart;
            osSyncPrintf("icon_item_dungeon gameover-size2=%x\n", size2);
            DmaMgr_SendRequest1(pauseCtx->unk_130, (u32)_icon_item_gameover_staticSegmentRomStart, size2,
                                "../z_kaleido_scope_PAL.c", 4370);

            pauseCtx->unk_134 = (void*)(((u32)pauseCtx->unk_130 + size2 + 0xF) & ~0xF);

            if (gSaveContext.language == 0) {
                size = (u32)_icon_item_nes_staticSegmentRomEnd - (u32)_icon_item_nes_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, (u32)_icon_item_nes_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 4379);
            } else if (gSaveContext.language == 1) {
                size = (u32)_icon_item_ger_staticSegmentRomEnd - (u32)_icon_item_ger_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, (u32)_icon_item_ger_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 4386);
            } else {
                size = (u32)_icon_item_fra_staticSegmentRomEnd - (u32)_icon_item_fra_staticSegmentRomStart;
                osSyncPrintf("icon_item_dungeon dungeon-size=%x\n", size);
                DmaMgr_SendRequest1(pauseCtx->unk_134, (u32)_icon_item_fra_staticSegmentRomStart, size,
                                    "../z_kaleido_scope_PAL.c", 4393);
            }

            D_8082AB8C = 255;
            D_8082AB90 = 130;
            D_8082AB94 = 0;
            D_8082AB98 = 0;
            D_8082AB9C = 30;
            D_8082ABA0 = 0;
            D_8082ABA4 = 0;
            D_8082B260 = 30;
            VREG(88) = 98;
            pauseCtx->unk_262 = 0;
            pauseCtx->state++;
            break;

        case 8:
            temp1 = ABS(D_8082AB8C - 30) / D_8082B260;
            temp2 = ABS(D_8082AB90) / D_8082B260;
            temp3 = ABS(D_8082AB94) / D_8082B260;
            temp4 = ABS(D_8082AB98 - 255) / D_8082B260;
            if (D_8082AB8C >= 30) {
                D_8082AB8C -= temp1;
            } else {
                D_8082AB8C += temp1;
            }
            if (D_8082AB90 >= 0) {
                D_8082AB90 -= temp2;
            } else {
                D_8082AB90 += temp2;
            }
            if (D_8082AB94 >= 0) {
                D_8082AB94 -= temp3;
            } else {
                D_8082AB94 += temp3;
            }
            if (D_8082AB98 >= 255) {
                D_8082AB98 -= temp4;
            } else {
                D_8082AB98 += temp4;
            }

            temp1 = ABS(D_8082AB9C - 255) / D_8082B260;
            temp2 = ABS(D_8082ABA0 - 130) / D_8082B260;
            temp3 = ABS(D_8082ABA4) / D_8082B260;
            if (D_8082AB9C >= 255) {
                D_8082AB9C -= temp1;
            } else {
                D_8082AB9C += temp1;
            }
            if (D_8082ABA0 >= 130) {
                D_8082ABA0 -= temp2;
            } else {
                D_8082ABA0 += temp2;
            }
            if (D_8082ABA4 >= 0) {
                D_8082ABA4 -= temp3;
            } else {
                D_8082ABA4 += temp3;
            }

            D_8082B260--;
            if (D_8082B260 == 0) {
                D_8082AB8C = 30;
                D_8082AB90 = 0;
                D_8082AB94 = 0;
                D_8082AB98 = 255;
                D_8082AB9C = 255;
                D_8082ABA0 = 130;
                D_8082ABA4 = 0;
                pauseCtx->state++;
                D_8082B260 = 40;
            }
            break;

        case 9:
            D_8082B260--;
            if (D_8082B260 == 0) {
                pauseCtx->state = 0xD;
            }
            break;

        case 10:
            pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 = pauseCtx->unk_204 -=
                160.0f / WREG(6);
            pauseCtx->unk_25A += (40 / WREG(6));
            interfaceCtx->startAlpha += 255 / WREG(6);
            VREG(88) -= 3;
            WREG(16) += WREG(25) / WREG(6);
            WREG(17) += WREG(26) / WREG(6);
            XREG(5) += 150 / WREG(6);
            pauseCtx->unk_208 += (u16)(255 / (WREG(6) + WREG(4)));
            if (pauseCtx->unk_204 < -628.0f) {
                pauseCtx->unk_204 = -628.0f;
                interfaceCtx->startAlpha = 255;
                VREG(88) = 66;
                WREG(2) = 0;
                pauseCtx->unk_208 = 255;
                pauseCtx->state = 0xE;
                gSaveContext.deaths++;
                if (gSaveContext.deaths > 999) {
                    gSaveContext.deaths = 999;
                }
            }
            osSyncPrintf("kscope->angle_s = %f\n", pauseCtx->unk_204);
            break;

        case 11:
            if (CHECK_BTN_ALL(input->press.button, BTN_A)) {
                if (pauseCtx->unk_262 != 0) {
                    pauseCtx->unk_262 = 0;
                    Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                    pauseCtx->state = 0x10;
                    (*unk_10A20)++;
                } else {
                    Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                           &D_801333E8);
                    pauseCtx->unk_262 = 0;
                    Gameplay_SaveSceneFlags(globalCtx);
                    gSaveContext.savedSceneNum = globalCtx->sceneNum;
                    Sram_WriteSave(&globalCtx->sramCtx);
                    pauseCtx->state = 0xF;
                    D_8082B25C = 3;
                }
            }
            break;

        case 12:
            D_8082B25C--;
            if (D_8082B25C == 0) {
                pauseCtx->state = 0x10;
                (*unk_10A20)++;
            } else if ((D_8082B25C <= 80) &&
                       (CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START))) {
                pauseCtx->state = 0x10;
                (*unk_10A20)++;
                func_800F64E0(0);
            }
            break;

        case 13:
            if (CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START)) {
                if (pauseCtx->unk_262 == 0) {
                    Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                           &D_801333E8);
                    Gameplay_SaveSceneFlags(globalCtx);

                    switch (gSaveContext.entranceIndex) {
                        case 0x0000:
                        case 0x0004:
                        case 0x0028:
                        case 0x0169:
                        case 0x0165:
                        case 0x0010:
                        case 0x0082:
                        case 0x0037:
                        case 0x041B:
                        case 0x0008:
                        case 0x0088:
                        case 0x0486:
                        case 0x0098:
                        case 0x0467:
                        case 0x0179:
                            break;
                        case 0x040F:
                            gSaveContext.entranceIndex = 0x0000;
                            break;
                        case 0x040B:
                            gSaveContext.entranceIndex = 0x0004;
                            break;
                        case 0x0301:
                            gSaveContext.entranceIndex = 0x0028;
                            break;
                        case 0x000C:
                            gSaveContext.entranceIndex = 0x0169;
                            break;
                        case 0x0305:
                            gSaveContext.entranceIndex = 0x0165;
                            break;
                        case 0x0417:
                            gSaveContext.entranceIndex = 0x0010;
                            break;
                        case 0x008D:
                            gSaveContext.entranceIndex = 0x0082;
                            break;
                        case 0x0413:
                            gSaveContext.entranceIndex = 0x0037;
                            break;
                        case 0x041F:
                            gSaveContext.entranceIndex = 0x041B;
                            break;
                    }
                } else {
                    Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                }

                pauseCtx->state = 0x11;
            }
            break;

        case 14:
            if (interfaceCtx->unk_244 != 255) {
                interfaceCtx->unk_244 += 10;
                if (interfaceCtx->unk_244 >= 255) {
                    interfaceCtx->unk_244 = 255;
                    pauseCtx->state = 0;
                    R_UPDATE_RATE = 3;
                    R_PAUSE_MENU_MODE = 0;
                    func_800981B8(&globalCtx->objectCtx);
                    func_800418D0(&globalCtx->colCtx, globalCtx);
                    if (pauseCtx->unk_262 == 0) {
                        Gameplay_TriggerRespawn(globalCtx);
                        gSaveContext.respawnFlag = -2;
                        gSaveContext.nextTransition = 2;
                        gSaveContext.health = 0x30;
                        Audio_SetBGM(0xF000000A);
                        gSaveContext.healthAccumulator = 0;
                        gSaveContext.unk_13F0 = 0;
                        gSaveContext.unk_13F2 = 0;
                        osSyncPrintf(VT_FGCOL(YELLOW));
                        osSyncPrintf("MAGIC_NOW=%d ", gSaveContext.magic);
                        osSyncPrintf("Z_MAGIC_NOW_NOW=%d   →  ", gSaveContext.unk_13F6);
                        gSaveContext.unk_13F4 = 0;
                        gSaveContext.unk_13F6 = gSaveContext.magic;
                        gSaveContext.magicLevel = gSaveContext.magic = 0;
                        osSyncPrintf("MAGIC_NOW=%d ", gSaveContext.magic);
                        osSyncPrintf("Z_MAGIC_NOW_NOW=%d\n", gSaveContext.unk_13F6);
                        osSyncPrintf(VT_RST);
                    } else {
                        globalCtx->state.running = 0;
                        SET_NEXT_GAMESTATE(&globalCtx->state, Opening_Init, OpeningContext);
                    }
                }
            }
            break;

        case 15:
            if (pauseCtx->unk_1F4 != 160.0f) {
                pauseCtx->unk_1F4 = pauseCtx->unk_1F8 = pauseCtx->unk_1FC = pauseCtx->unk_200 += 160.0f / WREG(6);
                pauseCtx->unk_25A -= 40 / WREG(6);
                interfaceCtx->startAlpha -= 255 / WREG(6);
                WREG(16) -= WREG(25) / WREG(6);
                WREG(17) -= WREG(26) / WREG(6);
                XREG(5) -= 150 / (WREG(6));
                pauseCtx->unk_208 -= (u16)(255 / WREG(6));
                if (pauseCtx->unk_1F4 == 160.0f) {
                    pauseCtx->unk_208 = 0;
                }
            } else {
                pauseCtx->flag = 0;
                pauseCtx->state = 0x13;
                pauseCtx->unk_200 = 160.0f;
                pauseCtx->unk_1FC = 160.0f;
                pauseCtx->unk_1F8 = 160.0f;
                pauseCtx->unk_1F4 = 160.0f;
                pauseCtx->unk_23C = 999;
                globalCtx->interfaceCtx.startAlpha = 0;
            }
            break;

        case 16:
            pauseCtx->state = 0;
            R_UPDATE_RATE = 3;
            R_PAUSE_MENU_MODE = 0;
            func_800981B8(&globalCtx->objectCtx);
            func_800418D0(&globalCtx->colCtx, globalCtx);

            switch (globalCtx->sceneNum) {
                case SCENE_YDAN:
                case SCENE_DDAN:
                case SCENE_BDAN:
                case SCENE_BMORI1:
                case SCENE_HIDAN:
                case SCENE_MIZUSIN:
                case SCENE_JYASINZOU:
                case SCENE_HAKADAN:
                case SCENE_HAKADANCH:
                case SCENE_ICE_DOUKUTO:
                case SCENE_YDAN_BOSS:
                case SCENE_DDAN_BOSS:
                case SCENE_BDAN_BOSS:
                case SCENE_MORIBOSSROOM:
                case SCENE_FIRE_BS:
                case SCENE_MIZUSIN_BS:
                case SCENE_JYASINBOSS:
                case SCENE_HAKADAN_BS:
                    Map_InitData(globalCtx, globalCtx->interfaceCtx.mapRoomNum);
                    break;
            }

            gSaveContext.buttonStatus[0] = D_808321A8[0];
            gSaveContext.buttonStatus[1] = D_808321A8[1];
            gSaveContext.buttonStatus[2] = D_808321A8[2];
            gSaveContext.buttonStatus[3] = D_808321A8[3];
            gSaveContext.buttonStatus[4] = D_808321A8[4];
            interfaceCtx->unk_1FA = interfaceCtx->unk_1FC = 0;
            osSyncPrintf(VT_FGCOL(YELLOW));
            osSyncPrintf("i=%d  LAST_TIME_TYPE=%d\n", i, gSaveContext.unk_13EE);
            gSaveContext.unk_13EA = 0;
            Interface_ChangeAlpha(gSaveContext.unk_13EE);
            player->targetActor = NULL;
            Player_SetEquipmentData(globalCtx, player);
            osSyncPrintf(VT_RST);
            break;
    }
}
