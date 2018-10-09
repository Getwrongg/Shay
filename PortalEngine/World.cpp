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

	levelmanager.SetLevel("level1");
	
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

int World::LevelNumber()
{
	return levelmanager.getLevelNumber();
}

void World::ResetLevel() 
{
	levelmanager.ResetLevel();
}

void World::muteLevel()
{
	levelmanager.muteLevel();
}
