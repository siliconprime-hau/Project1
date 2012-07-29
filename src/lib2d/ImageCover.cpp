#include "ImageCover.h"
#include "soilex/SOIL.h"
#include "l2dGlobals.h"
#include <stdlib.h>

ImageCover::ImageCover( const char* fileName )
{
	/*mTexID = SOIL_load_OGL_texture_ex
		(
			fileName,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO,
			&mWidth, &mHeight
		);*/			
	
	/*FILE *f = fopen(fileName, "rb");
	mTexID = SOIL_load_OGL_texture_ex_from_file
		(
			f,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO,
			&mWidth, &mHeight
		);
	fclose(f);*/

	FILE *f = fopen(fileName, "rb");
	fseek( f, 0, SEEK_END );
	int len = ftell( f );
	rewind( f );
	unsigned char* buffer = new unsigned char[len];
	fread( buffer, sizeof(char), len, f);
	fclose(f);
	mTexID = SOIL_load_OGL_texture_ex_from_memory
		(
			buffer,
			len,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO,
			&mWidth, &mHeight
		);			
	delete[] buffer;
}

ImageCover::~ImageCover()
{
}

void ImageCover::PaintA
	(
		float scr_x, float scr_y, float scr_w, float scr_h,
		float img_x, float img_y, float img_w, float img_h,
		int anchor_h, int anchor_v
	)
{
	if(
		(img_x < 0) || (img_y < 0)
		|| (img_x > (mWidth-1)) || (img_y > (mHeight-1))
		|| (img_w < 1) || (img_h < 1)
	)
	{
		return;//not valid rect
	}

	ResetTexMvp();
	esMatrixMultiply( &gMvpMatrix, &gModelView, &gOrthor );
	glUniformMatrix4fv( gTexMvpLoc, 1, GL_FALSE, (GLfloat*) &gMvpMatrix.m[0][0] );
	
	if( anchor_h == ANCHOR_CENTER )
	{
		scr_x -= (scr_w/2); 
	}
	else if( anchor_h == ANCHOR_RIGHT )
	{
		scr_x -= scr_w;
	}
	//else if( anchor_h == ANCHOR_LEFT ){}//this is the default anchor

	if( anchor_v == ANCHOR_CENTER )
	{
		scr_y -= (scr_h/2); 
	}
	else if( anchor_v == ANCHOR_BOTTOM )
	{
		scr_y -= scr_h;
	}
	//else if( anchor_v == ANCHOR_TOP ){}//this is the default anchor

	GLfloat tex_coord[] =
	{
		min( img_x/mWidth, 1 ),//x coord
		min( img_y/mHeight, 1 ),//y coord

		min( (img_x + img_w)/mWidth, 1 ),
		min( img_y/mHeight, 1 ),

		min( (img_x + img_w)/mWidth, 1 ),
		min( (img_y + img_h)/mHeight, 1 ),

		min( img_x/mWidth, 1 ),
		min( (img_y + img_h)/mHeight, 1 )
	};

	if( (img_x + img_w) > mWidth )
	{
		scr_w -= (scr_w * ((img_x + img_w) - mWidth)/img_w);
	}
	if( (img_y + img_h) > mHeight )
	{
		scr_h -= (scr_h * ((img_y + img_h) - mHeight)/img_h);
	}

	//update visible zone on GraphicObject class
	mVisiblePosX = scr_x;
	mVisiblePosY = scr_y;
	mVisibleWidth = scr_w;
	mVisibleHeight = scr_h;

	GLfloat* vertices = GenRect( scr_x, scr_y, scr_w, scr_h );
	GLushort indices[] = { 0, 1, 2, 0, 2, 3 };

	glVertexAttribPointer( gTexPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, vertices );	
	glVertexAttribPointer( gTexCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, tex_coord );

	glEnableVertexAttribArray( gTexPositionLoc );
	glEnableVertexAttribArray( gTexCoordLoc );

	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, mTexID );
	
	glUniform1i( gTexSamplerLoc, 0 );

	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );	

	delete[] vertices;
}

void ImageCover::PaintA( float scr_x, float scr_y, int anchor_h, int anchor_v )
{
	PaintA( scr_x, scr_y, mWidth, mHeight, 0, 0, mWidth, mHeight, anchor_h, anchor_v );
}

void ImageCover::PaintA( float scr_x, float scr_y, float img_x, float img_y, float img_w, float img_h, int anchor_h, int anchor_v )
{
	PaintA( scr_x, scr_y, img_w, img_h, img_x, img_y, img_w, img_h, anchor_h, anchor_v );
}

void ImageCover::PaintA( float scr_x, float scr_y, float scr_w, float scr_h, int anchor_h, int anchor_v )
{
	PaintA( scr_x, scr_y, scr_w, scr_h, 0, 0, mWidth, mHeight, anchor_h, anchor_v );
}

//----------//
void ImageCover::Paint
	(
		float scr_x, float scr_y, float scr_w, float scr_h,
		float img_x, float img_y, float img_w, float img_h
	)
{
	PaintA( scr_x, scr_y, scr_w, scr_h, img_x, img_y, img_w, img_h, ANCHOR_LEFT, ANCHOR_TOP );
}

void ImageCover::Paint( float scr_x, float scr_y )
{
	PaintA( scr_x, scr_y, mWidth, mHeight, 0, 0, mWidth, mHeight, ANCHOR_LEFT, ANCHOR_TOP );
}

void ImageCover::Paint( float scr_x, float scr_y, float img_x, float img_y, float img_w, float img_h )
{
	PaintA( scr_x, scr_y, img_w, img_h, img_x, img_y, img_w, img_h, ANCHOR_LEFT, ANCHOR_TOP );
}

void ImageCover::Paint( float scr_x, float scr_y, float scr_w, float scr_h )
{
	PaintA( scr_x, scr_y, scr_w, scr_h, 0, 0, mWidth, mHeight, ANCHOR_LEFT, ANCHOR_TOP );
}
