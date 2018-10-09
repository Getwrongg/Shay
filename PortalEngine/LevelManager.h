#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "Cube.h"
#include "Coin.h"
#include "audio.h"

const int MAX_HEIGHT = 9;

class LevelManager{
public:
	void LoadTexture();
	void AnimateCoin(const GLfloat timeSincePrevFrame);

	void LoadLevel(const std::string levelName, const char *file);
	void LoadLevelIndex(const char *file);// ./levels/level_index.txt

	void SetLevel(const std::string levelName);
	void DrawLevel(const Coordinates pos);

	void SetNextLevel();

	int GetCoinsCollected();

	bool HasEndedRound();
	bool HasFailed();
	void ResetLevel();
	std::string getLevelName();

private:
	
	bool CheckCollision(Coordinates pos, unsigned x, unsigned y);

	std::map<std::string, std::vector<std::string> > LevelStorage; //Stores all the levels
	std::vector<std::string> Level_Index; //Stores all loaded level names for easy access
	std::vector<std::string> currentLevel; //used to create a copy of the level in storage
	std::string currentLevelName; // Used to reset current level

	bool failed = false; //if player fails level
	bool endRound = false; //if player completes level
	int coinscollected=0;
	int currentlevelNumber = 0;

	Audio audio;
	Cube cubedraw;
	Coin coindraw;
};

