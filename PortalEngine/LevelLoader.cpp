#include "LevelLoader.h"

void LevelLoader::LoadTexture() {
	leveldraw.CreateTexture();
}

void LevelLoader::LoadLevel(const std::string levelName, const char *file) { // ./levels/level.txt

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

void LevelLoader::DrawLevel(const std::string levelName) {
	int reverse = MAX_HEIGHT-1;

	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < LevelStorage.find(levelName)->second[reverse].length(); j++) {
			if (LevelStorage.find(levelName)->second[reverse].at(j) == '1') {
				leveldraw.Draw(j, i, 0);
			}
		}
		reverse--;
	}
}