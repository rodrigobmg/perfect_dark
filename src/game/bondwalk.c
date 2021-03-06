#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_092610.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/bondwalk.h"
#include "game/game_0c79f0.h"
#include "game/game_111600.h"
#include "game/game_113220.h"
#include "game/game_11ecf0.h"
#include "game/game_127910.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

void currentPlayerWalkInit(void)
{
	u32 prevmode = g_Vars.currentplayer->bondmovemode;
	s32 i;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_WALK;
	g_Vars.currentplayer->unk1ae8 = 0;
	g_Vars.currentplayer->unk1aec = 0;
	g_Vars.currentplayer->unk1af0 = NULL;
	g_Vars.currentplayer->unk1af4 = 0;

	g_Vars.currentplayer->swaypos = 0;
	g_Vars.currentplayer->swayoffset = 0;
	g_Vars.currentplayer->swaytarget = 0;
	g_Vars.currentplayer->swayoffset0 = 0;
	g_Vars.currentplayer->swayoffset2 = 0;

	g_Vars.currentplayer->bdeltapos.x = 0;
	g_Vars.currentplayer->bdeltapos.y = -0.0001f;
	g_Vars.currentplayer->bdeltapos.z = 0;

	g_Vars.currentplayer->isfalling = false;
	g_Vars.currentplayer->fallstart = 0;

	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	g_Vars.currentplayer->bondforcespeed.x = 0;
	g_Vars.currentplayer->bondforcespeed.y = 0;
	g_Vars.currentplayer->bondforcespeed.z = 0;

	if (prevmode != MOVEMODE_WALK && prevmode != MOVEMODE_CUTSCENE) {
		g_Vars.currentplayer->sumcrouch = 0;
		g_Vars.currentplayer->crouchheight = 0;
		g_Vars.currentplayer->crouchtime240 = 0;
		g_Vars.currentplayer->crouchfall = 0;
		g_Vars.currentplayer->crouchpos = CROUCH_STAND;
		g_Vars.currentplayer->autocrouchpos = CROUCH_STAND;
		g_Vars.currentplayer->crouchspeed = 0;
		g_Vars.currentplayer->crouchoffset = 0;
		g_Vars.currentplayer->unk1968 = 0;
	}

	func0f0c6080();

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		for (i = 0; i != 3; i++) {
			g_Vars.currentplayer->bondshotspeed[i] = 0;
		}

		g_Vars.currentplayer->speedsideways = 0;
		g_Vars.currentplayer->speedstrafe = 0;
		g_Vars.currentplayer->unk19a4 = 0;
		g_Vars.currentplayer->speedboost = 1;
		g_Vars.currentplayer->speedmaxtime60 = 0;
		g_Vars.currentplayer->speedforwards = 0;
		g_Vars.currentplayer->speedtheta = 0;
		g_Vars.currentplayer->speedthetacontrol = 0;
	}

	if (g_Vars.currentplayer->unk1af8) {
		struct coord delta;
		func00016b58(g_Vars.currentplayer->walkinitmtx,
				0, 0, 0,
				-g_Vars.currentplayer->unk0388.x, -g_Vars.currentplayer->unk0388.y, -g_Vars.currentplayer->unk0388.z,
				g_Vars.currentplayer->unk0394.x, g_Vars.currentplayer->unk0394.y, g_Vars.currentplayer->unk0394.z);
		g_Vars.currentplayer->walkinitt = 0;
		g_Vars.currentplayer->walkinitt2 = 0;
		g_Vars.currentplayer->walkinitstart.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->walkinitstart.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->walkinitstart.z = g_Vars.currentplayer->prop->pos.z;

		delta.x = g_Vars.currentplayer->walkinitpos.x - g_Vars.currentplayer->prop->pos.x;
		delta.y = 0;
		delta.z = g_Vars.currentplayer->walkinitpos.z - g_Vars.currentplayer->prop->pos.z;

		func0f064178(g_Vars.currentplayer->hoverbike, false);
		func0f0c4250(&delta, 0, 1, 0, 63);
		func0f064178(g_Vars.currentplayer->hoverbike, true);
	} else if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}
}

void func0f0c3ad0(s32 value)
{
	g_Vars.currentplayer->swaytarget = value * 75.0f;
}

void currentPlayerAdjustCrouchPos(s32 value)
{
	g_Vars.currentplayer->crouchpos += value;

	if (g_Vars.currentplayer->crouchpos < CROUCH_SQUAT) {
		g_Vars.currentplayer->crouchpos = CROUCH_SQUAT;
	} else if (g_Vars.currentplayer->crouchpos > CROUCH_STAND) {
		g_Vars.currentplayer->crouchpos = CROUCH_STAND;
	}
}

GLOBAL_ASM(
glabel func0f0c3b38
/*  f0c3b38:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0c3b3c:	3c02800a */ 	lui	$v0,0x800a
/*  f0c3b40:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c3b44:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c3b48:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0c3b4c:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f0c3b50:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c3b54:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0c3b58:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0c3b5c:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f0c3b60:	24e7d750 */ 	addiu	$a3,$a3,-10416
/*  f0c3b64:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c3b68:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c3b6c:	240600df */ 	addiu	$a2,$zero,0xdf
/*  f0c3b70:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0c3b74:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c3b78:	c70a000c */ 	lwc1	$f10,0xc($t8)
/*  f0c3b7c:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f0c3b80:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c3b84:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f0c3b88:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0c3b8c:	c7320010 */ 	lwc1	$f18,0x10($t9)
/*  f0c3b90:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0c3b94:	0c009393 */ 	jal	func00024e4c
/*  f0c3b98:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0c3b9c:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f0c3ba0:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0c3ba4:	44801000 */ 	mtc1	$zero,$f2
/*  f0c3ba8:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f0c3bac:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0c3bb0:	c7b00034 */ 	lwc1	$f16,0x34($sp)
/*  f0c3bb4:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0c3bb8:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0c3bbc:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0c3bc0:	e7a00058 */ 	swc1	$f0,0x58($sp)
/*  f0c3bc4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c3bc8:	e7a2005c */ 	swc1	$f2,0x5c($sp)
/*  f0c3bcc:	45000005 */ 	bc1f	.L0f0c3be4
/*  f0c3bd0:	e7b20060 */ 	swc1	$f18,0x60($sp)
/*  f0c3bd4:	46121032 */ 	c.eq.s	$f2,$f18
/*  f0c3bd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c3bdc:	45030006 */ 	bc1tl	.L0f0c3bf8
/*  f0c3be0:	44812000 */ 	mtc1	$at,$f4
.L0f0c3be4:
/*  f0c3be4:	0c0011e4 */ 	jal	scaleTo1
/*  f0c3be8:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0c3bec:	10000005 */ 	beqz	$zero,.L0f0c3c04
/*  f0c3bf0:	27a80064 */ 	addiu	$t0,$sp,0x64
/*  f0c3bf4:	44812000 */ 	mtc1	$at,$f4
.L0f0c3bf8:
/*  f0c3bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3bfc:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f0c3c00:	27a80064 */ 	addiu	$t0,$sp,0x64
.L0f0c3c04:
/*  f0c3c04:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0c3c08:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0c3c0c:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c3c10:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f0c3c14:	0fc0b8f7 */ 	jal	func0f02e3dc
/*  f0c3c18:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0c3c1c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c3c20:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c3c24:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c3c28:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f0c3c2c:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0c3c30:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c3c34:	44801000 */ 	mtc1	$zero,$f2
/*  f0c3c38:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f0c3c3c:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*  f0c3c40:	e7a20050 */ 	swc1	$f2,0x50($sp)
/*  f0c3c44:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c3c48:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0c3c4c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c3c50:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c3c54:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f0c3c58:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0c3c5c:	e7b0004c */ 	swc1	$f16,0x4c($sp)
/*  f0c3c60:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c3c64:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*  f0c3c68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0c3c6c:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0c3c70:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0c3c74:	0fc20ba1 */ 	jal	func0f082e84
/*  f0c3c78:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c3c7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c3c80:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f0c3c84:	03e00008 */ 	jr	$ra
/*  f0c3c88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c3c8c
.late_rodata
glabel var7f1ad784
.word 0x3dcccccd
.text
/*  f0c3c8c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0c3c90:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0c3c94:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c3c98:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c3c9c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3ca0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0c3ca4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c3ca8:	944e161c */ 	lhu	$t6,0x161c($v0)
/*  f0c3cac:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c3cb0:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f0c3cb4:	31cf0100 */ 	andi	$t7,$t6,0x100
/*  f0c3cb8:	11e00003 */ 	beqz	$t7,.L0f0c3cc8
/*  f0c3cbc:	27a70038 */ 	addiu	$a3,$sp,0x38
/*  f0c3cc0:	10000002 */ 	beqz	$zero,.L0f0c3ccc
/*  f0c3cc4:	ae00032c */ 	sw	$zero,0x32c($s0)
.L0f0c3cc8:
/*  f0c3cc8:	ae18032c */ 	sw	$t8,0x32c($s0)
.L0f0c3ccc:
/*  f0c3ccc:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c3cd0:	8e0a0328 */ 	lw	$t2,0x328($s0)
/*  f0c3cd4:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0c3cd8:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0c3cdc:	240b003f */ 	addiu	$t3,$zero,0x3f
/*  f0c3ce0:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0c3ce4:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0c3ce8:	c506000c */ 	lwc1	$f6,0xc($t0)
/*  f0c3cec:	460c3200 */ 	add.s	$f8,$f6,$f12
/*  f0c3cf0:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f0c3cf4:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c3cf8:	c52a0010 */ 	lwc1	$f10,0x10($t1)
/*  f0c3cfc:	11400003 */ 	beqz	$t2,.L0f0c3d0c
/*  f0c3d00:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f0c3d04:	10000002 */ 	beqz	$zero,.L0f0c3d10
/*  f0c3d08:	afab0040 */ 	sw	$t3,0x40($sp)
.L0f0c3d0c:
/*  f0c3d0c:	afac0040 */ 	sw	$t4,0x40($sp)
.L0f0c3d10:
/*  f0c3d10:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c3d14:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c3d18:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3d1c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c3d20:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f0c3d24:	8da200bc */ 	lw	$v0,0xbc($t5)
/*  f0c3d28:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c3d2c:	0fc1979d */ 	jal	func0f065e74
/*  f0c3d30:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c3d34:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c3d38:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0c3d3c:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0c3d40:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0c3d44:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3d48:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c3d4c:	0fc1905e */ 	jal	func0f064178
/*  f0c3d50:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c3d54:	3c017f1b */ 	lui	$at,%hi(var7f1ad784)
/*  f0c3d58:	c432d784 */ 	lwc1	$f18,%lo(var7f1ad784)($at)
/*  f0c3d5c:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0c3d60:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c3d64:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0c3d68:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0c3d6c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c3d70:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f0c3d74:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0c3d78:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0c3d7c:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0c3d80:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0c3d84:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0c3d88:	c720000c */ 	lwc1	$f0,0xc($t9)
/*  f0c3d8c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0c3d90:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c3d94:	46002281 */ 	sub.s	$f10,$f4,$f0
/*  f0c3d98:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c3d9c:	0c00a9a1 */ 	jal	func0002a684
/*  f0c3da0:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0c3da4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c3da8:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0c3dac:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c3db0:	0fc1905e */ 	jal	func0f064178
/*  f0c3db4:	8d0400bc */ 	lw	$a0,0xbc($t0)
/*  f0c3db8:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f0c3dbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c3dc0:	5521000e */ 	bnel	$t1,$at,.L0f0c3dfc
/*  f0c3dc4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0c3dc8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c3dcc:	c7b0005c */ 	lwc1	$f16,0x5c($sp)
/*  f0c3dd0:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0c3dd4:	e570000c */ 	swc1	$f16,0xc($t3)
/*  f0c3dd8:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c3ddc:	0fc19711 */ 	jal	func0f065c44
/*  f0c3de0:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0c3de4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3de8:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0c3dec:	8da500bc */ 	lw	$a1,0xbc($t5)
/*  f0c3df0:	0fc195e9 */ 	jal	roomsCopy
/*  f0c3df4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c3df8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0c3dfc:
/*  f0c3dfc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0c3e00:	ae0e032c */ 	sw	$t6,0x32c($s0)
/*  f0c3e04:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0c3e08:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0c3e0c:	03e00008 */ 	jr	$ra
/*  f0c3e10:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0c3e14
.late_rodata
glabel var7f1ad788
.word 0x40c907a9
.text
/*  f0c3e14:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0c3e18:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0c3e1c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c3e20:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c3e24:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3e28:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c3e2c:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f0c3e30:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f0c3e34:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f0c3e38:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f0c3e3c:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c3e40:	944e161c */ 	lhu	$t6,0x161c($v0)
/*  f0c3e44:	00803825 */ 	or	$a3,$a0,$zero
/*  f0c3e48:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c3e4c:	31cf0100 */ 	andi	$t7,$t6,0x100
/*  f0c3e50:	11e00003 */ 	beqz	$t7,.L0f0c3e60
/*  f0c3e54:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c3e58:	10000002 */ 	beqz	$zero,.L0f0c3e64
/*  f0c3e5c:	ae00032c */ 	sw	$zero,0x32c($s0)
.L0f0c3e60:
/*  f0c3e60:	ae18032c */ 	sw	$t8,0x32c($s0)
.L0f0c3e64:
/*  f0c3e64:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c3e68:	44808000 */ 	mtc1	$zero,$f16
/*  f0c3e6c:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0c3e70:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f0c3e74:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0c3e78:	c506000c */ 	lwc1	$f6,0xc($t0)
/*  f0c3e7c:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c3e80:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c3e84:	c5280010 */ 	lwc1	$f8,0x10($t1)
/*  f0c3e88:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0c3e8c:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f0c3e90:	460a8032 */ 	c.eq.s	$f16,$f10
/*  f0c3e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3e98:	4502000c */ 	bc1fl	.L0f0c3ecc
/*  f0c3e9c:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c3ea0:	c4f20004 */ 	lwc1	$f18,0x4($a3)
/*  f0c3ea4:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0c3ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3eac:	45020007 */ 	bc1fl	.L0f0c3ecc
/*  f0c3eb0:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c3eb4:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f0c3eb8:	46048032 */ 	c.eq.s	$f16,$f4
/*  f0c3ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3ec0:	450300a3 */ 	bc1tl	.L0f0c4150
/*  f0c3ec4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c3ec8:	8c441aec */ 	lw	$a0,0x1aec($v0)
.L0f0c3ecc:
/*  f0c3ecc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c3ed0:	50800006 */ 	beqzl	$a0,.L0f0c3eec
/*  f0c3ed4:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c3ed8:	0fc1905e */ 	jal	func0f064178
/*  f0c3edc:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c3ee0:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c3ee4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3ee8:	8c4400bc */ 	lw	$a0,0xbc($v0)
.L0f0c3eec:
/*  f0c3eec:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c3ef0:	0fc1905e */ 	jal	func0f064178
/*  f0c3ef4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c3ef8:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c3efc:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0c3f00:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f0c3f04:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f0c3f08:	8e0a0328 */ 	lw	$t2,0x328($s0)
/*  f0c3f0c:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0c3f10:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c3f14:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0c3f18:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f0c3f1c:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0c3f20:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f0c3f24:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f0c3f28:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f0c3f2c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c3f30:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c3f34:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f0c3f38:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0c3f3c:	11400003 */ 	beqz	$t2,.L0f0c3f4c
/*  f0c3f40:	e7b200ac */ 	swc1	$f18,0xac($sp)
/*  f0c3f44:	10000002 */ 	beqz	$zero,.L0f0c3f50
/*  f0c3f48:	afab0060 */ 	sw	$t3,0x60($sp)
.L0f0c3f4c:
/*  f0c3f4c:	afac0060 */ 	sw	$t4,0x60($sp)
.L0f0c3f50:
/*  f0c3f50:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3f54:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0c3f58:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c3f5c:	8da400bc */ 	lw	$a0,0xbc($t5)
/*  f0c3f60:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0c3f64:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c3f68:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3f6c:	27af0064 */ 	addiu	$t7,$sp,0x64
/*  f0c3f70:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c3f74:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0c3f78:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c3f7c:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c3f80:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c3f84:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0c3f88:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c3f8c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c3f90:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c3f94:	0fc1977f */ 	jal	func0f065dfc
/*  f0c3f98:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c3f9c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c3fa0:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c3fa4:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0c3fa8:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f0c3fac:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c3fb0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c3fb4:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f0c3fb8:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0c3fbc:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f0c3fc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c3fc4:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f0c3fc8:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0c3fcc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0c3fd0:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f0c3fd4:	44815000 */ 	mtc1	$at,$f10
/*  f0c3fd8:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c3fdc:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0c3fe0:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0c3fe4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0c3fe8:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f0c3fec:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c3ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3ff4:	45030010 */ 	bc1tl	.L0f0c4038
/*  f0c3ff8:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0c3ffc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c4000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4004:	4503000c */ 	bc1tl	.L0f0c4038
/*  f0c4008:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0c400c:	46000387 */ 	neg.s	$f14,$f0
/*  f0c4010:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c4014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4018:	45030007 */ 	bc1tl	.L0f0c4038
/*  f0c401c:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0c4020:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0c4024:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0c4028:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0c402c:	45020029 */ 	bc1fl	.L0f0c40d4
/*  f0c4030:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4034:	8fa90060 */ 	lw	$t1,0x60($sp)
.L0f0c4038:
/*  f0c4038:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c403c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0c4040:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c4044:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c4048:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f0c404c:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*  f0c4050:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c4054:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c4058:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c405c:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c4060:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0c4064:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c4068:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c406c:	0c00b657 */ 	jal	func0002d95c
/*  f0c4070:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f0c4074:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4078:	14410024 */ 	bne	$v0,$at,.L0f0c410c
/*  f0c407c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c4080:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c4084:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0c4088:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c408c:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0c4090:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c4094:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c4098:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c409c:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c40a0:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f0c40a4:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c40a8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0c40ac:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c40b0:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c40b4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c40b8:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f0c40bc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c40c0:	0c00aa7c */ 	jal	func0002a9f0
/*  f0c40c4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0c40c8:	10000010 */ 	beqz	$zero,.L0f0c410c
/*  f0c40cc:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c40d0:	afae0010 */ 	sw	$t6,0x10($sp)
.L0f0c40d4:
/*  f0c40d4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0c40d8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c40dc:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f0c40e0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f0c40e4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c40e8:	46005481 */ 	sub.s	$f18,$f10,$f0
/*  f0c40ec:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c40f0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c40f4:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c40f8:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0c40fc:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f0c4100:	0c00aa7c */ 	jal	func0002a9f0
/*  f0c4104:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c4108:	00401825 */ 	or	$v1,$v0,$zero
.L0f0c410c:
/*  f0c410c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c4110:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c4114:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0c4118:	0fc1905e */ 	jal	func0f064178
/*  f0c411c:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c4120:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c4124:	44808000 */ 	mtc1	$zero,$f16
/*  f0c4128:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c412c:	8f241aec */ 	lw	$a0,0x1aec($t9)
/*  f0c4130:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c4134:	50800006 */ 	beqzl	$a0,.L0f0c4150
/*  f0c4138:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c413c:	0fc1905e */ 	jal	func0f064178
/*  f0c4140:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c4144:	44808000 */ 	mtc1	$zero,$f16
/*  f0c4148:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c414c:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0c4150:
/*  f0c4150:	14610038 */ 	bne	$v1,$at,.L0f0c4234
/*  f0c4154:	8fa800c0 */ 	lw	$t0,0xc0($sp)
/*  f0c4158:	11000036 */ 	beqz	$t0,.L0f0c4234
/*  f0c415c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c4160:	44811000 */ 	mtc1	$at,$f2
/*  f0c4164:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f0c4168:	3c017f1b */ 	lui	$at,%hi(var7f1ad788)
/*  f0c416c:	c432d788 */ 	lwc1	$f18,%lo(var7f1ad788)($at)
/*  f0c4170:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0c4174:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c4178:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f0c417c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f0c4180:	46043000 */ 	add.s	$f0,$f6,$f4
/*  f0c4184:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c4188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c418c:	45020007 */ 	bc1fl	.L0f0c41ac
/*  f0c4190:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c4194:	46020000 */ 	add.s	$f0,$f0,$f2
.L0f0c4198:
/*  f0c4198:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c419c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c41a0:	4503fffd */ 	bc1tl	.L0f0c4198
/*  f0c41a4:	46020000 */ 	add.s	$f0,$f0,$f2
/*  f0c41a8:	4600103e */ 	c.le.s	$f2,$f0
.L0f0c41ac:
/*  f0c41ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c41b0:	45020007 */ 	bc1fl	.L0f0c41d0
/*  f0c41b4:	e4400144 */ 	swc1	$f0,0x144($v0)
/*  f0c41b8:	46020001 */ 	sub.s	$f0,$f0,$f2
.L0f0c41bc:
/*  f0c41bc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c41c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c41c4:	4503fffd */ 	bc1tl	.L0f0c41bc
/*  f0c41c8:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f0c41cc:	e4400144 */ 	swc1	$f0,0x144($v0)
.L0f0c41d0:
/*  f0c41d0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c41d4:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0c41d8:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0c41dc:	e5480008 */ 	swc1	$f8,0x8($t2)
/*  f0c41e0:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c41e4:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0c41e8:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0c41ec:	e58a000c */ 	swc1	$f10,0xc($t4)
/*  f0c41f0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c41f4:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0c41f8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f0c41fc:	e5d20010 */ 	swc1	$f18,0x10($t6)
/*  f0c4200:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0c4204:	51e0000c */ 	beqzl	$t7,.L0f0c4238
/*  f0c4208:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c420c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c4210:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0c4214:	0fc19711 */ 	jal	func0f065c44
/*  f0c4218:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c421c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c4220:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0c4224:	8f2500bc */ 	lw	$a1,0xbc($t9)
/*  f0c4228:	0fc195e9 */ 	jal	roomsCopy
/*  f0c422c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c4230:	8fa300b4 */ 	lw	$v1,0xb4($sp)
.L0f0c4234:
/*  f0c4234:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0c4238:
/*  f0c4238:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c423c:	ae08032c */ 	sw	$t0,0x32c($s0)
/*  f0c4240:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0c4244:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0c4248:	03e00008 */ 	jr	$ra
/*  f0c424c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0c4250
/*  f0c4250:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0c4254:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f0c4258:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c425c:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0c4260:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0c4264:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0c4268:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0c426c:	0fc30f85 */ 	jal	func0f0c3e14
/*  f0c4270:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4274:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4278:	10410135 */ 	beq	$v0,$at,.L0f0c4750
/*  f0c427c:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c4280:	0c0093ac */ 	jal	func00024eb0
/*  f0c4284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4288:	10400131 */ 	beqz	$v0,.L0f0c4750
/*  f0c428c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0c4290:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4294:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4298:	8d0f0034 */ 	lw	$t7,0x34($t0)
/*  f0c429c:	59e0012d */ 	blezl	$t7,.L0f0c4754
/*  f0c42a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42a4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0c42a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c42ac:	54610046 */ 	bnel	$v1,$at,.L0f0c43c8
/*  f0c42b0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c42b4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0c42b8:	94780070 */ 	lhu	$t8,0x70($v1)
/*  f0c42bc:	33190400 */ 	andi	$t9,$t8,0x400
/*  f0c42c0:	53200124 */ 	beqzl	$t9,.L0f0c4754
/*  f0c42c4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42c8:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c42cc:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0c42d0:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0c42d4:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f0c42d8:	240601d1 */ 	addiu	$a2,$zero,0x1d1
/*  f0c42dc:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0c42e0:	5540011c */ 	bnezl	$t2,.L0f0c4754
/*  f0c42e4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42e8:	0c009393 */ 	jal	func00024e4c
/*  f0c42ec:	24e7d75c */ 	addiu	$a3,$a3,-10404
/*  f0c42f0:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0c42f4:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f0c42f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0c42fc:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f0c4300:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0c4304:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f0c4308:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c430c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4310:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0c4314:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f0c4318:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c431c:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0c4320:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f0c4324:	45000004 */ 	bc1f	.L0f0c4338
/*  f0c4328:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0c432c:	46041032 */ 	c.eq.s	$f2,$f4
/*  f0c4330:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4334:	45010006 */ 	bc1t	.L0f0c4350
.L0f0c4338:
/*  f0c4338:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0c433c:	0c0011e4 */ 	jal	scaleTo1
/*  f0c4340:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0c4344:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4348:	10000004 */ 	beqz	$zero,.L0f0c435c
/*  f0c434c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0c4350:
/*  f0c4350:	44813000 */ 	mtc1	$at,$f6
/*  f0c4354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4358:	e7a60098 */ 	swc1	$f6,0x98($sp)
.L0f0c435c:
/*  f0c435c:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c4360:	3c053ecc */ 	lui	$a1,0x3ecc
/*  f0c4364:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f0c4368:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0c436c:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0c4370:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4374:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c4378:	0fc0d05f */ 	jal	func0f03417c
/*  f0c437c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0c4380:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c4384:	44814000 */ 	mtc1	$at,$f8
/*  f0c4388:	3c048009 */ 	lui	$a0,0x8009
/*  f0c438c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0c4390:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0c4394:	240effff */ 	addiu	$t6,$zero,-1
/*  f0c4398:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0c439c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c43a0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c43a4:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f0c43a8:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f0c43ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c43b0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c43b4:	0c004241 */ 	jal	func00010904
/*  f0c43b8:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c43bc:	100000e5 */ 	beqz	$zero,.L0f0c4754
/*  f0c43c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c43c4:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0c43c8:
/*  f0c43c8:	5461008b */ 	bnel	$v1,$at,.L0f0c45f8
/*  f0c43cc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c43d0:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f0c43d4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f0c43d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c43dc:	1300000c */ 	beqz	$t8,.L0f0c4410
/*  f0c43e0:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0c43e4:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0c43e8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c43ec:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c43f0:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0c43f4:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f0c43f8:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0c43fc:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0c4400:	10400014 */ 	beqz	$v0,.L0f0c4454
/*  f0c4404:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0c4408:	10000012 */ 	beqz	$zero,.L0f0c4454
/*  f0c440c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4410:
/*  f0c4410:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0c4414:	8d4b0018 */ 	lw	$t3,0x18($t2)
/*  f0c4418:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f0c441c:	0581000d */ 	bgez	$t4,.L0f0c4454
/*  f0c4420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4424:	8d0d029c */ 	lw	$t5,0x29c($t0)
/*  f0c4428:	05a2000a */ 	bltzl	$t5,.L0f0c4454
/*  f0c442c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4430:	8d0e02a8 */ 	lw	$t6,0x2a8($t0)
/*  f0c4434:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c4438:	55cf0006 */ 	bnel	$t6,$t7,.L0f0c4454
/*  f0c443c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4440:	8d580014 */ 	lw	$t8,0x14($t2)
/*  f0c4444:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0c4448:	07200002 */ 	bltz	$t9,.L0f0c4454
/*  f0c444c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4450:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4454:
/*  f0c4454:	106000be */ 	beqz	$v1,.L0f0c4750
/*  f0c4458:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f0c445c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0c4460:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f0c4464:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0c4468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c446c:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0c4470:	0c012974 */ 	jal	sqrtf
/*  f0c4474:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c4478:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c447c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4480:	c5060044 */ 	lwc1	$f6,0x44($t0)
/*  f0c4484:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c4488:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f0c448c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f0c4490:	44801000 */ 	mtc1	$zero,$f2
/*  f0c4494:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4498:	8d2200bc */ 	lw	$v0,0xbc($t1)
/*  f0c449c:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0c44a0:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f0c44a4:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c44a8:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c44ac:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f0c44b0:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0c44b4:	46027032 */ 	c.eq.s	$f14,$f2
/*  f0c44b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c44bc:	45000005 */ 	bc1f	.L0f0c44d4
/*  f0c44c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c44c4:	46028032 */ 	c.eq.s	$f16,$f2
/*  f0c44c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c44cc:	450300a1 */ 	bc1tl	.L0f0c4754
/*  f0c44d0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c44d4:
/*  f0c44d4:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f0c44d8:	e7ae0050 */ 	swc1	$f14,0x50($sp)
/*  f0c44dc:	e7b0004c */ 	swc1	$f16,0x4c($sp)
/*  f0c44e0:	46108102 */ 	mul.s	$f4,$f16,$f16
/*  f0c44e4:	0c012974 */ 	jal	sqrtf
/*  f0c44e8:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c44ec:	44801000 */ 	mtc1	$zero,$f2
/*  f0c44f0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c44f4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c44f8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c44fc:	c7ae0050 */ 	lwc1	$f14,0x50($sp)
/*  f0c4500:	c7b0004c */ 	lwc1	$f16,0x4c($sp)
/*  f0c4504:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0c4508:	45020092 */ 	bc1fl	.L0f0c4754
/*  f0c450c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4510:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0c4514:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c4518:	44819000 */ 	mtc1	$at,$f18
/*  f0c451c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c4520:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0c4524:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c4528:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c452c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4530:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*  f0c4534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4538:	460c8402 */ 	mul.s	$f16,$f16,$f12
/*  f0c453c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4540:	460e9082 */ 	mul.s	$f2,$f18,$f14
/*  f0c4544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4548:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f0c454c:	e4820304 */ 	swc1	$f2,0x304($a0)
/*  f0c4550:	e4880308 */ 	swc1	$f8,0x308($a0)
/*  f0c4554:	c5000044 */ 	lwc1	$f0,0x44($t0)
/*  f0c4558:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c455c:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f0c4560:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c4564:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f0c4568:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0c456c:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f0c4570:	c48a0308 */ 	lwc1	$f10,0x308($a0)
/*  f0c4574:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c4578:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c457c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c4580:	0fc079fd */ 	jal	func0f01e7f4
/*  f0c4584:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f0c4588:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0c458c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f0c4590:	e48a0008 */ 	swc1	$f10,0x8($a0)
/*  f0c4594:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f0c4598:	e484000c */ 	swc1	$f4,0xc($a0)
/*  f0c459c:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0c45a0:	0fc19711 */ 	jal	func0f065c44
/*  f0c45a4:	e4860010 */ 	swc1	$f6,0x10($a0)
/*  f0c45a8:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f0c45ac:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0c45b0:	0fc195e9 */ 	jal	roomsCopy
/*  f0c45b4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c45b8:	0fc0882b */ 	jal	func0f0220ac
/*  f0c45bc:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c45c0:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f0c45c4:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c45c8:	0c006b4d */ 	jal	func0001ad34
/*  f0c45cc:	8d640020 */ 	lw	$a0,0x20($t3)
/*  f0c45d0:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f0c45d4:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c45d8:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c45dc:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c45e0:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c45e4:	0fc30f85 */ 	jal	func0f0c3e14
/*  f0c45e8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c45ec:	10000058 */ 	beqz	$zero,.L0f0c4750
/*  f0c45f0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c45f4:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0c45f8:
/*  f0c45f8:	10610055 */ 	beq	$v1,$at,.L0f0c4750
/*  f0c45fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4600:	54610054 */ 	bnel	$v1,$at,.L0f0c4754
/*  f0c4604:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4608:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0c460c:	8cc30040 */ 	lw	$v1,0x40($a2)
/*  f0c4610:	00036940 */ 	sll	$t5,$v1,0x5
/*  f0c4614:	05a0004e */ 	bltz	$t5,.L0f0c4750
/*  f0c4618:	00037100 */ 	sll	$t6,$v1,0x4
/*  f0c461c:	05c2004d */ 	bltzl	$t6,.L0f0c4754
/*  f0c4620:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4624:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4628:	8c6f1af0 */ 	lw	$t7,0x1af0($v1)
/*  f0c462c:	55e00008 */ 	bnezl	$t7,.L0f0c4650
/*  f0c4630:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4634:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f0c4638:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f0c463c:	55410004 */ 	bnel	$t2,$at,.L0f0c4650
/*  f0c4640:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4644:	10000042 */ 	beqz	$zero,.L0f0c4750
/*  f0c4648:	ac621aec */ 	sw	$v0,0x1aec($v1)
/*  f0c464c:	8cd80010 */ 	lw	$t8,0x10($a2)
.L0f0c4650:
/*  f0c4650:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0c4654:	5320003f */ 	beqzl	$t9,.L0f0c4754
/*  f0c4658:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c465c:	ac600178 */ 	sw	$zero,0x178($v1)
/*  f0c4660:	8cc90040 */ 	lw	$t1,0x40($a2)
/*  f0c4664:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0c4668:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c466c:	312b0080 */ 	andi	$t3,$t1,0x80
/*  f0c4670:	11600007 */ 	beqz	$t3,.L0f0c4690
/*  f0c4674:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0c4678:	8ccc0048 */ 	lw	$t4,0x48($a2)
/*  f0c467c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0c4680:	31ae1000 */ 	andi	$t6,$t5,0x1000
/*  f0c4684:	11c00002 */ 	beqz	$t6,.L0f0c4690
/*  f0c4688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c468c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0c4690:
/*  f0c4690:	50400030 */ 	beqzl	$v0,.L0f0c4754
/*  f0c4694:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4698:	0fc30ece */ 	jal	func0f0c3b38
/*  f0c469c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46a0:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46a4:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0c46a8:	31ea0080 */ 	andi	$t2,$t7,0x80
/*  f0c46ac:	51400029 */ 	beqzl	$t2,.L0f0c4754
/*  f0c46b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46b4:	8cd80048 */ 	lw	$t8,0x48($a2)
/*  f0c46b8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0c46bc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c46c0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0c46c4:	33290800 */ 	andi	$t1,$t9,0x800
/*  f0c46c8:	51200022 */ 	beqzl	$t1,.L0f0c4754
/*  f0c46cc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46d0:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0c46d4:	0fc1cf1b */ 	jal	func0f073c6c
/*  f0c46d8:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46dc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46e0:	8ccb0040 */ 	lw	$t3,0x40($a2)
/*  f0c46e4:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f0c46e8:	11800010 */ 	beqz	$t4,.L0f0c472c
/*  f0c46ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c46f0:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c46f4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0c46f8:	35ae1000 */ 	ori	$t6,$t5,0x1000
/*  f0c46fc:	10400006 */ 	beqz	$v0,.L0f0c4718
/*  f0c4700:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0c4704:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c4708:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0c470c:	35ea2000 */ 	ori	$t2,$t7,0x2000
/*  f0c4710:	10000006 */ 	beqz	$zero,.L0f0c472c
/*  f0c4714:	ac6a0000 */ 	sw	$t2,0x0($v1)
.L0f0c4718:
/*  f0c4718:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c471c:	2401dfff */ 	addiu	$at,$zero,-8193
/*  f0c4720:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0c4724:	0301c824 */ 	and	$t9,$t8,$at
/*  f0c4728:	ac790000 */ 	sw	$t9,0x0($v1)
.L0f0c472c:
/*  f0c472c:	10400008 */ 	beqz	$v0,.L0f0c4750
/*  f0c4730:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c4734:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f0c4738:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c473c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c4740:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c4744:	0fc30f85 */ 	jal	func0f0c3e14
/*  f0c4748:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0c474c:	afa200a4 */ 	sw	$v0,0xa4($sp)
.L0f0c4750:
/*  f0c4750:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c4754:
/*  f0c4754:	8fa200a4 */ 	lw	$v0,0xa4($sp)
/*  f0c4758:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f0c475c:	03e00008 */ 	jr	$ra
/*  f0c4760:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c4764
/*  f0c4764:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0c4768:	44800000 */ 	mtc1	$zero,$f0
/*  f0c476c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0c4770:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f0c4774:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0c4778:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c477c:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f0c4780:	44050000 */ 	mfc1	$a1,$f0
/*  f0c4784:	44070000 */ 	mfc1	$a3,$f0
/*  f0c4788:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c478c:	0fc31094 */ 	jal	func0f0c4250
/*  f0c4790:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4794:	14400009 */ 	bnez	$v0,.L0f0c47bc
/*  f0c4798:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c479c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0c47a0:	24e7d768 */ 	addiu	$a3,$a3,-10392
/*  f0c47a4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0c47a8:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0c47ac:	2406025f */ 	addiu	$a2,$zero,0x25f
/*  f0c47b0:	0c009393 */ 	jal	func00024e4c
/*  f0c47b4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0c47b8:	8fa30024 */ 	lw	$v1,0x24($sp)
.L0f0c47bc:
/*  f0c47bc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c47c0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0c47c4:	00601025 */ 	or	$v0,$v1,$zero
/*  f0c47c8:	03e00008 */ 	jr	$ra
/*  f0c47cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c47d0
/*  f0c47d0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0c47d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c47d8:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0c47dc:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0c47e0:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c47e4:	0c0093a9 */ 	jal	func00024ea4
/*  f0c47e8:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0c47ec:	50400053 */ 	beqzl	$v0,.L0f0c493c
/*  f0c47f0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0c47f4:	0c0093a6 */ 	jal	func00024e98
/*  f0c47f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c47fc:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0c4800:	3c013e80 */ 	lui	$at,0x3e80
/*  f0c4804:	44811000 */ 	mtc1	$at,$f2
/*  f0c4808:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0c480c:	44806000 */ 	mtc1	$zero,$f12
/*  f0c4810:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0c4814:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0c4818:	44056000 */ 	mfc1	$a1,$f12
/*  f0c481c:	44076000 */ 	mfc1	$a3,$f12
/*  f0c4820:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0c4824:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c4828:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0c482c:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f0c4830:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0c4834:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0c4838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c483c:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f0c4840:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f0c4844:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0c4848:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c484c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0c4850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4854:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0c4858:	0fc31094 */ 	jal	func0f0c4250
/*  f0c485c:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f0c4860:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4864:	14410003 */ 	bne	$v0,$at,.L0f0c4874
/*  f0c4868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c486c:	10000033 */ 	beqz	$zero,.L0f0c493c
/*  f0c4870:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c4874:
/*  f0c4874:	14400030 */ 	bnez	$v0,.L0f0c4938
/*  f0c4878:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0c487c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0c4880:	24e7d774 */ 	addiu	$a3,$a3,-10380
/*  f0c4884:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0c4888:	0c009393 */ 	jal	func00024e4c
/*  f0c488c:	2406027b */ 	addiu	$a2,$zero,0x27b
/*  f0c4890:	8fa2003c */ 	lw	$v0,0x3c($sp)
/*  f0c4894:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0c4898:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0c489c:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0c48a0:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f0c48a4:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0c48a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48ac:	45000020 */ 	bc1f	.L0f0c4930
/*  f0c48b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48b4:	c4720004 */ 	lwc1	$f18,0x4($v1)
/*  f0c48b8:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0c48bc:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0c48c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48c4:	4500001a */ 	bc1f	.L0f0c4930
/*  f0c48c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48cc:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0c48d0:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c48d4:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0c48d8:	46083032 */ 	c.eq.s	$f6,$f8
/*  f0c48dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48e0:	45000013 */ 	bc1f	.L0f0c4930
/*  f0c48e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48e8:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f0c48ec:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0c48f0:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0c48f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48f8:	4500000d */ 	bc1f	.L0f0c4930
/*  f0c48fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4900:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f0c4904:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0c4908:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0c490c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4910:	45000007 */ 	bc1f	.L0f0c4930
/*  f0c4914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4918:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0c491c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c4920:	46083032 */ 	c.eq.s	$f6,$f8
/*  f0c4924:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4928:	45030004 */ 	bc1tl	.L0f0c493c
/*  f0c492c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0c4930:
/*  f0c4930:	10000002 */ 	beqz	$zero,.L0f0c493c
/*  f0c4934:	00001025 */ 	or	$v0,$zero,$zero
.L0f0c4938:
/*  f0c4938:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0c493c:
/*  f0c493c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c4940:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0c4944:	03e00008 */ 	jr	$ra
/*  f0c4948:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c494c
/*  f0c494c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0c4950:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c4954:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0c4958:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0c495c:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f0c4960:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0c4964:	46020032 */ 	c.eq.s	$f0,$f2
/*  f0c4968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c496c:	45020009 */ 	bc1fl	.L0f0c4994
/*  f0c4970:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0c4974:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0c4978:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0c497c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0c4980:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0c4984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4988:	45010030 */ 	bc1t	.L0f0c4a4c
/*  f0c498c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4990:	46001201 */ 	sub.s	$f8,$f2,$f0
.L0f0c4994:
/*  f0c4994:	44807000 */ 	mtc1	$zero,$f14
/*  f0c4998:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f0c499c:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f0c49a0:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f0c49a4:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0c49a8:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f0c49ac:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c49b0:	e7b20040 */ 	swc1	$f18,0x40($sp)
/*  f0c49b4:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f0c49b8:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0c49bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c49c0:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f0c49c4:	0c012974 */ 	jal	sqrtf
/*  f0c49c8:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0c49cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c49d0:	44818000 */ 	mtc1	$at,$f16
/*  f0c49d4:	c7b20038 */ 	lwc1	$f18,0x38($sp)
/*  f0c49d8:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*  f0c49dc:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f0c49e0:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0c49e4:	44807000 */ 	mtc1	$zero,$f14
/*  f0c49e8:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f0c49ec:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0c49f0:	44057000 */ 	mfc1	$a1,$f14
/*  f0c49f4:	44077000 */ 	mfc1	$a3,$f14
/*  f0c49f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c49fc:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0c4a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4a04:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0c4a08:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0c4a0c:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f0c4a10:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c4a14:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f0c4a18:	e7ae0030 */ 	swc1	$f14,0x30($sp)
/*  f0c4a1c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0c4a20:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4a24:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0c4a28:	46088300 */ 	add.s	$f12,$f16,$f8
/*  f0c4a2c:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0c4a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4a34:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f0c4a38:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f0c4a3c:	0fc31094 */ 	jal	func0f0c4250
/*  f0c4a40:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0c4a44:	10000002 */ 	beqz	$zero,.L0f0c4a50
/*  f0c4a48:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0c4a4c:
/*  f0c4a4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0c4a50:
/*  f0c4a50:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0c4a54:	03e00008 */ 	jr	$ra
/*  f0c4a58:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c4a5c
/*  f0c4a5c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0c4a60:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c4a64:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c4a68:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0c4a6c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0c4a70:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0c4a74:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0c4a78:	00808825 */ 	or	$s1,$a0,$zero
/*  f0c4a7c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0c4a80:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0c4a84:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0c4a88:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f0c4a8c:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f0c4a90:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f0c4a94:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c4a98:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c4a9c:	3c03800a */ 	lui	$v1,0x800a
/*  f0c4aa0:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f0c4aa4:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f0c4aa8:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f0c4aac:	8c6f00bc */ 	lw	$t7,0xbc($v1)
/*  f0c4ab0:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f0c4ab4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c4ab8:	46085401 */ 	sub.s	$f16,$f10,$f8
/*  f0c4abc:	e7b00054 */ 	swc1	$f16,0x54($sp)
/*  f0c4ac0:	8c7800bc */ 	lw	$t8,0xbc($v1)
/*  f0c4ac4:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f0c4ac8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0c4acc:	c7040010 */ 	lwc1	$f4,0x10($t8)
/*  f0c4ad0:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0c4ad4:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c4ad8:	46108002 */ 	mul.s	$f0,$f16,$f16
/*  f0c4adc:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0c4ae0:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0c4ae4:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f0c4ae8:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c4aec:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f0c4af0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4af4:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f0c4af8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c4afc:	4600403e */ 	c.le.s	$f8,$f0
/*  f0c4b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4b04:	45000043 */ 	bc1f	.L0f0c4c14
/*  f0c4b08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4b0c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4b10:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0c4b14:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f0c4b18:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0c4b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4b20:	45020008 */ 	bc1fl	.L0f0c4b44
/*  f0c4b24:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f0c4b28:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0c4b2c:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c4b30:	46045032 */ 	c.eq.s	$f10,$f4
/*  f0c4b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4b38:	45030091 */ 	bc1tl	.L0f0c4d80
/*  f0c4b3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c4b40:	c6060008 */ 	lwc1	$f6,0x8($s0)
.L0f0c4b44:
/*  f0c4b44:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c4b48:	44807000 */ 	mtc1	$zero,$f14
/*  f0c4b4c:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0c4b50:	e7ae0058 */ 	swc1	$f14,0x58($sp)
/*  f0c4b54:	46008487 */ 	neg.s	$f18,$f16
/*  f0c4b58:	e7b20054 */ 	swc1	$f18,0x54($sp)
/*  f0c4b5c:	8c7900bc */ 	lw	$t9,0xbc($v1)
/*  f0c4b60:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f0c4b64:	46129202 */ 	mul.s	$f8,$f18,$f18
/*  f0c4b68:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0c4b6c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0c4b70:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0c4b74:	c7b0005c */ 	lwc1	$f16,0x5c($sp)
/*  f0c4b78:	46108282 */ 	mul.s	$f10,$f16,$f16
/*  f0c4b7c:	0c012974 */ 	jal	sqrtf
/*  f0c4b80:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f0c4b84:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4b88:	44812000 */ 	mtc1	$at,$f4
/*  f0c4b8c:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0c4b90:	c7b0005c */ 	lwc1	$f16,0x5c($sp)
/*  f0c4b94:	46002083 */ 	div.s	$f2,$f4,$f0
/*  f0c4b98:	44807000 */ 	mtc1	$zero,$f14
/*  f0c4b9c:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0c4ba0:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0c4ba4:	44057000 */ 	mfc1	$a1,$f14
/*  f0c4ba8:	44077000 */ 	mfc1	$a3,$f14
/*  f0c4bac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c4bb0:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f0c4bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4bb8:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0c4bbc:	e7b20054 */ 	swc1	$f18,0x54($sp)
/*  f0c4bc0:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*  f0c4bc4:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0c4bc8:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0c4bcc:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0c4bd0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c4bd4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0c4bd8:	46123402 */ 	mul.s	$f16,$f6,$f18
/*  f0c4bdc:	46102300 */ 	add.s	$f12,$f4,$f16
/*  f0c4be0:	460c9202 */ 	mul.s	$f8,$f18,$f12
/*  f0c4be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4be8:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f0c4bec:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4bf0:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0c4bf4:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0c4bf8:	0fc31094 */ 	jal	func0f0c4250
/*  f0c4bfc:	e7a60050 */ 	swc1	$f6,0x50($sp)
/*  f0c4c00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4c04:	5441005e */ 	bnel	$v0,$at,.L0f0c4d80
/*  f0c4c08:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c4c0c:	1000005c */ 	beqz	$zero,.L0f0c4d80
/*  f0c4c10:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c4c14:
/*  f0c4c14:	8c6900bc */ 	lw	$t1,0xbc($v1)
/*  f0c4c18:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f0c4c1c:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f0c4c20:	c5300008 */ 	lwc1	$f16,0x8($t1)
/*  f0c4c24:	46102480 */ 	add.s	$f18,$f4,$f16
/*  f0c4c28:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f0c4c2c:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4c30:	8c6a00bc */ 	lw	$t2,0xbc($v1)
/*  f0c4c34:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f0c4c38:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f0c4c3c:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*  f0c4c40:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f0c4c44:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0c4c48:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c4c4c:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f0c4c50:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f0c4c54:	46084182 */ 	mul.s	$f6,$f8,$f8
/*  f0c4c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c5c:	46042282 */ 	mul.s	$f10,$f4,$f4
/*  f0c4c60:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0c4c64:	4600803e */ 	c.le.s	$f16,$f0
/*  f0c4c68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c6c:	45000043 */ 	bc1f	.L0f0c4d7c
/*  f0c4c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c74:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4c78:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f0c4c7c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c4c80:	46089032 */ 	c.eq.s	$f18,$f8
/*  f0c4c84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c88:	45020008 */ 	bc1fl	.L0f0c4cac
/*  f0c4c8c:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f0c4c90:	c6440008 */ 	lwc1	$f4,0x8($s2)
/*  f0c4c94:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c4c98:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0c4c9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ca0:	45030037 */ 	bc1tl	.L0f0c4d80
/*  f0c4ca4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c4ca8:	c64a0008 */ 	lwc1	$f10,0x8($s2)
.L0f0c4cac:
/*  f0c4cac:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*  f0c4cb0:	44807000 */ 	mtc1	$zero,$f14
/*  f0c4cb4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c4cb8:	e7ae0058 */ 	swc1	$f14,0x58($sp)
/*  f0c4cbc:	46009207 */ 	neg.s	$f8,$f18
/*  f0c4cc0:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4cc4:	8c6b00bc */ 	lw	$t3,0xbc($v1)
/*  f0c4cc8:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f0c4ccc:	46084402 */ 	mul.s	$f16,$f8,$f8
/*  f0c4cd0:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f0c4cd4:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0c4cd8:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*  f0c4cdc:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c4ce0:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f0c4ce4:	0c012974 */ 	jal	sqrtf
/*  f0c4ce8:	46102300 */ 	add.s	$f12,$f4,$f16
/*  f0c4cec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4cf0:	44813000 */ 	mtc1	$at,$f6
/*  f0c4cf4:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0c4cf8:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c4cfc:	46003083 */ 	div.s	$f2,$f6,$f0
/*  f0c4d00:	44807000 */ 	mtc1	$zero,$f14
/*  f0c4d04:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f0c4d08:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f0c4d0c:	44057000 */ 	mfc1	$a1,$f14
/*  f0c4d10:	44077000 */ 	mfc1	$a3,$f14
/*  f0c4d14:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c4d18:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0c4d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d20:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0c4d24:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4d28:	e7a4005c */ 	swc1	$f4,0x5c($sp)
/*  f0c4d2c:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f0c4d30:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f0c4d34:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0c4d38:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f0c4d3c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c4d40:	46085482 */ 	mul.s	$f18,$f10,$f8
/*  f0c4d44:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f0c4d48:	460c4402 */ 	mul.s	$f16,$f8,$f12
/*  f0c4d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d50:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0c4d54:	e7b00054 */ 	swc1	$f16,0x54($sp)
/*  f0c4d58:	e7b00048 */ 	swc1	$f16,0x48($sp)
/*  f0c4d5c:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*  f0c4d60:	0fc31094 */ 	jal	func0f0c4250
/*  f0c4d64:	e7aa0050 */ 	swc1	$f10,0x50($sp)
/*  f0c4d68:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4d6c:	54410004 */ 	bnel	$v0,$at,.L0f0c4d80
/*  f0c4d70:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c4d74:	10000002 */ 	beqz	$zero,.L0f0c4d80
/*  f0c4d78:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c4d7c:
/*  f0c4d7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0c4d80:
/*  f0c4d80:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0c4d84:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0c4d88:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0c4d8c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0c4d90:	03e00008 */ 	jr	$ra
/*  f0c4d94:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

void func0f0c4d98(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f0c4da0
/*  f0c4da0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c4da4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c4da8:	8c6e0318 */ 	lw	$t6,0x318($v1)
/*  f0c4dac:	51c00019 */ 	beqzl	$t6,.L0f0c4e14
/*  f0c4db0:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4db4:	8c6f0288 */ 	lw	$t7,0x288($v1)
/*  f0c4db8:	3c08800b */ 	lui	$t0,0x800b
/*  f0c4dbc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c4dc0:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f0c4dc4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0c4dc8:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0c4dcc:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0c4dd0:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0c4dd4:	9508c7d4 */ 	lhu	$t0,-0x382c($t0)
/*  f0c4dd8:	44882000 */ 	mtc1	$t0,$f4
/*  f0c4ddc:	05010004 */ 	bgez	$t0,.L0f0c4df0
/*  f0c4de0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c4de4:	44814000 */ 	mtc1	$at,$f8
/*  f0c4de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4dec:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0c4df0:
/*  f0c4df0:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0c4df4:	44815000 */ 	mtc1	$at,$f10
/*  f0c4df8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0c4dfc:	44819000 */ 	mtc1	$at,$f18
/*  f0c4e00:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0c4e04:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f0c4e08:	460c2302 */ 	mul.s	$f12,$f4,$f12
/*  f0c4e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e10:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0c4e14:
/*  f0c4e14:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0c4e18:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c4e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e20:	45020013 */ 	bc1fl	.L0f0c4e70
/*  f0c4e24:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c4e28:	44864000 */ 	mtc1	$a2,$f8
/*  f0c4e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e30:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0c4e34:	46067282 */ 	mul.s	$f10,$f14,$f6
/*  f0c4e38:	460a0401 */ 	sub.s	$f16,$f0,$f10
/*  f0c4e3c:	e450016c */ 	swc1	$f16,0x16c($v0)
/*  f0c4e40:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4e44:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0c4e48:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c4e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e50:	4500001a */ 	bc1f	.L0f0c4ebc
/*  f0c4e54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e58:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0c4e5c:	3c02800a */ 	lui	$v0,0x800a
/*  f0c4e60:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c4e64:	10000015 */ 	beqz	$zero,.L0f0c4ebc
/*  f0c4e68:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0c4e6c:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c4e70:
/*  f0c4e70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e74:	45000011 */ 	bc1f	.L0f0c4ebc
/*  f0c4e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e7c:	44869000 */ 	mtc1	$a2,$f18
/*  f0c4e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e84:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0c4e88:	46047202 */ 	mul.s	$f8,$f14,$f4
/*  f0c4e8c:	46080180 */ 	add.s	$f6,$f0,$f8
/*  f0c4e90:	e446016c */ 	swc1	$f6,0x16c($v0)
/*  f0c4e94:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4e98:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0c4e9c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c4ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ea4:	45000005 */ 	bc1f	.L0f0c4ebc
/*  f0c4ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4eac:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0c4eb0:	3c02800a */ 	lui	$v0,0x800a
/*  f0c4eb4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c4eb8:	c440016c */ 	lwc1	$f0,0x16c($v0)
.L0f0c4ebc:
/*  f0c4ebc:	03e00008 */ 	jr	$ra
/*  f0c4ec0:	e4400168 */ 	swc1	$f0,0x168($v0)
);

GLOBAL_ASM(
glabel func0f0c4ec4
/*  f0c4ec4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c4ec8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c4ecc:	8c6e0318 */ 	lw	$t6,0x318($v1)
/*  f0c4ed0:	51c00019 */ 	beqzl	$t6,.L0f0c4f38
/*  f0c4ed4:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4ed8:	8c6f0288 */ 	lw	$t7,0x288($v1)
/*  f0c4edc:	3c08800b */ 	lui	$t0,0x800b
/*  f0c4ee0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0c4ee4:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f0c4ee8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0c4eec:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0c4ef0:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0c4ef4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f0c4ef8:	9508c7d4 */ 	lhu	$t0,-0x382c($t0)
/*  f0c4efc:	44882000 */ 	mtc1	$t0,$f4
/*  f0c4f00:	05010004 */ 	bgez	$t0,.L0f0c4f14
/*  f0c4f04:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c4f08:	44814000 */ 	mtc1	$at,$f8
/*  f0c4f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f10:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0c4f14:
/*  f0c4f14:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0c4f18:	44815000 */ 	mtc1	$at,$f10
/*  f0c4f1c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0c4f20:	44819000 */ 	mtc1	$at,$f18
/*  f0c4f24:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0c4f28:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f0c4f2c:	460c2302 */ 	mul.s	$f12,$f4,$f12
/*  f0c4f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f34:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0c4f38:
/*  f0c4f38:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0c4f3c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c4f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f44:	45020011 */ 	bc1fl	.L0f0c4f8c
/*  f0c4f48:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c4f4c:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f0c4f50:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0c4f54:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0c4f58:	e44a19a4 */ 	swc1	$f10,0x19a4($v0)
/*  f0c4f5c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4f60:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0c4f64:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c4f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f6c:	45000018 */ 	bc1f	.L0f0c4fd0
/*  f0c4f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f74:	e44c19a4 */ 	swc1	$f12,0x19a4($v0)
/*  f0c4f78:	3c02800a */ 	lui	$v0,0x800a
/*  f0c4f7c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c4f80:	10000013 */ 	beqz	$zero,.L0f0c4fd0
/*  f0c4f84:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0c4f88:	4600603c */ 	c.lt.s	$f12,$f0
.L0f0c4f8c:
/*  f0c4f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f90:	4500000f */ 	bc1f	.L0f0c4fd0
/*  f0c4f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f98:	c470004c */ 	lwc1	$f16,0x4c($v1)
/*  f0c4f9c:	46107482 */ 	mul.s	$f18,$f14,$f16
/*  f0c4fa0:	46120101 */ 	sub.s	$f4,$f0,$f18
/*  f0c4fa4:	e44419a4 */ 	swc1	$f4,0x19a4($v0)
/*  f0c4fa8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c4fac:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0c4fb0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c4fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4fb8:	45000005 */ 	bc1f	.L0f0c4fd0
/*  f0c4fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4fc0:	e44c19a4 */ 	swc1	$f12,0x19a4($v0)
/*  f0c4fc4:	3c02800a */ 	lui	$v0,0x800a
/*  f0c4fc8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c4fcc:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
.L0f0c4fd0:
/*  f0c4fd0:	03e00008 */ 	jr	$ra
/*  f0c4fd4:	e4400170 */ 	swc1	$f0,0x170($v0)
);

GLOBAL_ASM(
glabel func0f0c4fd8
.late_rodata
glabel var7f1ad78c
.word 0x3f99999a
glabel var7f1ad790
.word 0x3f8ccccd
glabel var7f1ad794
.word 0xc6ea6000
glabel var7f1ad798
.word 0xc6ea6000
glabel var7f1ad79c
.word 0x3d3a5e30
glabel var7f1ad7a0
.word 0x3d3a5e30
glabel var7f1ad7a4
.word 0x3f745a1d
glabel var7f1ad7a8
.word 0x3d3a5e30
glabel var7f1ad7ac
.word 0x3fb1c71d
glabel var7f1ad7b0
.word 0x3e8e38e4
glabel var7f1ad7b4
.word 0x3e8e38e4
glabel var7f1ad7b8
.word 0xc6ea6000
glabel var7f1ad7bc
.word 0xc6ea6000
glabel var7f1ad7c0
.word 0xc1555555
glabel var7f1ad7c4
.word 0x41055555
glabel var7f1ad7c8
.word 0x3f7212d7
glabel var7f1ad7cc
.word 0x3d5ed290
glabel var7f1ad7d0
.word 0x3bce168a
.text
/*  f0c4fd8:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f0c4fdc:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0c4fe0:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c4fe4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c4fe8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c4fec:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0c4ff0:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f0c4ff4:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0c4ff8:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f0c4ffc:	27a600f8 */ 	addiu	$a2,$sp,0xf8
/*  f0c5000:	27a700f4 */ 	addiu	$a3,$sp,0xf4
/*  f0c5004:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c5008:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c500c:	8e0f029c */ 	lw	$t7,0x29c($s0)
/*  f0c5010:	05e00026 */ 	bltz	$t7,.L0f0c50ac
/*  f0c5014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5018:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c501c:	8e1802a8 */ 	lw	$t8,0x2a8($s0)
/*  f0c5020:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c5024:	17020021 */ 	bne	$t8,$v0,.L0f0c50ac
/*  f0c5028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c502c:	44812000 */ 	mtc1	$at,$f4
/*  f0c5030:	c4460378 */ 	lwc1	$f6,0x378($v0)
/*  f0c5034:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c5038:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0c503c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5040:	4501001a */ 	bc1t	.L0f0c50ac
/*  f0c5044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5048:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c504c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c5050:	c7a800f8 */ 	lwc1	$f8,0xf8($sp)
/*  f0c5054:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c5058:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f0c505c:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f0c5060:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0c5064:	2407003f */ 	addiu	$a3,$zero,0x3f
/*  f0c5068:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c506c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c5070:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0c5074:	24660028 */ 	addiu	$a2,$v1,0x28
/*  f0c5078:	0c00a9a1 */ 	jal	func0002a684
/*  f0c507c:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f0c5080:	1040000a */ 	beqz	$v0,.L0f0c50ac
/*  f0c5084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5088:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c508c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c5090:	44810000 */ 	mtc1	$at,$f0
/*  f0c5094:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0c5098:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0c509c:	e5600024 */ 	swc1	$f0,0x24($t3)
/*  f0c50a0:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c50a4:	e5800378 */ 	swc1	$f0,0x378($t4)
/*  f0c50a8:	e7a000fc */ 	swc1	$f0,0xfc($sp)
.L0f0c50ac:
/*  f0c50ac:	3c017f1b */ 	lui	$at,%hi(var7f1ad78c)
/*  f0c50b0:	c42ad78c */ 	lwc1	$f10,%lo(var7f1ad78c)($at)
/*  f0c50b4:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f0c50b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c50bc:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f0c50c0:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c50c4:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c50c8:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c50cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c50d0:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c50d4:	340e8040 */ 	dli	$t6,0x8040
/*  f0c50d8:	244f02a0 */ 	addiu	$t7,$v0,0x2a0
/*  f0c50dc:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c50e0:	44052000 */ 	mfc1	$a1,$f4
/*  f0c50e4:	44813000 */ 	mtc1	$at,$f6
/*  f0c50e8:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c50ec:	44064000 */ 	mfc1	$a2,$f8
/*  f0c50f0:	246d0028 */ 	addiu	$t5,$v1,0x28
/*  f0c50f4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0c50f8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c50fc:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0c5100:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0c5104:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c5108:	44074000 */ 	mfc1	$a3,$f8
/*  f0c510c:	0c00a7ff */ 	jal	func00029ffc
/*  f0c5110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5114:	14400031 */ 	bnez	$v0,.L0f0c51dc
/*  f0c5118:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0c511c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5120:	3c014120 */ 	lui	$at,0x4120
/*  f0c5124:	44813000 */ 	mtc1	$at,$f6
/*  f0c5128:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c512c:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f0c5130:	c70a0008 */ 	lwc1	$f10,0x8($t8)
/*  f0c5134:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c5138:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c513c:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f0c5140:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c5144:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f0c5148:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c514c:	c52a0010 */ 	lwc1	$f10,0x10($t1)
/*  f0c5150:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c5154:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c5158:	0fc195e9 */ 	jal	roomsCopy
/*  f0c515c:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c5160:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c5164:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0c5168:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0c516c:	27a600d8 */ 	addiu	$a2,$sp,0xd8
/*  f0c5170:	3c017f1b */ 	lui	$at,%hi(var7f1ad790)
/*  f0c5174:	c426d790 */ 	lwc1	$f6,%lo(var7f1ad790)($at)
/*  f0c5178:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f0c517c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5180:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f0c5184:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c5188:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c518c:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c5190:	3c014120 */ 	lui	$at,0x4120
/*  f0c5194:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c5198:	27aa00d8 */ 	addiu	$t2,$sp,0xd8
/*  f0c519c:	340b8040 */ 	dli	$t3,0x8040
/*  f0c51a0:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c51a4:	44054000 */ 	mfc1	$a1,$f8
/*  f0c51a8:	44815000 */ 	mtc1	$at,$f10
/*  f0c51ac:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c51b0:	44062000 */ 	mfc1	$a2,$f4
/*  f0c51b4:	244c02a0 */ 	addiu	$t4,$v0,0x2a0
/*  f0c51b8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0c51bc:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c51c0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0c51c4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c51c8:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c51cc:	44072000 */ 	mfc1	$a3,$f4
/*  f0c51d0:	0c00a7ff */ 	jal	func00029ffc
/*  f0c51d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c51d8:	afa200e8 */ 	sw	$v0,0xe8($sp)
.L0f0c51dc:
/*  f0c51dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c51e0:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f0c51e4:	c5a60008 */ 	lwc1	$f6,0x8($t5)
/*  f0c51e8:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c51ec:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f0c51f0:	c5c8000c */ 	lwc1	$f8,0xc($t6)
/*  f0c51f4:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f0c51f8:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c51fc:	c5ea0010 */ 	lwc1	$f10,0x10($t7)
/*  f0c5200:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c5204:	8c5802b0 */ 	lw	$t8,0x2b0($v0)
/*  f0c5208:	5300000b */ 	beqzl	$t8,.L0f0c5238
/*  f0c520c:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c5210:	8c5919b8 */ 	lw	$t9,0x19b8($v0)
/*  f0c5214:	c444008c */ 	lwc1	$f4,0x8c($v0)
/*  f0c5218:	44993000 */ 	mtc1	$t9,$f6
/*  f0c521c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5220:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0c5224:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0c5228:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0c522c:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f0c5230:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f0c5234:	8c4400bc */ 	lw	$a0,0xbc($v0)
.L0f0c5238:
/*  f0c5238:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f0c523c:	0fc195e9 */ 	jal	roomsCopy
/*  f0c5240:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c5244:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c5248:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0c524c:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0c5250:	27a600d8 */ 	addiu	$a2,$sp,0xd8
/*  f0c5254:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5258:	27ac00ac */ 	addiu	$t4,$sp,0xac
/*  f0c525c:	27ad00a8 */ 	addiu	$t5,$sp,0xa8
/*  f0c5260:	8c450378 */ 	lw	$a1,0x378($v0)
/*  f0c5264:	2449161e */ 	addiu	$t1,$v0,0x161e
/*  f0c5268:	244a161c */ 	addiu	$t2,$v0,0x161c
/*  f0c526c:	244b19b0 */ 	addiu	$t3,$v0,0x19b0
/*  f0c5270:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0c5274:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0c5278:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0c527c:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0c5280:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0c5284:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c5288:	27a600d8 */ 	addiu	$a2,$sp,0xd8
/*  f0c528c:	0c00a86c */ 	jal	func0002a1b0
/*  f0c5290:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f0c5294:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5298:	3c017f1b */ 	lui	$at,%hi(var7f1ad794)
/*  f0c529c:	c426d794 */ 	lwc1	$f6,%lo(var7f1ad794)($at)
/*  f0c52a0:	c4481ae8 */ 	lwc1	$f8,0x1ae8($v0)
/*  f0c52a4:	46080380 */ 	add.s	$f14,$f0,$f8
/*  f0c52a8:	4606703c */ 	c.lt.s	$f14,$f6
/*  f0c52ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c52b0:	45000002 */ 	bc1f	.L0f0c52bc
/*  f0c52b4:	3c017f1b */ 	lui	$at,%hi(var7f1ad798)
/*  f0c52b8:	c42ed798 */ 	lwc1	$f14,%lo(var7f1ad798)($at)
.L0f0c52bc:
/*  f0c52bc:	8c4302b0 */ 	lw	$v1,0x2b0($v0)
/*  f0c52c0:	10600009 */ 	beqz	$v1,.L0f0c52e8
/*  f0c52c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c52c8:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f0c52cc:	15c00006 */ 	bnez	$t6,.L0f0c52e8
/*  f0c52d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c52d4:	0fc20b5d */ 	jal	func0f082d74
/*  f0c52d8:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0c52dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c52e0:	c7ae00f0 */ 	lwc1	$f14,0xf0($sp)
/*  f0c52e4:	8c4302b0 */ 	lw	$v1,0x2b0($v0)
.L0f0c52e8:
/*  f0c52e8:	50600050 */ 	beqzl	$v1,.L0f0c542c
/*  f0c52ec:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0c52f0:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0c52f4:	51e0004d */ 	beqzl	$t7,.L0f0c542c
/*  f0c52f8:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0c52fc:	8c5802ac */ 	lw	$t8,0x2ac($v0)
/*  f0c5300:	5700004a */ 	bnezl	$t8,.L0f0c542c
/*  f0c5304:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0c5308:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c530c:	44805000 */ 	mtc1	$zero,$f10
/*  f0c5310:	46007301 */ 	sub.s	$f12,$f14,$f0
/*  f0c5314:	460a6032 */ 	c.eq.s	$f12,$f10
/*  f0c5318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c531c:	45030044 */ 	bc1tl	.L0f0c5430
/*  f0c5320:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0c5324:	8c590030 */ 	lw	$t9,0x30($v0)
/*  f0c5328:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0c532c:	57200036 */ 	bnezl	$t9,.L0f0c5408
/*  f0c5330:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5334:	8c4a0298 */ 	lw	$t2,0x298($v0)
/*  f0c5338:	552a0033 */ 	bnel	$t1,$t2,.L0f0c5408
/*  f0c533c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5340:	c4440294 */ 	lwc1	$f4,0x294($v0)
/*  f0c5344:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c5348:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c534c:	44813000 */ 	mtc1	$at,$f6
/*  f0c5350:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f0c5354:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c5358:	4606103c */ 	c.lt.s	$f2,$f6
/*  f0c535c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5360:	45020029 */ 	bc1fl	.L0f0c5408
/*  f0c5364:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5368:	44815000 */ 	mtc1	$at,$f10
/*  f0c536c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5370:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0c5374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5378:	45020023 */ 	bc1fl	.L0f0c5408
/*  f0c537c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5380:	44804000 */ 	mtc1	$zero,$f8
/*  f0c5384:	460c0100 */ 	add.s	$f4,$f0,$f12
/*  f0c5388:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c538c:	e4440078 */ 	swc1	$f4,0x78($v0)
/*  f0c5390:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f0c5394:	45030012 */ 	bc1tl	.L0f0c53e0
/*  f0c5398:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c539c:	51600010 */ 	beqzl	$t3,.L0f0c53e0
/*  f0c53a0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c53a4:	8d620004 */ 	lw	$v0,0x4($t3)
/*  f0c53a8:	5040000d */ 	beqzl	$v0,.L0f0c53e0
/*  f0c53ac:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c53b0:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*  f0c53b4:	000c6800 */ 	sll	$t5,$t4,0x0
/*  f0c53b8:	05a30009 */ 	bgezl	$t5,.L0f0c53e0
/*  f0c53bc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c53c0:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
/*  f0c53c4:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c53c8:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0c53cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c53d0:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f0c53d4:	1441000b */ 	bne	$v0,$at,.L0f0c5404
/*  f0c53d8:	c7ae00f0 */ 	lwc1	$f14,0xf0($sp)
/*  f0c53dc:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c53e0:
/*  f0c53e0:	3c017f1b */ 	lui	$at,%hi(var7f1ad79c)
/*  f0c53e4:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c53e8:	460c3280 */ 	add.s	$f10,$f6,$f12
/*  f0c53ec:	e44a0074 */ 	swc1	$f10,0x74($v0)
/*  f0c53f0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c53f4:	c428d79c */ 	lwc1	$f8,%lo(var7f1ad79c)($at)
/*  f0c53f8:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c53fc:	46082183 */ 	div.s	$f6,$f4,$f8
/*  f0c5400:	e4460070 */ 	swc1	$f6,0x70($v0)
.L0f0c5404:
/*  f0c5404:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5408:
/*  f0c5408:	8c4e1af8 */ 	lw	$t6,0x1af8($v0)
/*  f0c540c:	51c00008 */ 	beqzl	$t6,.L0f0c5430
/*  f0c5410:	8faf00ac */ 	lw	$t7,0xac($sp)
/*  f0c5414:	c44a1b54 */ 	lwc1	$f10,0x1b54($v0)
/*  f0c5418:	460c5100 */ 	add.s	$f4,$f10,$f12
/*  f0c541c:	e4441b54 */ 	swc1	$f4,0x1b54($v0)
/*  f0c5420:	10000002 */ 	beqz	$zero,.L0f0c542c
/*  f0c5424:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5428:	afa000a8 */ 	sw	$zero,0xa8($sp)
.L0f0c542c:
/*  f0c542c:	8faf00ac */ 	lw	$t7,0xac($sp)
.L0f0c5430:
/*  f0c5430:	ac4f02b0 */ 	sw	$t7,0x2b0($v0)
/*  f0c5434:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f0c5438:	53000004 */ 	beqzl	$t8,.L0f0c544c
/*  f0c543c:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0c5440:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c5444:	e72e0294 */ 	swc1	$f14,0x294($t9)
/*  f0c5448:	8fa900a8 */ 	lw	$t1,0xa8($sp)
.L0f0c544c:
/*  f0c544c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c5450:	ad490298 */ 	sw	$t1,0x298($t2)
/*  f0c5454:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5458:	8c4b02ac */ 	lw	$t3,0x2ac($v0)
/*  f0c545c:	51600027 */ 	beqzl	$t3,.L0f0c54fc
/*  f0c5460:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0c5464:	c44c029c */ 	lwc1	$f12,0x29c($v0)
/*  f0c5468:	44804000 */ 	mtc1	$zero,$f8
/*  f0c546c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5470:	460c403e */ 	c.le.s	$f8,$f12
/*  f0c5474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5478:	4501000b */ 	bc1t	.L0f0c54a8
/*  f0c547c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5480:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c5484:	4602703e */ 	c.le.s	$f14,$f2
/*  f0c5488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c548c:	45020012 */ 	bc1fl	.L0f0c54d8
/*  f0c5490:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c5494:	460c1180 */ 	add.s	$f6,$f2,$f12
/*  f0c5498:	4606703e */ 	c.le.s	$f14,$f6
/*  f0c549c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c54a0:	4502000d */ 	bc1fl	.L0f0c54d8
/*  f0c54a4:	46027301 */ 	sub.s	$f12,$f14,$f2
.L0f0c54a8:
/*  f0c54a8:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c54ac:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0c54b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c54b4:	14410010 */ 	bne	$v0,$at,.L0f0c54f8
/*  f0c54b8:	c7ae00f0 */ 	lwc1	$f14,0xf0($sp)
/*  f0c54bc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c54c0:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c54c4:	c444029c */ 	lwc1	$f4,0x29c($v0)
/*  f0c54c8:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0c54cc:	1000000a */ 	beqz	$zero,.L0f0c54f8
/*  f0c54d0:	e4480074 */ 	swc1	$f8,0x74($v0)
/*  f0c54d4:	46027301 */ 	sub.s	$f12,$f14,$f2
.L0f0c54d8:
/*  f0c54d8:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c54dc:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0c54e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c54e4:	14410004 */ 	bne	$v0,$at,.L0f0c54f8
/*  f0c54e8:	c7ae00f0 */ 	lwc1	$f14,0xf0($sp)
/*  f0c54ec:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c54f0:	e58e0074 */ 	swc1	$f14,0x74($t4)
/*  f0c54f4:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f0c54f8:
/*  f0c54f8:	8fad00ec */ 	lw	$t5,0xec($sp)
.L0f0c54fc:
/*  f0c54fc:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c5500:	44802000 */ 	mtc1	$zero,$f4
/*  f0c5504:	adcd02ac */ 	sw	$t5,0x2ac($t6)
/*  f0c5508:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c550c:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f0c5510:	8c4f02ac */ 	lw	$t7,0x2ac($v0)
/*  f0c5514:	11e00005 */ 	beqz	$t7,.L0f0c552c
/*  f0c5518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c551c:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c5520:	e4460078 */ 	swc1	$f6,0x78($v0)
/*  f0c5524:	10000005 */ 	beqz	$zero,.L0f0c553c
/*  f0c5528:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c552c:
/*  f0c552c:	57000004 */ 	bnezl	$t8,.L0f0c5540
/*  f0c5530:	c44a0080 */ 	lwc1	$f10,0x80($v0)
/*  f0c5534:	e44e0078 */ 	swc1	$f14,0x78($v0)
/*  f0c5538:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c553c:
/*  f0c553c:	c44a0080 */ 	lwc1	$f10,0x80($v0)
.L0f0c5540:
/*  f0c5540:	3c017f1b */ 	lui	$at,%hi(var7f1ad7a0)
/*  f0c5544:	460a203e */ 	c.le.s	$f4,$f10
/*  f0c5548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c554c:	45030008 */ 	bc1tl	.L0f0c5570
/*  f0c5550:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c5554:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c5558:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c555c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c5560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5564:	45020078 */ 	bc1fl	.L0f0c5748
/*  f0c5568:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c556c:	c4480074 */ 	lwc1	$f8,0x74($v0)
.L0f0c5570:
/*  f0c5570:	c426d7a0 */ 	lwc1	$f6,%lo(var7f1ad7a0)($at)
/*  f0c5574:	3c017f1b */ 	lui	$at,%hi(var7f1ad7a4)
/*  f0c5578:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c557c:	46064283 */ 	div.s	$f10,$f8,$f6
/*  f0c5580:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c5584:	8e190034 */ 	lw	$t9,0x34($s0)
/*  f0c5588:	5b20000e */ 	blezl	$t9,.L0f0c55c4
/*  f0c558c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5590:	c420d7a4 */ 	lwc1	$f0,%lo(var7f1ad7a4)($at)
/*  f0c5594:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5598:
/*  f0c5598:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c559c:	c4440070 */ 	lwc1	$f4,0x70($v0)
/*  f0c55a0:	c4460078 */ 	lwc1	$f6,0x78($v0)
/*  f0c55a4:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0c55a8:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0c55ac:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c55b0:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0c55b4:	0069082a */ 	slt	$at,$v1,$t1
/*  f0c55b8:	5420fff7 */ 	bnezl	$at,.L0f0c5598
/*  f0c55bc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c55c0:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c55c4:
/*  f0c55c4:	3c017f1b */ 	lui	$at,%hi(var7f1ad7a8)
/*  f0c55c8:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c55cc:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c55d0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c55d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c55d8:	45020041 */ 	bc1fl	.L0f0c56e0
/*  f0c55dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c55e0:	c4440070 */ 	lwc1	$f4,0x70($v0)
/*  f0c55e4:	c428d7a8 */ 	lwc1	$f8,%lo(var7f1ad7a8)($at)
/*  f0c55e8:	3c014248 */ 	lui	$at,0x4248
/*  f0c55ec:	44813000 */ 	mtc1	$at,$f6
/*  f0c55f0:	46082382 */ 	mul.s	$f14,$f4,$f8
/*  f0c55f4:	46060301 */ 	sub.s	$f12,$f0,$f6
/*  f0c55f8:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0c55fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5600:	45020003 */ 	bc1fl	.L0f0c5610
/*  f0c5604:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c5608:	46006386 */ 	mov.s	$f14,$f12
/*  f0c560c:	46027301 */ 	sub.s	$f12,$f14,$f2
.L0f0c5610:
/*  f0c5610:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c5614:	e7ae00a4 */ 	swc1	$f14,0xa4($sp)
/*  f0c5618:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c561c:	14410004 */ 	bne	$v0,$at,.L0f0c5630
/*  f0c5620:	c7ae00a4 */ 	lwc1	$f14,0xa4($sp)
/*  f0c5624:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c5628:	1000002c */ 	beqz	$zero,.L0f0c56dc
/*  f0c562c:	e54e0074 */ 	swc1	$f14,0x74($t2)
.L0f0c5630:
/*  f0c5630:	0c0093ac */ 	jal	func00024eb0
/*  f0c5634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5638:	50400029 */ 	beqzl	$v0,.L0f0c56e0
/*  f0c563c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5640:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c5644:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f0c5648:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0c564c:	c58a000c */ 	lwc1	$f10,0xc($t4)
/*  f0c5650:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0c5654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5658:	45020021 */ 	bc1fl	.L0f0c56e0
/*  f0c565c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5660:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f0c5664:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c5668:	55a1001d */ 	bnel	$t5,$at,.L0f0c56e0
/*  f0c566c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5670:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c5674:	2401003a */ 	addiu	$at,$zero,0x3a
/*  f0c5678:	848e0004 */ 	lh	$t6,0x4($a0)
/*  f0c567c:	55c10018 */ 	bnel	$t6,$at,.L0f0c56e0
/*  f0c5680:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5684:	848f004e */ 	lh	$t7,0x4e($a0)
/*  f0c5688:	8498004c */ 	lh	$t8,0x4c($a0)
/*  f0c568c:	3c01437a */ 	lui	$at,0x437a
/*  f0c5690:	44815000 */ 	mtc1	$at,$f10
/*  f0c5694:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f0c5698:	27290001 */ 	addiu	$t1,$t9,0x1
/*  f0c569c:	44894000 */ 	mtc1	$t1,$f8
/*  f0c56a0:	8c8a0008 */ 	lw	$t2,0x8($a0)
/*  f0c56a4:	3c01fffd */ 	lui	$at,0xfffd
/*  f0c56a8:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0c56ac:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0c56b0:	8c860014 */ 	lw	$a2,0x14($a0)
/*  f0c56b4:	01415824 */ 	and	$t3,$t2,$at
/*  f0c56b8:	ac8b0008 */ 	sw	$t3,0x8($a0)
/*  f0c56bc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0c56c0:	460a3003 */ 	div.s	$f0,$f6,$f10
/*  f0c56c4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c56c8:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f0c56cc:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0c56d0:	44050000 */ 	mfc1	$a1,$f0
/*  f0c56d4:	0fc214ab */ 	jal	func0f0852ac
/*  f0c56d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c56dc:
/*  f0c56dc:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c56e0:
/*  f0c56e0:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c56e4:	944d161c */ 	lhu	$t5,0x161c($v0)
/*  f0c56e8:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c56ec:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c56f0:	31ae4000 */ 	andi	$t6,$t5,0x4000
/*  f0c56f4:	51c00014 */ 	beqzl	$t6,.L0f0c5748
/*  f0c56f8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c56fc:	44812000 */ 	mtc1	$at,$f4
/*  f0c5700:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5704:	46041201 */ 	sub.s	$f8,$f2,$f4
/*  f0c5708:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c570c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5710:	4502000d */ 	bc1fl	.L0f0c5748
/*  f0c5714:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c5718:	8c4f02ac */ 	lw	$t7,0x2ac($v0)
/*  f0c571c:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f0c5720:	55e00009 */ 	bnezl	$t7,.L0f0c5748
/*  f0c5724:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c5728:	57000007 */ 	bnezl	$t8,.L0f0c5748
/*  f0c572c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c5730:	0fc304ea */ 	jal	func0f0c13a8
/*  f0c5734:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c5738:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c573c:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c5740:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c5744:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0c5748:
/*  f0c5748:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c574c:	3c017f1b */ 	lui	$at,%hi(var7f1ad7ac)
/*  f0c5750:	450200ba */ 	bc1fl	.L0f0c5a3c
/*  f0c5754:	8c490030 */ 	lw	$t1,0x30($v0)
/*  f0c5758:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c575c:	e7a20090 */ 	swc1	$f2,0x90($sp)
/*  f0c5760:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f0c5764:	0fc47b82 */ 	jal	func0f11ee08
/*  f0c5768:	e7ae008c */ 	swc1	$f14,0x8c($sp)
/*  f0c576c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5770:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*  f0c5774:	10400011 */ 	beqz	$v0,.L0f0c57bc
/*  f0c5778:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0c577c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5780:	44803000 */ 	mtc1	$zero,$f6
/*  f0c5784:	c44a1b6c */ 	lwc1	$f10,0x1b6c($v0)
/*  f0c5788:	460a3032 */ 	c.eq.s	$f6,$f10
/*  f0c578c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5790:	4500000a */ 	bc1f	.L0f0c57bc
/*  f0c5794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5798:	44802000 */ 	mtc1	$zero,$f4
/*  f0c579c:	c4481b74 */ 	lwc1	$f8,0x1b74($v0)
/*  f0c57a0:	3c017f1b */ 	lui	$at,%hi(var7f1ad7b0)
/*  f0c57a4:	46082032 */ 	c.eq.s	$f4,$f8
/*  f0c57a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c57ac:	45000003 */ 	bc1f	.L0f0c57bc
/*  f0c57b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c57b4:	10000004 */ 	beqz	$zero,.L0f0c57c8
/*  f0c57b8:	c432d7ac */ 	lwc1	$f18,%lo(var7f1ad7ac)($at)
.L0f0c57bc:
/*  f0c57bc:	3c017f1b */ 	lui	$at,%hi(var7f1ad7b4)
/*  f0c57c0:	c432d7b0 */ 	lwc1	$f18,%lo(var7f1ad7b0)($at)
/*  f0c57c4:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c57c8:
/*  f0c57c8:	c60c004c */ 	lwc1	$f12,0x4c($s0)
/*  f0c57cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c57d0:	44814000 */ 	mtc1	$at,$f8
/*  f0c57d4:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f0c57d8:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c57dc:	46067081 */ 	sub.s	$f2,$f14,$f6
/*  f0c57e0:	46027280 */ 	add.s	$f10,$f14,$f2
/*  f0c57e4:	46001386 */ 	mov.s	$f14,$f2
/*  f0c57e8:	460a6102 */ 	mul.s	$f4,$f12,$f10
/*  f0c57ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c57f0:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0c57f4:	46068400 */ 	add.s	$f16,$f16,$f6
/*  f0c57f8:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c57fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5800:	45000016 */ 	bc1f	.L0f0c585c
/*  f0c5804:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5808:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c580c:	3c014270 */ 	lui	$at,0x4270
/*  f0c5810:	44819000 */ 	mtc1	$at,$f18
/*  f0c5814:	46005081 */ 	sub.s	$f2,$f10,$f0
/*  f0c5818:	3c017f1b */ 	lui	$at,%hi(var7f1ad7b8)
/*  f0c581c:	c428d7b4 */ 	lwc1	$f8,%lo(var7f1ad7b4)($at)
/*  f0c5820:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c5824:	46021100 */ 	add.s	$f4,$f2,$f2
/*  f0c5828:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f0c582c:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5830:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0c5834:	46123283 */ 	div.s	$f10,$f6,$f18
/*  f0c5838:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0c583c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5840:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0c5844:	0c012974 */ 	jal	sqrtf
/*  f0c5848:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f0c584c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5850:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0c5854:	46000387 */ 	neg.s	$f14,$f0
/*  f0c5858:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c585c:
/*  f0c585c:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c5860:	e7b00090 */ 	swc1	$f16,0x90($sp)
/*  f0c5864:	e7ae008c */ 	swc1	$f14,0x8c($sp)
/*  f0c5868:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c586c:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c5870:	46068301 */ 	sub.s	$f12,$f16,$f6
/*  f0c5874:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c5878:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c587c:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*  f0c5880:	1441001c */ 	bne	$v0,$at,.L0f0c58f4
/*  f0c5884:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0c5888:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c588c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c5890:	e7300074 */ 	swc1	$f16,0x74($t9)
/*  f0c5894:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c5898:	e52e0080 */ 	swc1	$f14,0x80($t1)
/*  f0c589c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c58a0:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c58a4:	55400008 */ 	bnezl	$t2,.L0f0c58c8
/*  f0c58a8:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0c58ac:	ac4b0030 */ 	sw	$t3,0x30($v0)
/*  f0c58b0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c58b4:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0c58b8:	adac0034 */ 	sw	$t4,0x34($t5)
/*  f0c58bc:	1000006e */ 	beqz	$zero,.L0f0c5a78
/*  f0c58c0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c58c4:	8e0e0008 */ 	lw	$t6,0x8($s0)
.L0f0c58c8:
/*  f0c58c8:	8c4f0034 */ 	lw	$t7,0x34($v0)
/*  f0c58cc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c58d0:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0c58d4:	2b0100f1 */ 	slti	$at,$t8,0xf1
/*  f0c58d8:	54200068 */ 	bnezl	$at,.L0f0c5a7c
/*  f0c58dc:	44808000 */ 	mtc1	$zero,$f16
/*  f0c58e0:	0fc304ea */ 	jal	func0f0c13a8
/*  f0c58e4:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c58e8:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c58ec:	10000062 */ 	beqz	$zero,.L0f0c5a78
/*  f0c58f0:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c58f4:
/*  f0c58f4:	8e190318 */ 	lw	$t9,0x318($s0)
/*  f0c58f8:	5720003a */ 	bnezl	$t9,.L0f0c59e4
/*  f0c58fc:	44804000 */ 	mtc1	$zero,$f8
/*  f0c5900:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5904:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c5908:	44812000 */ 	mtc1	$at,$f4
/*  f0c590c:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c5910:	c44a0078 */ 	lwc1	$f10,0x78($v0)
/*  f0c5914:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f0c5918:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0c591c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5920:	45020030 */ 	bc1fl	.L0f0c59e4
/*  f0c5924:	44804000 */ 	mtc1	$zero,$f8
/*  f0c5928:	0c0093ac */ 	jal	func00024eb0
/*  f0c592c:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5930:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5934:	1040002a */ 	beqz	$v0,.L0f0c59e0
/*  f0c5938:	00403825 */ 	or	$a3,$v0,$zero
/*  f0c593c:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f0c5940:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c5944:	5481000f */ 	bnel	$a0,$at,.L0f0c5984
/*  f0c5948:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c594c:	8c490004 */ 	lw	$t1,0x4($v0)
/*  f0c5950:	812b032d */ 	lb	$t3,0x32d($t1)
/*  f0c5954:	05630023 */ 	bgezl	$t3,.L0f0c59e4
/*  f0c5958:	44804000 */ 	mtc1	$zero,$f8
/*  f0c595c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c5960:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c5964:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f0c5968:	8d8500bc */ 	lw	$a1,0xbc($t4)
/*  f0c596c:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5970:	0fc0cc8f */ 	jal	func0f03323c
/*  f0c5974:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0c5978:	10000019 */ 	beqz	$zero,.L0f0c59e0
/*  f0c597c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5980:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0c5984:
/*  f0c5984:	54810017 */ 	bnel	$a0,$at,.L0f0c59e4
/*  f0c5988:	44804000 */ 	mtc1	$zero,$f8
/*  f0c598c:	8e0d028c */ 	lw	$t5,0x28c($s0)
/*  f0c5990:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0c5994:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5998:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c599c:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0c59a0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0c59a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c59a8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c59ac:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c59b0:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0c59b4:	8dcf02b0 */ 	lw	$t7,0x2b0($t6)
/*  f0c59b8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c59bc:	51e00005 */ 	beqzl	$t7,.L0f0c59d4
/*  f0c59c0:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0c59c4:	0fc30501 */ 	jal	func0f0c1404
/*  f0c59c8:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c59cc:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c59d0:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f0c59d4:
/*  f0c59d4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0c59d8:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c59dc:	8fa30104 */ 	lw	$v1,0x104($sp)
.L0f0c59e0:
/*  f0c59e0:	44804000 */ 	mtc1	$zero,$f8
.L0f0c59e4:
/*  f0c59e4:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c59e8:	3c017f1b */ 	lui	$at,%hi(var7f1ad7bc)
/*  f0c59ec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c59f0:	e7080080 */ 	swc1	$f8,0x80($t8)
/*  f0c59f4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c59f8:	8c590030 */ 	lw	$t9,0x30($v0)
/*  f0c59fc:	13200003 */ 	beqz	$t9,.L0f0c5a0c
/*  f0c5a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5a04:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c5a08:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5a0c:
/*  f0c5a0c:	c424d7b8 */ 	lwc1	$f4,%lo(var7f1ad7b8)($at)
/*  f0c5a10:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c5a14:	4604503e */ 	c.le.s	$f10,$f4
/*  f0c5a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5a1c:	45020017 */ 	bc1fl	.L0f0c5a7c
/*  f0c5a20:	44808000 */ 	mtc1	$zero,$f16
/*  f0c5a24:	0fc304ea */ 	jal	func0f0c13a8
/*  f0c5a28:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5a2c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5a30:	10000011 */ 	beqz	$zero,.L0f0c5a78
/*  f0c5a34:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5a38:	8c490030 */ 	lw	$t1,0x30($v0)
.L0f0c5a3c:
/*  f0c5a3c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c5a40:	11200004 */ 	beqz	$t1,.L0f0c5a54
/*  f0c5a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5a48:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c5a4c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5a50:	c4420074 */ 	lwc1	$f2,0x74($v0)
.L0f0c5a54:
/*  f0c5a54:	c426d7bc */ 	lwc1	$f6,%lo(var7f1ad7bc)($at)
/*  f0c5a58:	4606103e */ 	c.le.s	$f2,$f6
/*  f0c5a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5a60:	45020006 */ 	bc1fl	.L0f0c5a7c
/*  f0c5a64:	44808000 */ 	mtc1	$zero,$f16
/*  f0c5a68:	0fc304ea */ 	jal	func0f0c13a8
/*  f0c5a6c:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5a70:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5a74:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5a78:
/*  f0c5a78:	44808000 */ 	mtc1	$zero,$f16
.L0f0c5a7c:
/*  f0c5a7c:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c5a80:	4610703c */ 	c.lt.s	$f14,$f16
/*  f0c5a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5a88:	450200c5 */ 	bc1fl	.L0f0c5da0
/*  f0c5a8c:	8e190034 */ 	lw	$t9,0x34($s0)
/*  f0c5a90:	c4480078 */ 	lwc1	$f8,0x78($v0)
/*  f0c5a94:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c5a98:	3c017f1b */ 	lui	$at,%hi(var7f1ad7c0)
/*  f0c5a9c:	4608203e */ 	c.le.s	$f4,$f8
/*  f0c5aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5aa4:	450200be */ 	bc1fl	.L0f0c5da0
/*  f0c5aa8:	8e190034 */ 	lw	$t9,0x34($s0)
/*  f0c5aac:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c5ab0:	240b003c */ 	addiu	$t3,$zero,0x3c
/*  f0c5ab4:	11400004 */ 	beqz	$t2,.L0f0c5ac8
/*  f0c5ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5abc:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c5ac0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5ac4:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.L0f0c5ac8:
/*  f0c5ac8:	c42ad7c0 */ 	lwc1	$f10,%lo(var7f1ad7c0)($at)
/*  f0c5acc:	3c01c0a0 */ 	lui	$at,0xc0a0
/*  f0c5ad0:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c5ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5ad8:	4502000a */ 	bc1fl	.L0f0c5b04
/*  f0c5adc:	44810000 */ 	mtc1	$at,$f0
/*  f0c5ae0:	ac4b0090 */ 	sw	$t3,0x90($v0)
/*  f0c5ae4:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c5ae8:	44813000 */ 	mtc1	$at,$f6
/*  f0c5aec:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c5af0:	e5860094 */ 	swc1	$f6,0x94($t4)
/*  f0c5af4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5af8:	10000014 */ 	beqz	$zero,.L0f0c5b4c
/*  f0c5afc:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c5b00:	44810000 */ 	mtc1	$at,$f0
.L0f0c5b04:
/*  f0c5b04:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f0c5b08:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c5b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5b10:	4502000f */ 	bc1fl	.L0f0c5b50
/*  f0c5b14:	3c01c0c0 */ 	lui	$at,0xc0c0
/*  f0c5b18:	ac4d0090 */ 	sw	$t5,0x90($v0)
/*  f0c5b1c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5b20:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c5b24:	44815000 */ 	mtc1	$at,$f10
/*  f0c5b28:	c4480080 */ 	lwc1	$f8,0x80($v0)
/*  f0c5b2c:	3c017f1b */ 	lui	$at,%hi(var7f1ad7c4)
/*  f0c5b30:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f0c5b34:	c428d7c4 */ 	lwc1	$f8,%lo(var7f1ad7c4)($at)
/*  f0c5b38:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0c5b3c:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f0c5b40:	e4440094 */ 	swc1	$f4,0x94($v0)
/*  f0c5b44:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5b48:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.L0f0c5b4c:
/*  f0c5b4c:	3c01c0c0 */ 	lui	$at,0xc0c0
.L0f0c5b50:
/*  f0c5b50:	44815000 */ 	mtc1	$at,$f10
/*  f0c5b54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5b58:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c5b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5b60:	4502008c */ 	bc1fl	.L0f0c5d94
/*  f0c5b64:	44808000 */ 	mtc1	$zero,$f16
/*  f0c5b68:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f0c5b6c:	904f161e */ 	lbu	$t7,0x161e($v0)
/*  f0c5b70:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c5b74:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f0c5b78:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c5b7c:	a08f0191 */ 	sb	$t7,0x191($a0)
/*  f0c5b80:	a0980190 */ 	sb	$t8,0x190($a0)
/*  f0c5b84:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5b88:	0fc0181d */ 	jal	func0f006074
/*  f0c5b8c:	afa40074 */ 	sw	$a0,0x74($sp)
/*  f0c5b90:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c5b94:	10410043 */ 	beq	$v0,$at,.L0f0c5ca4
/*  f0c5b98:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5b9c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c5ba0:	1041001a */ 	beq	$v0,$at,.L0f0c5c0c
/*  f0c5ba4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c5ba8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c5bac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c5bb0:	44810000 */ 	mtc1	$at,$f0
/*  f0c5bb4:	8f2500bc */ 	lw	$a1,0xbc($t9)
/*  f0c5bb8:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c5bbc:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0c5bc0:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c5bc4:	340b8400 */ 	dli	$t3,0x8400
/*  f0c5bc8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0c5bcc:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f0c5bd0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0c5bd4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c5bd8:	01203025 */ 	or	$a2,$t1,$zero
/*  f0c5bdc:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5be0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c5be4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c5be8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c5bec:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c5bf0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c5bf4:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0c5bf8:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0c5bfc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0c5c00:	0fc24e7e */ 	jal	func0f0939f8
/*  f0c5c04:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0c5c08:	8fa30104 */ 	lw	$v1,0x104($sp)
.L0f0c5c0c:
/*  f0c5c0c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c5c10:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0c5c14:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c5c18:	a08d0190 */ 	sb	$t5,0x190($a0)
/*  f0c5c1c:	0fc0181d */ 	jal	func0f006074
/*  f0c5c20:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5c24:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c5c28:	1041001e */ 	beq	$v0,$at,.L0f0c5ca4
/*  f0c5c2c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5c30:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c5c34:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c5c38:	44813000 */ 	mtc1	$at,$f6
/*  f0c5c3c:	8dc500bc */ 	lw	$a1,0xbc($t6)
/*  f0c5c40:	44814000 */ 	mtc1	$at,$f8
/*  f0c5c44:	44812000 */ 	mtc1	$at,$f4
/*  f0c5c48:	44815000 */ 	mtc1	$at,$f10
/*  f0c5c4c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c5c50:	00067c03 */ 	sra	$t7,$a2,0x10
/*  f0c5c54:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0c5c58:	34198400 */ 	dli	$t9,0x8400
/*  f0c5c5c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0c5c60:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f0c5c64:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0c5c68:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0c5c6c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0c5c70:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5c74:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c5c78:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c5c7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c5c80:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c5c84:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c5c88:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c5c8c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0c5c90:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0c5c94:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f0c5c98:	0fc24e7e */ 	jal	func0f0939f8
/*  f0c5c9c:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c5ca0:	8fa30104 */ 	lw	$v1,0x104($sp)
.L0f0c5ca4:
/*  f0c5ca4:	8e0a0314 */ 	lw	$t2,0x314($s0)
/*  f0c5ca8:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f0c5cac:	55400039 */ 	bnezl	$t2,.L0f0c5d94
/*  f0c5cb0:	44808000 */ 	mtc1	$zero,$f16
/*  f0c5cb4:	81620006 */ 	lb	$v0,0x6($t3)
/*  f0c5cb8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c5cbc:	10410003 */ 	beq	$v0,$at,.L0f0c5ccc
/*  f0c5cc0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0c5cc4:	54410033 */ 	bnel	$v0,$at,.L0f0c5d94
/*  f0c5cc8:	44808000 */ 	mtc1	$zero,$f16
.L0f0c5ccc:
/*  f0c5ccc:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c5cd0:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0c5cd4:	3c198007 */ 	lui	$t9,%hi(var80070e50)
/*  f0c5cd8:	8dae0034 */ 	lw	$t6,0x34($t5)
/*  f0c5cdc:	27390e50 */ 	addiu	$t9,$t9,%lo(var80070e50)
/*  f0c5ce0:	018e7823 */ 	subu	$t7,$t4,$t6
/*  f0c5ce4:	29e10029 */ 	slti	$at,$t7,0x29
/*  f0c5ce8:	5420002a */ 	bnezl	$at,.L0f0c5d94
/*  f0c5cec:	44808000 */ 	mtc1	$zero,$f16
/*  f0c5cf0:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0c5cf4:	27b80068 */ 	addiu	$t8,$sp,0x68
/*  f0c5cf8:	8f2a0004 */ 	lw	$t2,0x4($t9)
/*  f0c5cfc:	af010000 */ 	sw	$at,0x0($t8)
/*  f0c5d00:	8f210008 */ 	lw	$at,0x8($t9)
/*  f0c5d04:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f0c5d08:	af010008 */ 	sw	$at,0x8($t8)
/*  f0c5d0c:	0c004b70 */ 	jal	random
/*  f0c5d10:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f0c5d14:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c5d18:	0041001b */ 	divu	$zero,$v0,$at
/*  f0c5d1c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c5d20:	00006810 */ 	mfhi	$t5
/*  f0c5d24:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f0c5d28:	03ac3021 */ 	addu	$a2,$sp,$t4
/*  f0c5d2c:	84c6006a */ 	lh	$a2,0x6a($a2)
/*  f0c5d30:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f0c5d34:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c5d38:	44813000 */ 	mtc1	$at,$f6
/*  f0c5d3c:	44814000 */ 	mtc1	$at,$f8
/*  f0c5d40:	44812000 */ 	mtc1	$at,$f4
/*  f0c5d44:	44815000 */ 	mtc1	$at,$f10
/*  f0c5d48:	240effff */ 	addiu	$t6,$zero,-1
/*  f0c5d4c:	340f8400 */ 	dli	$t7,0x8400
/*  f0c5d50:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0c5d54:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f0c5d58:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0c5d5c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c5d60:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c5d64:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c5d68:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c5d6c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c5d70:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c5d74:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c5d78:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0c5d7c:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0c5d80:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f0c5d84:	0fc24e7e */ 	jal	func0f0939f8
/*  f0c5d88:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c5d8c:	8fa30104 */ 	lw	$v1,0x104($sp)
/*  f0c5d90:	44808000 */ 	mtc1	$zero,$f16
.L0f0c5d94:
/*  f0c5d94:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c5d98:	e7100080 */ 	swc1	$f16,0x80($t8)
/*  f0c5d9c:	8e190034 */ 	lw	$t9,0x34($s0)
.L0f0c5da0:
/*  f0c5da0:	3c01bf90 */ 	lui	$at,0xbf90
/*  f0c5da4:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c5da8:	1b20002b */ 	blez	$t9,.L0f0c5e58
/*  f0c5dac:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f0c5db0:	44816000 */ 	mtc1	$at,$f12
/*  f0c5db4:	3c017f1b */ 	lui	$at,%hi(var7f1ad7c8)
/*  f0c5db8:	c422d7c8 */ 	lwc1	$f2,%lo(var7f1ad7c8)($at)
/*  f0c5dbc:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5dc0:
/*  f0c5dc0:	8c4a0090 */ 	lw	$t2,0x90($v0)
/*  f0c5dc4:	5940000c */ 	blezl	$t2,.L0f0c5df8
/*  f0c5dc8:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c5dcc:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c5dd0:	c4440094 */ 	lwc1	$f4,0x94($v0)
/*  f0c5dd4:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0c5dd8:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0c5ddc:	e44a0088 */ 	swc1	$f10,0x88($v0)
/*  f0c5de0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5de4:	8c4b0090 */ 	lw	$t3,0x90($v0)
/*  f0c5de8:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0c5dec:	10000015 */ 	beqz	$zero,.L0f0c5e44
/*  f0c5df0:	ac4d0090 */ 	sw	$t5,0x90($v0)
/*  f0c5df4:	c4400094 */ 	lwc1	$f0,0x94($v0)
.L0f0c5df8:
/*  f0c5df8:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c5dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5e00:	4502000d */ 	bc1fl	.L0f0c5e38
/*  f0c5e04:	c4480088 */ 	lwc1	$f8,0x88($v0)
/*  f0c5e08:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f0c5e0c:	e4460094 */ 	swc1	$f6,0x94($v0)
/*  f0c5e10:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5e14:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c5e18:	4600803e */ 	c.le.s	$f16,$f0
/*  f0c5e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5e20:	45020005 */ 	bc1fl	.L0f0c5e38
/*  f0c5e24:	c4480088 */ 	lwc1	$f8,0x88($v0)
/*  f0c5e28:	e4500094 */ 	swc1	$f16,0x94($v0)
/*  f0c5e2c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5e30:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c5e34:	c4480088 */ 	lwc1	$f8,0x88($v0)
.L0f0c5e38:
/*  f0c5e38:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0c5e3c:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f0c5e40:	e44a0088 */ 	swc1	$f10,0x88($v0)
.L0f0c5e44:
/*  f0c5e44:	8e0c0034 */ 	lw	$t4,0x34($s0)
/*  f0c5e48:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c5e4c:	006c082a */ 	slt	$at,$v1,$t4
/*  f0c5e50:	5420ffdb */ 	bnezl	$at,.L0f0c5dc0
/*  f0c5e54:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c5e58:
/*  f0c5e58:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5e5c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c5e60:	44811000 */ 	mtc1	$at,$f2
/*  f0c5e64:	3c017f1b */ 	lui	$at,%hi(var7f1ad7cc)
/*  f0c5e68:	c428d7cc */ 	lwc1	$f8,%lo(var7f1ad7cc)($at)
/*  f0c5e6c:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c5e70:	3c017f1b */ 	lui	$at,%hi(var7f1ad7d0)
/*  f0c5e74:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0c5e78:	e444008c */ 	swc1	$f4,0x8c($v0)
/*  f0c5e7c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5e80:	c44a03c4 */ 	lwc1	$f10,0x3c4($v0)
/*  f0c5e84:	c4460414 */ 	lwc1	$f6,0x414($v0)
/*  f0c5e88:	c44419c4 */ 	lwc1	$f4,0x19c4($v0)
/*  f0c5e8c:	46065203 */ 	div.s	$f8,$f10,$f6
/*  f0c5e90:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f0c5e94:	e44a19bc */ 	swc1	$f10,0x19bc($v0)
/*  f0c5e98:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c5e9c:	8c4e19b8 */ 	lw	$t6,0x19b8($v0)
/*  f0c5ea0:	c44619bc */ 	lwc1	$f6,0x19bc($v0)
/*  f0c5ea4:	448e4000 */ 	mtc1	$t6,$f8
/*  f0c5ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5eac:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0c5eb0:	c448008c */ 	lwc1	$f8,0x8c($v0)
/*  f0c5eb4:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0c5eb8:	c44619c4 */ 	lwc1	$f6,0x19c4($v0)
/*  f0c5ebc:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0c5ec0:	c428d7d0 */ 	lwc1	$f8,%lo(var7f1ad7d0)($at)
/*  f0c5ec4:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0c5ec8:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f0c5ecc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c5ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5ed4:	45020003 */ 	bc1fl	.L0f0c5ee4
/*  f0c5ed8:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c5edc:	46001006 */ 	mov.s	$f0,$f2
/*  f0c5ee0:	8c4f00bc */ 	lw	$t7,0xbc($v0)
.L0f0c5ee4:
/*  f0c5ee4:	3c014120 */ 	lui	$at,0x4120
/*  f0c5ee8:	c5e40008 */ 	lwc1	$f4,0x8($t7)
/*  f0c5eec:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f0c5ef0:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c5ef4:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0c5ef8:	44814000 */ 	mtc1	$at,$f8
/*  f0c5efc:	e7aa00c4 */ 	swc1	$f10,0xc4($sp)
/*  f0c5f00:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c5f04:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0c5f08:	c5260010 */ 	lwc1	$f6,0x10($t1)
/*  f0c5f0c:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f0c5f10:	c4440078 */ 	lwc1	$f4,0x78($v0)
/*  f0c5f14:	46082080 */ 	add.s	$f2,$f4,$f8
/*  f0c5f18:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0c5f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f20:	45020003 */ 	bc1fl	.L0f0c5f30
/*  f0c5f24:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c5f28:	e7a200c4 */ 	swc1	$f2,0xc4($sp)
/*  f0c5f2c:	8c4300bc */ 	lw	$v1,0xbc($v0)
.L0f0c5f30:
/*  f0c5f30:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0c5f34:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0c5f38:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0c5f3c:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c5f40:	46043032 */ 	c.eq.s	$f6,$f4
/*  f0c5f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f48:	4500000c */ 	bc1f	.L0f0c5f7c
/*  f0c5f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f50:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0c5f54:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0c5f58:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f0c5f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f60:	45000006 */ 	bc1f	.L0f0c5f7c
/*  f0c5f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f68:	c4640010 */ 	lwc1	$f4,0x10($v1)
/*  f0c5f6c:	46043032 */ 	c.eq.s	$f6,$f4
/*  f0c5f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5f74:	45030018 */ 	bc1tl	.L0f0c5fd8
/*  f0c5f78:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0c5f7c:
/*  f0c5f7c:	0fc1979d */ 	jal	func0f065e74
/*  f0c5f80:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f0c5f84:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c5f88:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c5f8c:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0c5f90:	e7280008 */ 	swc1	$f8,0x8($t9)
/*  f0c5f94:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c5f98:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0c5f9c:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0c5fa0:	e56a000c */ 	swc1	$f10,0xc($t3)
/*  f0c5fa4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c5fa8:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0c5fac:	8dac00bc */ 	lw	$t4,0xbc($t5)
/*  f0c5fb0:	e5860010 */ 	swc1	$f6,0x10($t4)
/*  f0c5fb4:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c5fb8:	0fc19711 */ 	jal	func0f065c44
/*  f0c5fbc:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c5fc0:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c5fc4:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0c5fc8:	8de500bc */ 	lw	$a1,0xbc($t7)
/*  f0c5fcc:	0fc195e9 */ 	jal	roomsCopy
/*  f0c5fd0:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c5fd4:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0c5fd8:
/*  f0c5fd8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0c5fdc:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f0c5fe0:	03e00008 */ 	jr	$ra
/*  f0c5fe4:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerApplyCrouchSpeed(void)
{
	if (currentPlayerGetCrouchPos() == CROUCH_HALF) {
		g_Vars.currentplayer->speedforwards *= 0.5f;
		g_Vars.currentplayer->speedsideways *= 0.5f;
	} else if (currentPlayerGetCrouchPos() == CROUCH_SQUAT) {
		g_Vars.currentplayer->speedforwards *= 0.35f;
		g_Vars.currentplayer->speedsideways *= 0.35f;
	}
}

GLOBAL_ASM(
glabel func0f0c6080
.late_rodata
glabel var7f1ad7d8
.word 0x3bce168a
.text
/*  f0c6080:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c6084:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c6088:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c608c:	3c01428a */ 	lui	$at,0x428a
/*  f0c6090:	44811000 */ 	mtc1	$at,$f2
/*  f0c6094:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c6098:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c609c:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c60a0:	44816000 */ 	mtc1	$at,$f12
/*  f0c60a4:	c44019c4 */ 	lwc1	$f0,0x19c4($v0)
/*  f0c60a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad7d8)
/*  f0c60ac:	c42ed7d8 */ 	lwc1	$f14,%lo(var7f1ad7d8)($at)
/*  f0c60b0:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0c60b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c60b8:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0c60bc:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0c60c0:	4602403c */ 	c.lt.s	$f8,$f2
/*  f0c60c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c60c8:	45000009 */ 	bc1f	.L0f0c60f0
/*  f0c60cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c60d0:	46001401 */ 	sub.s	$f16,$f2,$f0
/*  f0c60d4:	c44a00b4 */ 	lwc1	$f10,0xb4($v0)
/*  f0c60d8:	460c8483 */ 	div.s	$f18,$f16,$f12
/*  f0c60dc:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0c60e0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0c60e4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0c60e8:	10000009 */ 	beqz	$zero,.L0f0c6110
/*  f0c60ec:	ac4f19ac */ 	sw	$t7,0x19ac($v0)
.L0f0c60f0:
/*  f0c60f0:	c44800b4 */ 	lwc1	$f8,0xb4($v0)
/*  f0c60f4:	46004402 */ 	mul.s	$f16,$f8,$f0
/*  f0c60f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c60fc:	460e8282 */ 	mul.s	$f10,$f16,$f14
/*  f0c6100:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0c6104:	44199000 */ 	mfc1	$t9,$f18
/*  f0c6108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c610c:	ac5919ac */ 	sw	$t9,0x19ac($v0)
.L0f0c6110:
/*  f0c6110:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6114:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6118:	3c01428a */ 	lui	$at,0x428a
/*  f0c611c:	44811000 */ 	mtc1	$at,$f2
/*  f0c6120:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c6124:	1040000c */ 	beqz	$v0,.L0f0c6158
/*  f0c6128:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c612c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c6130:	c44419c4 */ 	lwc1	$f4,0x19c4($v0)
/*  f0c6134:	46041181 */ 	sub.s	$f6,$f2,$f4
/*  f0c6138:	e44619b4 */ 	swc1	$f6,0x19b4($v0)
/*  f0c613c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c6140:	c44819c4 */ 	lwc1	$f8,0x19c4($v0)
/*  f0c6144:	46081401 */ 	sub.s	$f16,$f2,$f8
/*  f0c6148:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f0c614c:	44095000 */ 	mfc1	$t1,$f10
/*  f0c6150:	10000007 */ 	beqz	$zero,.L0f0c6170
/*  f0c6154:	ac4919b8 */ 	sw	$t1,0x19b8($v0)
.L0f0c6158:
/*  f0c6158:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c615c:	c45200b4 */ 	lwc1	$f18,0xb4($v0)
/*  f0c6160:	e45219b4 */ 	swc1	$f18,0x19b4($v0)
/*  f0c6164:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c6168:	8c4a19ac */ 	lw	$t2,0x19ac($v0)
/*  f0c616c:	ac4a19b8 */ 	sw	$t2,0x19b8($v0)
.L0f0c6170:
/*  f0c6170:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c6174:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c6178:	03e00008 */ 	jr	$ra
/*  f0c617c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c6180
/*  f0c6180:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0c6184:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0c6188:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0c618c:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c6190:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0c6194:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0c6198:	14400004 */ 	bnez	$v0,.L0f0c61ac
/*  f0c619c:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c61a0:	4481a000 */ 	mtc1	$at,$f20
/*  f0c61a4:	1000000b */ 	beqz	$zero,.L0f0c61d4
/*  f0c61a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c61ac:
/*  f0c61ac:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0c61b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c61b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c61b8:	14410004 */ 	bne	$v0,$at,.L0f0c61cc
/*  f0c61bc:	3c01c234 */ 	lui	$at,0xc234
/*  f0c61c0:	4481a000 */ 	mtc1	$at,$f20
/*  f0c61c4:	10000003 */ 	beqz	$zero,.L0f0c61d4
/*  f0c61c8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c61cc:
/*  f0c61cc:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0c61d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c61d4:
/*  f0c61d4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0c61d8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0c61dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c61e0:	c44000b4 */ 	lwc1	$f0,0xb4($v0)
/*  f0c61e4:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c61e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c61ec:	45030036 */ 	bc1tl	.L0f0c62c8
/*  f0c61f0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c61f4:	e7a00040 */ 	swc1	$f0,0x40($sp)
/*  f0c61f8:	8c4e19ac */ 	lw	$t6,0x19ac($v0)
/*  f0c61fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6200:	44811000 */ 	mtc1	$at,$f2
/*  f0c6204:	448e2000 */ 	mtc1	$t6,$f4
/*  f0c6208:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c620c:	44819000 */ 	mtc1	$at,$f18
/*  f0c6210:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c6214:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c6218:	44071000 */ 	mfc1	$a3,$f2
/*  f0c621c:	244400b4 */ 	addiu	$a0,$v0,0xb4
/*  f0c6220:	244600b8 */ 	addiu	$a2,$v0,0xb8
/*  f0c6224:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0c6228:	c44819b4 */ 	lwc1	$f8,0x19b4($v0)
/*  f0c622c:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f0c6230:	8c4f19b8 */ 	lw	$t7,0x19b8($v0)
/*  f0c6234:	e7a20010 */ 	swc1	$f2,0x10($sp)
/*  f0c6238:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0c623c:	448f5000 */ 	mtc1	$t7,$f10
/*  f0c6240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6244:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c6248:	0fc1b643 */ 	jal	func0f06d90c
/*  f0c624c:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f0c6250:	0fc31820 */ 	jal	func0f0c6080
/*  f0c6254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6258:	44806000 */ 	mtc1	$zero,$f12
/*  f0c625c:	0fc30f23 */ 	jal	func0f0c3c8c
/*  f0c6260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6264:	14400017 */ 	bnez	$v0,.L0f0c62c4
/*  f0c6268:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f0c626c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c6270:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0c6274:	e70400b4 */ 	swc1	$f4,0xb4($t8)
/*  f0c6278:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f0c627c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c6280:	44802000 */ 	mtc1	$zero,$f4
/*  f0c6284:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0c6288:	44084000 */ 	mfc1	$t0,$f8
/*  f0c628c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6290:	ad2819ac */ 	sw	$t0,0x19ac($t1)
/*  f0c6294:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c6298:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f0c629c:	e54a19b4 */ 	swc1	$f10,0x19b4($t2)
/*  f0c62a0:	c7b00034 */ 	lwc1	$f16,0x34($sp)
/*  f0c62a4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c62a8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0c62ac:	440c9000 */ 	mfc1	$t4,$f18
/*  f0c62b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c62b4:	adac19b8 */ 	sw	$t4,0x19b8($t5)
/*  f0c62b8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c62bc:	0fc30ebd */ 	jal	currentPlayerAdjustCrouchPos
/*  f0c62c0:	e5c400b8 */ 	swc1	$f4,0xb8($t6)
.L0f0c62c4:
/*  f0c62c4:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f0c62c8:
/*  f0c62c8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c62cc:	44814000 */ 	mtc1	$at,$f8
/*  f0c62d0:	c44000b4 */ 	lwc1	$f0,0xb4($v0)
/*  f0c62d4:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c62d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c62dc:	45020008 */ 	bc1fl	.L0f0c6300
/*  f0c62e0:	46080283 */ 	div.s	$f10,$f0,$f8
/*  f0c62e4:	44803000 */ 	mtc1	$zero,$f6
/*  f0c62e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c62ec:	e44600b8 */ 	swc1	$f6,0xb8($v0)
/*  f0c62f0:	3c02800a */ 	lui	$v0,0x800a
/*  f0c62f4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c62f8:	c44000b4 */ 	lwc1	$f0,0xb4($v0)
/*  f0c62fc:	46080283 */ 	div.s	$f10,$f0,$f8
.L0f0c6300:
/*  f0c6300:	e44a1968 */ 	swc1	$f10,0x1968($v0)
/*  f0c6304:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0c6308:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0c630c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0c6310:	03e00008 */ 	jr	$ra
/*  f0c6314:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0c6318
.late_rodata
glabel var7f1ad7dc
.word 0x3c8ef461
.text
/*  f0c6318:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0c631c:	3c0e8007 */ 	lui	$t6,%hi(var80070e5c)
/*  f0c6320:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c6324:	25ce0e5c */ 	addiu	$t6,$t6,%lo(var80070e5c)
/*  f0c6328:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0c632c:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0c6330:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c6334:	ac810000 */ 	sw	$at,0x0($a0)
/*  f0c6338:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0c633c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c6340:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c6344:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f0c6348:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0c634c:	c470004c */ 	lwc1	$f16,0x4c($v1)
/*  f0c6350:	2408003f */ 	addiu	$t0,$zero,0x3f
/*  f0c6354:	ac810008 */ 	sw	$at,0x8($a0)
/*  f0c6358:	3c01431f */ 	lui	$at,0x431f
/*  f0c635c:	44812000 */ 	mtc1	$at,$f4
/*  f0c6360:	c44619c4 */ 	lwc1	$f6,0x19c4($v0)
/*  f0c6364:	c4480148 */ 	lwc1	$f8,0x148($v0)
/*  f0c6368:	3c017f1b */ 	lui	$at,%hi(var7f1ad7dc)
/*  f0c636c:	46062003 */ 	div.s	$f0,$f4,$f6
/*  f0c6370:	c424d7dc */ 	lwc1	$f4,%lo(var7f1ad7dc)($at)
/*  f0c6374:	3c014060 */ 	lui	$at,0x4060
/*  f0c6378:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0c637c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c6380:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0c6384:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0c6388:	44814000 */ 	mtc1	$at,$f8
/*  f0c638c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0c6390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6394:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c6398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c639c:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0c63a0:	44051000 */ 	mfc1	$a1,$f2
/*  f0c63a4:	0fc31094 */ 	jal	func0f0c4250
/*  f0c63a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c63ac:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c63b0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0c63b4:	03e00008 */ 	jr	$ra
/*  f0c63b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c63bc
/*  f0c63bc:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0c63c0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0c63c4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0c63c8:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f0c63cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c63d0:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0c63d4:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f0c63d8:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f0c63dc:	adc01af4 */ 	sw	$zero,0x1af4($t6)
/*  f0c63e0:	8c580284 */ 	lw	$t8,0x284($v0)
/*  f0c63e4:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0c63e8:	0fc31366 */ 	jal	func0f0c4d98
/*  f0c63ec:	af0f00b0 */ 	sw	$t7,0xb0($t8)
/*  f0c63f0:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c63f4:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c63f8:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c63fc:	0fc311d9 */ 	jal	func0f0c4764
/*  f0c6400:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c6404:	14400049 */ 	bnez	$v0,.L0f0c652c
/*  f0c6408:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c640c:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f0c6410:	27b90040 */ 	addiu	$t9,$sp,0x40
/*  f0c6414:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c6418:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c641c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c6420:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f0c6424:	0fc311f4 */ 	jal	func0f0c47d0
/*  f0c6428:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0c642c:	1c400003 */ 	bgtz	$v0,.L0f0c643c
/*  f0c6430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6434:	04410016 */ 	bgez	$v0,.L0f0c6490
/*  f0c6438:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c643c:
/*  f0c643c:	58400004 */ 	blezl	$v0,.L0f0c6450
/*  f0c6440:	8fa90074 */ 	lw	$t1,0x74($sp)
/*  f0c6444:	0fc31366 */ 	jal	func0f0c4d98
/*  f0c6448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c644c:	8fa90074 */ 	lw	$t1,0x74($sp)
.L0f0c6450:
/*  f0c6450:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c6454:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c6458:	11200034 */ 	beqz	$t1,.L0f0c652c
/*  f0c645c:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c6460:	0fc31253 */ 	jal	func0f0c494c
/*  f0c6464:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c6468:	1c400030 */ 	bgtz	$v0,.L0f0c652c
/*  f0c646c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c6470:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c6474:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c6478:	0fc31297 */ 	jal	func0f0c4a5c
/*  f0c647c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c6480:	1c40002a */ 	bgtz	$v0,.L0f0c652c
/*  f0c6484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6488:	10000028 */ 	beqz	$zero,.L0f0c652c
/*  f0c648c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c6490:
/*  f0c6490:	14400026 */ 	bnez	$v0,.L0f0c652c
/*  f0c6494:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c6498:	8fab0078 */ 	lw	$t3,0x78($sp)
/*  f0c649c:	27aa0024 */ 	addiu	$t2,$sp,0x24
/*  f0c64a0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c64a4:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0c64a8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0c64ac:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f0c64b0:	0fc311f4 */ 	jal	func0f0c47d0
/*  f0c64b4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0c64b8:	58400004 */ 	blezl	$v0,.L0f0c64cc
/*  f0c64bc:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f0c64c0:	0fc31366 */ 	jal	func0f0c4d98
/*  f0c64c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c64c8:	8fac0074 */ 	lw	$t4,0x74($sp)
.L0f0c64cc:
/*  f0c64cc:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c64d0:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0c64d4:	11800015 */ 	beqz	$t4,.L0f0c652c
/*  f0c64d8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0c64dc:	0fc31253 */ 	jal	func0f0c494c
/*  f0c64e0:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c64e4:	1c400011 */ 	bgtz	$v0,.L0f0c652c
/*  f0c64e8:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c64ec:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c64f0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c64f4:	0fc31253 */ 	jal	func0f0c494c
/*  f0c64f8:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c64fc:	1c40000b */ 	bgtz	$v0,.L0f0c652c
/*  f0c6500:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c6504:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0c6508:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0c650c:	0fc31297 */ 	jal	func0f0c4a5c
/*  f0c6510:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0c6514:	1c400005 */ 	bgtz	$v0,.L0f0c652c
/*  f0c6518:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c651c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0c6520:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c6524:	0fc31297 */ 	jal	func0f0c4a5c
/*  f0c6528:	8fa70078 */ 	lw	$a3,0x78($sp)
.L0f0c652c:
/*  f0c652c:	0fc31366 */ 	jal	func0f0c4d98
/*  f0c6530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6534:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c6538:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f0c653c:	03e00008 */ 	jr	$ra
/*  f0c6540:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerUpdatePrevPosWalk(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	roomsCopy(g_Vars.currentplayer->prop->rooms, g_Vars.currentplayer->bondprevrooms);
}

void func0f0c65a8(void)
{
	if (g_Vars.currentplayer->unk1af8) {
		g_Vars.currentplayer->unk00d0 = 0;
	}
}

GLOBAL_ASM(
glabel func0f0c65c8
.late_rodata
glabel var7f1ad7e0
.word 0x3e4ccccd
glabel var7f1ad7e4
.word 0x3e4ccccd
glabel var7f1ad7e8
.word 0x3e4ccccd
glabel var7f1ad7ec
.word 0x3c6a0ea1
glabel var7f1ad7f0
.word 0x3e4ccccd
glabel var7f1ad7f4
.word 0x3c6a0ea1
glabel var7f1ad7f8
.word 0x3f8a3d71
.text
/*  f0c65c8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c65cc:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c65d0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c65d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c65d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0c65dc:	8dcf1af8 */ 	lw	$t7,0x1af8($t6)
/*  f0c65e0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c65e4:	55e000d4 */ 	bnezl	$t7,.L0f0c6938
/*  f0c65e8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c65ec:	8c860028 */ 	lw	$a2,0x28($a0)
/*  f0c65f0:	10c00007 */ 	beqz	$a2,.L0f0c6610
/*  f0c65f4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c65f8:	44816000 */ 	mtc1	$at,$f12
/*  f0c65fc:	3c017f1b */ 	lui	$at,%hi(var7f1ad7e0)
/*  f0c6600:	0fc31368 */ 	jal	func0f0c4da0
/*  f0c6604:	c42ed7e0 */ 	lwc1	$f14,%lo(var7f1ad7e0)($at)
/*  f0c6608:	10000015 */ 	beqz	$zero,.L0f0c6660
/*  f0c660c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0c6610:
/*  f0c6610:	8e06002c */ 	lw	$a2,0x2c($s0)
/*  f0c6614:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6618:	50c00008 */ 	beqzl	$a2,.L0f0c663c
/*  f0c661c:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0c6620:	44816000 */ 	mtc1	$at,$f12
/*  f0c6624:	3c017f1b */ 	lui	$at,%hi(var7f1ad7e4)
/*  f0c6628:	0fc31368 */ 	jal	func0f0c4da0
/*  f0c662c:	c42ed7e4 */ 	lwc1	$f14,%lo(var7f1ad7e4)($at)
/*  f0c6630:	1000000b */ 	beqz	$zero,.L0f0c6660
/*  f0c6634:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0c6638:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0c663c:
/*  f0c663c:	3c017f1b */ 	lui	$at,%hi(var7f1ad7e8)
/*  f0c6640:	3c06800a */ 	lui	$a2,0x800a
/*  f0c6644:	14400006 */ 	bnez	$v0,.L0f0c6660
/*  f0c6648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c664c:	44806000 */ 	mtc1	$zero,$f12
/*  f0c6650:	c42ed7e8 */ 	lwc1	$f14,%lo(var7f1ad7e8)($at)
/*  f0c6654:	0fc31368 */ 	jal	func0f0c4da0
/*  f0c6658:	8cc69ff8 */ 	lw	$a2,-0x6008($a2)
/*  f0c665c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0c6660:
/*  f0c6660:	5040000e */ 	beqzl	$v0,.L0f0c669c
/*  f0c6664:	8e190020 */ 	lw	$t9,0x20($s0)
/*  f0c6668:	8e1800a4 */ 	lw	$t8,0xa4($s0)
/*  f0c666c:	3c017f1b */ 	lui	$at,%hi(var7f1ad7ec)
/*  f0c6670:	c428d7ec */ 	lwc1	$f8,%lo(var7f1ad7ec)($at)
/*  f0c6674:	44982000 */ 	mtc1	$t8,$f4
/*  f0c6678:	3c017f1b */ 	lui	$at,%hi(var7f1ad7f0)
/*  f0c667c:	3c06800a */ 	lui	$a2,0x800a
/*  f0c6680:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c6684:	8cc69ff8 */ 	lw	$a2,-0x6008($a2)
/*  f0c6688:	c42ed7f0 */ 	lwc1	$f14,%lo(var7f1ad7f0)($at)
/*  f0c668c:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0c6690:	0fc31368 */ 	jal	func0f0c4da0
/*  f0c6694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6698:	8e190020 */ 	lw	$t9,0x20($s0)
.L0f0c669c:
/*  f0c669c:	1320000d */ 	beqz	$t9,.L0f0c66d4
/*  f0c66a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c66a4:	44816000 */ 	mtc1	$at,$f12
/*  f0c66a8:	0fc313b1 */ 	jal	func0f0c4ec4
/*  f0c66ac:	46006386 */ 	mov.s	$f14,$f12
/*  f0c66b0:	3c02800a */ 	lui	$v0,0x800a
/*  f0c66b4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c66b8:	3c09800a */ 	lui	$t1,0x800a
/*  f0c66bc:	8d299ff8 */ 	lw	$t1,-0x6008($t1)
/*  f0c66c0:	8c480178 */ 	lw	$t0,0x178($v0)
/*  f0c66c4:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0c66c8:	ac4a0178 */ 	sw	$t2,0x178($v0)
/*  f0c66cc:	10000015 */ 	beqz	$zero,.L0f0c6724
/*  f0c66d0:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0c66d4:
/*  f0c66d4:	8e0b0024 */ 	lw	$t3,0x24($s0)
/*  f0c66d8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c66dc:	51600009 */ 	beqzl	$t3,.L0f0c6704
/*  f0c66e0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0c66e4:	44816000 */ 	mtc1	$at,$f12
/*  f0c66e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c66ec:	44817000 */ 	mtc1	$at,$f14
/*  f0c66f0:	0fc313b1 */ 	jal	func0f0c4ec4
/*  f0c66f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66f8:	1000000a */ 	beqz	$zero,.L0f0c6724
/*  f0c66fc:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0c6700:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0c6704:
/*  f0c6704:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6708:	14600006 */ 	bnez	$v1,.L0f0c6724
/*  f0c670c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6710:	44806000 */ 	mtc1	$zero,$f12
/*  f0c6714:	44817000 */ 	mtc1	$at,$f14
/*  f0c6718:	0fc313b1 */ 	jal	func0f0c4ec4
/*  f0c671c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6720:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0c6724:
/*  f0c6724:	1060001a */ 	beqz	$v1,.L0f0c6790
/*  f0c6728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c672c:	8e0c00a8 */ 	lw	$t4,0xa8($s0)
/*  f0c6730:	3c017f1b */ 	lui	$at,%hi(var7f1ad7f4)
/*  f0c6734:	c432d7f4 */ 	lwc1	$f18,%lo(var7f1ad7f4)($at)
/*  f0c6738:	448c5000 */ 	mtc1	$t4,$f10
/*  f0c673c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6740:	44817000 */ 	mtc1	$at,$f14
/*  f0c6744:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c6748:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0c674c:	0fc313b1 */ 	jal	func0f0c4ec4
/*  f0c6750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6754:	8e0d00a8 */ 	lw	$t5,0xa8($s0)
/*  f0c6758:	3c02800a */ 	lui	$v0,0x800a
/*  f0c675c:	3c19800a */ 	lui	$t9,0x800a
/*  f0c6760:	29a1003d */ 	slti	$at,$t5,0x3d
/*  f0c6764:	14200008 */ 	bnez	$at,.L0f0c6788
/*  f0c6768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c676c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c6770:	3c0f800a */ 	lui	$t7,0x800a
/*  f0c6774:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f0c6778:	8c4e0178 */ 	lw	$t6,0x178($v0)
/*  f0c677c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0c6780:	10000003 */ 	beqz	$zero,.L0f0c6790
/*  f0c6784:	ac580178 */ 	sw	$t8,0x178($v0)
.L0f0c6788:
/*  f0c6788:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f0c678c:	af200178 */ 	sw	$zero,0x178($t9)
.L0f0c6790:
/*  f0c6790:	3c02800a */ 	lui	$v0,0x800a
/*  f0c6794:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c6798:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c679c:	44811000 */ 	mtc1	$at,$f2
/*  f0c67a0:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0c67a4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c67a8:	44816000 */ 	mtc1	$at,$f12
/*  f0c67ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c67b0:	3c017f1b */ 	lui	$at,%hi(var7f1ad7f8)
/*  f0c67b4:	45020006 */ 	bc1fl	.L0f0c67d0
/*  f0c67b8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c67bc:	e4420170 */ 	swc1	$f2,0x170($v0)
/*  f0c67c0:	3c02800a */ 	lui	$v0,0x800a
/*  f0c67c4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c67c8:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0c67cc:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c67d0:
/*  f0c67d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c67d4:	45020005 */ 	bc1fl	.L0f0c67ec
/*  f0c67d8:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0c67dc:	e44c0170 */ 	swc1	$f12,0x170($v0)
/*  f0c67e0:	3c02800a */ 	lui	$v0,0x800a
/*  f0c67e4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c67e8:	c4400168 */ 	lwc1	$f0,0x168($v0)
.L0f0c67ec:
/*  f0c67ec:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c67f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c67f4:	45020006 */ 	bc1fl	.L0f0c6810
/*  f0c67f8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c67fc:	e4420168 */ 	swc1	$f2,0x168($v0)
/*  f0c6800:	3c02800a */ 	lui	$v0,0x800a
/*  f0c6804:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c6808:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0c680c:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c6810:
/*  f0c6810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6814:	45020005 */ 	bc1fl	.L0f0c682c
/*  f0c6818:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0c681c:	e44c0168 */ 	swc1	$f12,0x168($v0)
/*  f0c6820:	3c02800a */ 	lui	$v0,0x800a
/*  f0c6824:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c6828:	c4440170 */ 	lwc1	$f4,0x170($v0)
.L0f0c682c:
/*  f0c682c:	c426d7f8 */ 	lwc1	$f6,%lo(var7f1ad7f8)($at)
/*  f0c6830:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c6834:	e4480170 */ 	swc1	$f8,0x170($v0)
/*  f0c6838:	3c02800a */ 	lui	$v0,0x800a
/*  f0c683c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0c6840:	c44a0170 */ 	lwc1	$f10,0x170($v0)
/*  f0c6844:	c4500174 */ 	lwc1	$f16,0x174($v0)
/*  f0c6848:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0c684c:	e4520170 */ 	swc1	$f18,0x170($v0)
/*  f0c6850:	8e080010 */ 	lw	$t0,0x10($s0)
/*  f0c6854:	15000004 */ 	bnez	$t0,.L0f0c6868
/*  f0c6858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c685c:	8e090020 */ 	lw	$t1,0x20($s0)
/*  f0c6860:	11200005 */ 	beqz	$t1,.L0f0c6878
/*  f0c6864:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c6868:
/*  f0c6868:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0c686c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6870:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c6874:	10410003 */ 	beq	$v0,$at,.L0f0c6884
.L0f0c6878:
/*  f0c6878:	3c0a800a */ 	lui	$t2,0x800a
/*  f0c687c:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0c6880:	ad400178 */ 	sw	$zero,0x178($t2)
.L0f0c6884:
/*  f0c6884:	8e0b006c */ 	lw	$t3,0x6c($s0)
/*  f0c6888:	51600006 */ 	beqzl	$t3,.L0f0c68a4
/*  f0c688c:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0c6890:	0fc30eb4 */ 	jal	func0f0c3ad0
/*  f0c6894:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0c6898:	1000000b */ 	beqz	$zero,.L0f0c68c8
/*  f0c689c:	8e030064 */ 	lw	$v1,0x64($s0)
/*  f0c68a0:	8e0c0070 */ 	lw	$t4,0x70($s0)
.L0f0c68a4:
/*  f0c68a4:	11800005 */ 	beqz	$t4,.L0f0c68bc
/*  f0c68a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c68ac:	0fc30eb4 */ 	jal	func0f0c3ad0
/*  f0c68b0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c68b4:	10000004 */ 	beqz	$zero,.L0f0c68c8
/*  f0c68b8:	8e030064 */ 	lw	$v1,0x64($s0)
.L0f0c68bc:
/*  f0c68bc:	0fc30eb4 */ 	jal	func0f0c3ad0
/*  f0c68c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c68c4:	8e030064 */ 	lw	$v1,0x64($s0)
.L0f0c68c8:
/*  f0c68c8:	0003102a */ 	slt	$v0,$zero,$v1
/*  f0c68cc:	246dffff */ 	addiu	$t5,$v1,-1
/*  f0c68d0:	10400008 */ 	beqz	$v0,.L0f0c68f4
/*  f0c68d4:	ae0d0064 */ 	sw	$t5,0x64($s0)
.L0f0c68d8:
/*  f0c68d8:	0fc30ebd */ 	jal	currentPlayerAdjustCrouchPos
/*  f0c68dc:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0c68e0:	8e030064 */ 	lw	$v1,0x64($s0)
/*  f0c68e4:	0003102a */ 	slt	$v0,$zero,$v1
/*  f0c68e8:	246effff */ 	addiu	$t6,$v1,-1
/*  f0c68ec:	1440fffa */ 	bnez	$v0,.L0f0c68d8
/*  f0c68f0:	ae0e0064 */ 	sw	$t6,0x64($s0)
.L0f0c68f4:
/*  f0c68f4:	8e030068 */ 	lw	$v1,0x68($s0)
/*  f0c68f8:	0003102a */ 	slt	$v0,$zero,$v1
/*  f0c68fc:	246fffff */ 	addiu	$t7,$v1,-1
/*  f0c6900:	10400008 */ 	beqz	$v0,.L0f0c6924
/*  f0c6904:	ae0f0068 */ 	sw	$t7,0x68($s0)
.L0f0c6908:
/*  f0c6908:	0fc30ebd */ 	jal	currentPlayerAdjustCrouchPos
/*  f0c690c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c6910:	8e030068 */ 	lw	$v1,0x68($s0)
/*  f0c6914:	0003102a */ 	slt	$v0,$zero,$v1
/*  f0c6918:	2478ffff */ 	addiu	$t8,$v1,-1
/*  f0c691c:	1440fffa */ 	bnez	$v0,.L0f0c6908
/*  f0c6920:	ae180068 */ 	sw	$t8,0x68($s0)
.L0f0c6924:
/*  f0c6924:	3c08800a */ 	lui	$t0,0x800a
/*  f0c6928:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f0c692c:	8e190080 */ 	lw	$t9,0x80($s0)
/*  f0c6930:	ad190268 */ 	sw	$t9,0x268($t0)
/*  f0c6934:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0c6938:
/*  f0c6938:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0c693c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c6940:	03e00008 */ 	jr	$ra
/*  f0c6944:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerApplyCrouchSpeedTheta(void)
{
	if (currentPlayerGetCrouchPos() == CROUCH_SQUAT) {
		g_Vars.currentplayer->speedtheta *= 0.5f;
	} else if (currentPlayerGetCrouchPos() == CROUCH_HALF) {
		g_Vars.currentplayer->speedtheta *= 0.75f;
	}
}

GLOBAL_ASM(
glabel func0f0c69b8
.late_rodata
glabel var7f1ad7fc
.word 0xc27e6668
glabel var7f1ad800
.word 0x43b0aaaa
glabel var7f1ad804
.word 0x3ecccccd
glabel var7f1ad808
.word 0x3c888889
glabel var7f1ad80c
.word 0x404907a9
glabel var7f1ad810
.word 0x3eb33333
glabel var7f1ad814
.word 0x3eb33333
glabel var7f1ad818
.word 0x3dcccccd
glabel var7f1ad81c
.word 0x3dcccccd
glabel var7f1ad820
.word 0x3eb33333
glabel var7f1ad824
.word 0x3f4ccccd
glabel var7f1ad828
.word 0x3f4ccccd
glabel var7f1ad82c
.word 0x3f4ccccd
glabel var7f1ad830
.word 0x4528c000
glabel var7f1ad834
.word 0x3ecccccd
glabel var7f1ad838
.word 0x3ecccccd
glabel var7f1ad83c
.word 0x3e99999a
glabel var7f1ad840
.word 0x3f8ccccd
glabel var7f1ad844
.word 0x3e99999a
glabel var7f1ad848
.word 0x3e99999a
glabel var7f1ad84c
.word 0x3f333333
glabel var7f1ad850
.word 0x3f99999a
glabel var7f1ad854
.word 0x3c8ef461
.text
/*  f0c69b8:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0c69bc:	3c0f8007 */ 	lui	$t7,%hi(var80070e68)
/*  f0c69c0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c69c4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0c69c8:	25ef0e68 */ 	addiu	$t7,$t7,%lo(var80070e68)
/*  f0c69cc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0c69d0:	27ae00cc */ 	addiu	$t6,$sp,0xcc
/*  f0c69d4:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0c69d8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0c69dc:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0c69e0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c69e4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c69e8:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0c69ec:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0c69f0:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0c69f4:	3c01431f */ 	lui	$at,0x431f
/*  f0c69f8:	44813000 */ 	mtc1	$at,$f6
/*  f0c69fc:	c54419c4 */ 	lwc1	$f4,0x19c4($t2)
/*  f0c6a00:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c6a04:	0fc44a11 */ 	jal	currentPlayerHasBriefcase
/*  f0c6a08:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f0c6a0c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6a10:	1040000a */ 	beqz	$v0,.L0f0c6a3c
/*  f0c6a14:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6a18:	3c02800b */ 	lui	$v0,0x800b
/*  f0c6a1c:	9042cb98 */ 	lbu	$v0,-0x3468($v0)
/*  f0c6a20:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c6a24:	10410002 */ 	beq	$v0,$at,.L0f0c6a30
/*  f0c6a28:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c6a2c:	14410003 */ 	bne	$v0,$at,.L0f0c6a3c
.L0f0c6a30:
/*  f0c6a30:	3c017f1b */ 	lui	$at,%hi(var7f1ad7fc)
/*  f0c6a34:	c420d7fc */ 	lwc1	$f0,%lo(var7f1ad7fc)($at)
/*  f0c6a38:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
.L0f0c6a3c:
/*  f0c6a3c:	3c017f1b */ 	lui	$at,%hi(var7f1ad800)
/*  f0c6a40:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0c6a44:	c42ad800 */ 	lwc1	$f10,%lo(var7f1ad800)($at)
/*  f0c6a48:	8d0b0318 */ 	lw	$t3,0x318($t0)
/*  f0c6a4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6a50:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f0c6a54:	44813000 */ 	mtc1	$at,$f6
/*  f0c6a58:	3c0c800b */ 	lui	$t4,0x800b
/*  f0c6a5c:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6a60:	1160000a */ 	beqz	$t3,.L0f0c6a8c
/*  f0c6a64:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f0c6a68:	8d8ccb94 */ 	lw	$t4,-0x346c($t4)
/*  f0c6a6c:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0c6a70:	318d0100 */ 	andi	$t5,$t4,0x100
/*  f0c6a74:	11a00005 */ 	beqz	$t5,.L0f0c6a8c
/*  f0c6a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6a7c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6a80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6a84:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6a88:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c6a8c:
/*  f0c6a8c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6a90:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f0c6a94:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6a98:	10400006 */ 	beqz	$v0,.L0f0c6ab4
/*  f0c6a9c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6aa0:	3c017f1b */ 	lui	$at,%hi(var7f1ad804)
/*  f0c6aa4:	c424d804 */ 	lwc1	$f4,%lo(var7f1ad804)($at)
/*  f0c6aa8:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0c6aac:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0c6ab0:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
.L0f0c6ab4:
/*  f0c6ab4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6ab8:	8c791af8 */ 	lw	$t9,0x1af8($v1)
/*  f0c6abc:	1320003f */ 	beqz	$t9,.L0f0c6bbc
/*  f0c6ac0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ac4:	44811000 */ 	mtc1	$at,$f2
/*  f0c6ac8:	3c017f1b */ 	lui	$at,%hi(var7f1ad808)
/*  f0c6acc:	c42ad808 */ 	lwc1	$f10,%lo(var7f1ad808)($at)
/*  f0c6ad0:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c6ad4:	c4661b48 */ 	lwc1	$f6,0x1b48($v1)
/*  f0c6ad8:	3c017f1b */ 	lui	$at,%hi(var7f1ad80c)
/*  f0c6adc:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c6ae0:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0c6ae4:	e4681b48 */ 	swc1	$f8,0x1b48($v1)
/*  f0c6ae8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6aec:	c4601b48 */ 	lwc1	$f0,0x1b48($v1)
/*  f0c6af0:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c6af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6af8:	45000006 */ 	bc1f	.L0f0c6b14
/*  f0c6afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6b00:	e4621b48 */ 	swc1	$f2,0x1b48($v1)
/*  f0c6b04:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0c6b08:	af001af8 */ 	sw	$zero,0x1af8($t8)
/*  f0c6b0c:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c6b10:	c5c01b48 */ 	lwc1	$f0,0x1b48($t6)
.L0f0c6b14:
/*  f0c6b14:	c42ad80c */ 	lwc1	$f10,%lo(var7f1ad80c)($at)
/*  f0c6b18:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0c6b1c:	0c0068f4 */ 	jal	fcos
/*  f0c6b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6b24:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6b28:	44811000 */ 	mtc1	$at,$f2
/*  f0c6b2c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6b30:	44812000 */ 	mtc1	$at,$f4
/*  f0c6b34:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f0c6b38:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6b3c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6b40:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c6b44:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0c6b48:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c6b4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6b50:	4406a000 */ 	mfc1	$a2,$f20
/*  f0c6b54:	4600a306 */ 	mov.s	$f12,$f20
/*  f0c6b58:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c6b5c:	46081281 */ 	sub.s	$f10,$f2,$f8
/*  f0c6b60:	e5ea1b4c */ 	swc1	$f10,0x1b4c($t7)
/*  f0c6b64:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6b68:	c4661b4c */ 	lwc1	$f6,0x1b4c($v1)
/*  f0c6b6c:	24671b08 */ 	addiu	$a3,$v1,0x1b08
/*  f0c6b70:	46061101 */ 	sub.s	$f4,$f2,$f6
/*  f0c6b74:	0fc330ee */ 	jal	func0f0cc3b8
/*  f0c6b78:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0c6b7c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6b80:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6b84:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c6b88:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c6b8c:	0fc32ed2 */ 	jal	currentPlayerUpdateMoveInitSpeed
/*  f0c6b90:	e53400cc */ 	swc1	$f20,0xcc($t1)
/*  f0c6b94:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c6b98:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c6b9c:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f0c6ba0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c6ba4:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c6ba8:	0fc31094 */ 	jal	func0f0c4250
/*  f0c6bac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c6bb0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bb4:	100002ea */ 	beqz	$zero,.L0f0c7760
/*  f0c6bb8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0c6bbc:
/*  f0c6bbc:	0fc317fa */ 	jal	currentPlayerApplyCrouchSpeed
/*  f0c6bc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6bc4:	0fc31860 */ 	jal	func0f0c6180
/*  f0c6bc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6bcc:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bd0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6bd4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6bd8:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0c6bdc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0c6be0:	c468014c */ 	lwc1	$f8,0x14c($v1)
/*  f0c6be4:	8c670150 */ 	lw	$a3,0x150($v1)
/*  f0c6be8:	2466017c */ 	addiu	$a2,$v1,0x17c
/*  f0c6bec:	0fc32ea2 */ 	jal	func0f0cba88
/*  f0c6bf0:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0c6bf4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bf8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6bfc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6c00:	3c01c234 */ 	lui	$at,0xc234
/*  f0c6c04:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c6c08:	c46c00a0 */ 	lwc1	$f12,0xa0($v1)
/*  f0c6c0c:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c6c10:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c6c14:	46006187 */ 	neg.s	$f6,$f12
/*  f0c6c18:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c6c1c:	46065002 */ 	mul.s	$f0,$f10,$f6
/*  f0c6c20:	44815000 */ 	mtc1	$at,$f10
/*  f0c6c24:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c6c28:	460c2382 */ 	mul.s	$f14,$f4,$f12
/*  f0c6c2c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c6c30:	4600a086 */ 	mov.s	$f2,$f20
/*  f0c6c34:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c3c:	46087382 */ 	mul.s	$f14,$f14,$f8
/*  f0c6c40:	4500000a */ 	bc1f	.L0f0c6c6c
/*  f0c6c44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c48:	3c017f1b */ 	lui	$at,%hi(var7f1ad810)
/*  f0c6c4c:	c426d810 */ 	lwc1	$f6,%lo(var7f1ad810)($at)
/*  f0c6c50:	3c017f1b */ 	lui	$at,%hi(var7f1ad814)
/*  f0c6c54:	c424d814 */ 	lwc1	$f4,%lo(var7f1ad814)($at)
/*  f0c6c58:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c6c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c60:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f0c6c64:	1000000b */ 	beqz	$zero,.L0f0c6c94
/*  f0c6c68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c6c6c:
/*  f0c6c6c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6c70:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6c74:	45020008 */ 	bc1fl	.L0f0c6c98
/*  f0c6c78:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c6c7c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6c80:	44815000 */ 	mtc1	$at,$f10
/*  f0c6c84:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c8c:	460a7382 */ 	mul.s	$f14,$f14,$f10
/*  f0c6c90:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c6c94:
/*  f0c6c94:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
.L0f0c6c98:
/*  f0c6c98:	c46400a8 */ 	lwc1	$f4,0xa8($v1)
/*  f0c6c9c:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0c6ca0:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f0c6ca4:	46047481 */ 	sub.s	$f18,$f14,$f4
/*  f0c6ca8:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0c6cac:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f0c6cb0:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f0c6cb4:	e7b200b0 */ 	swc1	$f18,0xb0($sp)
/*  f0c6cb8:	0c012974 */ 	jal	sqrtf
/*  f0c6cbc:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0c6cc0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6cc4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6cc8:	3c014080 */ 	lui	$at,0x4080
/*  f0c6ccc:	44817000 */ 	mtc1	$at,$f14
/*  f0c6cd0:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c6cd4:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0c6cd8:	4612703c */ 	c.lt.s	$f14,$f18
/*  f0c6cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6ce0:	45020005 */ 	bc1fl	.L0f0c6cf8
/*  f0c6ce4:	46009306 */ 	mov.s	$f12,$f18
/*  f0c6ce8:	46007306 */ 	mov.s	$f12,$f14
/*  f0c6cec:	10000003 */ 	beqz	$zero,.L0f0c6cfc
/*  f0c6cf0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0c6cf4:	46009306 */ 	mov.s	$f12,$f18
.L0f0c6cf8:
/*  f0c6cf8:	8d030038 */ 	lw	$v1,0x38($t0)
.L0f0c6cfc:
/*  f0c6cfc:	18600008 */ 	blez	$v1,.L0f0c6d20
/*  f0c6d00:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c6d04:	3c017f1b */ 	lui	$at,%hi(var7f1ad818)
/*  f0c6d08:	c42ed818 */ 	lwc1	$f14,%lo(var7f1ad818)($at)
.L0f0c6d0c:
/*  f0c6d0c:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0c6d10:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c6d14:	460e3102 */ 	mul.s	$f4,$f6,$f14
/*  f0c6d18:	1443fffc */ 	bne	$v0,$v1,.L0f0c6d0c
/*  f0c6d1c:	46041080 */ 	add.s	$f2,$f2,$f4
.L0f0c6d20:
/*  f0c6d20:	3c017f1b */ 	lui	$at,%hi(var7f1ad81c)
/*  f0c6d24:	c42ed81c */ 	lwc1	$f14,%lo(var7f1ad81c)($at)
/*  f0c6d28:	3c014070 */ 	lui	$at,0x4070
/*  f0c6d2c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6d30:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6d34:	3c01c234 */ 	lui	$at,0xc234
/*  f0c6d38:	44813000 */ 	mtc1	$at,$f6
/*  f0c6d3c:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c6d40:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0c6d44:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c6d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6d4c:	45000006 */ 	bc1f	.L0f0c6d68
/*  f0c6d50:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f0c6d54:	3c017f1b */ 	lui	$at,%hi(var7f1ad820)
/*  f0c6d58:	c424d820 */ 	lwc1	$f4,%lo(var7f1ad820)($at)
/*  f0c6d5c:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c6d60:	1000000a */ 	beqz	$zero,.L0f0c6d8c
/*  f0c6d64:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0c6d68:
/*  f0c6d68:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6d6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6d70:	45020006 */ 	bc1fl	.L0f0c6d8c
/*  f0c6d74:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c6d78:	44814000 */ 	mtc1	$at,$f8
/*  f0c6d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6d80:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0c6d84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6d88:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0c6d8c:
/*  f0c6d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6d90:	4502000a */ 	bc1fl	.L0f0c6dbc
/*  f0c6d94:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c6d98:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0c6d9c:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c6da0:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c6da4:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0c6da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6dac:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0c6db0:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c6db4:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f0c6db8:	c46a0168 */ 	lwc1	$f10,0x168($v1)
.L0f0c6dbc:
/*  f0c6dbc:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c6dc0:	3c017f1b */ 	lui	$at,%hi(var7f1ad824)
/*  f0c6dc4:	c428d824 */ 	lwc1	$f8,%lo(var7f1ad824)($at)
/*  f0c6dc8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0c6dcc:	3c017f1b */ 	lui	$at,%hi(var7f1ad828)
/*  f0c6dd0:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0c6dd4:	c46a0170 */ 	lwc1	$f10,0x170($v1)
/*  f0c6dd8:	46082082 */ 	mul.s	$f2,$f4,$f8
/*  f0c6ddc:	c428d828 */ 	lwc1	$f8,%lo(var7f1ad828)($at)
/*  f0c6de0:	c4640148 */ 	lwc1	$f4,0x148($v1)
/*  f0c6de4:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f0c6de8:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f0c6dec:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0c6df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6df4:	45020003 */ 	bc1fl	.L0f0c6e04
/*  f0c6df8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0c6dfc:	46001087 */ 	neg.s	$f2,$f2
/*  f0c6e00:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0c6e04:
/*  f0c6e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e08:	45020003 */ 	bc1fl	.L0f0c6e18
/*  f0c6e0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6e10:	46006307 */ 	neg.s	$f12,$f12
/*  f0c6e14:	4614803c */ 	c.lt.s	$f16,$f20
.L0f0c6e18:
/*  f0c6e18:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0c6e1c:	45020004 */ 	bc1fl	.L0f0c6e30
/*  f0c6e20:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c6e24:	46008407 */ 	neg.s	$f16,$f16
/*  f0c6e28:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0c6e2c:	4602603c */ 	c.lt.s	$f12,$f2
.L0f0c6e30:
/*  f0c6e30:	46006406 */ 	mov.s	$f16,$f12
/*  f0c6e34:	45020003 */ 	bc1fl	.L0f0c6e44
/*  f0c6e38:	c7a2007c */ 	lwc1	$f2,0x7c($sp)
/*  f0c6e3c:	46001406 */ 	mov.s	$f16,$f2
/*  f0c6e40:	c7a2007c */ 	lwc1	$f2,0x7c($sp)
.L0f0c6e44:
/*  f0c6e44:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0c6e48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e4c:	45020003 */ 	bc1fl	.L0f0c6e5c
/*  f0c6e50:	4600703e */ 	c.le.s	$f14,$f0
/*  f0c6e54:	46001406 */ 	mov.s	$f16,$f2
/*  f0c6e58:	4600703e */ 	c.le.s	$f14,$f0
.L0f0c6e5c:
/*  f0c6e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e60:	45000007 */ 	bc1f	.L0f0c6e80
/*  f0c6e64:	3c017f1b */ 	lui	$at,%hi(var7f1ad82c)
/*  f0c6e68:	c420d82c */ 	lwc1	$f0,%lo(var7f1ad82c)($at)
/*  f0c6e6c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c6e70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e74:	45020003 */ 	bc1fl	.L0f0c6e84
/*  f0c6e78:	3c013f40 */ 	lui	$at,0x3f40
/*  f0c6e7c:	46000406 */ 	mov.s	$f16,$f0
.L0f0c6e80:
/*  f0c6e80:	3c013f40 */ 	lui	$at,0x3f40
.L0f0c6e84:
/*  f0c6e84:	44810000 */ 	mtc1	$at,$f0
/*  f0c6e88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e8c:	4610003e */ 	c.le.s	$f0,$f16
/*  f0c6e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e94:	4502000b */ 	bc1fl	.L0f0c6ec4
/*  f0c6e98:	46100101 */ 	sub.s	$f4,$f0,$f16
/*  f0c6e9c:	46008281 */ 	sub.s	$f10,$f16,$f0
/*  f0c6ea0:	3c014461 */ 	lui	$at,0x4461
/*  f0c6ea4:	44812000 */ 	mtc1	$at,$f4
/*  f0c6ea8:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f0c6eac:	c46a0198 */ 	lwc1	$f10,0x198($v1)
/*  f0c6eb0:	46043203 */ 	div.s	$f8,$f6,$f4
/*  f0c6eb4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c6eb8:	10000009 */ 	beqz	$zero,.L0f0c6ee0
/*  f0c6ebc:	e4660198 */ 	swc1	$f6,0x198($v1)
/*  f0c6ec0:	46100101 */ 	sub.s	$f4,$f0,$f16
.L0f0c6ec4:
/*  f0c6ec4:	3c017f1b */ 	lui	$at,%hi(var7f1ad830)
/*  f0c6ec8:	c428d830 */ 	lwc1	$f8,%lo(var7f1ad830)($at)
/*  f0c6ecc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0c6ed0:	c4640198 */ 	lwc1	$f4,0x198($v1)
/*  f0c6ed4:	46085183 */ 	div.s	$f6,$f10,$f8
/*  f0c6ed8:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0c6edc:	e46a0198 */ 	swc1	$f10,0x198($v1)
.L0f0c6ee0:
/*  f0c6ee0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6ee4:	c4600198 */ 	lwc1	$f0,0x198($v1)
/*  f0c6ee8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c6eec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6ef0:	45020005 */ 	bc1fl	.L0f0c6f08
/*  f0c6ef4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ef8:	e4740198 */ 	swc1	$f20,0x198($v1)
/*  f0c6efc:	1000000c */ 	beqz	$zero,.L0f0c6f30
/*  f0c6f00:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6f04:	3c013f80 */ 	lui	$at,0x3f80
.L0f0c6f08:
/*  f0c6f08:	44814000 */ 	mtc1	$at,$f8
/*  f0c6f0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6f10:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c6f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6f18:	45000005 */ 	bc1f	.L0f0c6f30
/*  f0c6f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6f20:	44812000 */ 	mtc1	$at,$f4
/*  f0c6f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6f28:	e4640198 */ 	swc1	$f4,0x198($v1)
/*  f0c6f2c:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c6f30:
/*  f0c6f30:	3c018007 */ 	lui	$at,0x8007
/*  f0c6f34:	c4265c24 */ 	lwc1	$f6,0x5c24($at)
/*  f0c6f38:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6f3c:	44815000 */ 	mtc1	$at,$f10
/*  f0c6f40:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0c6f44:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6f48:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c6f4c:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0c6f50:	c4660168 */ 	lwc1	$f6,0x168($v1)
/*  f0c6f54:	e7b00078 */ 	swc1	$f16,0x78($sp)
/*  f0c6f58:	46044002 */ 	mul.s	$f0,$f8,$f4
/*  f0c6f5c:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
/*  f0c6f60:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c6f64:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c6f68:	46003082 */ 	mul.s	$f2,$f6,$f0
/*  f0c6f6c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6f70:	e7a200e0 */ 	swc1	$f2,0xe0($sp)
/*  f0c6f74:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6f78:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6f7c:	10400004 */ 	beqz	$v0,.L0f0c6f90
/*  f0c6f80:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*  f0c6f84:	3c017f1b */ 	lui	$at,%hi(var7f1ad834)
/*  f0c6f88:	c42ad834 */ 	lwc1	$f10,%lo(var7f1ad834)($at)
/*  f0c6f8c:	460a1083 */ 	div.s	$f2,$f2,$f10
.L0f0c6f90:
/*  f0c6f90:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c6f94:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f0c6f98:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0c6f9c:	c5680170 */ 	lwc1	$f8,0x170($t3)
/*  f0c6fa0:	44061000 */ 	mfc1	$a2,$f2
/*  f0c6fa4:	c7ac0078 */ 	lwc1	$f12,0x78($sp)
/*  f0c6fa8:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c6fac:	0fc33195 */ 	jal	func0f0cc654
/*  f0c6fb0:	460a3380 */ 	add.s	$f14,$f6,$f10
/*  f0c6fb4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6fb8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6fbc:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0c6fc0:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0c6fc4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6fc8:	e58800cc */ 	swc1	$f8,0xcc($t4)
/*  f0c6fcc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6fd0:	c46003c0 */ 	lwc1	$f0,0x3c0($v1)
/*  f0c6fd4:	c46203c8 */ 	lwc1	$f2,0x3c8($v1)
/*  f0c6fd8:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*  f0c6fdc:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6fe0:	e7a200d8 */ 	swc1	$f2,0xd8($sp)
/*  f0c6fe4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6fe8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6fec:	c7a000dc */ 	lwc1	$f0,0xdc($sp)
/*  f0c6ff0:	10400005 */ 	beqz	$v0,.L0f0c7008
/*  f0c6ff4:	c7a200d8 */ 	lwc1	$f2,0xd8($sp)
/*  f0c6ff8:	3c017f1b */ 	lui	$at,%hi(var7f1ad838)
/*  f0c6ffc:	c424d838 */ 	lwc1	$f4,%lo(var7f1ad838)($at)
/*  f0c7000:	46040002 */ 	mul.s	$f0,$f0,$f4
/*  f0c7004:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c7008:
/*  f0c7008:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c700c:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c7010:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7014:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c7018:	c4680374 */ 	lwc1	$f8,0x374($v1)
/*  f0c701c:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0c7020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7024:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0c7028:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0c702c:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c7030:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f0c7034:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c7038:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c703c:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c7040:	c468036c */ 	lwc1	$f8,0x36c($v1)
/*  f0c7044:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0c7048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c704c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0c7050:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0c7054:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c7058:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0c705c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c7060:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0c7064:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c7068:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c706c:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0c7070:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c7074:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c7078:	0fc32ed2 */ 	jal	currentPlayerUpdateMoveInitSpeed
/*  f0c707c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c7080:	0fc47b82 */ 	jal	func0f11ee08
/*  f0c7084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7088:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c708c:	1040001f */ 	beqz	$v0,.L0f0c710c
/*  f0c7090:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7094:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7098:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c709c:	3c014120 */ 	lui	$at,0x4120
/*  f0c70a0:	c46a036c */ 	lwc1	$f10,0x36c($v1)
/*  f0c70a4:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c70a8:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c70ac:	44810000 */ 	mtc1	$at,$f0
/*  f0c70b0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c70b4:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c70b8:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c70bc:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0c70c0:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c70c4:	46123282 */ 	mul.s	$f10,$f6,$f18
/*  f0c70c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c70cc:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c70d0:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c70d4:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c70d8:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c70dc:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c70e0:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c70e4:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c70e8:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c70ec:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c70f0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c70f4:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c70f8:	46123282 */ 	mul.s	$f10,$f6,$f18
/*  f0c70fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7100:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c7104:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c7108:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
.L0f0c710c:
/*  f0c710c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7110:	c4601b6c */ 	lwc1	$f0,0x1b6c($v1)
/*  f0c7114:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c7118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c711c:	45020007 */ 	bc1fl	.L0f0c713c
/*  f0c7120:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c7124:	c46a1b74 */ 	lwc1	$f10,0x1b74($v1)
/*  f0c7128:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0c712c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7130:	4503000c */ 	bc1tl	.L0f0c7164
/*  f0c7134:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
/*  f0c7138:	c512004c */ 	lwc1	$f18,0x4c($t0)
.L0f0c713c:
/*  f0c713c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7140:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c7144:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0c7148:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c714c:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c7150:	c4681b74 */ 	lwc1	$f8,0x1b74($v1)
/*  f0c7154:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f0c7158:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c715c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c7160:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
.L0f0c7164:
/*  f0c7164:	246402a0 */ 	addiu	$a0,$v1,0x2a0
/*  f0c7168:	246502a4 */ 	addiu	$a1,$v1,0x2a4
/*  f0c716c:	51a0006a */ 	beqzl	$t5,.L0f0c7318
/*  f0c7170:	8c640298 */ 	lw	$a0,0x298($v1)
/*  f0c7174:	0c0011e4 */ 	jal	scaleTo1
/*  f0c7178:	246602a8 */ 	addiu	$a2,$v1,0x2a8
/*  f0c717c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7180:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7184:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7188:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c718c:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c7190:	c46802a8 */ 	lwc1	$f8,0x2a8($v1)
/*  f0c7194:	c46202a0 */ 	lwc1	$f2,0x2a0($v1)
/*  f0c7198:	3c01c080 */ 	lui	$at,0xc080
/*  f0c719c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c71a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c71a4:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0c71a8:	46082000 */ 	add.s	$f0,$f4,$f8
/*  f0c71ac:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c71b0:	44812000 */ 	mtc1	$at,$f4
/*  f0c71b4:	46000007 */ 	neg.s	$f0,$f0
/*  f0c71b8:	46082102 */ 	mul.s	$f4,$f4,$f8
/*  f0c71bc:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0c71c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c71c4:	45000051 */ 	bc1f	.L0f0c730c
/*  f0c71c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c71cc:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c71d0:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0c71d4:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0c71d8:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0c71dc:	4502000e */ 	bc1fl	.L0f0c7218
/*  f0c71e0:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0c71e4:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0c71e8:	3c017f1b */ 	lui	$at,%hi(var7f1ad83c)
/*  f0c71ec:	c42cd83c */ 	lwc1	$f12,%lo(var7f1ad83c)($at)
/*  f0c71f0:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0c71f4:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c71f8:	c46602a8 */ 	lwc1	$f6,0x2a8($v1)
/*  f0c71fc:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7200:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c7204:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f0c7208:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0c720c:	10000036 */ 	beqz	$zero,.L0f0c72e8
/*  f0c7210:	e466029c */ 	swc1	$f6,0x29c($v1)
/*  f0c7214:	8c6400bc */ 	lw	$a0,0xbc($v1)
.L0f0c7218:
/*  f0c7218:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c721c:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0c7220:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7224:	3c017f1b */ 	lui	$at,%hi(var7f1ad840)
/*  f0c7228:	c428d840 */ 	lwc1	$f8,%lo(var7f1ad840)($at)
/*  f0c722c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0c7230:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7234:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7238:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c723c:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0c7240:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7244:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0c7248:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c724c:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c7250:	34188040 */ 	dli	$t8,0x8040
/*  f0c7254:	44052000 */ 	mfc1	$a1,$f4
/*  f0c7258:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f0c725c:	44813000 */ 	mtc1	$at,$f6
/*  f0c7260:	24590028 */ 	addiu	$t9,$v0,0x28
/*  f0c7264:	46024101 */ 	sub.s	$f4,$f8,$f2
/*  f0c7268:	44065000 */ 	mfc1	$a2,$f10
/*  f0c726c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c7270:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c7274:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c7278:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c727c:	44075000 */ 	mfc1	$a3,$f10
/*  f0c7280:	0c00a84f */ 	jal	func0002a13c
/*  f0c7284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7288:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c728c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7290:	14400006 */ 	bnez	$v0,.L0f0c72ac
/*  f0c7294:	c7a00074 */ 	lwc1	$f0,0x74($sp)
/*  f0c7298:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c729c:	3c017f1b */ 	lui	$at,%hi(var7f1ad844)
/*  f0c72a0:	e5d4029c */ 	swc1	$f20,0x29c($t6)
/*  f0c72a4:	10000010 */ 	beqz	$zero,.L0f0c72e8
/*  f0c72a8:	c42cd844 */ 	lwc1	$f12,%lo(var7f1ad844)($at)
.L0f0c72ac:
/*  f0c72ac:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c72b0:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c72b4:	3c017f1b */ 	lui	$at,%hi(var7f1ad848)
/*  f0c72b8:	c46402a0 */ 	lwc1	$f4,0x2a0($v1)
/*  f0c72bc:	c42cd848 */ 	lwc1	$f12,%lo(var7f1ad848)($at)
/*  f0c72c0:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0c72c4:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c72c8:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0c72cc:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c72d0:	c46802a8 */ 	lwc1	$f8,0x2a8($v1)
/*  f0c72d4:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0c72d8:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c72dc:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f0c72e0:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c72e4:	e468029c */ 	swc1	$f8,0x29c($v1)
.L0f0c72e8:
/*  f0c72e8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c72ec:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c72f0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c72f4:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0c72f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c72fc:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f0c7300:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c7304:	10000003 */ 	beqz	$zero,.L0f0c7314
/*  f0c7308:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
.L0f0c730c:
/*  f0c730c:	e474029c */ 	swc1	$f20,0x29c($v1)
/*  f0c7310:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7314:
/*  f0c7314:	8c640298 */ 	lw	$a0,0x298($v1)
.L0f0c7318:
/*  f0c7318:	50800015 */ 	beqzl	$a0,.L0f0c7370
/*  f0c731c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7320:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f0c7324:	2401003b */ 	addiu	$at,$zero,0x3b
/*  f0c7328:	904f0003 */ 	lbu	$t7,0x3($v0)
/*  f0c732c:	55e10010 */ 	bnel	$t7,$at,.L0f0c7370
/*  f0c7330:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7334:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0c7338:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0c733c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7340:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0c7344:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0c7348:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c734c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c7350:	8c4a0014 */ 	lw	$t2,0x14($v0)
/*  f0c7354:	c4480068 */ 	lwc1	$f8,0x68($v0)
/*  f0c7358:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c735c:	c5460010 */ 	lwc1	$f6,0x10($t2)
/*  f0c7360:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0c7364:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0c7368:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c736c:	8c6200bc */ 	lw	$v0,0xbc($v1)
.L0f0c7370:
/*  f0c7370:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7374:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c7378:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c737c:	e7a8008c */ 	swc1	$f8,0x8c($sp)
/*  f0c7380:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c7384:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f0c7388:	c46a00a0 */ 	lwc1	$f10,0xa0($v1)
/*  f0c738c:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0c7390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7394:	45000002 */ 	bc1f	.L0f0c73a0
/*  f0c7398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c739c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c73a0:
/*  f0c73a0:	0fc318ef */ 	jal	func0f0c63bc
/*  f0c73a4:	2406003f */ 	addiu	$a2,$zero,0x3f
/*  f0c73a8:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c73ac:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c73b0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c73b4:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c73b8:	c46a0318 */ 	lwc1	$f10,0x318($v1)
/*  f0c73bc:	c4680310 */ 	lwc1	$f8,0x310($v1)
/*  f0c73c0:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c73c4:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0c73c8:	c462036c */ 	lwc1	$f2,0x36c($v1)
/*  f0c73cc:	460a2381 */ 	sub.s	$f14,$f4,$f10
/*  f0c73d0:	c4600374 */ 	lwc1	$f0,0x374($v1)
/*  f0c73d4:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f0c73d8:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*  f0c73dc:	46006207 */ 	neg.s	$f8,$f12
/*  f0c73e0:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0c73e4:	460ca03e */ 	c.le.s	$f20,$f12
/*  f0c73e8:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f0c73ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c73f0:	46026202 */ 	mul.s	$f8,$f12,$f2
/*  f0c73f4:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f0c73f8:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c73fc:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0c7400:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0c7404:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c7408:	46005207 */ 	neg.s	$f8,$f10
/*  f0c740c:	46004202 */ 	mul.s	$f8,$f8,$f0
/*  f0c7410:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0c7414:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c741c:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0c7420:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f0c7424:	46064200 */ 	add.s	$f8,$f8,$f6
/*  f0c7428:	4500001c */ 	bc1f	.L0f0c749c
/*  f0c742c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0c7430:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c7434:	46002086 */ 	mov.s	$f2,$f4
/*  f0c7438:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c743c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c7440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7444:	4502000f */ 	bc1fl	.L0f0c7484
/*  f0c7448:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0c744c:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0c7450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7454:	4502002c */ 	bc1fl	.L0f0c7508
/*  f0c7458:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c745c:	460a603c */ 	c.lt.s	$f12,$f10
/*  f0c7460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7464:	45020028 */ 	bc1fl	.L0f0c7508
/*  f0c7468:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c746c:	460a6183 */ 	div.s	$f6,$f12,$f10
/*  f0c7470:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7474:	e468017c */ 	swc1	$f8,0x17c($v1)
/*  f0c7478:	10000022 */ 	beqz	$zero,.L0f0c7504
/*  f0c747c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7480:	4614203c */ 	c.lt.s	$f4,$f20
.L0f0c7484:
/*  f0c7484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7488:	4502001f */ 	bc1fl	.L0f0c7508
/*  f0c748c:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7490:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7494:	1000001b */ 	beqz	$zero,.L0f0c7504
/*  f0c7498:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c749c:
/*  f0c749c:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c74a0:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f0c74a4:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c74a8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c74ac:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c74b0:	4502000f */ 	bc1fl	.L0f0c74f0
/*  f0c74b4:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c74b8:	4614503e */ 	c.le.s	$f10,$f20
/*  f0c74bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c74c0:	45020011 */ 	bc1fl	.L0f0c7508
/*  f0c74c4:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74c8:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c74cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c74d0:	4502000d */ 	bc1fl	.L0f0c7508
/*  f0c74d4:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74d8:	460a6183 */ 	div.s	$f6,$f12,$f10
/*  f0c74dc:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c74e0:	e468017c */ 	swc1	$f8,0x17c($v1)
/*  f0c74e4:	10000007 */ 	beqz	$zero,.L0f0c7504
/*  f0c74e8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c74ec:	4604a03c */ 	c.lt.s	$f20,$f4
.L0f0c74f0:
/*  f0c74f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c74f4:	45020004 */ 	bc1fl	.L0f0c7508
/*  f0c74f8:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74fc:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7500:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7504:
/*  f0c7504:	460ea03e */ 	c.le.s	$f20,$f14
.L0f0c7508:
/*  f0c7508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c750c:	4502001d */ 	bc1fl	.L0f0c7584
/*  f0c7510:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7514:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7518:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c751c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c7520:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c7524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7528:	4502000f */ 	bc1fl	.L0f0c7568
/*  f0c752c:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0c7530:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0c7534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7538:	4502002c */ 	bc1fl	.L0f0c75ec
/*  f0c753c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7540:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c7544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7548:	45020028 */ 	bc1fl	.L0f0c75ec
/*  f0c754c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7550:	460a7183 */ 	div.s	$f6,$f14,$f10
/*  f0c7554:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7558:	e4680184 */ 	swc1	$f8,0x184($v1)
/*  f0c755c:	10000022 */ 	beqz	$zero,.L0f0c75e8
/*  f0c7560:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7564:	4614203c */ 	c.lt.s	$f4,$f20
.L0f0c7568:
/*  f0c7568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c756c:	4502001f */ 	bc1fl	.L0f0c75ec
/*  f0c7570:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7574:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c7578:	1000001b */ 	beqz	$zero,.L0f0c75e8
/*  f0c757c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7580:	c4600184 */ 	lwc1	$f0,0x184($v1)
.L0f0c7584:
/*  f0c7584:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c7588:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c758c:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7594:	4502000f */ 	bc1fl	.L0f0c75d4
/*  f0c7598:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c759c:	4614503e */ 	c.le.s	$f10,$f20
/*  f0c75a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c75a4:	45020011 */ 	bc1fl	.L0f0c75ec
/*  f0c75a8:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75ac:	460e503c */ 	c.lt.s	$f10,$f14
/*  f0c75b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c75b4:	4502000d */ 	bc1fl	.L0f0c75ec
/*  f0c75b8:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75bc:	460a7183 */ 	div.s	$f6,$f14,$f10
/*  f0c75c0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c75c4:	e4680184 */ 	swc1	$f8,0x184($v1)
/*  f0c75c8:	10000007 */ 	beqz	$zero,.L0f0c75e8
/*  f0c75cc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c75d0:	4604a03c */ 	c.lt.s	$f20,$f4
.L0f0c75d4:
/*  f0c75d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c75d8:	45020004 */ 	bc1fl	.L0f0c75ec
/*  f0c75dc:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75e0:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c75e4:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c75e8:
/*  f0c75e8:	46141032 */ 	c.eq.s	$f2,$f20
.L0f0c75ec:
/*  f0c75ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c75f0:	4503001a */ 	bc1tl	.L0f0c765c
/*  f0c75f4:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c75f8:	c460016c */ 	lwc1	$f0,0x16c($v1)
/*  f0c75fc:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f0c7600:	460aa03c */ 	c.lt.s	$f20,$f10
/*  f0c7604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7608:	45020014 */ 	bc1fl	.L0f0c765c
/*  f0c760c:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c7610:	46028403 */ 	div.s	$f16,$f16,$f2
/*  f0c7614:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7618:	4614803e */ 	c.le.s	$f16,$f20
/*  f0c761c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7620:	45020005 */ 	bc1fl	.L0f0c7638
/*  f0c7624:	44813000 */ 	mtc1	$at,$f6
/*  f0c7628:	e474016c */ 	swc1	$f20,0x16c($v1)
/*  f0c762c:	1000000a */ 	beqz	$zero,.L0f0c7658
/*  f0c7630:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7634:	44813000 */ 	mtc1	$at,$f6
.L0f0c7638:
/*  f0c7638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c763c:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c7640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7644:	45020005 */ 	bc1fl	.L0f0c765c
/*  f0c7648:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c764c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0c7650:	e468016c */ 	swc1	$f8,0x16c($v1)
/*  f0c7654:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7658:
/*  f0c7658:	c7a20048 */ 	lwc1	$f2,0x48($sp)
.L0f0c765c:
/*  f0c765c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7664:	4503001a */ 	bc1tl	.L0f0c76d0
/*  f0c7668:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c766c:	c46019a4 */ 	lwc1	$f0,0x19a4($v1)
/*  f0c7670:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f0c7674:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c7678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c767c:	45020014 */ 	bc1fl	.L0f0c76d0
/*  f0c7680:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7684:	46029483 */ 	div.s	$f18,$f18,$f2
/*  f0c7688:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c768c:	4614903e */ 	c.le.s	$f18,$f20
/*  f0c7690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7694:	45020005 */ 	bc1fl	.L0f0c76ac
/*  f0c7698:	44815000 */ 	mtc1	$at,$f10
/*  f0c769c:	e47419a4 */ 	swc1	$f20,0x19a4($v1)
/*  f0c76a0:	1000000a */ 	beqz	$zero,.L0f0c76cc
/*  f0c76a4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c76a8:	44815000 */ 	mtc1	$at,$f10
.L0f0c76ac:
/*  f0c76ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c76b0:	460a903c */ 	c.lt.s	$f18,$f10
/*  f0c76b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c76b8:	45020005 */ 	bc1fl	.L0f0c76d0
/*  f0c76bc:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c76c0:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f0c76c4:	e46619a4 */ 	swc1	$f6,0x19a4($v1)
/*  f0c76c8:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c76cc:
/*  f0c76cc:	8c6200bc */ 	lw	$v0,0xbc($v1)
.L0f0c76d0:
/*  f0c76d0:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0c76d4:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0c76d8:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c76dc:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0c76e0:	46044001 */ 	sub.s	$f0,$f8,$f4
/*  f0c76e4:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c76e8:	46065081 */ 	sub.s	$f2,$f10,$f6
/*  f0c76ec:	46084102 */ 	mul.s	$f4,$f8,$f8
/*  f0c76f0:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c76f4:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f0c76f8:	46062380 */ 	add.s	$f14,$f4,$f6
/*  f0c76fc:	46147032 */ 	c.eq.s	$f14,$f20
/*  f0c7700:	46007306 */ 	mov.s	$f12,$f14
/*  f0c7704:	45010006 */ 	bc1t	.L0f0c7720
/*  f0c7708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c770c:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0c7710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7714:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0c7718:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c771c:	460e2303 */ 	div.s	$f12,$f4,$f14
.L0f0c7720:
/*  f0c7720:	0c012974 */ 	jal	sqrtf
/*  f0c7724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7728:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0c772c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7730:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7734:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0c7738:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c773c:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c7740:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0c7744:	e46400a4 */ 	swc1	$f4,0xa4($v1)
/*  f0c7748:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0c774c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7750:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c7754:	c46800a8 */ 	lwc1	$f8,0xa8($v1)
/*  f0c7758:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c775c:	e46400a8 */ 	swc1	$f4,0xa8($v1)
.L0f0c7760:
/*  f0c7760:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7764:	3c017f1b */ 	lui	$at,%hi(var7f1ad84c)
/*  f0c7768:	c42ad84c */ 	lwc1	$f10,%lo(var7f1ad84c)($at)
/*  f0c776c:	c4660148 */ 	lwc1	$f6,0x148($v1)
/*  f0c7770:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c7774:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f0c7778:	c468015c */ 	lwc1	$f8,0x15c($v1)
/*  f0c777c:	c46600b8 */ 	lwc1	$f6,0xb8($v1)
/*  f0c7780:	460a4103 */ 	div.s	$f4,$f8,$f10
/*  f0c7784:	44814000 */ 	mtc1	$at,$f8
/*  f0c7788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c778c:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0c7790:	c46600cc */ 	lwc1	$f6,0xcc($v1)
/*  f0c7794:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0c7798:	460a2080 */ 	add.s	$f2,$f4,$f10
/*  f0c779c:	0fc4505b */ 	jal	func0f11416c
/*  f0c77a0:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0c77a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c77a8:	44817000 */ 	mtc1	$at,$f14
/*  f0c77ac:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0c77b0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c77b4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c77b8:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0c77bc:	46000306 */ 	mov.s	$f12,$f0
/*  f0c77c0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c77c4:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0c77c8:	45020004 */ 	bc1fl	.L0f0c77dc
/*  f0c77cc:	44817000 */ 	mtc1	$at,$f14
/*  f0c77d0:	10000008 */ 	beqz	$zero,.L0f0c77f4
/*  f0c77d4:	46007086 */ 	mov.s	$f2,$f14
/*  f0c77d8:	44817000 */ 	mtc1	$at,$f14
.L0f0c77dc:
/*  f0c77dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c77e0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c77e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c77e8:	45020003 */ 	bc1fl	.L0f0c77f8
/*  f0c77ec:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c77f0:	46007086 */ 	mov.s	$f2,$f14
.L0f0c77f4:
/*  f0c77f4:	8d0b0284 */ 	lw	$t3,0x284($t0)
.L0f0c77f8:
/*  f0c77f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c77fc:	44061000 */ 	mfc1	$a2,$f2
/*  f0c7800:	8d6c03ac */ 	lw	$t4,0x3ac($t3)
/*  f0c7804:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0c7808:	15810004 */ 	bne	$t4,$at,.L0f0c781c
/*  f0c780c:	3c017f1b */ 	lui	$at,%hi(var7f1ad850)
/*  f0c7810:	c428d850 */ 	lwc1	$f8,%lo(var7f1ad850)($at)
/*  f0c7814:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f0c7818:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c781c:
/*  f0c781c:	0fc27637 */ 	jal	func0f09d8dc
/*  f0c7820:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0c7824:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7828:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c782c:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0c7830:	3c017f1b */ 	lui	$at,%hi(var7f1ad854)
/*  f0c7834:	c42ad854 */ 	lwc1	$f10,%lo(var7f1ad854)($at)
/*  f0c7838:	c5a40158 */ 	lwc1	$f4,0x158($t5)
/*  f0c783c:	460a2302 */ 	mul.s	$f12,$f4,$f10
/*  f0c7840:	0fc288a4 */ 	jal	func0f0a2290
/*  f0c7844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7848:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c784c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0c7850:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0c7854:	03e00008 */ 	jr	$ra
/*  f0c7858:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c785c
/*  f0c785c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0c7860:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c7864:	0fc31951 */ 	jal	currentPlayerUpdatePrevPosWalk
/*  f0c7868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c786c:	0fc318c6 */ 	jal	func0f0c6318
/*  f0c7870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7874:	0fc32fd4 */ 	jal	func0f0cbf50
/*  f0c7878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c787c:	0fc31a6e */ 	jal	func0f0c69b8
/*  f0c7880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7884:	0fc313f6 */ 	jal	func0f0c4fd8
/*  f0c7888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c788c:	3c05800a */ 	lui	$a1,0x800a
/*  f0c7890:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
/*  f0c7894:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0c7898:	8ca700bc */ 	lw	$a3,0xbc($a1)
/*  f0c789c:	84ee0028 */ 	lh	$t6,0x28($a3)
/*  f0c78a0:	00e01025 */ 	or	$v0,$a3,$zero
/*  f0c78a4:	10ce0017 */ 	beq	$a2,$t6,.L0f0c7904
/*  f0c78a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c78ac:	84a419b0 */ 	lh	$a0,0x19b0($a1)
/*  f0c78b0:	84e30028 */ 	lh	$v1,0x28($a3)
.L0f0c78b4:
/*  f0c78b4:	54830010 */ 	bnel	$a0,$v1,.L0f0c78f8
/*  f0c78b8:	8443002a */ 	lh	$v1,0x2a($v0)
/*  f0c78bc:	0fc19711 */ 	jal	func0f065c44
/*  f0c78c0:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0c78c4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0c78c8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0c78cc:	8c450284 */ 	lw	$a1,0x284($v0)
/*  f0c78d0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0c78d4:	84af19b0 */ 	lh	$t7,0x19b0($a1)
/*  f0c78d8:	8cb800bc */ 	lw	$t8,0xbc($a1)
/*  f0c78dc:	a70f0028 */ 	sh	$t7,0x28($t8)
/*  f0c78e0:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f0c78e4:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f0c78e8:	a506002a */ 	sh	$a2,0x2a($t0)
/*  f0c78ec:	10000005 */ 	beqz	$zero,.L0f0c7904
/*  f0c78f0:	8c450284 */ 	lw	$a1,0x284($v0)
/*  f0c78f4:	8443002a */ 	lh	$v1,0x2a($v0)
.L0f0c78f8:
/*  f0c78f8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0c78fc:	14c3ffed */ 	bne	$a2,$v1,.L0f0c78b4
/*  f0c7900:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c7904:
/*  f0c7904:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0c7908:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0c790c:	3c09800a */ 	lui	$t1,0x800a
/*  f0c7910:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f0c7914:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0c7918:	0fc257d8 */ 	jal	objectiveCheckRoomEntered
/*  f0c791c:	85440028 */ 	lh	$a0,0x28($t2)
/*  f0c7920:	3c05800a */ 	lui	$a1,0x800a
/*  f0c7924:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
/*  f0c7928:	8cab1af8 */ 	lw	$t3,0x1af8($a1)
/*  f0c792c:	11600023 */ 	beqz	$t3,.L0f0c79bc
/*  f0c7930:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7934:	44811000 */ 	mtc1	$at,$f2
/*  f0c7938:	c4a41b50 */ 	lwc1	$f4,0x1b50($a1)
/*  f0c793c:	c4a61afc */ 	lwc1	$f6,0x1afc($a1)
/*  f0c7940:	c4aa1b4c */ 	lwc1	$f10,0x1b4c($a1)
/*  f0c7944:	8cac00bc */ 	lw	$t4,0xbc($a1)
/*  f0c7948:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c794c:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f0c7950:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f0c7954:	460a1401 */ 	sub.s	$f16,$f2,$f10
/*  f0c7958:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f0c795c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c7960:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0c7964:	8cad00bc */ 	lw	$t5,0xbc($a1)
/*  f0c7968:	c4b01b4c */ 	lwc1	$f16,0x1b4c($a1)
/*  f0c796c:	c4aa1b54 */ 	lwc1	$f10,0x1b54($a1)
/*  f0c7970:	c5a0000c */ 	lwc1	$f0,0xc($t5)
/*  f0c7974:	46101481 */ 	sub.s	$f18,$f2,$f16
/*  f0c7978:	46005201 */ 	sub.s	$f8,$f10,$f0
/*  f0c797c:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f0c7980:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f0c7984:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0c7988:	c4b21b4c */ 	lwc1	$f18,0x1b4c($a1)
/*  f0c798c:	c4b01b04 */ 	lwc1	$f16,0x1b04($a1)
/*  f0c7990:	c4aa1b58 */ 	lwc1	$f10,0x1b58($a1)
/*  f0c7994:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0c7998:	8cae00bc */ 	lw	$t6,0xbc($a1)
/*  f0c799c:	46105201 */ 	sub.s	$f8,$f10,$f16
/*  f0c79a0:	c5ca0010 */ 	lwc1	$f10,0x10($t6)
/*  f0c79a4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c79a8:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0c79ac:	0fc33067 */ 	jal	func0f0cc19c
/*  f0c79b0:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0c79b4:	10000004 */ 	beqz	$zero,.L0f0c79c8
/*  f0c79b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c79bc:
/*  f0c79bc:	8ca400bc */ 	lw	$a0,0xbc($a1)
/*  f0c79c0:	0fc33067 */ 	jal	func0f0cc19c
/*  f0c79c4:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0c79c8:
/*  f0c79c8:	0fc307fd */ 	jal	func0f0c1ff4
/*  f0c79cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c79d0:	0fc23064 */ 	jal	func0f08c190
/*  f0c79d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c79d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c79dc:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0c79e0:	03e00008 */ 	jr	$ra
/*  f0c79e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c79e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c79ec:	00000000 */ 	sll	$zero,$zero,0x0
);
