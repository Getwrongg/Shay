#include "World.h"

void World::CreateTextures(const std::string name, const char * filePath)
{
	j.CreateTexture("SWIRL", "data/trees.jpg");

	j.CreateTexture("PINK", "data/multicolor.jpg");

	j.CreateTexture("GOD1", "data/god1.png");

	j.CreateTexture("COIN", "data/coin.jpg");

	j.CreateTexture("STARS", "data/stars.jpg");

	j.CreateTexture("SKY", "data/skyC.jpg");
	
	j.CreateTexture("SPACE", "data/space.jpg");

	j.CreateTexture("NEB", "data/tri.jpg");

	levelmanager.LoadTexture();

	levelmanager.LoadLevelIndex("./levels/level_index.txt");
	//levelmanager.LoadLevel("level1", "./levels/level1.txt");
	//levelmanager.LoadLevel("level2", "./levels/level2.txt");
	//levelmanager.LoadLevel("level3", "./levels/level3.txt");

	levelmanager.SetLevel("level4");
	
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

void World::AnimatePortalWorld(const GLfloat timeSincePrevFrame)
{
	rotates += rotateSPEED * timeSincePrevFrame;
	if (rotates >= 360) {
		rotates = 0;
	}
	levelmanager.AnimateCoin(timeSincePrevFrame);
}

void World::SkyCylinder()
{	
	std::string levelName;
	GLUquadricObj* glu_cylinder;
	glu_cylinder = gluNewQuadric();

	gluQuadricTexture(glu_cylinder, GL_TRUE);
	gluQuadricDrawStyle(glu_cylinder, GLU_FILL); //GLUquadricObj * qobj = gluNewQuadric();

	
	levelName=levelmanager.getLevelName();
	if (levelName == "level1")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	}
	else
		if (levelName == "level2") 
		{
			glBindTexture(GL_TEXTURE_2D, j.getTextureID("SKY"));
		}
		else
			if (levelName == "level3")
			{
				glBindTexture(GL_TEXTURE_2D, j.getTextureID("SPACE"));
			}
			else
				if (levelName=="level4")
				{
					glBindTexture(GL_TEXTURE_2D, j.getTextureID("NEB"));
				}
	

	
	

	glPushMatrix();
	
	glTranslatef(-50, 70, 1);
	glRotatef(180, 1.0f, 0.0f, 1);
	glRotatef(rotates, 1.0f, 0.0f, rotates);
	gluCylinder(glu_cylinder, 100, 100, 600, 200, 200); //quad,base,top,height,slices,stacks

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

bool World::DrawLevel(const Coordinates pos) //returns true if player fails level
{
	glPushMatrix();
	glScaled(14.5, 14.5, 14.5);

	levelmanager.DrawLevel(pos);

	if (levelmanager.HasFailed() || levelmanager.HasEndedRound()) //Level is currently set in World::CreateTextures
	{
		return true;
	}
	glPopMatrix();

	return false;
}

int World::GetCoins()
{
	return levelmanager.GetCoinsCollected();
}

void World::ResetLevel() 
{
	levelmanager.ResetLevel();
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
