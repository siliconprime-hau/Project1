#include "Geometry.h"
#include "l2dGlobals.h"

GLfloat* ParseColor( unsigned int color );

GLfloat* ParseColor( unsigned int color )
{
	float r = (float) ( color >> 24 ) / 255;
	float g = (float) ( ( color >> 16 ) & 0x00ff ) / 255;
	float b = (float) ( ( color >> 8 ) & 0x0000ff ) / 255;
	float a = (float) ( color & 0x000000ff ) / 255;
	
	GLfloat* vColor = new GLfloat[4];
	vColor[0] = r;
	vColor[1] = g;
	vColor[2] = b;
	vColor[3] = a;

	return vColor;
}

void DrawRect( float x, float y, float w, float h, unsigned int color )//color should be like this 0xFFFFFFFF
{
	gResetGeoMvp();		
	esMatrixMultiply( &gMvpMatrix, &gModelView, &gOrthor );
	glUniformMatrix4fv( gGeoMvpLoc, 1, GL_FALSE, (GLfloat*) &gMvpMatrix.m[0][0] );
	
	GLfloat* vertices = gnGenRect( x, y, w, h );    
	GLfloat* vColor = ParseColor( color );
		
	glVertexAttribPointer ( gGeoPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, vertices );
	glUniform4fv ( gGeoColorLoc, 1, vColor );
	glEnableVertexAttribArray ( gGeoPositionLoc );

	glDrawArrays ( GL_TRIANGLE_FAN, 0, 4 );
	delete[] vertices;
	delete[] vColor;
}

void DrawLine( float x1, float y1, float x2, float y2, unsigned int color )
{
	gResetGeoMvp();		
	esMatrixMultiply( &gMvpMatrix, &gModelView, &gOrthor );
	glUniformMatrix4fv( gGeoMvpLoc, 1, GL_FALSE, (GLfloat*) &gMvpMatrix.m[0][0] );
	
	GLfloat* vColor = ParseColor( color );
	GLfloat* vertices = new GLfloat[4];    
	vertices[0] = gPixelToCoordX(x1);
	vertices[1] = gPixelToCoordY(y1);
	vertices[2] = gPixelToCoordX(x2);
	vertices[3] = gPixelToCoordY(y2);
		
	glVertexAttribPointer ( gGeoPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, vertices );
	glUniform4fv ( gGeoColorLoc, 1, vColor );
	glEnableVertexAttribArray ( gGeoPositionLoc );

	glDrawArrays ( GL_LINES, 0, 2 );	
	delete[] vColor;
	delete[] vertices;
}