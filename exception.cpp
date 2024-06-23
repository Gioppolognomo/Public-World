#include <stdexcept>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "exception.h"

void InitError() {
    std::cerr<<"SDL initialize error:"<<SDL_GetError()<<" . "<< TTF_GetError();
    throw std::runtime_error ("Initialize error");
}
void WindowError() {
    std::cerr<<"Window could not be created: " << SDL_GetError()<< '\n';
    throw std::runtime_error ("Window error");
}