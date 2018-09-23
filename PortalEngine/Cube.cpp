#include "Cube.h"

Cube::Cube()
{
	pos.x = 0.0;
	pos.y = 0.0;
	pos.z = 0.0;
}

Cube::Cube(const GLfloat x1, const GLfloat y1, const GLfloat z1)
{
	pos.x = x1;
	pos.y = y1;
	pos.z = z1;
}

void Cube::CreateTexture()
{
	j.CreateTexture("pillar", "data/pillarTexture.jpg");
	j.CreateTexture("bottompillar", "data/bottompillar.jpg");
	j.CreateTexture("SWIRL", "data/stars.jpg");
}

void Cube::Draw(const GLfloat x1, const GLfloat y1, const GLfloat z1)
{
	
	glPushMatrix();
	glTranslatef(x1,y1,z1);
	
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	//front square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0, 1.0, 1.0);
		glTexCoord2i(0, 0); glVertex3f(2.0 ,0.0, 1.0);
		glTexCoord2i(1, 0); glVertex3f(1.0, 0.0, 1.0);
	glEnd();

	//left square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,1.0);
	glEnd();

	//right square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(2.0,1.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//back square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,0.0);
	glEnd();


	//bottom square
	//glBindTexture(GL_TEXTURE_2D, j.getTextureID("bottompillar"));
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0,0.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//top square
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2i(0, 1); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2i(0, 0); glVertex3f(2.0, 1.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(2.0, 1.0, 1.0);
	glEnd();


	glPopMatrix();

	
	
}
