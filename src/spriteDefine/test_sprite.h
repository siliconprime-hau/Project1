#include "l2d.h"

unsigned short testModules[] =
{
63,	51,	129,	129,//yellow
308,	50,	129,	129,//red
195,	187,	129,	129,//blue
39,	308,	129,	129//green
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
	1,	
	3, 0, 0
};
short frame4[] =
{
	1,	
    1,	0,	0
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
	2,	
	1, 0, 0, 50,
	3, 0, 0, 50
};
short anim2_data[] =
{
	2,	
	2, 0, 0, 50,
	1, 0, 0, 50
};
short anim3_data[] =
{
	2,
	1, 0, 0, 50,
	2, 0, 0, 50
};
short anim4_data[] =
{
	2,
	1, 0, 0, 50,
	3, 0, 0, 50
};
short anim5_data[] =
{
	1,	
	3, 0, 0, 50
};
Anim* anim1 = new Anim( anim1_data );
Anim* anim2 = new Anim( anim2_data );
Anim* anim3 = new Anim( anim3_data );
Anim* anim4 = new Anim( anim4_data );
Anim* anim5 = new Anim( anim5_data );

Anim* testAnims[] =
{
	anim1,
	anim2,
	anim3,
	anim4,
	anim5
};