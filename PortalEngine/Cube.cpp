#include "Cube.h"



Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::Draw() 
{
	glBegin(GL_POLYGON);
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(2.0, 1.0, 1.0);
		glVertex3f(2.0 ,0.0, 1.0);
		glVertex3f(1.0, 0.0, 1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0,1.0,0.0);
		glVertex3f(1.0,0.0,0.0);
		glVertex3f(1.0,0.0,1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(2.0,1.0,1.0);
		glVertex3f(2.0,1.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(2.0,0.0,1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.0,1.0,1.0);
		glVertex3f(2.0,1.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(1.0,0.0,0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.0,1.0,1.0);
		glVertex3f(1.0,1.0,0.0);
		glVertex3f(2.0,1.0,0.0);
		glVertex3f(2.0,1.0,1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.0,0.0,1.0);
		glVertex3f(1.0,0.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(2.0,0.0,1.0);
	glEnd();

	
	
}