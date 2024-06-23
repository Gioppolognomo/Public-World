#include <vector>
#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include "boundary.h"
#include "render.h"
#include "config.h"
#include "flag.h"
constexpr int MaxCoord {180};
const double CoordToPointX {static_cast <double> (MaxCoord)/SCREEN_WIDTH};
const double CoordToPointY {static_cast <double> (MaxCoord)/SCREEN_HEIGHT};
class boundary; 
boundary::boundary () : line {}// TODO :: Fix namespaces
{}

 void boundary::SetInfo () {
width   = v.empty () ? 0 : GetFromVector (flag::MAX,flag::X) - GetFromVector (flag::MIN,flag::X);
height = v.empty () ? 0 : GetFromVector (flag::MAX,flag::Y) - GetFromVector (flag::MIN,flag::Y);
CenterX = v.empty () ? 0 : GetFromVector (flag::MIN,flag::X) + width / 2;
CenterY = v.empty () ? 0 : GetFromVector (flag::MIN,flag::Y) + height / 2;
std::cout<<'\n'<<v.empty()<<"<-"<<CenterY<<'\n';
 }

void boundary::SetContinentalBounds (int scaling_factor) {

	auto coeff {scaling_factor * std::max(height,width)	};
	
	for (auto& coord : v) {

	}
	}
	

int boundary::GetFromVector ( const flag&& what, const flag&& XorY) {
 	auto& v {GetVector()};
 	if (v.empty()) throw std::runtime_error ("Empty B Vector");
	switch (what){
		case flag::MAX:
if (XorY==flag::X) 
{return (*std::max_element(v.begin(),v.end(),[](const SDL_Point& a, const SDL_Point& b){return a.x < b.x;})).x;}
else if (XorY==flag::Y) 
{return (*std::max_element(v.begin(),v.end(),[](const SDL_Point& a, const SDL_Point& b){return a.x < b.x;})).y;}
	else {throw std::invalid_argument("invalid flag");}
		break;
	case	flag::MIN:
			if (XorY==flag::X) 
{return (*std::min_element(v.begin(),v.end(),[](const SDL_Point& a, const SDL_Point& b){return a.x > b.x;})).x;}
else if (XorY==flag::Y) 
{return (*std::min_element(v.begin(),v.end(),[](const SDL_Point& a, const SDL_Point& b){return a.x > b.x;})).y;}
	else {throw std::invalid_argument("invalid flag");}
	break;
	default:	
	return -1; //this should never happen
	break;}
}