#include <GL/glut.h>

#pragma once
class Cam
{
public:
	Cam();
	void MoveLeftRight(const GLdouble amount);
	void MoveForwardBack(const GLdouble amount);
	void CallGluLookat();
	
private:
	

	GLdouble view[9];
};
