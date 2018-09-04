#pragma once
#include "Structs.h"
class Cube
{
public:
	Cube();
	Cube(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	~Cube();
	void Draw(const GLdouble x1, const GLdouble y1, const GLdouble z1);
private:
	Coordinates pos;
};

