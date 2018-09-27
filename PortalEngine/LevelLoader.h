#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "Cube.h"
#include "Coin.h"

const int MAX_HEIGHT = 9;

class LevelLoader{
public:
	void LoadTexture();
	void AnimateCoin();
	void LoadLevel(const std::string levelName, const char *file);
	void DrawLevel(const std::string levelName);

private:
	std::map<std::string, std::vector<std::string> > LevelStorage;

	Cube cubedraw;
	Coin coindraw;
};

