#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H
#include <cstdint>
#include <string_view>
#include <SDL.h>
#include <memory>
#include "render.h"
#include "stuff.h"
extern const uint8_t WHITE;
extern const SDL_Color RED;
void LoadingScreen (SDL_Renderer*& render);
void LoadingScreenAudio ();
void C_W (SDL_Window*& window); //creates the actual window
SDL_Window* CreateWindow (std::string_view name, const int x=0, const int y=0, const int w=2048,  const int h=1024);
void SetGrid (line& line,const int linesx, const int linesy);
std::unique_ptr <SDL_Surface>  optimize (std::shared_ptr <stuff> stuf, SDL_Renderer*& render);
#endif
