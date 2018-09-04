#include "World.h"



World::World()
{
}

void World::Axis() 
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(100.0, -0.9, 0.0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.9, 0.0);
	glVertex3f(0.0, -0.9, 100.0);
	glEnd();


}
void World::Ground() 
{
	j.CreateTexture("SWIRL", "data/portalswirl.jpg");
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
	cube.Draw();
}


