#ifndef BOUNDARY_H
#define BOUNDARY_H
#include <string>
#include "render.h"
#include "flag.h"
	
extern const int MaxCoord ;
extern const double CoordToPointX ;
extern const double CoordToPointY ;
class boundary : public line {
std::string continent;
int width {};
int height {};
int CenterX {};
int CenterY {};
	public:
	boundary ();
	boundary (boundary& l) = delete;
	boundary (boundary&& l) = delete;
	int GetFromVector (const flag&& what,const flag&& XorY);
	void SetContinentalBounds (int scaling_factor);
	void SetInfo();
	void SetBounds ();
};
#endif




