//
// Mr. Blonde's Revenge
//

#include "stagesetup.h"

u8 intro[];
u8 props[];
struct aipaths paths[];
struct ailists functions[];

void *setup[] = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	functions,
	NULL,
};

u8 props[] = {
	endprops
};

u8 intro[] = {
	endintro
};

s32 path00[] = {
	-1,
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

u8 func0000_0034[] = {
	endfunction
};

struct ailists functions[] = {
	{ NULL, 0 },
};
