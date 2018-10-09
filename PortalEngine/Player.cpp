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
	rot = 0;

	boostTotal = BOOST_NUMBER;
	boostSpeed = 1.25f;
	boostDelay = 0.5f;
	boostAmount = BOOST_START;

	texName = "";

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);
}

void Player::DrawPlayer()
{
	glBindTexture(GL_TEXTURE_2D, pj.getTextureID(texName));
	glTranslated(pos.x, pos.y, pos.z);
	glRotatef(rot, 0, 1, 0);
	gluSphere(sphere, size, slices, stacks);
}

void Player::LoadTexture(const std::string name, const char * filePath)
{
	pj.UnloadAllTextures();
	pj.CreateTexture(name, filePath);

	texName = name;
}

void Player::LoadSounds() 
{
	audio.LoadWAV("BOOST", "sounds/boost.wav");
//	audio.LoadWAV("JUMP", "sounds/jump.wav");
}

void Player::muteSound()
{
	if (mute) {
		audio.AudioVolume(-1, 128);
		audio.MusicVolume(128);
		mute = false;
	}
	else
	{
		audio.AudioVolume(-1, 0);
		audio.MusicVolume(0);
		mute = true;
	}
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

void Player::Update(const GLfloat timeSincePrevFrame, const bool leftclickedMouse, const bool rightclickedMouse, const bool startRun)
{
	

	if (startRun)
	{
		rot = 0;
		
		// if the user clicks the player is moved upwards
		if (leftclickedMouse)
		{
			vertSpeed = jumpSpeed;
			//audio.PlayAudio("JUMP", 0); Gets called to much and sounds bad for now 
		}

		// Boost the player forward if they have boost left
		if (boostTimer >= boostDelay) //Player can only boost every 2 seconds, stops boost spam
		{
			boostTimer = 0;
			boostReady = true;
		}
		boostTimer += timeSincePrevFrame;

		if (((rightclickedMouse) && (boostTotal > 0) && (boostReady)) || (boostActive)) //boostActive keeps the boost looking smooth (stops it teleporting)
		{
			if (boostSound) {
				audio.PlayAudio("BOOST", 0);
				boostSound = false;
			}
			boostActive = true;
			BoostPlayer();
			boostTimer = 0;
		}
		// moves the player up or down
		pos.y += vertSpeed * timeSincePrevFrame;
		vertSpeed -= gravity * timeSincePrevFrame;

		// moves the player forward along the level
		pos.x += moveSpeed * timeSincePrevFrame;
	}
	else
	{
		rot += 5 * timeSincePrevFrame;
	}

}

void Player::BoostPlayer() 
{

	if(boostAmount > 0)
	{
		pos.x += boostSpeed;
		vertSpeed = 0;
		boostAmount -= 1;
		
	}	

	if (boostAmount < 1) // Resets all boost variables and reduces total boosts by 1
	{
		boostActive = false;
		boostReady = false;
		boostSound = true;
		boostTotal -= 1;
		boostAmount = BOOST_START;
	}
}


void Player::PointCounter(int amount)
{

}

void Player::ResetPlayer() 
{
	SetPosition(10.0f, 72.5f, 7.0f);
	boostAmount = BOOST_START;
	boostTotal = BOOST_NUMBER;
	vertSpeed = 0;
}

void Player::SetMoveSpeed(const GLfloat speed)
{
	moveSpeed = speed;
}

void Player::AddCoins(const int coins)
{
	totalcoinsCollected += coins;
}

int Player::GetTotalCoins()
{
	return totalcoinsCollected;
}