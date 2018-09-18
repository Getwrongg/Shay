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

const void Audio::LoadWAV(const std::string Audio_Name, const char* audiofile) { //Load WAV Sound Effects
	Audio_Files[Audio_Name] = Mix_LoadWAV(audiofile);
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Unable to Load Audio File: " << audiofile << " With Error: " << Mix_GetError() << std::endl;
		return;
	}
	Audio_Names.push_back(Audio_Name);
}

const void Audio::LoadOGG(const std::string Music_Name, const char* audiofile) { //Load OGG Music
	Music_Files[Music_Name] = Mix_LoadMUS(audiofile);
	if (Music_Files[Music_Name] == NULL) {
		std::cout << "Unable to Load Music File: " << audiofile <<" With Error: "<< Mix_GetError() << std::endl;
		return;
	}
	Music_Names.push_back(Music_Name);
}

void Audio::PlayAudioChannel(const std::string Audio_Name, const int channel, const int playNum) { // Play Audio on Selected channel
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Audio File Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayChannel(channel, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::PlayAudio(const std::string Audio_Name, const int playNum) { // Play Audio on first free channel
	if (Audio_Files[Audio_Name] == NULL) {
		std::cout << "Sound Name " << Audio_Name << " Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayChannel(-1, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::PlayMusic(const std::string Music_Name, const int playNum) {
	if (Music_Files[Music_Name] == NULL) {
		std::cout << "Music Name "<<Music_Name<< " Does Not Exist" << std::endl;
		return;
	}
	Mix_PlayMusic(Music_Files.find(Music_Name)->second, playNum);
}

int Audio::AudioVolume(const int channel, const int volume) {
	return Mix_Volume(channel, volume);
}

int Audio::MusicVolume(const int volume) {
	return Mix_VolumeMusic(volume);
}

void Audio::StopAudio(const int channel) {
	Mix_Pause(channel);
}

void Audio::StopMusic() {
	Mix_HaltMusic();
}

int Audio::IsPlaying(const int channel) {
	return Mix_Playing(channel);
}