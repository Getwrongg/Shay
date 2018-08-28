#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SDL.h>


struct Audio_Effect {
	Uint32 au_length;
	Uint8 *au_buffer;
	SDL_AudioSpec au_audio;
	SDL_AudioDeviceID au_ID;
};

class Audio
{
public:
	Audio();
	~Audio();
	void playAudio(const std::string Audio_Name);
	void stopAudio(const std::string Audio_Name);

	const void CreateAudio(const std::string Audio_Name, const char* audiofile);

	

private:
	std::map< std::string, Audio_Effect> Audio_Files;
	std::vector<std::string> Audio_Names; //Only used for destructor 
};

