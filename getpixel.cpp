#include <SDL.h>
#include "pixel.h"
Uint32 getpixel(const SDL_Surface * surface, int x, int y) 
{ if (x >= 0 && y >= 0 && x < surface->w && y < surface->h)
	{
		
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    //pitch is the length of a row of pixels in bytes 
    //consider that uint8 is a byte
    //p = pixels + y rows (get pixel from that row) + x spaces in that row 
	//(since we're dealing with bytes, spaces must be multiplied to walk bpp bytes to the nearest pixel)
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp) //how deep in bytes the image is
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN) //if PowerPC
            return p[0] << 16 | p[1] << 8 | p[2];
        else //if x64 x86
        { return p[0] | p[1] << 8 | p[2] << 16;
            break;
		}
           

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
	  } return 0; 
}

pixel& 	pixel::setcolor (const SDL_Surface * surface){
	SDL_GetRGBA(getpixel(surface,location.x,location.y), surface->format, &rgb.r, &rgb.g, &rgb.b, &rgb.a);
	return *this;
	}

//SDL_Color rgb;
//Uint32 data = getpixel(gSurface, 200, 200);
