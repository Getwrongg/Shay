#include "World.h"

void World::CreateTextures(const std::string name, const char * filePath)
{
	j.CreateTexture("SWIRL", "data/stars.jpg");

	j.CreateTexture("PINK", "data/multicolor.jpg");

	j.CreateTexture("GOD1", "data/god1.png");

	j.CreateTexture("COIN", "data/coin.jpg");
	
	cube.CreateTexture();

	coin.CreateTexture();

	levelloader.LoadTexture();

	levelloader.LoadLevel("level1", "./levels/level1.txt");
	
}

void World::Axis() 
{
	//x axis
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, -0.9f, 0.0f);
	glEnd();

	//y axis
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 200.0f, 0.0f);
	glEnd();


	//z axis
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.9f, 300.0f);
	glEnd();


}

void World::AnimatePortalWorld() 
{
	rotates = rotates + rotateSPEED;
	if (rotates >= 360) {
		rotates = 0;
	}
	levelloader.AnimateCoin();
}

void World::SkyCylinder()
{	
	GLUquadricObj* glu_cylinder;
	glu_cylinder = gluNewQuadric();

	gluQuadricTexture(glu_cylinder, GL_TRUE);
	gluQuadricDrawStyle(glu_cylinder, GLU_FILL); //GLUquadricObj * qobj = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));

	glPushMatrix();
	
	glTranslatef(-50, 70, 1);
	glRotatef(180, 1.0f, 0.0f, 1);
	glRotatef(rotates, 1.0f, 0.0f, rotates);
	gluCylinder(glu_cylinder, 100, 100, 450, 200, 200);

	glPopMatrix();	
}

void World::Ground() 
{	
	//glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	
	glBegin(GL_POLYGON);
		glTexCoord2i(0, 0); glVertex3f(-40.0, -1, 100.0);
		glTexCoord2i(0, 1); glVertex3f(40.0, -1, 100.0);
		glTexCoord2i(1, 1); glVertex3f(40.0, -1, -100.0);
		glTexCoord2i(1, 0); glVertex3f(-40.0, -1, -100.0);
	glEnd();

}

void World::DrawLevel()
{
	glPushMatrix();
	glScaled(14.5, 14.5, 14.5);

	levelloader.DrawLevel("level1");

	glPopMatrix();
}

void World::Track1()
{
	////_________________BOTTOM PILLAR OF TRACK________________
	////_______________________________________________________

	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));

	//RIGHT
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 2.0, 15.0);	// TOP RIGHT
	glTexCoord2i(0, 1); glVertex3f(0.0, 2.0, 15.0);	    // BOTTOM RIGHT
	glTexCoord2i(0, 0); glVertex3f(0.0, -100.0, 15.0);	    // TOP LEFT
	glTexCoord2i(1, 0); glVertex3f(400.0, -100.0, 15.0);	// BOTTOM LEFT
	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 2.0, -1.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 2.0, -1.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, -100.0, -1.0);
	glTexCoord2i(1, 0); glVertex3f(400.0, -100.0, -1.0);
	glEnd();

	//FRONT
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(0.0, 2.0, 15.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 2.0, -1.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, -100.0, -1.0);
	glTexCoord2i(1, 0); glVertex3f(0.0, -100.0, 15.0);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 2.0, 15.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 2.0, 15.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, 2.0, -1.0);
	glTexCoord2i(1, 0); glVertex3f(400.0, 2.0, -1.0);
	glEnd();


	//____________________TOP PILLAR OF TRACK________________
	//_______________________________________________________

	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));

	//RIGHT
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 70.0, 15.0);	// TOP RIGHT
	glTexCoord2i(0, 1); glVertex3f(0.0, 70.0, 15.0);	    // BOTTOM RIGHT
	glTexCoord2i(0, 0); glVertex3f(0.0, 100.0, 15.0);	    // TOP LEFT
	glTexCoord2i(1, 0); glVertex3f(400.0, 100.0, 15.0);	// BOTTOM LEFT
	glEnd();

	//BACK
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 70.0, 0.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 70.0, 0.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, 100.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(400.0, 100.0, 0.0);
	glEnd();

	//FRONT
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(0.0, 70.0, 15.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 70.0, 0.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, 100.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(0.0, 100.0, 15.0);
	glEnd();

	//TOP
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 70.0, 15.0);
	glTexCoord2i(0, 1); glVertex3f(0.0, 70.0, 15.0);
	glTexCoord2i(0, 0); glVertex3f(0.0, 70.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(400.0, 70.0, 0.0);
	glEnd();

	//____________________TRACK ONE GOD______________________
	//_______________________________________________________
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("GOD1"));
	
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(400.0, 10.0, 20.0);
	glTexCoord2i(0, 1); glVertex3f(400.0, 10.0, -20.0);
	glTexCoord2i(0, 0); glVertex3f(400.0, 70.0, -20.0);
	glTexCoord2i(1, 0); glVertex3f(400.0, 70.0, 20.0);
	glEnd();


	//____________________BOTTOM PILLARS ONE TO LAST_________
	//_______________________________________________________
	//FIRST PILLAR FRONT
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(40.0, 40.0, 15.0);
	glTexCoord2i(0, 1); glVertex3f(40.0, 40.0, 0.0);
	glTexCoord2i(0, 0); glVertex3f(40.0, 2.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(40.0, 2.0, 15.0);
	glEnd();
}

void World::DrawBushes() {
	Bushes(0,-1,-4);
	Bushes(5,-1,-4);
	Bushes(10,-1,-4);

}

void World::Bushes(const GLfloat x1, const GLfloat y1, const GLfloat z1)
{
	glPushMatrix();
	glTranslatef(x1, y1, z1);
	//left half of bush
	for (float i = -1.5f; i > -3; i = i - 0.1f)
	{
		for (float j = 2; j > 0; j = j - 0.1f)
		{
			for(float k = -1; k < 1; k = k + 0.1f)
			{
				
				glBegin(GL_TRIANGLES);
					glVertex3f(-2, 0, 0);
					glVertex3f(i, j, k);
					glVertex3f(-1, 0, 0);
				glEnd();
			}
			
		}
		
	}
	
	//right half of bush
	for (float i = -1.5f; i < 0; i = i + 0.1f)
	{
		for (float j = 2; j > 0; j = j - 0.1f)
		{
			for (float k = -1; k < 1; k = k + 0.1f)
			{
				glBegin(GL_TRIANGLES);
					glVertex3f(-2, 0, 0);
					glVertex3f(i, j, k);
					glVertex3f(-1, 0, 0);
				glEnd();
			}
		}

	}
	glPopMatrix();
}
