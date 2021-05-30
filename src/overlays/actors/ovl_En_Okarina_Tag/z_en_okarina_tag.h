#ifndef _Z_EN_OKARINA_TAG_H_
#define _Z_EN_OKARINA_TAG_H_

#include "ultra64.h"
#include "global.h"

struct EnOkarinaTag;

typedef void (*EnOkarinaTagActionFunc)(struct EnOkarinaTag*, GlobalContext*);

typedef struct EnOkarinaTag {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnOkarinaTagActionFunc actionFunc;
    /* 0x0150 */ s16 type;
    /* 0x0152 */ s16 answer;
    /* 0x0154 */ s16 switchFlag;
    /* 0x0156 */ char unk_156[0x2];
    /* 0x0158 */ s16 hit;
    /* 0x015A */ s16 debugFrameCounter;
    /* 0x015C */ f32 range;
} EnOkarinaTag; // size = 0x0160

extern const ActorInit En_Okarina_Tag_InitVars;

#endif
