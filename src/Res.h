#ifndef __RES__
#define __RES__

#ifdef __WINDOW__
#define IMAGE_RES_PATH "./../res/"
#define AUDIO_RES_PATH "./../res/"
#else
#ifdef __ANDROID__
#define IMAGE_RES_PATH "/mnt/sdcard/project1/res/"
#define AUDIO_RES_PATH "/mnt/sdcard/project1/res/"
#else
#endif
#endif

enum RES_IMAGE
{
	PNG = 0,
	JPG,
	BMP,
	TGA,
	DDS,
	TEST_SPRITE,

	RES_IMAGE_COUNT
};

extern const char* gResImage[];


enum RES_AUDIO
{
	EFFECT_MUSIC_1 = 0,
	EFFECT_MUSIC_2,
	EFFECT_MUSIC_3,
	BACKGROUND_MUSIC,

	RES_AUDIO_COUNT
};

extern const char* gResAudio[];

#endif //__RES__