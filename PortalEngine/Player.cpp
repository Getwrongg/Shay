#include "Player.h"

Player::Player()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

	size = 5.0;
	slices = 20;
	stacks = 20;

	gravity = 40.0f;
	vertSpeed = 0.0f;
	jumpSpeed = 25.0f;
	moveSpeed = 25.0f;

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
	pj.UnloadAllTextures();
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

void Player::Update(const GLfloat timeSincePrevFrame, const bool clickedMouse)
{
	// if the user clicks the player is moved upwards
	if (clickedMouse)
	{
		vertSpeed = jumpSpeed;
	}
	// moves the player up or down
	pos.y += vertSpeed * timeSincePrevFrame;
	vertSpeed -= gravity * timeSincePrevFrame;

	// moves the player forward along the level
	pos.x += moveSpeed * timeSincePrevFrame;
}

void Player::PointCounter(int amount)
{

}
