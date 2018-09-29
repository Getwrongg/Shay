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
	void SetLevel(const std::string levelName);
	void DrawLevel(const Coordinates pos);

	int GetCoinsCollected();

	bool HasFailed();
	void ResetLevel();

private:
	
	bool CheckCollision(Coordinates pos, unsigned x, unsigned y);

	std::map<std::string, std::vector<std::string> > LevelStorage;
	std::vector<std::string> currentLevel; //used to create a copy of the level in storage
	std::string currentLevelName; // Used to reset current level

	bool failed=false;
	int coinscollected=0;

	Audio audio;
	Cube cubedraw;
	Coin coindraw;
};

