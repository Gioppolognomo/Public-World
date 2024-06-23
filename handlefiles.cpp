#include <fstream>
#include <string>
#include <string_view>
#include "handlefiles.h"
std::string_view ReadCoords (std::ifstream& coords){
	  //Thanks to Jerry Coffin for this short method of file reading
  coords.seekg(0,std::ios::end); //Goto end of file
  std::size_t size = coords.tellg(); 	//Tell number of char at the end of file (size of file)
static	std::string lin (size, ' '); //instatiate string as big as size
 	 coords.seekg(0); //Goto beginning of file ==========================================||
  coords.read(&lin[0],size); //Read from beginning of file and write at beginning of lin <U
	return lin;
}