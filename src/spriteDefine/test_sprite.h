#include "Sprite.h"

unsigned short testModules[] =
{
63,	51,	129,	129,
308,	50,	129,	129,
195,	187,	129,	129,
39,	308,	129,	129
};

short frame0[] =
{
	1,
	0, 0, 0
};
short frame1[] =
{
	1,
	1, 0, 0
};
short frame2[] =
{
	1,
	2, 0, 0
};
short frame3[] =
{
	2,
	0, -103,	-79,
    1,	26,	-17
};
short frame4[] =
{
	2,
	2, 0, 0,
	1, 129, 0,
};
short* testFrames[] =
{
	frame0,
	frame1,
	frame2,
	frame3,
	frame4
};

short anim1_data[] =
{
	3,
	0, 0, 0, 5,
	1, 0, 0, 10,
	2, 0, 0, 5
};
short anim2_data[] =
{
	2,
	0, 0, 0, 500,
	1, 0, 0, 500
};
Anim* anim1 = new Anim( anim1_data );
Anim* anim2 = new Anim( anim2_data );

Anim* testAnims[] =
{
	anim1,
	anim2
};