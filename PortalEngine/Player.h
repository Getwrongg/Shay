#include "ImageLoader.h"
#include <GL/glut.h>
#include "audio.h"

#include "Structs.h"


#pragma once

/**
* @class Player
* @brief  used to represent a the object of the player
*
* Which is a round ball with a texture and physics properties
*
* @author ClickBait Inc - Manu Murray
* @version 01
* @date 04/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/

const GLfloat BOOST_START = 15.0f;
const int BOOST_NUMBER = 3;

class Player
{
public:
	Player();
	void DrawPlayer();
	void LoadSounds();
	void LoadTexture(const std::string name, const char * filePath);
	void Update(const GLfloat timeSincePrevFrame, const bool leftclickedMouse, const bool rightclickedMouse, const bool startRun);
	Coordinates & GetPosition();
	void SetPosition(const GLfloat x, const GLfloat y, const GLfloat z);
	void PointCounter(int amount);
	void SetMoveSpeed(const GLfloat speed);
	void AddCoins(const int coins);
	int GetTotalCoins();

	void muteSound();

	void BoostPlayer();

	void ResetPlayer();

private:
	Coordinates pos;
	GLfloat size;
	GLint slices, stacks;
	int totalcoinsCollected=0;
	GLUquadricObj *sphere;
	std::string texName;

	// jpegloader object for textures
	ImageLoader pj;
	Audio audio;

	GLfloat gravity, vertSpeed, jumpSpeed, moveSpeed, rot;

	//Boost Variables
	GLfloat boostSpeed, boostAmount;
	float boostDelay; //How often you can boost in seconds
	int boostTotal;
	bool boostSound = true;
	bool boostReady = true;
	bool boostActive = false;
	GLfloat boostTimer = 0;

	bool mute = false;

};

