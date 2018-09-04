#pragma once
#include "Structs.h"
#include "JpegLoader.h"
class Cube
{
public:
	Cube();
	Cube(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	~Cube();
	void Draw(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	void DrawBush(const GLdouble x1, const GLdouble y1, const GLdouble z1);
private:
	JpegLoader j;
	Coordinates pos;
};

