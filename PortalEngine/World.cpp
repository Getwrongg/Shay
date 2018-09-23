#include "World.h"



World::World()
{
}

void World::CreateTextures(const std::string name, const char * filePath)
{
	j.CreateTexture("SWIRL", "data/stars.jpg");

	j.CreateTexture("PINK", "data/multicolor.jpg");

	j.CreateTexture("GOD1", "data/god1.png");
	
	cube.CreateTexture();
	

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
}

void World::SkyCylinder()
{
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));

	glPushMatrix();
	GLUquadricObj *glu_cylinder;

	glu_cylinder = gluNewQuadric();
	gluQuadricTexture(glu_cylinder, GL_TRUE);
	
	glTranslatef(-50, 1, 1);
	glRotatef(180, 1.0f, 0.0f, 1);
	glRotatef(rotates, 1.0f, 0.0f, rotates);
	
	gluQuadricDrawStyle(glu_cylinder, GLU_FILL); //GLUquadricObj * qobj = gluNewQuadric();
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

void World::Cubes()
{

	glPushMatrix();
	glScaled(14.5, 14.5, 14.5);

	

	//First Pillar

	//bottom
	cube.Draw(0, 0, 0);
	cube.Draw(0, 1, 0);

	//top
	cube.Draw(0, 4, 0);
	

	//Second Pillar
	//bottom
	cube.Draw(3, 0, 0);
	
	
	cube.Draw(3, 3, 0);//top
	cube.Draw(3, 4, 0);
	

	//Third Pillar
	//bottom
	cube.Draw(6, 0, 0);
	cube.Draw(6, 1, 0);

	cube.Draw(6, 4, 0);//top
	

	//Fourth Pillar
	cube.Draw(9, 2, 0);
	

	//Fifth Pillar
	
	cube.Draw(12, 2, 0);
	cube.Draw(12, 3, 0);
	cube.Draw(12, 4, 0);
	

	//Sixth Pillar
	cube.Draw(15, 0, 0);
	cube.Draw(15, 1, 0);
	


	/*//top railing pillar
	for (float i = 0; i <= 15; i++)
	{
		cube.Draw(i, 7.0f, 0.0f);
	}

	//bottom railing pillar
	for (float i = 0; i <= 15; i++)
	{
		cube.Draw(i, -1.0f, 0.0f);
	}*/


	glPopMatrix();
	
}

void World::Track1()
{
	//_________________BOTTOM PILLAR OF TRACK________________
	//_______________________________________________________

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
