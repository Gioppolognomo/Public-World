#include <array>
#include <cstdint>
#include <utility> // for std::move
#include "config.h"
constexpr int SCREEN_WIDTH = 950;
constexpr int SCREEN_HEIGHT = 500;
constexpr int SCREEN_CENTER_W = SCREEN_WIDTH/2;
constexpr int SCREEN_CENTER_H = SCREEN_HEIGHT/2;
constexpr int CONTINENT_WIDTH = 14400;
constexpr int CONTINENT_HEIGHT = 10800;

constexpr int linesx = 9; //number of orizontal lines in the grid
constexpr int linesy = 18; //number of vertical lines in the grid

namespace config {	
constexpr int NumberOfOptions {8};
[[maybe_unused]] 	std::uint8_t conf = 0; //This is your whole configuration (yes,really)
[[maybe_unused]] 	std::array <std::uint8_t, 8> mask = {}; //These are meant to be used to check if an option is true and shouldn't be touched at all 
void setup () {
for (int i {}; i<NumberOfOptions;++i) { //allocate a 1 for every option shifted by i spaces
		mask [i] = static_cast <std::uint8_t> (1 << i);
			}
	} 	
void enlarge () {
conf |=	mask [zoom]; }
	void reduce (){
conf ^=	mask [zoom]; }
void ToggleMouse () {
conf ^=	mask [MouseInside]; }	
void exit () {
conf |=	mask [quit]; 
} 
void OpenGrid (){
	conf ^=	mask [GridOpen]; }
void OpenContinent (){
	conf |=	mask [continent]; }	
void CloseContinent (){
	conf ^=	mask [continent]; }
void ToggleBoundaries ()
		{conf ^=	mask [OpenBoundaries];}
	
		
	//Did and is are the same thing because the pc talks in unga bunga (sorry chatgpt)
	const_bool is ( options&& option)  {
	return (conf & mask [option]);
	}
	const_bool did ( options&& option)  {
	return	is  (std::move (option));
			} 
				const_bool is (  options& option)  {
	return	is  (std::move (option));
			}
			 	const_bool did (  options& option) {
	return	is  (std::move (option));
			} 
			
}