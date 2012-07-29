#ifndef __WINUTIL__
#define __WINUTIL__

#include <GLES2/gl2.h>
#include <EGL/egl.h>

EGLBoolean InitEGL( char* title, float screenWidth, float screenHeight, GLuint flags );
void EGLSwapBuffer();

//flag - RGB color buffer
#define ES_WINDOW_RGB           0
//flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1 
//flag - depth buffer
#define ES_WINDOW_DEPTH         2 
//flag - stencil buffer
#define ES_WINDOW_STENCIL       4
//flag - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8

#endif //__WINUTIL__