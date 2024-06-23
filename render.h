#ifndef RENDER_H
#define RENDER_H
#include <vector>
#include <array>
#include <SDL.h>
#include "pixel.h"
class line {
	protected:
	std::vector <SDL_Point> v;
	SDL_Renderer* renderer;
	public:
	line () ; 
	line (SDL_Window*& win);
	line (line& l) = delete;
	line (line&& l) = delete;
std::vector <SDL_Point>&  GetVector ();
void push (const SDL_Point& p);
void ClearV (); //clears the vector of points, idk if it's necessary but still...
SDL_Renderer* GetRenderer () ; 


	
};
void F1_Button (SDL_Window*& window);
//using std::array;

//std::vector <array<pixel, width>>  makepixels ();
#endif