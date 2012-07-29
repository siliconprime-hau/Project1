#include "SoundMng.h"
#include "windows.h"
#include "mmsystem.h"

#include "Res.h"

SoundMng::SoundMng()
{
}

SoundMng::~SoundMng()
{
}

void SoundMng::Init( const char *fileName[], int numFile )
{

}

void SoundMng::Play( int fileIndex )
{
	if( fileIndex < RES_AUDIO_COUNT )
	{
		//PlaySound( gResAudio[fileIndex],	NULL, SND_ASYNC|SND_FILENAME );
	}	
}
