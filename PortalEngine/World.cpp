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

	j.CreateTexture("SCOPE", "data/kScope.jpg");

	j.CreateTexture("oSwirl", "data/swirl.jpg");

	j.CreateTexture("AS", "data/alienSky.jpg");

	j.CreateTexture("SC", "data/spaceCastle.jpg");

	j.CreateTexture("IC", "data/insideCastle.jpg");

	j.CreateTexture("IC2", "data/InsideCastle2.jpg");

	levelmanager.LoadTexture();

	levelmanager.LoadLevelIndex("./levels/level_index.txt"); // Setup Level
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

void World::BackGround()
{
	GLUquadricObj* glu_cylinder;
	glu_cylinder = gluNewQuadric();

	gluQuadricTexture(glu_cylinder, GL_TRUE);
	gluQuadricDrawStyle(glu_cylinder, GLU_FILL); //GLUquadricObj * qobj = gluNewQuadric();

	std::string levelName;
	levelName = levelmanager.getLevelName();
	if (levelName == "level1" || levelName == "random")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	}

	if (levelName == "level2")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SKY"));
	}

	if (levelName == "level3")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SPACE"));
	}

	if (levelName == "level4")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("NEB"));
	}

	if (levelName == "level5")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SCOPE"));
	}

	if (levelName == "level6")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("oSwirl"));
	}

	if (levelName == "level7")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("AS"));
	}

	if (levelName == "level8")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SC"));
	}

	if (levelName == "level9")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("IC"));
	}

	if (levelName == "level10")
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("IC2"));
	}

	glPushMatrix();
	
	glTranslatef(-50, 70, 1);
	glRotatef(180, 1.0f, 0.0f, 1);
	glRotatef(rotates, 1.0f, 0.0f, rotates);
	gluCylinder(glu_cylinder, 100, 100, 600, 200, 200); //quad,base,top,height,slices,stacks

	glPopMatrix();	


	GLUquadric* glu_disk;
	glu_disk = gluNewQuadric();

	gluQuadricTexture(glu_disk, GL_TRUE);
	//glBindTexture(GL_TEXTURE_2D, image.getTextureID());

	glPushMatrix();

	glTranslatef(550, 70, 1);
	glRotatef(rotates, rotates, 1.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	gluDisk(glu_disk, 0, 125, 24, 16);

	glPopMatrix();

}

void World::DrawLevel(const Coordinates pos) //returns true if player fails level
{
	glPushMatrix();
	glScaled(14.5, 14.5, 14.5);

	levelmanager.DrawLevel(pos);

	glPopMatrix();

}

int World::GetDistanceToEnd(Coordinates pos)
{
	pos.x = (GLfloat)(pos.x / 14.5); // remove scaling factor
	int endpoint = levelmanager.GetEndPoint();
	double distance = (double)pos.x / endpoint * 100;

	return (int)distance;
}

bool World::levelFailed()
{
	return levelmanager.HasFailed();
}

bool World::levelComplete()
{
	return levelmanager.HasEndedRound();
}

int World::GetCoins()
{
	return levelmanager.GetCoinsCollected();
}

int World::GetTrophys()
{
	return levelmanager.GetTrophysCollected();
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

void World::ContinueLevel()
{
	std::vector<std::string> levels;
	levels = levelmanager.GetLevelIndex();

	levelmanager.SetLevel(levels[levelmanager.getLevelNumber()]);
}

void World::SetLevel(const int levelNum)
{
	std::vector<std::string> levels;
	levels = levelmanager.GetLevelIndex();

	levelmanager.SetLevel(levels[levelNum]);
}

void World::SetLevelRandom()
{
	levelmanager.SetLevel("random");
}
