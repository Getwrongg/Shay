#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <GL/glut.h>
#pragma once

const int HEIGHT = 9; 
const int LENGTH = 17;

class LevelGen
{
public:
	LevelGen();

	std::vector<std::string> GenLevel();

private:
	std::vector<std::string> GenPartNames();
	void outputLevel(std::vector<std::string> level);

	int nameCounter = 0;
};

