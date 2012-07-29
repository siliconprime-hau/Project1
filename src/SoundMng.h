#ifndef __SOUNDMNG__
#define __SOUNDMNG__

//class that control sound functions

class SoundMng
{
public:
	SoundMng();
	~SoundMng();

	void Init( const char *fileName[], int numFile );
	void Play( int fileIndex );
};


#endif //__SOUNDMNG__