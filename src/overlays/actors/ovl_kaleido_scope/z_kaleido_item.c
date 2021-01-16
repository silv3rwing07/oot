#include "ultra64.h"
#include "global.h"

// .data
u8 D_8082A420[] = {
    SLOT_STICK,    SLOT_NUT,  SLOT_BOMB, SLOT_BOW,  SLOT_NONE, SLOT_NONE, SLOT_SLINGSHOT,   SLOT_NONE,
    SLOT_HOOKSHOT, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_NONE, SLOT_ARROW_LIGHT, SLOT_NONE,
};

s16 D_8082A430 = 0;

s16 D_8082A434 = 0;

s16 D_8082A438 = 10;

s16 D_8082A43C[] = {
    0, 2, 4, 6, 99, 99, 8, 99, 99, 10, 99, 99, 99, 99, 99, 99, 12,
};

void func_808198A0(PauseContext* pauseCtx, GraphicsContext* gfxCtx, s16 item) {
    s16 ammo;
    s16 i;

    OPEN_DISPS(gfxCtx, "../z_kaleido_item.c", 69);

    ammo = AMMO(item);

    gDPPipeSync(POLY_OPA_DISP++);

    if (!((D_8082ABFC[SLOT(item)] == 9) || D_8082ABFC[SLOT(item)] == ((void)0, gSaveContext.linkAge))) {
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
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[(D_8082A43C[item] + 0x1B) * 4], 4, 0);

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

    gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[(D_8082A43C[item] + 0x1C) * 4], 4, 0);

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
    func_80819E14(pauseCtx, pauseCtx->unk_246[0] * 4, pauseCtx->vtx_158);
}

s16 D_8082A460[] = { 255, 100, 255 };

s16 D_8082A468[] = { 0, 100, 255 };

s16 D_8082A470[] = { 0, 255, 100 };

#ifdef NON_MATCHING
void func_80819E6C(GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input[0];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    u16 i;
    u16 spAC;
    u16 spAA;
    u16 spA8;
    s16 phi_s2;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    s16 sp9E;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_item.c", 234);

    func_800949A8(globalCtx->state.gfxCtx);

    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    pauseCtx->unk_260 = 0;
    pauseCtx->unk_25E = 0;

    if ((pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0) && (pauseCtx->kscpPos == 0)) {
        phi_s2 = 0;

        sp9E = pauseCtx->unk_218[0];
        spAA = pauseCtx->unk_23E[0];
        spA8 = pauseCtx->unk_246[0];

        if (pauseCtx->unk_238 == 0) {
            pauseCtx->unk_260 = 4;

            if (spAA == 999) {
                pauseCtx->stickRelX = 40;
            }

            if (ABS(pauseCtx->stickRelX) > 30) {
                spA4 = pauseCtx->unk_218[0];
                spA2 = pauseCtx->unk_222[0];
                spA0 = pauseCtx->unk_22C[0];

                osSyncPrintf("now=%d  ccc=%d\n", spA4, spAA);

                while (phi_s2 == 0) {
                    if (pauseCtx->stickRelX < -30) {
                        if (pauseCtx->unk_222[0] != 0) {
                            pauseCtx->unk_222[0] = pauseCtx->unk_222[0] - 1;
                            pauseCtx->unk_218[0] = pauseCtx->unk_218[0] - 1;

                            if (gSaveContext.inventory.items[pauseCtx->unk_218[0]] != ITEM_NONE) {
                                phi_s2 = 1;
                            }
                        } else {
                            pauseCtx->unk_222[0] = spA2;
                            pauseCtx->unk_22C[0] = pauseCtx->unk_22C[0] + 1;

                            if (pauseCtx->unk_22C[0] >= 4) {
                                pauseCtx->unk_22C[0] = 0;
                            }

                            pauseCtx->unk_218[0] = (pauseCtx->unk_22C[0] * 6) + pauseCtx->unk_222[0];

                            if (pauseCtx->unk_218[0] >= 24) {
                                pauseCtx->unk_218[0] = pauseCtx->unk_222[0];
                            }

                            if (spA0 == pauseCtx->unk_22C[0]) {
                                pauseCtx->unk_222[0] = spA2;
                                pauseCtx->unk_218[0] = spA4;

                                func_8081F81C(globalCtx, 10);

                                phi_s2 = 2;
                            }
                        }
                    } else if (pauseCtx->stickRelX > 30) {
                        if (pauseCtx->unk_222[0] < 5) {
                            pauseCtx->unk_222[0] = pauseCtx->unk_222[0] + 1;
                            pauseCtx->unk_218[0] = pauseCtx->unk_218[0] + 1;

                            if (gSaveContext.inventory.items[pauseCtx->unk_218[0]] != ITEM_NONE) {
                                phi_s2 = 1;
                            }
                        } else {
                            pauseCtx->unk_222[0] = spA2;
                            pauseCtx->unk_22C[0] = pauseCtx->unk_22C[0] + 1;

                            if (pauseCtx->unk_22C[0] >= 4) {
                                pauseCtx->unk_22C[0] = 0;
                            }

                            pauseCtx->unk_218[0] = (pauseCtx->unk_22C[0] * 6) + pauseCtx->unk_222[0];

                            if (pauseCtx->unk_218[0] >= 24) {
                                pauseCtx->unk_218[0] = pauseCtx->unk_222[0];
                            }

                            if (spA0 == pauseCtx->unk_22C[0]) {
                                pauseCtx->unk_222[0] = spA2;
                                pauseCtx->unk_218[0] = spA4;

                                func_8081F81C(globalCtx, 11);

                                phi_s2 = 2;
                            }
                        }
                    }
                }

                if (phi_s2 == 1) {
                    spAA = gSaveContext.inventory.items[pauseCtx->unk_218[0]];
                }

                osSyncPrintf("【Ｘ cursor=%d(%) (cur_xpt=%d)(ok_fg=%d)(ccc=%d)(key_angle=%d)】  ", pauseCtx->unk_218[0],
                             pauseCtx->unk_222[0], phi_s2, spAA, pauseCtx->unk_238);
            }
        } else if (pauseCtx->unk_238 == 10) {
            if (pauseCtx->stickRelX > 30) {
                pauseCtx->unk_25C = 0;
                pauseCtx->unk_238 = 0;

                Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

                spA4 = 0;
                spA2 = 0;
                spA0 = 0;
                while (true) {
                    if (gSaveContext.inventory.items[spA4] != ITEM_NONE) {
                        pauseCtx->unk_218[0] = spA4;
                        pauseCtx->unk_222[0] = spA2;
                        pauseCtx->unk_22C[0] = spA0;
                        phi_s2 = 1;
                        break;
                    } else {
                        spA0 = spA0 + 1;
                        spA4 = spA4 + 6;
                        if (spA0 < 4) {
                            continue;
                        }

                        spA0 = 0;
                        spA4 = spA2 + 1;
                        spA2 = spA4;
                        if (spA2 < 6) {
                            continue;
                        }

                        func_8081F81C(globalCtx, 11);
                        break;
                    }
                }
            }
        } else {
            if (pauseCtx->stickRelX < -30) {
                pauseCtx->unk_25C = 0;
                pauseCtx->unk_238 = 0;

                Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);

                spA4 = 5;
                spA2 = 5;
                spA0 = 0;
                while (true) {
                    if (gSaveContext.inventory.items[spA4] != ITEM_NONE) {
                        pauseCtx->unk_218[0] = spA4;
                        pauseCtx->unk_222[0] = spA2;
                        pauseCtx->unk_22C[0] = spA0;
                        phi_s2 = 1;
                        break;
                    } else {
                        spA0 = spA0 + 1;
                        spA4 = spA4 + 6;
                        if (spA0 < 4) {
                            continue;
                        }

                        spA0 = 0;
                        spA4 = spA2 - 1;
                        spA2 = spA4;
                        if (spA2 >= 0) {
                            continue;
                        }

                        func_8081F81C(globalCtx, 10);
                        break;
                    }
                }
            }
        }

        if (pauseCtx->unk_238 == 0) {
            if (spAA != 999) {
                if (ABS(pauseCtx->stickRelY) > 30) {
                    phi_s2 = 0;
                    spA4 = pauseCtx->unk_218[0];
                    spA0 = pauseCtx->unk_22C[0];
                    while (phi_s2 == 0) {
                        if (pauseCtx->stickRelY > 30) {
                            if (pauseCtx->unk_22C[0] != 0) {
                                pauseCtx->unk_22C[0] = pauseCtx->unk_22C[0] - 1;
                                pauseCtx->unk_218[0] = pauseCtx->unk_218[0] - 6;

                                if (gSaveContext.inventory.items[pauseCtx->unk_218[0]] != ITEM_NONE) {
                                    phi_s2 = 1;
                                }
                            } else {
                                pauseCtx->unk_22C[0] = spA0;
                                pauseCtx->unk_218[0] = spA4;

                                phi_s2 = 2;
                            }
                        } else if (pauseCtx->stickRelY < -30) {
                            if (pauseCtx->unk_22C[0] < 3) {
                                pauseCtx->unk_22C[0] = pauseCtx->unk_22C[0] + 1;
                                pauseCtx->unk_218[0] = pauseCtx->unk_218[0] + 6;

                                if (gSaveContext.inventory.items[pauseCtx->unk_218[0]] != ITEM_NONE) {
                                    phi_s2 = 1;
                                }
                            } else {
                                pauseCtx->unk_22C[0] = spA0;
                                pauseCtx->unk_218[0] = spA4;

                                phi_s2 = 2;
                            }
                        }
                    }

                    osSyncPrintf("【Ｙ cursor=%d(%) (cur_ypt=%d)(ok_fg=%d)(ccc=%d)】  ", pauseCtx->unk_218[0],
                                 pauseCtx->unk_22C[0], phi_s2, spAA);
                }
            }

            spA8 = pauseCtx->unk_218[0];

            pauseCtx->unk_260 = 4;

            if (phi_s2 == 1) {
                spAA = gSaveContext.inventory.items[pauseCtx->unk_218[0]];
            } else if (phi_s2 != 2) {
                spAA = gSaveContext.inventory.items[pauseCtx->unk_218[0]];
            }

            pauseCtx->unk_23E[0] = spAA;
            pauseCtx->unk_246[0] = spA8;

            if (!((D_8082ABFC[spA8] == 9) || (D_8082ABFC[spA8] == ((void)0, gSaveContext.linkAge)))) {
                pauseCtx->unk_25E = 1;
            }

            if (spAA != 999) {
                func_80819E14(pauseCtx, spA8 * 4, pauseCtx->vtx_158);

                if ((pauseCtx->flag == 0) && (pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0)) {
                    if (CHECK_BTN_ANY(input->press.button, BTN_CLEFT | BTN_CDOWN | BTN_CRIGHT)) {
                        if (((D_8082ABFC[spA8] == 9) || (D_8082ABFC[spA8] == gSaveContext.linkAge)) &&
                            (spAA != ITEM_SOLD_OUT)) {
                            if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
                                pauseCtx->unk_252 = 0;
                            } else if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
                                pauseCtx->unk_252 = 1;
                            } else if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
                                pauseCtx->unk_252 = 2;
                            }

                            pauseCtx->unk_24E = spAA;
                            pauseCtx->unk_250 = spA8;
                            pauseCtx->unk_1E4 = 3;
                            pauseCtx->unk_254 = pauseCtx->vtx_158[spA8 * 4].v.ob[0] * 10;
                            pauseCtx->unk_256 = pauseCtx->vtx_158[spA8 * 4].v.ob[1] * 10;
                            pauseCtx->unk_258 = 255;
                            D_8082A434 = 0;
                            D_8082A430 = 3;
                            D_8082A438 = 10;
                            if ((pauseCtx->unk_24E == ITEM_ARROW_FIRE) || (pauseCtx->unk_24E == ITEM_ARROW_ICE) ||
                                (pauseCtx->unk_24E == ITEM_ARROW_LIGHT)) {
                                i = 0;
                                if (pauseCtx->unk_24E == ITEM_ARROW_ICE) {
                                    i = 1;
                                }
                                if (pauseCtx->unk_24E == ITEM_ARROW_LIGHT) {
                                    i = 2;
                                }
                                Audio_PlaySoundGeneral(NA_SE_SY_SET_FIRE_ARROW + i, &D_801333D4, 4, &D_801333E0,
                                                       &D_801333E0, &D_801333E8);
                                pauseCtx->unk_24E = 0xBF + i;
                                D_8082A430 = 0;
                                pauseCtx->unk_258 = 0;
                                D_8082A438 = 6;
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
            pauseCtx->unk_23E[0] = 999;
        }

        if (sp9E != pauseCtx->unk_218[0]) {
            Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
    } else if ((pauseCtx->unk_1E4 == 3) && (pauseCtx->kscpPos == 0)) {
        func_80819E14(pauseCtx, spA8 * 4, pauseCtx->vtx_158);
        pauseCtx->unk_260 = 4;
    }

    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

    for (i = 0, spAC = 96; i < 3; i++, spAC += 4) {
        if (gSaveContext.equips.buttonItems[i + 1] != ITEM_NONE) {
            gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[spAC], 4, 0);
            POLY_OPA_DISP = func_8081F50C(POLY_OPA_DISP, &D_02000A00[1], 32, 32, 0);
        }
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    for (i = 0, spAC = 0; i < 24; i++, spAC += 4) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->unk_208);

        if (gSaveContext.inventory.items[i] != ITEM_NONE) {
            if ((pauseCtx->unk_1E4 == 0) && (pauseCtx->kscpPos == 0) && (pauseCtx->unk_238 == 0)) {
                if ((D_8082ABFC[i] == 9) || (D_8082ABFC[i] == gSaveContext.linkAge)) {
                    if ((D_8082A430 == 2) && (i == 3)) {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_8082A460[pauseCtx->unk_24E - 0xBF],
                                        D_8082A468[pauseCtx->unk_24E - 0xBF], D_8082A470[pauseCtx->unk_24E - 0xBF],
                                        pauseCtx->unk_208);

                        pauseCtx->vtx_158[spAC + 0].v.ob[0] = pauseCtx->vtx_158[spAC + 2].v.ob[0] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[0] - 2;

                        pauseCtx->vtx_158[spAC + 1].v.ob[0] = pauseCtx->vtx_158[spAC + 3].v.ob[0] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[0] + 32;

                        pauseCtx->vtx_158[spAC + 0].v.ob[1] = pauseCtx->vtx_158[spAC + 1].v.ob[1] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[1] + 2;

                        pauseCtx->vtx_158[spAC + 2].v.ob[1] = pauseCtx->vtx_158[spAC + 3].v.ob[1] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[1] - 32;
                    } else if (spA8 == i) {
                        pauseCtx->vtx_158[spAC + 0].v.ob[0] = pauseCtx->vtx_158[spAC + 2].v.ob[0] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[0] - 2;

                        pauseCtx->vtx_158[spAC + 1].v.ob[0] = pauseCtx->vtx_158[spAC + 3].v.ob[0] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[0] + 32;

                        pauseCtx->vtx_158[spAC + 0].v.ob[1] = pauseCtx->vtx_158[spAC + 1].v.ob[1] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[1] + 2;

                        pauseCtx->vtx_158[spAC + 2].v.ob[1] = pauseCtx->vtx_158[spAC + 3].v.ob[1] =
                            pauseCtx->vtx_158[spAC + 0].v.ob[1] - 32;
                    }
                }
            }

            gSPVertex(POLY_OPA_DISP++, &pauseCtx->vtx_158[spAC], 4, 0);
            func_8081F87C(globalCtx->state.gfxCtx, gItemIcons[gSaveContext.inventory.items[i]], 32, 32, 0);
        }
    }

    if (pauseCtx->unk_238 == 0) {
        func_8081FE30(globalCtx, 0);
    }

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

    for (i = 0; i < 15; i++) {
        if ((D_8082A420[i] != SLOT_NONE) && (gSaveContext.inventory.items[i] != ITEM_NONE)) {
            func_808198A0(pauseCtx, globalCtx->state.gfxCtx, gSaveContext.inventory.items[i]);
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

    if (D_8082A430 == 0) {
        pauseCtx->unk_258 += 0xE;
        if (pauseCtx->unk_258 > 0xFF) {
            pauseCtx->unk_258 = 0xFE;
            D_8082A430++;
        }
        D_8082A434 = 5;
        return;
    }

    if (D_8082A430 == 2) {
        D_8082A488--;

        if (D_8082A488 == 0) {
            pauseCtx->unk_24E -= 0x87;
            pauseCtx->unk_250 = 3;
            D_8082A438 = 6;
            WREG(90) = 320;
            WREG(87) = WREG(91);
            D_8082A430++;
            Audio_PlaySoundGeneral(NA_SE_SY_SYNTH_MAGIC_ARROW, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        }
        return;
    }

    if (D_8082A430 == 1) {
        vtx = &pauseCtx->vtx_158[12];
        phi_a2 = ABS(pauseCtx->unk_254 - vtx->v.ob[0] * 10) / D_8082A438;
        phi_a1 = ABS(pauseCtx->unk_256 - vtx->v.ob[1] * 10) / D_8082A438;
    } else {
        phi_a2 = ABS(pauseCtx->unk_254 - D_8082A478[pauseCtx->unk_252]) / D_8082A438;
        phi_a1 = ABS(pauseCtx->unk_256 - D_8082A480[pauseCtx->unk_252]) / D_8082A438;
    }

    if (pauseCtx->unk_24E >= 0xBF) {
        if (pauseCtx->unk_258 < 0xFE) {
            pauseCtx->unk_258 += 0xE;
            if (pauseCtx->unk_258 >= 0x100) {
                pauseCtx->unk_258 = 0xFE;
            }
            D_8082A434 = 5;
            return;
        }
    }

    if (D_8082A434 == 0) {
        WREG(90) -= WREG(87) / D_8082A438;
        WREG(87) -= WREG(87) / D_8082A438;

        if (D_8082A430 == 1) {
            if (pauseCtx->unk_254 >= (pauseCtx->vtx_158[12].v.ob[0] * 10)) {
                pauseCtx->unk_254 -= phi_a2;
            } else {
                pauseCtx->unk_254 += phi_a2;
            }

            if (pauseCtx->unk_256 >= (pauseCtx->vtx_158[12].v.ob[1] * 10)) {
                pauseCtx->unk_256 -= phi_a1;
            } else {
                pauseCtx->unk_256 += phi_a1;
            }
        } else {
            if (pauseCtx->unk_254 >= D_8082A478[pauseCtx->unk_252]) {
                pauseCtx->unk_254 -= phi_a2;
            } else {
                pauseCtx->unk_254 += phi_a2;
            }

            if (pauseCtx->unk_256 >= D_8082A480[pauseCtx->unk_252]) {
                pauseCtx->unk_256 -= phi_a1;
            } else {
                pauseCtx->unk_256 += phi_a1;
            }
        }

        D_8082A438--;

        if (D_8082A438 == 0) {
            if (D_8082A430 == 1) {
                D_8082A430++;
                D_8082A488 = 4;
                return;
            }

            osSyncPrintf("\n＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");

            if (pauseCtx->unk_252 == 0) {

                if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[1]) {
                    if (gSaveContext.equips.buttonItems[1] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[1] == 3) ||
                             ((gSaveContext.equips.buttonItems[1] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[1] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[1];
                            gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[0];
                            Interface_LoadItemIcon2(globalCtx, 2);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[2] = 0xFF;
                        gSaveContext.equips.cButtonSlots[1] = 0xFF;
                    }
                } else if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[2]) {
                    if (gSaveContext.equips.buttonItems[1] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[1] == 3) ||
                             ((gSaveContext.equips.buttonItems[1] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[1] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[1];
                            gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[0];
                            Interface_LoadItemIcon2(globalCtx, 3);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[3] = 0xFF;
                        gSaveContext.equips.cButtonSlots[2] = 0xFF;
                    }
                }

                if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2)) {
                    if ((gSaveContext.equips.buttonItems[1] == 3) ||
                        ((gSaveContext.equips.buttonItems[1] >= 0x38) && (gSaveContext.equips.buttonItems[1] < 0x3B))) {
                        pauseCtx->unk_24E -= 0x87;
                        pauseCtx->unk_250 = 3;
                    }
                } else if (pauseCtx->unk_24E == 3) {
                    if ((gSaveContext.equips.buttonItems[2] >= 0x38) && (gSaveContext.equips.buttonItems[2] < 0x3B)) {
                        gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[1];
                        gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[0];
                        Interface_LoadItemIcon2(globalCtx, 2);
                    } else if ((gSaveContext.equips.buttonItems[3] >= 0x38) &&
                               (gSaveContext.equips.buttonItems[3] < 0x3B)) {
                        gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[1];
                        gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[0];
                        Interface_LoadItemIcon2(globalCtx, 3);
                    }
                }

                gSaveContext.equips.buttonItems[1] = pauseCtx->unk_24E;
                gSaveContext.equips.cButtonSlots[0] = pauseCtx->unk_250;
                Interface_LoadItemIcon1(globalCtx, 1);

                osSyncPrintf("Ｃ左sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_24E,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ左sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_250,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            } else if (pauseCtx->unk_252 == 1) {
                osSyncPrintf("Ｃ下sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_24E,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ下sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_250,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);

                if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[0]) {
                    if (gSaveContext.equips.buttonItems[2] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[2] == 3) ||
                             ((gSaveContext.equips.buttonItems[2] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[2] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[2];
                            gSaveContext.equips.cButtonSlots[0] = gSaveContext.equips.cButtonSlots[1];
                            Interface_LoadItemIcon2(globalCtx, 1);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[1] = 0xFF;
                        gSaveContext.equips.cButtonSlots[0] = 0xFF;
                    }
                } else if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[2]) {
                    if (gSaveContext.equips.buttonItems[2] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[2] == 3) ||
                             ((gSaveContext.equips.buttonItems[2] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[2] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[2];
                            gSaveContext.equips.cButtonSlots[2] = gSaveContext.equips.cButtonSlots[1];
                            Interface_LoadItemIcon2(globalCtx, 3);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[3] = 0xFF;
                        gSaveContext.equips.cButtonSlots[2] = 0xFF;
                    }
                }

                if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2)) {
                    if ((gSaveContext.equips.buttonItems[2] == 3) ||
                        ((gSaveContext.equips.buttonItems[2] >= 0x38) && (gSaveContext.equips.buttonItems[2] < 0x3B))) {
                        pauseCtx->unk_24E -= 0x87;
                        pauseCtx->unk_250 = 3;
                    }
                } else if (pauseCtx->unk_24E == 3) {
                    if ((gSaveContext.equips.buttonItems[1] >= 0x38) && (gSaveContext.equips.buttonItems[1] < 0x3B)) {
                        gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[2];
                        Interface_LoadItemIcon2(globalCtx, 1);
                    } else if ((gSaveContext.equips.buttonItems[3] >= 0x38) &&
                               (gSaveContext.equips.buttonItems[3] < 0x3B)) {
                        gSaveContext.equips.buttonItems[3] = gSaveContext.equips.buttonItems[2];
                        Interface_LoadItemIcon2(globalCtx, 3);
                    }
                }

                gSaveContext.equips.buttonItems[2] = pauseCtx->unk_24E;
                gSaveContext.equips.cButtonSlots[1] = pauseCtx->unk_250;
                Interface_LoadItemIcon1(globalCtx, 2);

                osSyncPrintf("Ｃ下sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_24E,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ下sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_250,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            } else {
                osSyncPrintf("Ｃ右sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_24E,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ右sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_250,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);

                if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[0]) {
                    if (gSaveContext.equips.buttonItems[3] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[3] == 3) ||
                             ((gSaveContext.equips.buttonItems[3] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[3] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[3];
                            gSaveContext.equips.cButtonSlots[0] = gSaveContext.equips.cButtonSlots[2];
                            Interface_LoadItemIcon2(globalCtx, 1);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[1] = 0xFF;
                        gSaveContext.equips.cButtonSlots[0] = 0xFF;
                    }
                } else if (pauseCtx->unk_250 == gSaveContext.equips.cButtonSlots[1]) {
                    if (gSaveContext.equips.buttonItems[3] != 0xFF) {
                        if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2) &&
                            ((gSaveContext.equips.buttonItems[3] == 3) ||
                             ((gSaveContext.equips.buttonItems[3] >= 0x38) &&
                              (gSaveContext.equips.buttonItems[3] < 0x3B)))) {
                            pauseCtx->unk_24E -= 0x87;
                            pauseCtx->unk_250 = 3;
                        } else {
                            gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[3];
                            gSaveContext.equips.cButtonSlots[1] = gSaveContext.equips.cButtonSlots[2];
                            Interface_LoadItemIcon2(globalCtx, 2);
                        }
                    } else {
                        gSaveContext.equips.buttonItems[2] = 0xFF;
                        gSaveContext.equips.cButtonSlots[1] = 0xFF;
                    }
                }

                if ((pauseCtx->unk_24E >= 0xBF) && (pauseCtx->unk_24E < 0xC2)) {
                    if ((gSaveContext.equips.buttonItems[3] == 3) ||
                        ((gSaveContext.equips.buttonItems[3] >= 0x38) && (gSaveContext.equips.buttonItems[3] < 0x3B))) {
                        pauseCtx->unk_24E -= 0x87;
                        pauseCtx->unk_250 = 3;
                    }
                } else if (pauseCtx->unk_24E == 3) {
                    if ((gSaveContext.equips.buttonItems[1] >= 0x38) && (gSaveContext.equips.buttonItems[1] < 0x3B)) {
                        gSaveContext.equips.buttonItems[1] = gSaveContext.equips.buttonItems[3];
                        Interface_LoadItemIcon2(globalCtx, 1);
                    } else if ((gSaveContext.equips.buttonItems[2] >= 0x38) &&
                               (gSaveContext.equips.buttonItems[2] < 0x3B)) {
                        gSaveContext.equips.buttonItems[2] = gSaveContext.equips.buttonItems[3];
                        Interface_LoadItemIcon2(globalCtx, 2);
                    }
                }

                gSaveContext.equips.buttonItems[3] = pauseCtx->unk_24E;
                gSaveContext.equips.cButtonSlots[2] = pauseCtx->unk_250;
                Interface_LoadItemIcon1(globalCtx, 3);

                osSyncPrintf("Ｃ右sl_item_no=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_24E,
                             gSaveContext.equips.buttonItems[1], gSaveContext.equips.buttonItems[2],
                             gSaveContext.equips.buttonItems[3]);
                osSyncPrintf("Ｃ右sl_number=%d (1)=%d (2)=%d (3)=%d\n", pauseCtx->unk_250,
                             gSaveContext.equips.cButtonSlots[0], gSaveContext.equips.cButtonSlots[1],
                             gSaveContext.equips.cButtonSlots[2]);
            }

            pauseCtx->unk_1E4 = 0;
            D_8082A438 = 10;
            WREG(90) = 320;
            WREG(87) = WREG(91);
        }
        return;
    }

    D_8082A434--;

    if (D_8082A434 == 0) {
        pauseCtx->unk_258 = 0xFF;
    }
}
