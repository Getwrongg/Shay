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
	void Update();
	Coordinates & GetPosition();
	void SetPosition(const GLdouble x, const GLdouble y, const GLdouble z);

private:
	Coordinates pos;
	GLfloat size;
	GLint slices, stacks;
	GLUquadricObj *sphere;

	// jpegloader object for textures
	JpegLoader pj;

	GLdouble gravity;

};

