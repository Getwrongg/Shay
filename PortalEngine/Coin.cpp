#include "Coin.h"

void Coin::CreateTexture()
{
	image.CreateTexture("COIN", "data/coin.jpg");
}

void Coin::DrawCoin(const GLfloat x1, const GLfloat y1, const GLfloat z1) 
{
	GLUquadric* glu_disk;
	glu_disk = gluNewQuadric();

	gluQuadricTexture(glu_disk, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, image.getTextureID("COIN"));
	
	glPushMatrix();
	
	glTranslatef(x1+1.5f, y1+0.5f, z1+0.5f);
	glRotatef((float)rotate, 0.0f, 1.0f, 0.0f);
	gluDisk(glu_disk, 0, 0.35, 24, 16);

	glPopMatrix();
}

void Coin::AnimateCoin() 
{
	rotate = rotate + rotateSpeed;
	if (rotate >= 360) {
		rotate = 0;
	}
}