#include "LevelLoader.h"

void LevelLoader::LoadTexture()
{
	cubedraw.CreateTexture();
	coindraw.CreateTexture();
}

void LevelLoader::AnimateCoin() 
{
	coindraw.AnimateCoin();
}

void LevelLoader::LoadLevel(const std::string levelName, const char *file) // ./levels/level.txt
{ 

	std::ifstream levelfile(file);
	if (!levelfile) {
		std::cout << "Unable to Load Level" << std::endl;
		return;
	}

	std::string line[MAX_HEIGHT];
	std::vector<std::string> levelVec;
	for (int i = 0; i < MAX_HEIGHT; i++) {
		std::getline(levelfile, line[i]);
		levelVec.push_back(line[i]);
	}
	LevelStorage[levelName] = levelVec;

	levelfile.close();
}

void LevelLoader::DrawLevel(const std::string levelName) 
{
	int reverse = MAX_HEIGHT-1;
	std::string currentnumber;
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (unsigned j = 0; j < LevelStorage.find(levelName)->second[reverse].length(); j++) {
			currentnumber = LevelStorage.find(levelName)->second[reverse].at(j);
			if (currentnumber == "1") {
				cubedraw.Draw((float)j, (float)i, 0.0f);
			}
			if (currentnumber == "2") {
				coindraw.DrawCoin((float)j, (float)i, 0.0f);
			}
		}
		reverse--;
	}
}