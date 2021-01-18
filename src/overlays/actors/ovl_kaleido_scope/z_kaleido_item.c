#include "ultra64.h"
#include "global.h"

#define TARGET_ITEM_IS_MAGIC_ARROW \
    (pauseCtx->equipTargetItem >= ITEM_MGARROW_EQUIP_FIRE) && \
    (pauseCtx->equipTargetItem < ITEM_MGARROW_EQUIP_END)

#define BUTTON_ITEM_IS_MAGICARROW(n) \
    ((gSaveContext.equips.buttonItems[n] >= ITEM_BOW_ARROW_FIRE) \
    && (gSaveContext.equips.buttonItems[n] < (ITEM_BOW_ARROW_LIGHT + 1))) \
    
#define BUTTON_ITEM_IS_BOW_OR_MAGICARROW(n) \
    (gSaveContext.equips.buttonItems[n] == ITEM_BOW) || BUTTON_ITEM_IS_MAGICARROW(n)

// .data
//D_8082A420
u8 sSlotAmmoMap[] = {
    SLOT_STICK,    SLOT_NUT,  SLOT_BOMB, SLOT_BOW,  SLOT_NONE, SLOT_NONE, SLOT_SLINGSHOT,   SLOT_NONE,
    SLOT_HOOKSHOT, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_ARROW_LIGHT, SLOT_NONE,
};

s16 sEquipAnimState = 0; //D_8082A430

s16 sEquipAnimTimer = 0; //D_8082A434

s16 sEquipAnimNumFrames = 10; //D_8082A438

s16 sAmmoVertexOffset[] = {
    0, 2, 4, 6, 99, 99, 8, 99, 99, 10, 99, 99, 99, 99, 99, 99, 12,
};

void KaleidoScope_DrawInventoryAmmo(PauseContext* pauseCtx, GraphicsContext* gfxCtx, s16 item) {
    s16 ammo;
    s16 i;

    OPEN_DISPS(gfxCtx, "../z_kaleido_item.c", 69);

    ammo = AMMO(item);

    gDPPipeSync(POLY_OPA_DISP++);

    if (!((gSlotAgeReqs[SLOT(item)] == SLOT_AGE_EITHER) || gSlotAgeReqs[SLOT(item)] == ((void)0, gSaveContext.linkAge))) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 100, 100, pauseCtx->unk_208);
    } else {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);

        if (ammo == 0) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 130, 130, 130, pauseCtx->unk_208);
        } else if ((item == ITEM_BOMB && AMMO(item) == CUR_CAPACITY(UPG_BOMB_BAG)) ||
                   (item == ITEM_BOW && AMMO(item) == CUR_CAPACITY(UPG_QUIVER)) ||
                   (item == ITEM_SLINGSHOT && AMMO(item) == CUR_CAPACITY(UPG_BULLET_BAG)) ||
                   (item == ITEM_STICK && AMMO(item) == CUR_CAPACITY(UPG_STICKS)) ||
                   (item == ITEM_NUT && AMMO(item) == CUR_CAPACITY(UPG_NUTS)) || (item == ITEM_BOMBCHU && ammo == 50) ||
                   (item == ITEM_BEAN && ammo == 15)) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 120, 255, 0, pauseCtx->unk_208);
        }
    }

    for (i = 0; ammo >= 10; i++) {
        ammo -= 10;
    }

    gDPPipeSync(POLY_OPA_DISP++);

    if (i != 0) {
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[(sAmmoVertexOffset[item] + 0x1B) * 4], 4, 0);

        gDPSetTextureImage(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_020035C0[i]);
        gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(POLY_OPA_DISP++);
        gDPLoadBlock(POLY_OPA_DISP++, G_TX_LOADTILE, 0, 0, 31, 2048);
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(POLY_OPA_DISP++, G_TX_RENDERTILE, 0, 0, 28, 28);
        gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
    }

    gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[(sAmmoVertexOffset[item] + 0x1C) * 4], 4, 0);

    gDPSetTextureImage(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_020035C0[ammo]);
    gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(POLY_OPA_DISP++);
    gDPLoadBlock(POLY_OPA_DISP++, G_TX_LOADTILE, 0, 0, 31, 2048);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(POLY_OPA_DISP++, G_TX_RENDERTILE, 0, 0, 28, 28);
    gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);

    CLOSE_DISPS(gfxCtx, "../z_kaleido_item.c", 116);
}

void func_80819E14(PauseContext* pauseCtx, u16 arg1, Vtx* arg2) {
    pauseCtx->vtx_168[0].v.ob[0] = arg2[arg1].v.ob[0];
    pauseCtx->vtx_168[0].v.ob[1] = arg2[arg1].v.ob[1];
}

void func_80819E40(PauseContext* pauseCtx) {
    func_80819E14(pauseCtx, pauseCtx->cursorSlotCopy[0] * 4, pauseCtx->vtx_158);
}

s16 D_8082A460[] = { 255, 100, 255 };

s16 D_8082A468[] = { 0, 100, 255 };

s16 D_8082A470[] = { 0, 255, 100 };

#ifdef NON_MATCHING
void func_80819E6C(GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input[0];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    u16 i;
    u16 v;
    u16 cursorItem; //"ccc"
    u16 cursorSlot;
    s16 moveCursorResult; //"ok_fg"
    s16 oldCursorSlot;
    s16 oldCursorX;
    s16 oldCursorY;
    s16 oldCursorSlot;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_item.c", 234);

    func_800949A8(globalCtx->state.gfxCtx);

    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    pauseCtx->unk_260 = 0;
    pauseCtx->unk_25E = 0;

    if ((pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0) && (pauseCtx->kscpPos == 0)) {
        moveCursorResult = 0;

        oldCursorSlot = pauseCtx->cursorSlot[0];
        cursorItem = pauseCtx->cursorItem[0];
        cursorSlot = pauseCtx->cursorSlotCopy[0];

        if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
            pauseCtx->unk_260 = 4;

            if (cursorItem == ITEM_CURSOR_INVALID) {
                pauseCtx->stickRelX = 40;
            }

            if (ABS(pauseCtx->stickRelX) > 30) {
                oldCursorSlot = pauseCtx->cursorSlot[0];
                oldCursorX = pauseCtx->cursorX[0];
                oldCursorY = pauseCtx->cursorY[0];

                osSyncPrintf("now=%d  ccc=%d\n", oldCursorSlot, cursorItem);

                while (moveCursorResult == 0) {
                    if (pauseCtx->stickRelX < -30) {
                        if (pauseCtx->cursorX[0] != 0) {
                            pauseCtx->cursorX[0] = pauseCtx->cursorX[0] - 1;
                            pauseCtx->cursorSlot[0] = pauseCtx->cursorSlot[0] - 1;

                            if (gSaveContext.inventory.items[pauseCtx->cursorSlot[0]] != ITEM_NONE) {
                                moveCursorResult = 1;
                            }
                        } else {
                            pauseCtx->cursorX[0] = oldCursorX;
                            pauseCtx->cursorY[0] = pauseCtx->cursorY[0] + 1;

                            if (pauseCtx->cursorY[0] >= 4) {
                                pauseCtx->cursorY[0] = 0;
                            }

                            pauseCtx->cursorSlot[0] = (pauseCtx->cursorY[0] * 6) + pauseCtx->cursorX[0];

                            if (pauseCtx->cursorSlot[0] >= 24) {
                                pauseCtx->cursorSlot[0] = pauseCtx->cursorX[0];
                            }

                            if (oldCursorY == pauseCtx->cursorY[0]) {
                                pauseCtx->cursorX[0] = oldCursorX;
                                pauseCtx->cursorSlot[0] = oldCursorSlot;

                                KaleidoScope_MoveCursorToSpecialPos(globalCtx, KSCP_CURSOR_SPECIAL_PAGELEFT);

                                moveCursorResult = 2;
                            }
                        }
                    } else if (pauseCtx->stickRelX > 30) {
                        if (pauseCtx->cursorX[0] < 5) {
                            pauseCtx->cursorX[0] = pauseCtx->cursorX[0] + 1;
                            pauseCtx->cursorSlot[0] = pauseCtx->cursorSlot[0] + 1;

                            if (gSaveContext.inventory.items[pauseCtx->cursorSlot[0]] != ITEM_NONE) {
                                moveCursorResult = 1;
                            }
                        } else {
                            pauseCtx->cursorX[0] = oldCursorX;
                            pauseCtx->cursorY[0] = pauseCtx->cursorY[0] + 1;

                            if (pauseCtx->cursorY[0] >= 4) {
                                pauseCtx->cursorY[0] = 0;
                            }

                            pauseCtx->cursorSlot[0] = (pauseCtx->cursorY[0] * 6) + pauseCtx->cursorX[0];

                            if (pauseCtx->cursorSlot[0] >= 24) {
                                pauseCtx->cursorSlot[0] = pauseCtx->cursorX[0];
                            }

                            if (oldCursorY == pauseCtx->cursorY[0]) {
                                pauseCtx->cursorX[0] = oldCursorX;
                                pauseCtx->cursorSlot[0] = oldCursorSlot;

                                KaleidoScope_MoveCursorToSpecialPos(globalCtx, KSCP_CURSOR_SPECIAL_PAGERIGHT);

                                moveCursorResult = 2;
                            }
                        }
                    }
                }

                if (moveCursorResult == 1) {
                    cursorItem = gSaveContext.inventory.items[pauseCtx->cursorSlot[0]];
                }

                osSyncPrintf("【Ｘ cursor=%d(%) (cur_xpt=%d)(ok_fg=%d)(ccc=%d)(key_angle=%d)】  ", pauseCtx->cursorSlot[0],
                             pauseCtx->cursorX[0], moveCursorResult, cursorItem, pauseCtx->cursorSpecialPos);
            }
        } else if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_SPECIAL_PAGELEFT) {
            if (pauseCtx->stickRelX > 30) {
                pauseCtx->unk_25C = 0;
                pauseCtx->cursorSpecialPos = KSCP_CURSOR_NORMAL;

                Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

                oldCursorSlot = 0;
                oldCursorX = 0;
                oldCursorY = 0;
                while (true) {
                    if (gSaveContext.inventory.items[oldCursorSlot] != ITEM_NONE) {
                        pauseCtx->cursorSlot[0] = oldCursorSlot;
                        pauseCtx->cursorX[0] = oldCursorX;
                        pauseCtx->cursorY[0] = oldCursorY;
                        moveCursorResult = 1;
                        break;
                    } else {
                        oldCursorY = oldCursorY + 1;
                        oldCursorSlot = oldCursorSlot + 6;
                        if (oldCursorY < 4) {
                            continue;
                        }

                        oldCursorY = 0;
                        oldCursorSlot = oldCursorX + 1;
                        oldCursorX = oldCursorSlot;
                        if (oldCursorX < 6) {
                            continue;
                        }

                        KaleidoScope_MoveCursorToSpecialPos(globalCtx, KSCP_CURSOR_SPECIAL_PAGERIGHT);
                        break;
                    }
                }
            }
        } else {
            if (pauseCtx->stickRelX < -30) {
                pauseCtx->unk_25C = 0;
                pauseCtx->cursorSpecialPos = KSCP_CURSOR_NORMAL;

                Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

                oldCursorSlot = 5;
                oldCursorX = 5;
                oldCursorY = 0;
                while (true) {
                    if (gSaveContext.inventory.items[oldCursorSlot] != ITEM_NONE) {
                        pauseCtx->cursorSlot[0] = oldCursorSlot;
                        pauseCtx->cursorX[0] = oldCursorX;
                        pauseCtx->cursorY[0] = oldCursorY;
                        moveCursorResult = 1;
                        break;
                    } else {
                        oldCursorY = oldCursorY + 1;
                        oldCursorSlot = oldCursorSlot + 6;
                        if (oldCursorY < 4) {
                            continue;
                        }

                        oldCursorY = 0;
                        oldCursorSlot = oldCursorX - 1;
                        oldCursorX = oldCursorSlot;
                        if (oldCursorX >= 0) {
                            continue;
                        }

                        KaleidoScope_MoveCursorToSpecialPos(globalCtx, KSCP_CURSOR_SPECIAL_PAGELEFT);
                        break;
                    }
                }
            }
        }

        if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
            if (cursorItem != ITEM_CURSOR_INVALID) {
                if (ABS(pauseCtx->stickRelY) > 30) {
                    moveCursorResult = 0;
                    oldCursorSlot = pauseCtx->cursorSlot[0];
                    oldCursorY = pauseCtx->cursorY[0];
                    while (moveCursorResult == 0) {
                        if (pauseCtx->stickRelY > 30) {
                            if (pauseCtx->cursorY[0] != 0) {
                                pauseCtx->cursorY[0] = pauseCtx->cursorY[0] - 1;
                                pauseCtx->cursorSlot[0] = pauseCtx->cursorSlot[0] - 6;

                                if (gSaveContext.inventory.items[pauseCtx->cursorSlot[0]] != ITEM_NONE) {
                                    moveCursorResult = 1;
                                }
                            } else {
                                pauseCtx->cursorY[0] = oldCursorY;
                                pauseCtx->cursorSlot[0] = oldCursorSlot;

                                moveCursorResult = 2;
                            }
                        } else if (pauseCtx->stickRelY < -30) {
                            if (pauseCtx->cursorY[0] < 3) {
                                pauseCtx->cursorY[0] = pauseCtx->cursorY[0] + 1;
                                pauseCtx->cursorSlot[0] = pauseCtx->cursorSlot[0] + 6;

                                if (gSaveContext.inventory.items[pauseCtx->cursorSlot[0]] != ITEM_NONE) {
                                    moveCursorResult = 1;
                                }
                            } else {
                                pauseCtx->cursorY[0] = oldCursorY;
                                pauseCtx->cursorSlot[0] = oldCursorSlot;

                                moveCursorResult = 2;
                            }
                        }
                    }

                    osSyncPrintf("【Ｙ cursor=%d(%) (cur_ypt=%d)(ok_fg=%d)(ccc=%d)】  ", pauseCtx->cursorSlot[0],
                                 pauseCtx->cursorY[0], moveCursorResult, cursorItem);
                }
            }

            cursorSlot = pauseCtx->cursorSlot[0];

            pauseCtx->unk_260 = 4;

            if (moveCursorResult == 1) {
                cursorItem = gSaveContext.inventory.items[pauseCtx->cursorSlot[0]];
            } else if (moveCursorResult != 2) {
                cursorItem = gSaveContext.inventory.items[pauseCtx->cursorSlot[0]];
            }

            pauseCtx->cursorItem[0] = cursorItem;
            pauseCtx->cursorSlotCopy[0] = cursorSlot;

            if (!((gSlotAgeReqs[cursorSlot] == SLOT_AGE_EITHER) || (gSlotAgeReqs[cursorSlot] == ((void)0, gSaveContext.linkAge)))) {
                pauseCtx->unk_25E = 1;
            }

            if (cursorItem != ITEM_CURSOR_INVALID) {
                func_80819E14(pauseCtx, cursorSlot * 4, pauseCtx->vtx_158);

                if ((pauseCtx->flag == 0) && (pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0)) {
                    if (CHECK_BTN_ANY(input->press.button, BTN_CLEFT | BTN_CDOWN | BTN_CRIGHT)) {
                        if (((gSlotAgeReqs[cursorSlot] == SLOT_AGE_EITHER) || (gSlotAgeReqs[cursorSlot] == gSaveContext.linkAge)) &&
                            (cursorItem != ITEM_SOLD_OUT)) {
                            if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
                                pauseCtx->equipTargetCBtn = 0;
                            } else if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
                                pauseCtx->equipTargetCBtn = 1;
                            } else if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
                                pauseCtx->equipTargetCBtn = 2;
                            }

                            pauseCtx->equipTargetItem = cursorItem;
                            pauseCtx->equipTargetSlot = cursorSlot;
                            pauseCtx->unk_1E4 = 3;
                            pauseCtx->equipAnimX = pauseCtx->vtx_158[cursorSlot * 4].v.ob[0] * 10;
                            pauseCtx->equipAnimY = pauseCtx->vtx_158[cursorSlot * 4].v.ob[1] * 10;
                            pauseCtx->equipAnimAlpha = 255;
                            sEquipAnimTimer = 0;
                            sEquipAnimState = 3;
                            sEquipAnimNumFrames = 10;
                            if ((pauseCtx->equipTargetItem == ITEM_ARROW_FIRE) || (pauseCtx->equipTargetItem == ITEM_ARROW_ICE) ||
                                (pauseCtx->equipTargetItem == ITEM_ARROW_LIGHT)) {
                                i = 0;
                                if (pauseCtx->equipTargetItem == ITEM_ARROW_ICE) {
                                    i = 1;
                                }
                                if (pauseCtx->equipTargetItem == ITEM_ARROW_LIGHT) {
                                    i = 2;
                                }
                                Audio_PlaySoundGeneral(NA_SE_SY_SET_FIRE_ARROW + i, &D_801333D4, 4, &D_801333E0,
                                                       &D_801333E0, &D_801333E8);
                                pauseCtx->equipTargetItem = ITEM_MGARROW_EQUIP_FIRE + i;
                                sEquipAnimState = 0;
                                pauseCtx->equipAnimAlpha = 0;
                                sEquipAnimNumFrames = 6;
                            } else {
                                Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                       &D_801333E8);
                            }
                        } else {
                            Audio_PlaySoundGeneral(NA_SE_SY_ERROR, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                                   &D_801333E8);
                        }
                    }
                }
            } else {
                pauseCtx->vtx_168[0].v.ob[0] = pauseCtx->vtx_168[2].v.ob[0] = pauseCtx->vtx_168[1].v.ob[0] =
                    pauseCtx->vtx_168[3].v.ob[0] = 0;

                pauseCtx->vtx_168[0].v.ob[1] = pauseCtx->vtx_168[1].v.ob[1] = pauseCtx->vtx_168[2].v.ob[1] =
                    pauseCtx->vtx_168[3].v.ob[1] = -200;
            }
        } else {
            pauseCtx->cursorItem[0] = ITEM_CURSOR_INVALID;
        }

        if (oldCursorSlot != pauseCtx->cursorSlot[0]) {
            Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((pauseCtx->unk_1E4 == 3) && (pauseCtx->kscpPos == 0)) {
        func_80819E14(pauseCtx, cursorSlot * 4, pauseCtx->vtx_158);
        pauseCtx->unk_260 = 4;
    }

    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

    for (i = 0, v = 96; i < 3; i++, v += 4) {
        if (gSaveContext.equips.buttonItems[i + 1] != ITEM_NONE) {
            gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[v], 4, 0);
            POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, &D_02000A00[1], 32, 32, 0);
        }
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    for (i = 0, v = 0; i < 24; i++, v += 4) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);

        if (gSaveContext.inventory.items[i] != ITEM_NONE) {
            if ((pauseCtx->unk_1E4 == 0) && (pauseCtx->kscpPos == 0) && (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL)) {
                if ((gSlotAgeReqs[i] == SLOT_AGE_EITHER) || (gSlotAgeReqs[i] == gSaveContext.linkAge)) {
                    if ((sEquipAnimState == 2) && (i == 3)) {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082A460[pauseCtx->equipTargetItem - ITEM_MGARROW_EQUIP_FIRE],
                                        D_8082A468[pauseCtx->equipTargetItem - ITEM_MGARROW_EQUIP_FIRE], D_8082A470[pauseCtx->equipTargetItem - ITEM_MGARROW_EQUIP_FIRE],
                                        pauseCtx->unk_208);

                        pauseCtx->vtx_158[v + 0].v.ob[0] = pauseCtx->vtx_158[v + 2].v.ob[0] =
                            pauseCtx->vtx_158[v + 0].v.ob[0] - 2;

                        pauseCtx->vtx_158[v + 1].v.ob[0] = pauseCtx->vtx_158[v + 3].v.ob[0] =
                            pauseCtx->vtx_158[v + 0].v.ob[0] + 32;

                        pauseCtx->vtx_158[v + 0].v.ob[1] = pauseCtx->vtx_158[v + 1].v.ob[1] =
                            pauseCtx->vtx_158[v + 0].v.ob[1] + 2;

                        pauseCtx->vtx_158[v + 2].v.ob[1] = pauseCtx->vtx_158[v + 3].v.ob[1] =
                            pauseCtx->vtx_158[v + 0].v.ob[1] - 32;
                    } else if (cursorSlot == i) {
                        pauseCtx->vtx_158[v + 0].v.ob[0] = pauseCtx->vtx_158[v + 2].v.ob[0] =
                            pauseCtx->vtx_158[v + 0].v.ob[0] - 2;

                        pauseCtx->vtx_158[v + 1].v.ob[0] = pauseCtx->vtx_158[v + 3].v.ob[0] =
                            pauseCtx->vtx_158[v + 0].v.ob[0] + 32;

                        pauseCtx->vtx_158[v + 0].v.ob[1] = pauseCtx->vtx_158[v + 1].v.ob[1] =
                            pauseCtx->vtx_158[v + 0].v.ob[1] + 2;

                        pauseCtx->vtx_158[v + 2].v.ob[1] = pauseCtx->vtx_158[v + 3].v.ob[1] =
                            pauseCtx->vtx_158[v + 0].v.ob[1] - 32;
                    }
                }
            }

            gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[v], 4, 0);
            func_8081F87C(globalCtx->state.gfxCtx, gItemIcons[gSaveContext.inventory.items[i]], 32, 32, 0);
        }
    }

    if (pauseCtx->cursorSpecialPos == KSCP_CURSOR_NORMAL) {
        func_8081FE30(globalCtx, 0);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

    for (i = 0; i < 15; i++) {
        if ((sSlotAmmoMap[i] != SLOT_NONE) && (gSaveContext.inventory.items[i] != ITEM_NONE)) {
            KaleidoScope_DrawInventoryAmmo(pauseCtx, globalCtx->state.gfxCtx, gSaveContext.inventory.items[i]);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_item.c", 516);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80819E6C.s")
#endif

s16 D_8082A478[] = { 660, 900, 1140 };

s16 D_8082A480[] = { 1100, 920, 1100 };

void func_8081AD44(GlobalContext* globalCtx) {
    static s16 D_8082A488 = 0;
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    Vtx* vtx;
    u16 phi_a2;
    u16 phi_a1;

    if (sEquipAnimState == 0) {
        pauseCtx->equipAnimAlpha += 0xE;
        if (pauseCtx->equipAnimAlpha > 0xFF) {
            pauseCtx->equipAnimAlpha = 0xFE;
            sEquipAnimState++;
        }
        sEquipAnimTimer = 5;
        return;
    }

    if (sEquipAnimState == 2) {
        D_8082A488--;

        if (D_8082A488 == 0) {
            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
            pauseCtx->equipTargetSlot = SLOT_BOW;
            sEquipAnimNumFrames = 6;
            WREG(90) = 320;
            WREG(87) = WREG(91);
            sEquipAnimState++;
            Audio_PlaySoundGeneral(NA_SE_SY_SYNTH_MAGIC_ARROW, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
        return;
    }

    if (sEquipAnimState == 1) {
        vtx = &pauseCtx->vtx_158[12];
        phi_a2 = ABS(pauseCtx->equipAnimX - vtx->v.ob[0] * 10) / sEquipAnimNumFrames;
        phi_a1 = ABS(pauseCtx->equipAnimY - vtx->v.ob[1] * 10) / sEquipAnimNumFrames;
    } else {
        phi_a2 = ABS(pauseCtx->equipAnimX - D_8082A478[pauseCtx->equipTargetCBtn]) / sEquipAnimNumFrames;
        phi_a1 = ABS(pauseCtx->equipAnimY - D_8082A480[pauseCtx->equipTargetCBtn]) / sEquipAnimNumFrames;
    }

    if (pauseCtx->equipTargetItem >= ITEM_MGARROW_EQUIP_FIRE) {
        if (pauseCtx->equipAnimAlpha < 0xFE) {
            pauseCtx->equipAnimAlpha += 0xE;
            if (pauseCtx->equipAnimAlpha >= 0x100) {
                pauseCtx->equipAnimAlpha = 0xFE;
            }
            sEquipAnimTimer = 5;
            return;
        }
    }

    if (sEquipAnimTimer == 0) {
        WREG(90) -= WREG(87) / sEquipAnimNumFrames;
        WREG(87) -= WREG(87) / sEquipAnimNumFrames;

        if (sEquipAnimState == 1) {
            if (pauseCtx->equipAnimX >= (pauseCtx->vtx_158[12].v.ob[0] * 10)) {
                pauseCtx->equipAnimX -= phi_a2;
            } else {
                pauseCtx->equipAnimX += phi_a2;
            }

            if (pauseCtx->equipAnimY >= (pauseCtx->vtx_158[12].v.ob[1] * 10)) {
                pauseCtx->equipAnimY -= phi_a1;
            } else {
                pauseCtx->equipAnimY += phi_a1;
            }
        } else {
            if (pauseCtx->equipAnimX >= D_8082A478[pauseCtx->equipTargetCBtn]) {
                pauseCtx->equipAnimX -= phi_a2;
            } else {
                pauseCtx->equipAnimX += phi_a2;
            }

            if (pauseCtx->equipAnimY >= D_8082A480[pauseCtx->equipTargetCBtn]) {
                pauseCtx->equipAnimY -= phi_a1;
            } else {
                pauseCtx->equipAnimY += phi_a1;
            }
        }

        sEquipAnimNumFrames--;

        if (sEquipAnimNumFrames == 0) {
            if (sEquipAnimState == 1) {
                sEquipAnimState++;
                D_8082A488 = 4;
                return;
            }

            osSyncPrintf("\n＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");

            if (pauseCtx->equipTargetCBtn == 0) {

                if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[1]) {
                    if (gSaveContext.equips.buttonItems[1] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(1)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[1];
                            gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[0];
                            Interface_LoadItemIcon2(globalCtx, 2);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[2] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[1] = SLOT_NONE;
                    }
                } else if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[2]) {
                    if (gSaveContext.equips.buttonItems[1] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(1)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[1];
                            gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[0];
                            Interface_LoadItemIcon2(globalCtx, 3);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[3] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[2] = SLOT_NONE;
                    }
                }

                if (TARGET_ITEM_IS_MAGIC_ARROW) {
                    if (BUTTON_ITEM_IS_BOW_OR_MAGICARROW(1)) {
                        pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                        pauseCtx->equipTargetSlot = SLOT_BOW;
                    }
                } else if (pauseCtx->equipTargetItem == ITEM_BOW) {
                    if (BUTTON_ITEM_IS_MAGICARROW(2)) {
                        gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[1];
                        gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[0];
                        Interface_LoadItemIcon2(globalCtx, 2);
                    } else if (BUTTON_ITEM_IS_MAGICARROW(3)) {
                        gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[1];
                        gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[0];
                        Interface_LoadItemIcon2(globalCtx, 3);
                    }
                }

                gSaveContext.equips.buttonItems[1] = pauseCtx->equipTargetItem;
                gSaveContext.equips.cButtonSlots[0] = pauseCtx->equipTargetSlot;
                Interface_LoadItemIcon1(globalCtx, 1);

                osSyncPrintf("Ｃ左sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetItem,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ左sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetSlot,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            } else if (pauseCtx->equipTargetCBtn == 1) {
                osSyncPrintf("Ｃ下sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetItem,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ下sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetSlot,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);

                if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[0]) {
                    if (gSaveContext.equips.buttonItems[2] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(2)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[2];
                            gSaveContext.equips.cButtonSlots[0] = gSaveContext.equips.cButtonSlots[1];
                            Interface_LoadItemIcon2(globalCtx, 1);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[1] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[0] = SLOT_NONE;
                    }
                } else if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[2]) {
                    if (gSaveContext.equips.buttonItems[2] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(2)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[2];
                            gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[1];
                            Interface_LoadItemIcon2(globalCtx, 3);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[3] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[2] = SLOT_NONE;
                    }
                }

                if (TARGET_ITEM_IS_MAGIC_ARROW) {
                    if (BUTTON_ITEM_IS_BOW_OR_MAGICARROW(2)) {
                        pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                        pauseCtx->equipTargetSlot = SLOT_BOW;
                    }
                } else if (pauseCtx->equipTargetItem == 3) {
                    if (BUTTON_ITEM_IS_MAGICARROW(1)) {
                        gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[2];
                        Interface_LoadItemIcon2(globalCtx, 1);
                    } else if (BUTTON_ITEM_IS_MAGICARROW(3)) {
                        gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[2];
                        Interface_LoadItemIcon2(globalCtx, 3);
                    }
                }

                gSaveContext.equips.buttonItems[2] = pauseCtx->equipTargetItem;
                gSaveContext.equips.cButtonSlots[1] = pauseCtx->equipTargetSlot;
                Interface_LoadItemIcon1(globalCtx, 2);

                osSyncPrintf("Ｃ下sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetItem,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ下sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetSlot,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            } else {
                osSyncPrintf("Ｃ右sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetItem,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ右sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetSlot,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);

                if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[0]) {
                    if (gSaveContext.equips.buttonItems[3] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(3)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[3];
                            gSaveContext.equips.cButtonSlots[0] = gSaveContext.equips.cButtonSlots[2];
                            Interface_LoadItemIcon2(globalCtx, 1);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[1] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[0] = SLOT_NONE;
                    }
                } else if (pauseCtx->equipTargetSlot == gSaveContext.equips.cButtonSlots[1]) {
                    if (gSaveContext.equips.buttonItems[3] != ITEM_NONE) {
                        if (TARGET_ITEM_IS_MAGIC_ARROW && BUTTON_ITEM_IS_BOW_OR_MAGICARROW(3)) {
                            pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                            pauseCtx->equipTargetSlot = SLOT_BOW;
                        } else {
                            gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[3];
                            gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[2];
                            Interface_LoadItemIcon2(globalCtx, 2);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[2] = ITEM_NONE;
                        gSaveContext.equips.cButtonSlots[1] = SLOT_NONE;
                    }
                }

                if (TARGET_ITEM_IS_MAGIC_ARROW) {
                    if (BUTTON_ITEM_IS_BOW_OR_MAGICARROW(3)) {
                        pauseCtx->equipTargetItem -= ITEM_MGARROW_EQUIP_OFFSET;
                        pauseCtx->equipTargetSlot = SLOT_BOW;
                    }
                } else if (pauseCtx->equipTargetItem == ITEM_BOW) {
                    if (BUTTON_ITEM_IS_MAGICARROW(1)) {
                        gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[3];
                        Interface_LoadItemIcon2(globalCtx, 1);
                    } else if (BUTTON_ITEM_IS_MAGICARROW(2)) {
                        gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[3];
                        Interface_LoadItemIcon2(globalCtx, 2);
                    }
                }

                gSaveContext.equips.buttonItems[3] = pauseCtx->equipTargetItem;
                gSaveContext.equips.cButtonSlots[2] = pauseCtx->equipTargetSlot;
                Interface_LoadItemIcon1(globalCtx, 3);

                osSyncPrintf("Ｃ右sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetItem,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ右sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->equipTargetSlot,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            }

            pauseCtx->unk_1E4 = 0;
            sEquipAnimNumFrames = 10;
            WREG(90) = 320;
            WREG(87) = WREG(91);
        }
        return;
    }

    sEquipAnimTimer--;

    if (sEquipAnimTimer == 0) {
        pauseCtx->equipAnimAlpha = 0xFF;
    }
}
