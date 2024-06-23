//#define DEBUG
#include <cctype>//?
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <cmath>
#include <functional>
#include <sstream>//
#include <SDL.h>
#include <regex>
#include "createwindow.h"
#include "config.h"
#include "boundary.h"
#include "handlefiles.h"
using namespace config;
void boundary::SetBounds () {
std::ifstream Ru ("Ru.txt");
  if (Ru.is_open())
    { SDL_Point p {0,0};
	std::string_view lin {ReadCoords(Ru)};
  const static	std::regex token {"[^\\D](-(?=\\d|\\.\\d))?(\\d+)?(\\.)?\\d+[^\"]", std::regex::optimize}; //I regret this choice (it basically takes a valid double)
	  auto i {std::regex_iterator <std::string_view::const_iterator> (lin.begin(),lin.end(),token)};
	  auto ended {std::regex_iterator<std::string_view::const_iterator>()};
	  i++;i++;i++;i++; //fuck it, good enough. Skips Shapeid and first useless coordinate
  for (;i!=ended;i++) {
  const std::match_results<std::string_view::const_iterator> match {*i};
	const auto DoubleLinVal {std::stod(match.str())};
     if (p.y>0.0) {
p.x = std::round((DoubleLinVal+180)/360*SCREEN_WIDTH)/**/;} else 	 p.y= (std::round(DoubleLinVal*-1+90)/180*SCREEN_HEIGHT) /**/;	 
	 if ((p.x>0.0) & (p.y> 0.0) ) {
	 	std::function isVectorEmpty {[this]() {return GetVector().empty();}};
		std::function temp2 {[this,&p]() {return GetVector().back()!=p;}};
	 	bool x {isVectorEmpty ()};
		 if ( x )  {push(p); } 
		else {
		bool z {temp2 ()};
		if (z) {push(p);} 
		else {
			#ifdef DEBUG
		std::cout.precision(6);
		std::cout<<static_cast <double> (p.x)/SCREEN_WIDTH*180-90 <<' '<<static_cast <double> (p.y)/SCREEN_HEIGHT*360-180<<'\n';
			#endif
		}
		};
	 	p.x = 0.0;
	 	p.y = 0.0;
	} } 
    Ru.close();
  }
  else std::cout << "Unable to open file"; 
		//if there are no lines, get outta here
		if (GetVector().begin() == GetVector().end()) return; 		
}
//void boundary::SetContinentalBounds () {}