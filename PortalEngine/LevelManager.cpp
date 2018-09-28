#include "LevelManager.h"

void LevelManager::LoadTexture()
{
	cubedraw.CreateTexture();
	coindraw.CreateTexture();
	audio.LoadWAV("COIN_PICKUP", "sounds/coin_pickup.wav");
	audio.LoadWAV("FAIL", "sounds/missionfailed.wav");
	audio.AudioVolume(1, 80);
}

void LevelManager::AnimateCoin(const GLfloat timeSincePrevFrame)
{
	coindraw.AnimateCoin(timeSincePrevFrame);
}

void LevelManager::LoadLevel(const std::string levelName, const char *file) // ./levels/level.txt
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

void LevelManager::SetLevel(const std::string levelName)
{
	currentLevel = LevelStorage.find(levelName)->second;
	currentLevelName = levelName;
}

void LevelManager::DrawLevel(const Coordinates pos)
{
	int reverse = MAX_HEIGHT-1;
	std::string currentnumber;
	for (unsigned i = 0; i < MAX_HEIGHT; i++) {
		for (unsigned j = 0; j < currentLevel[reverse].length(); j++) {
			currentnumber = currentLevel[reverse].at(j);
			if (currentnumber == "1") {
				if (CheckCollision(pos, j, i)) {
					audio.PlayAudioChannel("FAIL", 1, 0);
					failed = true; 
				}
				else {
					cubedraw.Draw((float)j, (float)i, 0.0f);
				}
			}
			if (currentnumber == "2") {
				if (CheckCollision(pos, j, i)) {
					audio.PlayAudioChannel("COIN_PICKUP", 2, 0);
					currentLevel[reverse].replace(j, 1, "0"); //Remove coin from level
				}
				else {
					coindraw.DrawCoin((float)j, (float)i, 0.0f);
				}
				
			}
		}
		reverse--;
	}
}

bool LevelManager::CheckCollision(Coordinates pos, unsigned x, unsigned y) 
{
	pos.x = (GLfloat)(pos.x / 14.5)-1; //Divide by scaling factor atm is 14.5 and take 1 but not sure why
	pos.y = (GLfloat)(pos.y / 14.5);

	if ((pos.x > x - 0.5 && pos.x < x + 1.5)&& (pos.y > y - 0.5 && pos.y < y + 1.5 ) ) {  
 		return true;
	}
	return false;;
}

bool LevelManager::HasFailed() {
	return failed;
}

void LevelManager::ResetLevel() {
	SetLevel(currentLevelName);
	failed = false;
}