	#include <memory>
	#include <stdexcept>
	#include <SDL.h>
	#include "stuff.h"
	std::unique_ptr <SDL_Surface> optimize (std::shared_ptr <stuff> stuf, SDL_Renderer*& render) {			
	//TODO: fix =
	auto optimg { std::move(stuf->img)};//stuf->img
   SDL_RendererInfo rendererInfo;
    if (SDL_GetRendererInfo(render, &rendererInfo) != 0) throw std::runtime_error ("no renderinfo");
    // The pixel format of the renderer is in rendererInfo.texture_formats[0]
    Uint32 pixelFormat { rendererInfo.texture_formats[0]};
		auto temp {SDL_ConvertSurfaceFormat ( optimg.get(), pixelFormat,0 )};
	optimg = std::make_unique <SDL_Surface> (*temp);
	return optimg;
	}