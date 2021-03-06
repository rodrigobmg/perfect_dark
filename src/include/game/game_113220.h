#ifndef IN_GAME_GAME_113220_H
#define IN_GAME_GAME_113220_H
#include <ultra64.h>
#include "types.h"

u32 func0f113220(void);
void currentPlayerUpdateIdleHeadRoll(void);
void currentPlayerUpdateHeadPos(struct coord *vel);
void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel);
void currentPlayerSetHeadAmp(f32 headamp);
u32 func0f1138a4(void);
u32 func0f113f10(void);
u32 func0f1140bc(void);
void func0f11412c(f32 speed);
f32 func0f11416c(void);

#endif
