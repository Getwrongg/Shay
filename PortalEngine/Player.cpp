#include "Player.h"

Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	size = 5.0;
	slices = 20;
	stacks = 20;

	gravity = -0.0001;

	texName = "";

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);
}

void Player::DrawPlayer()
{
	glBindTexture(GL_TEXTURE_2D, pj.getTextureID(texName));
	glTranslated(pos.x, pos.y, pos.z);
	gluSphere(sphere, size, slices, stacks);
}

void Player::LoadTexture(const std::string name, const char * filePath)
{
	pj.CreateTexture(name, filePath);
	texName = name;
}

Coordinates & Player::GetPosition()
{
	return pos;
}

void Player::SetPosition(const GLfloat x, const GLfloat y, const GLfloat z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void Player::Update()
{
	pos.y -= gravity;
}

void Player::PointCounter(int amount)
{

}
