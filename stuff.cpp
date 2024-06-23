#include <string_view>
#include <SDL.h>
#include "stuff.h"

stuff::stuff (const std::string_view name) : name_m {name} 
{
	 		try { 
	 		//load bmp, if not existent throw exception
			 if (!SDL_LoadBMP ( name_m.data () )) throw std::runtime_error ("No name");
			 img = std::make_unique <SDL_Surface> (
			 *SDL_LoadBMP ( name_m.data() ));
			 }
			 catch ( const std::exception& wtf) {
			 std::cerr<<"Failed to load " << name<< '\n'; 
			 success=false;} //"The error handling in stuff::stuff constructor seems inconsistent, setting success to false only for one specific exception." -Chatgpt
		
		 }
		 bool stuff::success = true;
