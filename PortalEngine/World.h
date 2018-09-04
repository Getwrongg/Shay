#pragma once

#include <GL/glut.h>
#include "JpegLoader.h"
#include "Structs.h"
#include "Cube.h"

class World
{
public:
	World();
	void CreateTextures(const std::string name, const char * filePath);
	void Ground();
	void Cubes();
	void Axis();

private:
	JpegLoader j;
	Cube cube;
	

};

