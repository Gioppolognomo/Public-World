#include <cassert>
#include <iostream>
#include "createwindow.h"
#include "config.h"
#include "audio.h"
#include "render.h"
int main([[maybe_unused]]int argc,[[maybe_unused]] char* args[]){
assert ((SCREEN_WIDTH>=160) & (SCREEN_HEIGHT>=100) && "resolution too low");
assert ((SCREEN_WIDTH>=SCREEN_HEIGHT) && "invalid ratio");
using namespace config;
setup();
	SDL_DestroyWindow(CreateWindow ("earthbig.bmp"));
	return 0;
}