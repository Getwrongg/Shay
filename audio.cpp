#include "audio.h"


Audio::Audio() {
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

Audio::~Audio() {
	for (int i = 0; i < Audio_Names.size(); i++) {
		Mix_FreeChunk(Audio_Files.find(Audio_Names[i])->second);
	}
	for (int i = 0; i < Music_Names.size(); i++) {
		Mix_FreeMusic(Music_Files.find(Music_Names[i])->second);
	}
	Mix_CloseAudio();
	SDL_Quit();
}

const void Audio::LoadWAV(const std::string Audio_Name, const char* audiofile) { //Sound Effects
	Audio_Files[Audio_Name] = Mix_LoadWAV(audiofile);
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Unable to Load Audio File: " << audiofile << " With Error: " << Mix_GetError() << std::endl;
		return;
	}
	Audio_Names.push_back(Audio_Name);
}

const void Audio::LoadOGG(const std::string Music_Name, const char* audiofile) { //Music
	Music_Files[Music_Name] = Mix_LoadMUS(audiofile);
	if (Music_Files[Music_Name] == NULL) {
		std::cout << "Unable to Load Music File: " << audiofile <<" With Error: "<< Mix_GetError() << std::endl;
		return;
	}
	Music_Names.push_back(Music_Name);
}

void Audio::playAudioChannel(const std::string Audio_Name, const int channel, const int playNum) {
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Audio File Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayChannel(channel, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::playAudio(const std::string Audio_Name, const int playNum) {
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Audio File Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayChannel(-1, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::playMusic(const std::string Music_Name, const int playNum) {
	if (Music_Files[Music_Name] == NULL) {
		std::cout << "Music File Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayMusic(Music_Files.find(Music_Name)->second, playNum);
}

void Audio::stopAudio(const int channel) {
	Mix_Pause(channel);
}

void Audio::stopMusic() {
	Mix_HaltMusic();
}








/*
Audio::Audio(){
	SDL_Init(SDL_INIT_AUDIO);
}

Audio::~Audio(){

	for (int i = 0; i < Audio_Names.size(); i++) {
		Audio_Files.find(Audio_Names[i]);
		SDL_CloseAudioDevice(Audio_Files.find(Audio_Names[i])->second.au_ID);
		SDL_FreeWAV(Audio_Files.find(Audio_Names[i])->second.au_buffer);
	}
	Audio_Names.clear();
}

void Audio::playAudio(const std::string Audio_Name) {
	SDL_QueueAudio(Audio_Files.find(Audio_Name)->second.au_ID, Audio_Files.find(Audio_Name)->second.au_buffer, Audio_Files.find(Audio_Name)->second.au_length);
	SDL_PauseAudioDevice(Audio_Files.find(Audio_Name)->second.au_ID, 0);
}

void Audio::stopAudio(const std::string Audio_Name) {
	SDL_CloseAudioDevice(Audio_Files.find(Audio_Name)->second.au_ID);
}

const void Audio::CreateAudio(const std::string Audio_Name, const char* audiofile) {
	Audio_Effect tempAudio;

	if (Audio_Files.find(Audio_Name)->first == Audio_Name) {
		std::cout << "AUDIO NAME \"" << Audio_Name << "\" ALREADY EXISTS, AUDIO FILE NOT LOADED" << std::endl;
	}
	else {
		bool success;
		success=SDL_LoadWAV(audiofile, &tempAudio.au_audio, &tempAudio.au_buffer, &tempAudio.au_length);
		if (success) {
			tempAudio.au_ID = SDL_OpenAudioDevice(NULL, 0, &tempAudio.au_audio, NULL, 0);
			Audio_Files[Audio_Name] = tempAudio;
			Audio_Names.push_back(Audio_Name);
		}else
		{
			std::cout << "FAIL TO LOAD "<<audiofile << std::endl;
		}
	}

}
*/