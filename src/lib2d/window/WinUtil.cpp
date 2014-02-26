#include "WinUtil.h"
#include "Globals.h"
#include "Game.h"

HWND gHwnd;
EGLDisplay gEglDisplay;
EGLContext gEglContext;
EGLSurface gEglSurface;

GLboolean WinCreate ( const char *title, float screenWidth, float screenHeight );
EGLBoolean CreateEGLContext ( GLuint flags );

EGLBoolean InitEGL( char* title, float screenWidth, float screenHeight, GLuint flags )
{
	WinCreate( title, screenWidth, screenHeight );
	CreateEGLContext( flags );
	return EGL_TRUE;
}

void EGLSwapBuffer()
{
	eglSwapBuffers ( gEglDisplay, gEglSurface );
}

LRESULT WINAPI MainWindowProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) 
{
   LRESULT  lRet = 1; 
   int xPos = -1;
   int yPos = -1;

   switch (uMsg) 
   { 
	case WM_DESTROY:
			PostQuitMessage(0);             
		break;       

	case WM_LBUTTONDOWN:		  
			xPos = LOWORD( lParam );
			yPos = HIWORD( lParam );
			Game::Instance()->OnTouchEvent( 0, TOUCH_DOWN, xPos, yPos );			  
		break;

	case WM_LBUTTONUP:
			xPos = LOWORD( lParam );
			yPos = HIWORD( lParam );
			Game::Instance()->OnTouchEvent( 0, TOUCH_UP, xPos, yPos );			  
		break;	

	case WM_MOUSEMOVE:
		if( wParam & MK_LBUTTON )
		{
			xPos = LOWORD( lParam );
			yPos = HIWORD( lParam );
			Game::Instance()->OnTouchEvent( 0, TOUCH_MOVE, xPos, yPos );			  
		}
		break;

	case WM_KEYDOWN:
			int fwKeysDown;
			LPARAM keyDataDown;
			fwKeysDown = (int)wParam;    // virtual-key code 
			keyDataDown = lParam;          // key data 
			switch(fwKeysDown)
			{
				case VK_ESCAPE:
						PostQuitMessage(0);
					break;
				default:
					Game::Instance()->OnKeyEvent( fwKeysDown, KEY_DOWN );
					break;
			}
		break;
	case WM_KEYUP:
			int fwKeysUp;
			LPARAM keyDataUp;
			fwKeysUp = (int)wParam;    // virtual-key code 
			keyDataUp = lParam;          // key data 

			Game::Instance()->OnKeyEvent( fwKeysUp, KEY_UP );
		break;
	default: 
			lRet = DefWindowProc (hWnd, uMsg, wParam, lParam); 
		break; 
   } 

   return lRet; 
}

GLboolean WinCreate ( const char *title, float screenWidth, float screenHeight  )
{
   WNDCLASS wndclass = {0}; 
   DWORD    wStyle   = 0;
   RECT     windowRect;
   HINSTANCE hInstance = GetModuleHandle(NULL);

   wndclass.style         = CS_OWNDC;
   wndclass.lpfnWndProc   = (WNDPROC)MainWindowProc; 
   wndclass.hInstance     = hInstance; 
   wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
   wndclass.lpszClassName = "opengles2.0"; 

   if (!RegisterClass (&wndclass) ) 
      return FALSE; 

   wStyle = WS_VISIBLE | WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION;
   
   // Adjust the window rectangle so that the client area has
   // the correct number of pixels
   windowRect.left = 0;
   windowRect.top = 0;
   windowRect.right = screenWidth;
   windowRect.bottom = screenHeight;

   AdjustWindowRect ( &windowRect, wStyle, FALSE );

   gHwnd = CreateWindow(
                         "opengles2.0",
                         title,
                         wStyle,
						 GetSystemMetrics(SM_CXSCREEN) - screenWidth - 15,
						 GetSystemMetrics(SM_CYSCREEN) - screenHeight - 78,
                         windowRect.right - windowRect.left,
                         windowRect.bottom - windowRect.top,
                         NULL,
                         NULL,
                         hInstance,
                         NULL);   

   if ( gHwnd == NULL )
      return GL_FALSE;

   ShowWindow ( gHwnd, TRUE );

   return GL_TRUE;
}

EGLBoolean CreateEGLContext ( GLuint flags )
{
   EGLint numConfigs;
   EGLint majorVersion;
   EGLint minorVersion;
   EGLDisplay display;
   EGLContext context;
   EGLSurface surface;
   EGLConfig config;
   EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };   
   EGLint attribList[] =
   {
       EGL_RED_SIZE,       5,
       EGL_GREEN_SIZE,     6,
       EGL_BLUE_SIZE,      5,
       EGL_ALPHA_SIZE,     (flags & ES_WINDOW_ALPHA) ? 8 : EGL_DONT_CARE,
       EGL_DEPTH_SIZE,     (flags & ES_WINDOW_DEPTH) ? 8 : EGL_DONT_CARE,
       EGL_STENCIL_SIZE,   (flags & ES_WINDOW_STENCIL) ? 8 : EGL_DONT_CARE,
       EGL_SAMPLE_BUFFERS, (flags & ES_WINDOW_MULTISAMPLE) ? 1 : 0,
       EGL_NONE
   };

   // Get Display
   display = eglGetDisplay(GetDC(gHwnd));
   if ( display == EGL_NO_DISPLAY )
   {
      return EGL_FALSE;
   }

   // Initialize EGL
   if ( !eglInitialize(display, &majorVersion, &minorVersion) )
   {
      return EGL_FALSE;
   }

   // Get configs
   if ( !eglGetConfigs(display, NULL, 0, &numConfigs) )
   {
      return EGL_FALSE;
   }

   // Choose config
   if ( !eglChooseConfig(display, attribList, &config, 1, &numConfigs) )
   {
      return EGL_FALSE;
   }

   // Create a surface
   surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)gHwnd, NULL);
   if ( surface == EGL_NO_SURFACE )
   {
      return EGL_FALSE;
   }

   // Create a GL context
   context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs );
   if ( context == EGL_NO_CONTEXT )
   {
      return EGL_FALSE;
   }   
   
   // Make the context current
   if ( !eglMakeCurrent(display, surface, surface, context) )
   {
      return EGL_FALSE;
   }
   
   gEglDisplay = display;
   gEglSurface = surface;
   gEglContext = context;

   return EGL_TRUE;
}
