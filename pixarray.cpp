	#include <array>
#include <vector>
	#include <memory>
	#include <SDL.h>
	#include <iostream>
	#include "pixel.h"
	#include "pixarray.h"
	#include "createwindow.h"
	pixel::pixel(){success=true;}
	using std::array;
	constexpr int height {500};
	std::vector <array<pixel, width>>  makepixels (){
	 std::vector <array<pixel,width>>  pix (height);
	if (pix [1] [1].getsuccess())	{
	std::cerr<<"good";} else std::cerr<<"bad";

	 return pix;
	} 