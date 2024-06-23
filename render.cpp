#include <vector>

#include <iostream>
#include <SDL.h>
#include "render.h"
#include "config.h"
#include "createwindow.h"
void F1_Button (SDL_Window*& window) {
	 if (is(config::MouseInside)) SDL_SetWindowGrab (window,SDL_TRUE);
            else SDL_SetWindowGrab (window,SDL_FALSE);
}

line::line() {}

line::line(SDL_Window*& win) {
renderer = SDL_CreateRenderer (win,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
   if (renderer == nullptr) {
		throw std::runtime_error("No Renderer");
    }
}
	void line::push (const SDL_Point& p) {
v.push_back (p);
	} 	
	void line::ClearV() {
		v.clear();
	}
	SDL_Renderer* line::GetRenderer () {return renderer;}
std::vector <SDL_Point>&  line::GetVector () {return v;}
