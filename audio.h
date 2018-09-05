#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>

//http://lazyfoo.net/SDL_tutorials/lesson11/index.php

//Channel Usage:
//Channel 1: Walking steps
//Channel 2: Free
//Channel 3: Free
//Channel 4: Free
//Channel 5: Free
//Channel 6: Free
//Channel 7: Free
//Channel 8: Free
//Channel 9: Free
//Channel 10: Free
//Channel 11: Free
//Channel 12: Free
//Channel 13: Free
//Channel 14: Free
//Channel 15: Free
//Channel 16: Free

class Audio
{
public:
	Audio();
	~Audio();

	void PlayAudioChannel(const std::string Audio_Name, const int channel, const int playNum); //channel = channel to play this audio on, playNum = number of times to play audio: -1=loop, 0-1=play once
	void PlayAudio(const std::string Audio_Name, const int playNum); // Play audio on any free channel
	void PlayMusic(const std::string Music_Name, const int playNum); // Play music, -1 to loop forever

	void StopAudio(const int channel); //Pause all audio on inputed channel, -1 for all channels (not music)
	void StopMusic(); //Stop current music

	const void LoadWAV(const std::string Audio_Name, const char* audiofile); //Sound Effects
	const void LoadOGG(const std::string Audio_Name, const char* audiofile); //Music
	

private:
	std::map<std::string, Mix_Chunk*> Audio_Files; //Sound Effects
	std::vector<std::string> Audio_Names; //Used for destructor 

	std::map<std::string, Mix_Music*> Music_Files; //Music
	std::vector<std::string> Music_Names; //Used for destructor 
};

