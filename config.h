#ifndef CONFIG_H
#define CONFIG_H
#include <array>
#include <cstdint>
#include <atomic>
#include "sdl_utility.h"
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_CENTER_W;
extern const int SCREEN_CENTER_H;
extern const int CONTINENT_WIDTH;
extern const int CONTINENT_HEIGHT;

extern const int CONTINENT_WIDTH;
extern const int CONTINENT_HEIGHT;
extern const int linesx; //number of orizontal lines in the grid
extern const int linesy; //number of vertical lines in the grid


//all the configuration related stuff
 namespace config {
	enum options {
	quit,
	GridOpen,
	MouseInside,
	zoom,
	continent,
	OpenBoundaries
	}; 
	
//This is your whole configuration (yes,really)
[[maybe_unused]] 	extern std::uint8_t conf ;
//These are meant to be used to check if an option is true and shouldn't be touched at all 				
[[maybe_unused]]   extern std::array <std::uint8_t, 8> mask; 

	    void setup ();   //allocate every option 
		void exit (); 	//tell the pc that maybe it's time to refresh the page
		void enlarge ();
		void reduce ();
		void ToggleMouse (); //Traps the mouse in the window (I swear, it's not animal cruelty...)
		void OpenGrid (); //Opens the grid (duh!)
		void OpenContinent ();
		void CloseContinent ();
		void ToggleBoundaries ();
		//Did and is are the same thing because the pc talks in unga bunga (sorry chatgpt)
		const_bool is (  options& option)  ; 
		const_bool did (  options& option)  ; 
		const_bool is (  options&& option)  ;                          
		const_bool did (  options&& option)  ;   
		static std::atomic<bool> Threadone(false);  	}

#endif