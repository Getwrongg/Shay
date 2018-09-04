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
		glVertex3f(1, 1, 1);
		glVertex3f(2, 1, 1);
		glVertex3f(2 ,0, 1);
		glVertex3f(1, 0, 1);
	glEnd();

	
	



}