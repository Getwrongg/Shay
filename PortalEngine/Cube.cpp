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

void Cube::CreateTexture() {
	j.CreateTexture("pillar", "data/pillarTexture.jpg");
	j.CreateTexture("bottompillar", "data/bottompillar.jpg");
}

void Cube::Draw(const GLdouble x1, const GLdouble y1, const GLdouble z1)
{
	
	glPushMatrix();
	glTranslatef(x1,y1,z1);
	
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("pillar"));
	//front square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0, 1.0, 1.0);
		glTexCoord2i(0, 0); glVertex3f(2.0 ,0.0, 1.0);
		glTexCoord2i(1, 0); glVertex3f(1.0, 0.0, 1.0);
	glEnd();

	//left square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 0); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,1.0);
	glEnd();

	//right square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 0); glVertex3f(2.0,1.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//back square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 0); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,0.0);
	glEnd();


	//bottom square
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("bottompillar"));
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//top square
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 0); glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2i(0, 1); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2i(0, 1); glVertex3f(2.0, 1.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(2.0, 1.0, 1.0);
	glEnd();


	glPopMatrix();

	
	
}
