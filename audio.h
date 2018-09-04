#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>

//http://lazyfoo.net/SDL_tutorials/lesson11/index.php

//Channel Usage:
//Channel 1: Ambience/Game Music
//Channel 2: Walking steps

class Audio
{
public:
	Audio();
	~Audio();

	void playAudioChannel(const std::string Audio_Name, const int channel, const int playNum); //channel = channel to play this audio on, playNum = number of times to play audio: -1=loop, 0-1=play once
	void playAudio(const std::string Audio_Name, const int playNum); // Play audio on any free channel

	void pauseAudio(const int channel); //Pause all audio on inputed channel, -1 for all channels
	const void LoadWAV(const std::string Audio_Name, const char* audiofile);
	

private:
	std::map<std::string, Mix_Chunk*> Audio_Files;
	std::vector<std::string> Audio_Names; //Only used for destructor 
};

