#ifndef PIXARRAY_H
#define PIXARRAY_H
#include <SDL.h>
#include <array>
constexpr int width {950};
std::vector <std::array<pixel, width>>  makepixels ();

template <typename T>
class pixarray {
T pixar  {};
	public:
const T& getpixar () const {return pixar;}
	pixarray  () {};
	pixarray& make () {
	pixar = makepixels ();
        SDL_Point esempio {};
         for (auto z {static_cast <int> (pixar.size())-1};z>=0;z--)  {
		 for ( auto z2 {static_cast <int> (pixar.at(z).size())-1};z2>=0;z2--)
		 {	esempio.x = z;
			esempio.y = z2;
			pixar [z] [z2] = esempio;
		 } } 
return *this;	}

};

#endif