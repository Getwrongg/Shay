#include "Player.h"



Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	size = 0.5;
	slices = 20;
	stacks = 20;

	gravity = 0.0001;

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);
}

void Player::DrawPlayer()
{
	glTranslated(pos.x, pos.y, pos.z);
	gluSphere(sphere, size, slices, stacks);
}

void Player::LoadTexture(const std::string name, const char * filePath)
{
	pj.CreateTexture(name, filePath);
	glBindTexture(GL_TEXTURE_2D, pj.getTextureID(name));
}

Coordinates & Player::GetPosition()
{
	return pos;
}

void Player::SetPosition(const GLdouble x, const GLdouble y, const GLdouble z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void Player::Update()
{
	pos.y -= gravity;
}
