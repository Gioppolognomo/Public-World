//#define DEBUG
#include <iostream>
#include <utility> // for std::move
#include <unordered_map>
#include <string>
#include <string_view>
#include <SDL.h>
#include <functional>
#include "config.h"
#include "createwindow.h"
#include "timer.h"

static constexpr SDL_Point res {475,250};
const static int q {SCREEN_WIDTH/res.x}; //do magick
constexpr double ContinentXRatio {7.03125};
constexpr double ContinentYRatio {10.546875};
static constexpr SDL_Point ContinentRes {static_cast <int> (res.x*ContinentXRatio),static_cast <int> (res.x*ContinentYRatio)};
void reset (/*SDL_Surface*& screenSurface,*/ SDL_Renderer*& render,  SDL_Texture*& textureImg, SDL_Window*& window ) {
	SDL_RenderClear(render);
	    SDL_DestroyTexture(textureImg);
         SDL_DestroyRenderer(render);
         render=nullptr;
		//	screenSurface = nullptr;
			SDL_DestroyWindow(window);
}

const std::unordered_map<int, std::string_view> keyToFile  {
    {SDLK_1, "North_America.bmp"},
    {SDLK_2, "Eurasia.bmp"},
    {SDLK_3, "East_Asia.bmp"},
    {SDLK_4, "South_America.bmp"},
    {SDLK_5, "Africa.bmp"},
    // old code {SDLK_6, "South_East.bmp"},  {SDLK_7, "West_Antartica.bmp"},  {SDLK_8, "Central_Antartica.bmp"},{SDLK_9, "East_Antartica.bmp"},
    {SDLK_0, "earthbig.bmp"}
};


void wait (/*SDL_Surface*& screenSurface,*/ SDL_Renderer*& render,  SDL_Texture*& textureImg, SDL_Window*& window, const std::string_view name ){
	using namespace config;
  while( !did (quit))          
{  SDL_Event e;
	 static Timer input {};
	std::function didNotSpam {[] () {return input.elapsed()>WaitingTime; }};
	std::function Ignore {[] ([[maybe_unused]] char letter) {	input.reset();
	#ifdef DEBUG
std::cerr<<letter;
	#endif
	}};
// Wait indefinitely for the next available event
                SDL_PollEvent(&e);
                switch (e.type) {
				case SDL_QUIT :  exit ();  break;
				case SDL_KEYDOWN :
			
				if (didNotSpam ()) {	input.reset();
				reset(render,textureImg,window)	;
					if (e.key.keysym.sym==SDLK_g) {
					OpenGrid ();
				is(continent) ? CreateWindow (name,0,0,CONTINENT_HEIGHT,CONTINENT_WIDTH) :	CreateWindow (name);}
						else {
						if (e.key.keysym.sym==SDLK_F1)
					ToggleMouse();
						auto key {e.key.keysym.sym};
						std::string_view namefile = keyToFile.at(key);
						if (namefile.empty()) {
							CloseContinent ();
							CreateWindow (name);
						} 
						else if (namefile=="earthbig.bmp") {
							CloseContinent ();
							CreateWindow (namefile);	}
						else {OpenContinent();
						CreateWindow (namefile,0,0,CONTINENT_HEIGHT,CONTINENT_WIDTH);}
					}	} else {
		Ignore ('e');	
			}

			break;
		
				case SDL_MOUSEBUTTONDOWN :	
				if (didNotSpam () & (name != "earthbig.bmp")) {
			
				if (e.button.button == SDL_BUTTON_LEFT)
				reset(render,textureImg,window)	;
				input.reset();
				if (!did(zoom)) {enlarge();
					 CreateWindow (
					name,
				is(continent)?	e.button.x*q *ContinentXRatio -(ContinentRes.x/2)	: e.button.x*q-(res.x/2)	,
				is(continent)?	e.button.y*q *ContinentYRatio -(ContinentRes.y/2)	: e.button.y*q-(res.y/2)	,
				is(continent)? ContinentRes.x : res.x,
				is(continent)? ContinentRes.x : res.y
					);
				} else {
					reduce ();
					CreateWindow (name,0,0,CONTINENT_HEIGHT,CONTINENT_WIDTH);
					
				} 
		
				} else {
		Ignore ('m');
		
			}
			 break;
			 	case SDL_MOUSEWHEEL:
			 		if (didNotSpam ()) {reset(render,textureImg,window)	;	
				input.reset();
					ToggleBoundaries ();			
is(continent) ? CreateWindow (name,0,0,CONTINENT_HEIGHT,CONTINENT_WIDTH) :	CreateWindow (name);}else {
		Ignore ('w');
		} 
					break;
;				 
       }
}}