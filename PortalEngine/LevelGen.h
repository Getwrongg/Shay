#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <GL/glut.h>
#pragma once

const int MAX = 9;

class LevelGen
{
public:

	LevelGen();
	std::vector<std::string> GenLevel();

private:

	void GenPartNames();
	std::vector<std::string> partNames;
	std::vector<std::string> currentLevel;

};

