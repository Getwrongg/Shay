#include "World.h"



World::World()
{
}

void World::CreateTextures(const std::string name, const char * filePath)
{
	j.CreateTexture("SWIRL", "data/portalswirl.jpg");
	
	j.CreateTexture("pillar", "data/pillarTexture.jpg");

}

void World::Axis() 
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(1.0, -0.9, 0.0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(0.0, 2.0, 0.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(0.0, -0.9, 3.0);
	glEnd();


}
void World::Ground() 
{
	
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	
	glBegin(GL_POLYGON);
		glTexCoord2i(0, 0); glVertex3f(-40.0, -1, 100.0);
		glTexCoord2i(0, 1); glVertex3f(40.0, -1, 100.0);
		glTexCoord2i(1, 1); glVertex3f(40.0, -1, -100.0);
		glTexCoord2i(1, 0); glVertex3f(-40.0, -1, -100.0);
	glEnd();

}

void World::Cubes()
{

	//First Pillar
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("pillar"));
	cube.Draw(0, -1, 0);//bottom
	cube.Draw(0, 0, 0);
	cube.Draw(0, 1, 0);

	cube.Draw(0, 4, 0);//top
	cube.Draw(0, 5, 0);
	cube.Draw(0, 6, 0);

	//Second Pillar
	cube.Draw(3, -1 ,0);//bottom
	cube.Draw(3, 0, 0);
	
	
	cube.Draw(3, 3, 0);//top
	cube.Draw(3, 4, 0);
	cube.Draw(3, 5, 0);
	cube.Draw(3, 6, 0);

	//Third Pillar
	cube.Draw(6, -1, 0);//bottom
	cube.Draw(6, 0, 0);
	cube.Draw(6, 1, 0);

	cube.Draw(6, 4, 0);//top
	cube.Draw(6, 5, 0);
	cube.Draw(6, 6, 0);

	
	
}

void World::Bushes()
{

	for (float i = -1.5; i > -3; i = i - 0.1) 
	{
		for (float j=2;j>0;j=j-0.1)
		{
			for(float k=-1;k<1;k=k+0.1)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(-2, 0, 0);
				glVertex3f(i, j, k);
				glVertex3f(-1, 0, 0);
				glEnd();
			}
			
		}
		
	}

	for (float i = -1.5; i < 0; i = i + 0.1)
	{
		for (float j = 2; j>0; j = j - 0.1)
		{
			for (float k = -1; k<1; k = k + 0.1)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(-2, 0, 0);
				glVertex3f(i, j, k);
				glVertex3f(-1, 0, 0);
				glEnd();
			}
		}

	}
	

}
