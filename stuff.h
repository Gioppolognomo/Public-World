#ifndef STUFF_H
#define STUFF_H
#include <iostream>
#include <memory>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_utility.h"
class stuff { private:
	static bool success ;
	const std::string name_m ;
	 public:
	 	 const_bool getsuccess () const { const_bool test (success); return test;}
	 std::unique_ptr <SDL_Surface> img ; //new imgptr
	 stuff (const std::string_view name);
	 stuff (stuff& s) = delete;
	  stuff (stuff&& s) = delete;
};
//yo mama so slow we had to code a whole ass function just to wait for her input
void wait (/*SDL_Surface*& screenSurface, */SDL_Renderer*& render,  SDL_Texture*& textureImg, SDL_Window*& window, const std::string_view name );
//kills the render,the texture, the window, the pointer to them and your social life
void reset (/*SDL_Surface*& screenSurface, */SDL_Renderer*& render,  SDL_Texture*& textureImg, SDL_Window*& window );
void reset (SDL_Surface*& screenSurface, TTF_Font*& font,  SDL_Texture*& textureImg, const SDL_Rect*& ptrsrc);
#endif