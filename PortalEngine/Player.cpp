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
	jumpSpeed = 30.0f;
	moveSpeed = 25.0f;
	boostx = 1.25f;
	boostAmount = 15.0f;

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

void Player::Update(const GLfloat timeSincePrevFrame, const bool leftclickedMouse, const bool rightclickedMouse)
{
	// if the user clicks the player is moved upwards
	if (leftclickedMouse)
	{
		vertSpeed = jumpSpeed;
	}
	// Boost the player forward if they have boost left
	if ((rightclickedMouse) && (boostAmount > 0)) {
		pos.x += boostx;
		vertSpeed = 0;
		boostAmount -= 1;
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

void Player::ResetPlayer() 
{
	SetPosition(10.0f, 72.5f, 7.0f);
	boostAmount = 15.0f;
	vertSpeed = 0;
}

void Player::SetMoveSpeed(const GLfloat speed)
{
	moveSpeed = speed;
}

void Player::AddCoins(const int coins)
{
	coinsCollected += coins;
}

int Player::GetCoins()
{
	return coinsCollected;
}