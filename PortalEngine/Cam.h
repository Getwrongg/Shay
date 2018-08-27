#include <GL/glut.h>

#pragma once

class Cam
{
public:
	Cam();
	void DirectionLeftRight(const GLdouble dir);
	void DirectionForwardBack(const GLdouble dir);
	void MoveLeftRight();
	void MoveForwardBack();

	void UpdateCamera();

	void SetMoveSpeed(const GLdouble speed);
	void SetPosition(const GLdouble pos[9]);

	GLdouble & GetPosition();
	
private:
	
	GLdouble view[9]; // for gluLookAt
	
	GLdouble dirLR, dirFB; // direction either 1 or -1
	
	GLdouble moveSpeed; // speed of camera movement

	bool CanMoveLR();
	bool CanMoveFB();

	void CallGluLookat();


};
