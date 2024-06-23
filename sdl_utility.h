#ifndef SDL_UTILITY_H
#define SDL_UTILITY_H
#include <SDL.h>
inline bool operator==(SDL_Point const &a, SDL_Point const &b)
{
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(SDL_Point const &a, SDL_Point const &b)
{
    return !(a == b);
}
inline bool isEven (int i) { return (i%2)==0 ? true : false;}
 class const_bool {
 	private:
	bool Bool {};
	public:
	const_bool (bool b): Bool {b} {};
operator bool()  {return Bool;};
	 operator=(bool) & = delete;
	 operator=(bool) && = delete;
};


#endif