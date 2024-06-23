#include <SDL.h>
	void checksrc ([[maybe_unused]]	const SDL_Rect* ptrsrc,SDL_Rect& srcrect  ){
		if (srcrect.x<0) srcrect.x=0;
			if (srcrect.y<0 ) srcrect.y=0;
			if ((srcrect.h<1) | (srcrect.w<1))ptrsrc=nullptr;
				
		}