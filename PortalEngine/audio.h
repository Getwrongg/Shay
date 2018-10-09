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
//Channel 2: Portal Sound
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

/**
* @class Audio
* @brief Performs audio for the project
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 27/08/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class Audio
{
public:
	Audio();
	~Audio();
	/**
	* @author
	*
	* @brief Play Audio on Selected channel
	*
	* @param const std::string Audio_Name, const int channel, const int playNum
	*
	* @return void
	*/
	void PlayAudioChannel(const std::string Audio_Name, const int channel, const int playNum); //channel = channel to play this audio on, playNum = number of times to play audio: -1=loop, 0-1=play once
	
	/**
	* @author
	*
	* @brief Play Audio on first free channel
	*
	* @param const std::string Audio_Name, const int playNum
	*
	* @return void
	*/
	void PlayAudio(const std::string Audio_Name, const int playNum); // Play audio on any free channel
	
	/**
	* @author
	*
	* @brief Play music, -1 to loop forever
	*
	* @param const std::string Music_Name, const int playNum
	*
	* @return void
	*/
	void PlayMusic(const std::string Music_Name, const int playNum); // Play music, -1 to loop forever

	/**
	* @author
	*
	* @brief 0-128 for volume level, returns current volume
	*
	* @param const int channel, const int volume
	*
	* @return int
	*/
	int AudioVolume(const int channel, const int volume); //0-128 for volume level, returns current volume

	/**
	* @author
	*
	* @brief Returns previous volume level
	*
	* @param const int volume
	*
	* @return int
	*/
	int MusicVolume(const int volume); //Returns previous volume level

	/**
	* @author
	*
	* @brief Pause all audio on inputed channel, -1 for all channels (not music)
	*
	* @param const int channel
	*
	* @return void
	*/
	void StopAudio(const int channel); //Pause all audio on inputed channel, -1 for all channels (not music)

	/**
	* @author
	*
	* @brief Stop current music
	*
	* 
	*
	* @return void
	*/
	void StopMusic(); //Stop current music

	/**
	* @author
	*
	* @brief Return channel that is playing
	*
	* @param const int channel
	*
	* @return int
	*/
	int IsPlaying(const int channel);

	/**
	* @author
	*
	* @brief loads sound effects
	*
	* @param const std::string Audio_Name, const char* audiofile
	*
	* @return const void
	*/
	const void LoadWAV(const std::string Audio_Name, const char* audiofile); //Sound Effects

	/**
	* @author
	*
	* @brief loads music
	*
	* @param const std::string Audio_Name, const char* audiofile
	*
	* @return const void
	*/
	const void LoadOGG(const std::string Audio_Name, const char* audiofile); //Music
	

private:
	std::map<std::string, Mix_Chunk*> Audio_Files; //Sound Effects
	std::vector<std::string> Audio_Names; //Used for destructor 

	std::map<std::string, Mix_Music*> Music_Files; //Music
	std::vector<std::string> Music_Names; //Used for destructor 
};

