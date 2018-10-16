#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

#include "Structs.h"
#include "Cube.h"
#include "Coin.h"
#include "ImageLoader.h"
#include "LevelManager.h"
#include "objectaudio.h"

/**
* @class World
* @brief
*
*
* @author ClickBait Inc - Christopher Gemmell
* @version 01
* @date 03/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/

class World
{
public:
	/**
	* @author Christopher Gemmell
	*
	* @brief creates textures for the world
	*
	* @param const std::string name, const char * filePath
	*
	* @return void
	*/
	void CreateTextures(const std::string name, const char * filePath);



	/**
	* @author Christopher Gemmell
	*
	* @brief draws the pillars out of cubes
	*
	*
	*
	* @return 
	*/
	void DrawLevel(const Coordinates pos);

	int GetDistanceToEnd(Coordinates pos);

	/**
	* @author
	*
	* @brief Returns number of coins
	*
	*
	*
	* @return int
	*/
	int GetCoins();

	int GetTrophys();

	/**
	* @author
	*
	* @brief Sets the Player to the start of the level
	*
	*
	*
	* @return void
	*/
	void ResetLevel();

	/**
	* @author Shane Martinez
	*
	* @brief performs animations in portal world
	*
	*
	*
	* @return void
	*/
	void AnimatePortalWorld(const GLfloat timeSincePrevFrame);

	/**
	* @author Christopher Gemmell
	*
	* @brief draws a skybox/cylinder
	*
	*
	*
	* @return void
	*/
	void BackGround();

	int LevelNumber();

	void muteLevel();

	bool levelComplete();

	bool levelFailed();


private:
	ImageLoader j; // object to load images
	Cube cube; // object of type cube - draws cubes for pillars
	Coin coin;

	LevelManager levelmanager; //loads the level from a file

	// variables for skyCylinder rotation
	float rotates = 0.0f;
	float rotateSPEED = 10.0f;
};

