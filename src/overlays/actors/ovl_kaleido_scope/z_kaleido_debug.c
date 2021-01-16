#include "ultra64.h"
#include "global.h"

void func_80815CE0(Gfx** gfxp) {
    GfxPrint printer;
    s32 pad[2];

    GfxPrint_Init(&printer);
    GfxPrint_Open(&printer, *gfxp);

    GfxPrint_SetPos(&printer, 4, 2);
    GfxPrint_SetColor(&printer, 255, 60, 0, 255);
    GfxPrint_Printf(&printer, "%s", "\x8Cﾙﾋﾟｰ");
    GfxPrint_SetPos(&printer, 15, 2);
    GfxPrint_Printf(&printer, "%s", "\x8Cﾊｰﾄ");
    GfxPrint_SetPos(&printer, 26, 3);
    GfxPrint_Printf(&printer, "%s", "/4");
    GfxPrint_SetPos(&printer, 4, 5);
    GfxPrint_Printf(&printer, "%s", "\x8Cｱｲﾃﾑ");
    GfxPrint_SetPos(&printer, 4, 13);
    GfxPrint_Printf(&printer, "%s", "KEY");
    GfxPrint_SetPos(&printer, 4, 15);
    GfxPrint_Printf(&printer, "%s", "\x8Dｿｳﾋﾞ");
    GfxPrint_SetPos(&printer, 23, 14);
    GfxPrint_Printf(&printer, "%s", "\x8Cｹﾝ");
    GfxPrint_SetPos(&printer, 23, 15);
    GfxPrint_Printf(&printer, "%s", "\x8Cﾀﾃ");
    GfxPrint_SetPos(&printer, 4, 17);
    GfxPrint_Printf(&printer, "%s", "MAP");
    GfxPrint_SetPos(&printer, 4, 19);
    GfxPrint_Printf(&printer, "%s", "\x8Dﾌｳｲﾝ");
    GfxPrint_SetPos(&printer, 20, 19);
    GfxPrint_Printf(&printer, "%s", "\x8Dｾｲﾚｲｾｷ");
    GfxPrint_SetPos(&printer, 4, 21);
    GfxPrint_Printf(&printer, "%s", "\x8Cｵｶﾘﾅ");
    GfxPrint_SetPos(&printer, 4, 24);
    GfxPrint_Printf(&printer, "%s", "\x8Cｺﾚｸﾄ");
    GfxPrint_SetPos(&printer, 14, 24);
    GfxPrint_Printf(&printer, "%s", "\x8Cｷﾝｽﾀ");
    GfxPrint_SetPos(&printer, 23, 24);
    GfxPrint_Printf(&printer, "%s", "\x8Cｶｹﾗ");
    GfxPrint_SetPos(&printer, 28, 24);
    GfxPrint_Printf(&printer, "%s", "/4");

    *gfxp = GfxPrint_Close(&printer);
    GfxPrint_Destroy(&printer);
}

void func_80815FD4(GlobalContext* globalCtx, s32 digit, s32 rectLeft, s32 rectTop) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_debug.c", 208);

    gDPLoadTextureBlock(POLY_OPA_DISP++, &D_02003040[digit], G_IM_FMT_I, G_IM_SIZ_8b, 8, 16, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(POLY_OPA_DISP++, rectLeft << 2, rectTop << 2, (rectLeft + 8) << 2, (rectTop + 16) << 2,
                        G_TX_RENDERTILE, 0, 0, 1024, 1024);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_kaleido_debug.c", 220);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808161AC.s")
