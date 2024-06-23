#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <memory>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_utility.h"
class pixel { private:
 bool success {false};
//	const std::string kind ;
	SDL_Point location;
	SDL_Color rgb;
	 public:
	const_bool getsuccess () const { const_bool test (success); return test;}
	SDL_Point getlocation () const { return location;}
	pixel& setcolor (const SDL_Surface * surface);
	 pixel ();
	 // pixel (pixel&& s) ;
	  pixel& operator= (const pixel&) {
	  	return *this;
	  }
	  pixel& operator= (SDL_Point& point) {
	  	location.x = point.x;
	  	location.y = point.y;
	  	return *this;
	  }
	 pixel (pixel& s) = delete;
	 pixel (pixel&& s) = delete;
};
#endif