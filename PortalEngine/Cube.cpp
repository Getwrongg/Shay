#include "Cube.h"


Cube::Cube()
{

}
Cube::Cube(const GLdouble x1, const GLdouble y1, const GLdouble z1)
{
	pos.x = x1;
	pos.y = y1;
	pos.z = z1;
}


Cube::~Cube()
{
}


void Cube::Draw(const GLdouble x1, const GLdouble y1, const GLdouble z1)
{
	glPushMatrix();
	glTranslatef(x1,y1,z1);
	
	
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

	glPopMatrix();

	
	
}

void Cube::DrawBush(const GLdouble x1, const GLdouble y1, const GLdouble z1) {

	glBegin(GL_TRIANGLES)
}