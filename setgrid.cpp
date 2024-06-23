#include "createwindow.h"
#include "config.h"
#include "render.h"
#include "sdl_utility.h"
using namespace config;
void SetGrid (line& line,const int linesx,const int linesy) {
	if (is(GridOpen) ) {
		//if there are no lines, get outta here
		if ((linesx<=0) | (linesy<=0)) return; 
		// create points
		//make orizontal lines
		for (int i {1}; i<=linesx; i++) {  
				SDL_Point y {0,i*(SCREEN_HEIGHT/linesx) };
				SDL_Point x {SCREEN_WIDTH,i*(SCREEN_HEIGHT/linesx) 	};
		// every even time, push x,y
		if(isEven(i))	{line.push(x);	line.push(y);}
		// every odd time, push y,x (kinda odd but works)
		 else {	line.push(y);line.push(x);
			}} 
			//z is to avoid ugly not straight lines (no offence, LGBTQ+ lines, we still support you)
			SDL_Point z {SCREEN_WIDTH,0};
			line.push(z);
			//kind of the same as above
			//make vertical lines
			for (int i {1}; i<=linesy; i++) {  
				SDL_Point y {i*(SCREEN_WIDTH/linesy),0 };
				SDL_Point x {i*(SCREEN_WIDTH/linesy),SCREEN_HEIGHT};
			if(isEven(i))	{
			line.push(x);	line.push(y);
			} 
			else {
				line.push(y);line.push(x);
			}
			} 	
			}
}