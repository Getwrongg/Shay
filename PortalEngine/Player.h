#include <GL/glut.h>

#include "Structs.h"
#include "JpegLoader.h"

#pragma once

class Player
{
public:
	Player();
	void DrawPlayer();
	void LoadTexture(const std::string name, const char * filePath);

private:
	Coordinates pos;
	GLfloat size;
	GLint slices, stacks;
	GLUquadricObj *sphere;
	JpegLoader pj;

};

