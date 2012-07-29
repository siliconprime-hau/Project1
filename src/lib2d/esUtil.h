#ifndef ESUTIL_H
#define ESUTIL_H

#include <GLES2/gl2.h>

#ifdef __WINDOW__
#include <EGL/egl.h>
#endif

struct ESMatrix
{
    GLfloat   m[4][4];
};

//esShader
GLuint  esLoadShader ( GLenum type, const char *shaderSrc );
GLuint  esLoadProgram ( const char *vertShaderSrc, const char *fragShaderSrc );

//esTransform
void  esScale(ESMatrix *result, GLfloat sx, GLfloat sy, GLfloat sz);
void  esTranslate(ESMatrix *result, GLfloat tx, GLfloat ty, GLfloat tz);
void  esRotate(ESMatrix *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void  esFrustum(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);
void  esPerspective(ESMatrix *result, float fovy, float aspect, float nearZ, float farZ);
void  esOrtho(ESMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ);
void  esMatrixMultiply(ESMatrix *result, ESMatrix *srcA, ESMatrix *srcB);
void  esMatrixLoadIdentity(ESMatrix *result);

//esUtil
void  esLogMessage ( const char *formatStr, ... );

#endif // ESUTIL_H