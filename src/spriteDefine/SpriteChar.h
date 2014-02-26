#ifndef __SPRITE_CHAR__
#define __SPRITE_CHAR__

#include "l2d.h"

//modules define
unsigned short charModules[] =
{
	0, 0, 32, 32,//first row: 0->
	32, 0, 32, 32,
	64, 0, 32, 32,
	96, 0, 32, 32,
	128, 0, 32, 32,
	160, 0, 32, 32,
	192, 0, 32, 32,
	224, 0, 32, 32,

	0, 32, 32, 32,//second row: 8->
	32, 32, 32, 32,
	64, 32, 32, 32,
	96, 32, 32, 32,
	128, 32, 32, 32,
	160, 32, 32, 32,
	192, 32, 32, 32,
	224, 32, 32, 32,

	0, 64, 32, 32,//third row: 16->
	32, 64, 32, 32,
	64, 64, 32, 32,
	96, 64, 32, 32,
	128, 64, 32, 32,
	160, 64, 32, 32,
	192, 64, 32, 32,
	224, 64, 32, 32,

	0, 96, 32, 32,//24->
	32, 96, 32, 32,
	64, 96, 32, 32,
	96, 96, 32, 32,
	128, 96, 32, 32,
	160, 96, 32, 32,
	192, 96, 32, 32,
	224, 96, 32, 32,

	0, 128, 32, 32,//32->
	32, 128, 32, 32,
	64, 128, 32, 32,
	96, 128, 32, 32,
	128, 128, 32, 32,
	160, 128, 32, 32,
	192, 128, 32, 32,
	224, 128, 32, 32,

	0, 160, 32, 32,//40->
	32, 160, 32, 32,
	64, 160, 32, 32,
	96, 160, 32, 32,
	128, 160, 32, 32,
	160, 160, 32, 32,
	192, 160, 32, 32,
	224, 160, 32, 32,

	0, 192, 32, 32,//48->
	32, 192, 32, 32,
	64, 192, 32, 32,
	96, 192, 32, 32,
	128, 192, 32, 32,
	160, 192, 32, 32,
	192, 192, 32, 32,
	224, 192, 32, 32,

	0, 224, 32, 32,//56->
	32, 224, 32, 32,
	64, 224, 32, 32,
	96, 224, 32, 32,
	128, 224, 32, 32,

	160, 224, 32, 32,//61 yellow circle
	192, 224, 32, 32,//62 blue circle
	224, 224, 32, 32//63 red circle
};



//frames define
short charFrame44[] =
{
	1,
	44, 0, 0
};
short charFrame45[] =
{
	1,
	45, 0, 0
};
short charFrame46[] =
{
	1,
	46, 0, 0
};
short charFrame47[] =
{
	1,
	47, 0, 0
};
short charFrame48[] =
{
	1,
	48, 0, 0
};
short charFrame49[] =
{
	1,
	49, 0, 0
};
short charFrame50[] =
{
	1,
	50, 0, 0
};
short charFrame51[] =
{
	1,
	51, 0, 0
};
short charFrame52[] =
{
	1,
	52, 0, 0
};
short charFrame53[] =
{
	1,
	53, 0, 0
};
short charFrame54[] =
{
	1,
	54, 0, 0
};
short charFrame55[] =
{
	1,
	55, 0, 0
};
short charFrame56[] =
{
	1,
	56, 0, 0
};
short charFrame57[] =
{
	1,
	57, 0, 0
};
short charFrame58[] =
{
	1,
	58, 0, 0
};

//yellow frame
short charFrame61[] =
{
	1,
	61, 0, 0
};
//blue frame
short charFrame62[] =
{
	1,
	62, 0, 0
};
//red frame
short charFrame63[] =
{
	1,
	63, 0, 0
};


short* charFrames[] =
{
	charFrame44,
	charFrame45,
	charFrame46,
	charFrame47,
	charFrame48,
	charFrame49,
	charFrame50,
	charFrame51,
	charFrame52,
	charFrame53,
	charFrame54,
	charFrame55,
	charFrame56,
	charFrame57,
	charFrame58,
	
	charFrame61,//15 yellow frame
	charFrame62,//16 blue frame
	charFrame63//17 red frame
};



//anims define
#define ANIM_FRAME_OR_TIME	100
#define YELLOW_FRAME_INDEX		15
#define BLUE_FRAME_INDEX		16
#define RED_FRAME_INDEX		17

#define NUM_FRAME 1		//2: animate, 1: stand

short charAnimData44[] =
{
	NUM_FRAME,
	0, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData45[] =
{
	NUM_FRAME,
	1, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData46[] =
{
	NUM_FRAME,
	2, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData47[] =
{
	NUM_FRAME,
	3, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData48[] =
{
	NUM_FRAME,
	4, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData49[] =
{
	NUM_FRAME,
	5, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData50[] =
{
	NUM_FRAME,
	6, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData51[] =
{
	NUM_FRAME,
	7, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData52[] =
{
	NUM_FRAME,
	8, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData53[] =
{
	NUM_FRAME,
	9, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData54[] =
{
	NUM_FRAME,
	10, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData55[] =
{
	NUM_FRAME,
	11, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData56[] =
{
	NUM_FRAME,
	12, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData57[] =
{
	NUM_FRAME,
	13, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};
short charAnimData58[] =
{
	NUM_FRAME,
	14, 0, 0, ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX, 0, 0, ANIM_FRAME_OR_TIME
};

Anim* charAnim0 = new Anim(charAnimData44);
Anim* charAnim1 = new Anim(charAnimData45);
Anim* charAnim2 = new Anim(charAnimData46);
Anim* charAnim3 = new Anim(charAnimData47);
Anim* charAnim4 = new Anim(charAnimData48);
Anim* charAnim5 = new Anim(charAnimData49);
Anim* charAnim6 = new Anim(charAnimData50);
Anim* charAnim7 = new Anim(charAnimData51);
Anim* charAnim8 = new Anim(charAnimData52);
Anim* charAnim9 = new Anim(charAnimData53);
Anim* charAnim10 = new Anim(charAnimData54);
Anim* charAnim11 = new Anim(charAnimData55);
Anim* charAnim12 = new Anim(charAnimData56);
Anim* charAnim13 = new Anim(charAnimData57);
Anim* charAnim14 = new Anim(charAnimData58);

Anim* charAnims[] =
{
	charAnim0,
	charAnim1,
	charAnim2,
	charAnim3,
	charAnim4,
	charAnim5,
	charAnim6,
	charAnim7,
	charAnim8,
	charAnim9,
	charAnim10,
	charAnim11,
	charAnim12,
	charAnim13,
	charAnim14,
};

enum SPRITE_CHAR_ANIM
{
	SPRITE_CHAR_ANIM_UP = 0,
	SPRITE_CHAR_ANIM_RIGHT,
	SPRITE_CHAR_ANIM_DOWN,
	SPRITE_CHAR_ANIM_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN,
	SPRITE_CHAR_ANIM_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_DOWN_LEFT_UP,
	SPRITE_CHAR_ANIM_LEFT_UP_RIGHT,
	SPRITE_CHAR_ANIM_UP_DOWN,
	SPRITE_CHAR_ANIM_RIGHT_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT,
	SPRITE_CHAR_ANIM_RIGHT_DOWN,
	SPRITE_CHAR_ANIM_DOWN_LEFT,
	SPRITE_CHAR_ANIM_LEFT_UP
};

int enemySpriteMap[] =
{
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,//range = 1
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_UP_DOWN,
	SPRITE_CHAR_ANIM_RIGHT_LEFT,
	SPRITE_CHAR_ANIM_DOWN,
	SPRITE_CHAR_ANIM_UP,
	SPRITE_CHAR_ANIM_RIGHT,
	SPRITE_CHAR_ANIM_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,//range = 2
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_UP_RIGHT_DOWN_LEFT,
	SPRITE_CHAR_ANIM_UP_DOWN,
	SPRITE_CHAR_ANIM_RIGHT_LEFT,
	SPRITE_CHAR_ANIM_UP,
	SPRITE_CHAR_ANIM_RIGHT,
	SPRITE_CHAR_ANIM_LEFT
};

#endif //__SPRITE_CHAR__