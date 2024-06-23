//#define DEBUG
#define RENDER_LOADING_SCREEN   if (config::Threadone)	{SDL_RenderPresent (render);config::Threadone=false; }  
#include <cstdint>
#include <cassert>
#include <iostream>
#include <thread>
#include <functional>
#include <typeinfo>
#include <SDL.h>
#include <SDL_ttf.h>
#include "stuff.h"
#include "config.h"
#include "render.h"
#include "createwindow.h"
#include "audio.h"
#include "boundary.h"
#include "timer.h"
#include "pixel.h"
#include "pixarray.h"
#include "checksrc.h"
#include "getpixel.h"
#include "exception.h"
constexpr uint8_t WHITE = 255;
constexpr SDL_Color RED = {255,0,0,255};

void LoadingScreen ( SDL_Renderer*& render) { //std::cerr<<"done0"<<'\n'<<SDL_GetError();
Audio audio;
std::thread* LoadingScreenAudio {new std::thread ([&audio] { audio.play();	})} ;
#ifdef DEBUG
 std::cerr<<"done1"<<'\n';
 #endif
 	TTF_Font* VT323 = TTF_OpenFont("VT323.ttf", 24);
constexpr SDL_Color white {WHITE,WHITE,WHITE,WHITE};
	SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(VT323, "LOADING...",white ); 
SDL_Rect srcrect {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
	const SDL_Rect* ptrsrc {&srcrect};	
//now convert it into a texture
SDL_Texture* Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
SDL_RenderCopy(render, Message, nullptr, ptrsrc); 
 config::Threadone=true; 
reset (surfaceMessage,VT323,Message,ptrsrc); 
#ifdef DEBUG
 std::cerr<<"done2"<<'\n';
#endif
volatile bool keepRunning {true};
while (keepRunning)
if (config::Threadone) {audio.stop();keepRunning=false;}
LoadingScreenAudio->join(); delete LoadingScreenAudio;
static int c {};c++;
#ifdef DEBUG
std::cerr<<"Load_thread"<<c<<'\n';
#endif
}

void reset (SDL_Surface*& screenSurface, TTF_Font*& font,  SDL_Texture*& textureImg, const SDL_Rect*& ptrsrc ) {
 SDL_DestroyTexture(textureImg);
 SDL_FreeSurface(screenSurface);
 TTF_CloseFont(font);
 textureImg=nullptr;
 screenSurface=nullptr;
 font=nullptr;
 ptrsrc=nullptr;
}

void C_W(SDL_Window*& window) {
    window = SDL_CreateWindow(
        "World",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
}

SDL_Window* CreateWindow(std::string_view name, const int x, const int y, const int h,  const int w) {
std::shared_ptr<stuff> stuf(new stuff(name));
    SDL_Window* window {nullptr} ;
	try {
    if ((SDL_Init(SDL_INIT_VIDEO) < 0 )| (TTF_Init() < 0) |  (SDL_Init(SDL_INIT_AUDIO) < 0)) {
        InitError();
    } else {
        C_W(window);
        if (!window) {
            WindowError();
        } else { 
            // Get the SDL_Renderer from the line class
            line line(window);
            static boundary b;
            SDL_Renderer* render = line.GetRenderer();
            if (!render) throw std::runtime_error ("Renderer error");      
          	std::thread* load {new std::thread (LoadingScreen,std::ref (render))} 	;
          	#ifdef DEBUG
		  	std::cerr<<"Main_thread"<<'\n';
		  	#endif
			  SetGrid (line, linesx, linesy); 
    // Draw the lines using SDL_RenderDrawLines() 
            const std::vector<SDL_Point>& points = line.GetVector(); 
			const std::vector<SDL_Point>& boundary = b.GetVector();  
	// Convert the SDL_Surface to an SDL_Texture
			auto optiptr {optimize  (stuf,render)};
            SDL_Texture* textureImg {SDL_CreateTextureFromSurface(render,optiptr.get())	};
            if (!textureImg) throw std::runtime_error ("Texture error");
      
			RENDER_LOADING_SCREEN 
			
			b.SetInfo();
	{using namespace config;	if (did(OpenBoundaries)) {	
	if (is(continent)) { 	} b.SetBounds() ; }}
			pixarray <decltype (makepixels())> pixels{};
         	pixels.make();          
	const_cast<decltype (makepixels())&>(pixels.getpixar())[1] [2].setcolor(optiptr.get());
		 // Draw the texture on the window 
            SDL_Rect srcrect {x,y,h,w};
			const SDL_Rect* ptrsrc {&srcrect};
			#ifdef DEBUG
			std::cout<<srcrect.x<<'\n'<<srcrect.y<<'\n'<<srcrect.h<<'\n'<<srcrect.w<<'\n';
			#endif
			 checksrc ( ptrsrc,srcrect  );
			// If the pointer to this slice of the earth is missing, we suspect foul play or interdimensional snacking.
			assert (ptrsrc && "Seems like a pointer to this slice of the earth is missing (did yo mama eat it or smth idfk)");
	  load->join ();  delete load;
RENDER_LOADING_SCREEN 
	SDL_RenderCopy(render, textureImg, ptrsrc, nullptr);   
    SDL_SetRenderDrawColor(render, WHITE, WHITE, WHITE, WHITE); // Set color (white)
	if (points.data())  SDL_RenderDrawLines(render, points.data(), static_cast<int>(points.size()));
   	SDL_SetRenderDrawColor(render,RED.r,RED.g,RED.b,RED.a); 
	if (boundary.data() && did(config::OpenBoundaries))  SDL_RenderDrawLines(render, boundary.data(), static_cast<int>(boundary.size()));
    //b.ClearV(); TODO
	std::cerr<<render<<SDL_GetError();
SDL_RenderPresent(render);
	#ifdef DEBUG
	std::cerr<<"After_render"<<'\n';  
	#endif
            //clear vector
            line.ClearV();
            //Make the F1 button work, (it needs a window btw)
          	F1_Button (window);
          	
            // Wait for user input
wait(/*surfaceImg,*/render,textureImg,window,name);
    } // Clean up    
} 
} 
catch (std::exception& wtf) {
	std::cerr<<SDL_GetError()<<'\n'<< TTF_GetError()<< '\n'<<wtf.what()<<'\n';
	return nullptr;
}
return window;
}