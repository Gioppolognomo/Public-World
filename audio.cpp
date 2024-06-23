#define DEBUG

#include <stdexcept>
#include <iostream>
#include <thread>
#include <SDL.h>
#include "audio.h"
Audio::Audio() {
didStop.store(false);}
void Audio::error() {
    std::cerr<<"SDL audio error:"<<SDL_GetError()<<'\n';
    throw std::runtime_error ("Audio error");
}
void Audio::stop () {
	didStop.store(true);
}
bool Audio::a (){return didStop; }
void Audio::play (){
if (!SDL_LoadWAV("sound.wav", &wavSpec, &wavBuffer, &wavLength)) error ();
SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(nullptr, 0, &wavSpec, nullptr, 0);
int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
if (success!=0) error ();
SDL_PauseAudioDevice(deviceId, 0);
while (!didStop.load()) {
            // Waiting for condition to be met
            //Relinquish control of this thread sending it to the end of the running queue
            std::this_thread::yield();
        }

SDL_CloseAudioDevice(deviceId);
#ifdef DEBUG
std::cerr<<'j'<<'\n';
#endif
SDL_FreeWAV(wavBuffer);}

