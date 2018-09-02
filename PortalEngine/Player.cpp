#include "Player.h"



Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	size = 0.5;
	slices = 20;
	stacks = 20;

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);
}

void Player::DrawPlayer()
{
	gluSphere(sphere, size, slices, stacks);
}

void Player::LoadTexture(const std::string name, const char * filePath)
{
	pj.CreateTexture(name, filePath);
	glBindTexture(GL_TEXTURE_2D, pj.getTextureID(name));
}
