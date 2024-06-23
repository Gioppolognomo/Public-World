#ifndef AUDIO_H
#define AUDIO_H
#include <atomic>

class Audio{
SDL_AudioSpec wavSpec; //Audio
Uint32 wavLength; //audio length
Uint8 *wavBuffer;
std::atomic <bool> didStop ; 
public:
Audio ();
void play ();
void error() ;
void stop();
bool a ();
};

#endif
