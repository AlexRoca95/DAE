#ifndef PCH_H
#define PCH_H


#define g_Scale 2.7f				// Scale of the Game
#define g_Gravity -981.f			// Value of the gravity

// Game Stage positions
#define g_Stage2Pos 1700.f
#define g_Stage3Pos 3050.f
#define g_Stage4Pos 3950.f


//ML Detection Extension
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

// SDL libs
#pragma comment(lib, "sdl2.lib")
#pragma comment(lib, "SDL2main.lib")

// OpenGL libs
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"Glu32.lib")

// SDL extension libs 
#pragma comment(lib, "SDL2_image.lib")  
#pragma comment(lib, "SDL2_ttf.lib") 
#pragma comment(lib, "SDL2_mixer.lib")  


// SDL and OpenGL Includes
#pragma warning(disable : 26812)
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_mixer.h> 

#pragma warning(default : 26812)
#include "structs.h"
#endif //PCH_H
