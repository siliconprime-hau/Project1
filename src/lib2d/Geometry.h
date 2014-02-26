#ifndef __GEOMETRY__
#define __GEOMETRY__

//collection of global geometry functions

//color is in RGBA format ex: 0x112233ff
/*
void DrawCircle( float x, float y, float radius, bool fill, unsigned int color );
*/
void DrawRect( float x, float y, float w, float h, unsigned int color );
void DrawLine( float x1, float y1, float x2, float y2, unsigned int color );

#endif //__GEOMETRY__