#include "l2d.h"


//modules define
unsigned short charModules[] =
{
	0,		0,		32,		32,//first row: 0->
	32,		0,		32,		32,
	64,		0,		32,		32,
	96,		0,		32,		32,
	128,	0,		32,		32,
	160,	0,		32,		32,
	192,	0,		32,		32,
	224,	0,		32,		32,

	0,		32,		32,		32,//second row: 8->
	32,		32,		32,		32,
	64,		32,		32,		32,
	96,		32,		32,		32,
	128,	32,		32,		32,
	160,	32,		32,		32,
	192,	32,		32,		32,
	224,	32,		32,		32,

	0,		64,		32,		32,//third row: 16->
	32,		64,		32,		32,
	64,		64,		32,		32,
	96,		64,		32,		32,
	128,	64,		32,		32,
	160,	64,		32,		32,
	192,	64,		32,		32,
	224,	64,		32,		32,

	0,		96,		32,		32,//24->
	32,		96,		32,		32,
	64,		96,		32,		32,
	96,		96,		32,		32,
	128,	96,		32,		32,
	160,	96,		32,		32,
	192,	96,		32,		32,
	224,	96,		32,		32,

	0,		128,	32,		32,//32->
	32,		128,	32,		32,
	64,		128,	32,		32,
	96,		128,	32,		32,
	128,	128,	32,		32,
	160,	128,	32,		32,
	192,	128,	32,		32,
	224,	128,	32,		32,

	0,		160,	32,		32,//40->
	32,		160,	32,		32,
	64,		160,	32,		32,
	96,		160,	32,		32,
	128,	160,	32,		32,
	160,	160,	32,		32,
	192,	160,	32,		32,
	224,	160,	32,		32,

	0,		192,	32,		32,//48->
	32,		192,	32,		32,
	64,		192,	32,		32,
	96,		192,	32,		32,
	128,	192,	32,		32,
	160,	192,	32,		32,
	192,	192,	32,		32,
	224,	192,	32,		32,

	0,		224,	32,		32,//56->
	32,		224,	32,		32,
	64,		224,	32,		32,
	96,		224,	32,		32,
	128,	224,	32,		32,

	160,	224,	32,		32,//61 yellow circle
	192,	224,	32,		32,//62 blue circle
	224,	224,	32,		32//63 red circle
};



//frames define
short charFrame0[] =
{
	1,
	0, 0, 0
};
short charFrame1[] =
{
	1,
	1, 0, 0
};
short charFrame2[] =
{
	1,
	2, 0, 0
};
short charFrame3[] =
{
	1,
	3, 0, 0
};
short charFrame4[] =
{
	1,
	4, 0, 0
};
short charFrame5[] =
{
	1,
	5, 0, 0
};
short charFrame6[] =
{
	1,
	6, 0, 0
};
short charFrame7[] =
{
	1,
	7, 0, 0
};
short charFrame8[] =
{
	1,
	8, 0, 0
};
short charFrame9[] =
{
	1,
	9, 0, 0
};
short charFrame10[] =
{
	1,
	10, 0, 0
};
short charFrame11[] =
{
	1,
	11, 0, 0
};
short charFrame12[] =
{
	1,
	12, 0, 0
};
short charFrame13[] =
{
	1,
	13, 0, 0
};
short charFrame14[] =
{
	1,
	14, 0, 0
};
short charFrame15[] =
{
	1,
	15, 0, 0
};
short charFrame16[] =
{
	1,
	16, 0, 0
};
short charFrame17[] =
{
	1,
	17, 0, 0
};
short charFrame18[] =
{
	1,
	18, 0, 0
};
short charFrame19[] =
{
	1,
	19, 0, 0
};
short charFrame20[] =
{
	1,
	20, 0, 0
};
short charFrame21[] =
{
	1,
	21, 0, 0
};
short charFrame22[] =
{
	1,
	22, 0, 0
};
short charFrame23[] =
{
	1,
	23, 0, 0
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
	charFrame0,
	charFrame1,
	charFrame2,
	charFrame3,
	charFrame4,
	charFrame5,
	charFrame6,
	charFrame7,
	charFrame8,
	charFrame9,
	charFrame10,
	charFrame11,
	charFrame12,
	charFrame13,
	charFrame14,
	charFrame15,
	charFrame16,
	charFrame17,
	charFrame18,
	charFrame19,
	charFrame20,
	charFrame21,
	charFrame22,
	charFrame23,
	
	charFrame61,//24 yellow frame
	charFrame62,//25 blue frame
	charFrame63//26 red frame
};



//anims define
#define ANIM_FRAME_OR_TIME	100
#define YELLOW_FRAME_INDEX		24
#define BLUE_FRAME_INDEX		25
#define RED_FRAME_INDEX		26

#define NUM_FRAME 2		//2: animate, 1: stand

short charAnimData0[] =
{
	NUM_FRAME,
	0,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData1[] =
{
	NUM_FRAME,
	1,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData2[] =
{
	NUM_FRAME,
	2,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData3[] =
{
	NUM_FRAME,
	3,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData4[] =
{
	NUM_FRAME,
	4,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData5[] =
{
	NUM_FRAME,
	5,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData6[] =
{
	NUM_FRAME,
	6,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData7[] =
{
	NUM_FRAME,
	7,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData8[] =
{
	NUM_FRAME,
	8,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData9[] =
{
	NUM_FRAME,
	9,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData10[] =
{
	NUM_FRAME,
	10,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData11[] =
{
	NUM_FRAME,
	11,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData12[] =
{
	NUM_FRAME,
	12,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData13[] =
{
	NUM_FRAME,
	13,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData14[] =
{
	NUM_FRAME,
	14,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData15[] =
{
	NUM_FRAME,
	15,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData16[] =
{
	NUM_FRAME,
	16,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData17[] =
{
	NUM_FRAME,
	17,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData18[] =
{
	NUM_FRAME,
	18,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData19[] =
{
	NUM_FRAME,
	19,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData20[] =
{
	NUM_FRAME,
	20,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData21[] =
{
	NUM_FRAME,
	21,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData22[] =
{
	NUM_FRAME,
	22,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData23[] =
{
	NUM_FRAME,
	23,					0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};



short charAnimData62[] =//yellow - red
{
	NUM_FRAME,
	YELLOW_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};
short charAnimData63[] =//red - blue
{
	NUM_FRAME,
	RED_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME,
	BLUE_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME	
};
short charAnimData64[] =//yellow - blue
{
	NUM_FRAME,
	YELLOW_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME,
	BLUE_FRAME_INDEX,	0,	0,	ANIM_FRAME_OR_TIME
};


Anim* charAnim0 = new Anim( charAnimData0 );
Anim* charAnim1 = new Anim( charAnimData1 );
Anim* charAnim2 = new Anim( charAnimData2 );
Anim* charAnim3 = new Anim( charAnimData3 );
Anim* charAnim4 = new Anim( charAnimData4 );
Anim* charAnim5 = new Anim( charAnimData5 );
Anim* charAnim6 = new Anim( charAnimData6 );
Anim* charAnim7 = new Anim( charAnimData7 );
Anim* charAnim8 = new Anim( charAnimData8 );
Anim* charAnim9 = new Anim( charAnimData9 );
Anim* charAnim10 = new Anim( charAnimData10 );
Anim* charAnim11 = new Anim( charAnimData11 );
Anim* charAnim12 = new Anim( charAnimData12 );
Anim* charAnim13 = new Anim( charAnimData13 );
Anim* charAnim14 = new Anim( charAnimData14 );
Anim* charAnim15 = new Anim( charAnimData15 );
Anim* charAnim16 = new Anim( charAnimData16 );
Anim* charAnim17 = new Anim( charAnimData17 );
Anim* charAnim18 = new Anim( charAnimData18 );
Anim* charAnim19 = new Anim( charAnimData19 );
Anim* charAnim20 = new Anim( charAnimData20 );
Anim* charAnim21 = new Anim( charAnimData21 );
Anim* charAnim22 = new Anim( charAnimData22 );
Anim* charAnim23 = new Anim( charAnimData23 );

Anim* charAnim62 = new Anim( charAnimData62 );//yellow - red
Anim* charAnim63 = new Anim( charAnimData63 );//red - blue
Anim* charAnim64 = new Anim( charAnimData64 );//yellow - blue

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
	charAnim15,
	charAnim16,
	charAnim17,
	charAnim18,
	charAnim19,
	charAnim20,
	charAnim21,
	charAnim22,
	charAnim23,

	charAnim62,//24 yellow - red
	charAnim63,//25 red - blue
	charAnim64//26 yellow - blue
};