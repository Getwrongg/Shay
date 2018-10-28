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
* @brief Manages the world 
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
	* @param const Coordinates pos
	*
	* @return 
	*/
	void DrawLevel(const Coordinates pos);

	/**
	* @author Christopher Gemmell
	*
	* @brief Returns number of coins
	*
	* @param Coordinates pos
	*
	* @return int 
	*/
	int GetDistanceToEnd(Coordinates pos);

	/**
	* @author Shane Martinez
	*
	* @brief Returns number of coins
	*
	*
	*
	* @return int
	*/
	int GetCoins();

	/**
	* @author Shane Martinez
	*
	* @brief Returns number of trophys
	*
	*
	*
	* @return int
	*/
	int GetTrophys();

	/**
	* @author Shane Martinez
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

	/**
	* @author Shane Martinez
	*
	* @brief gets the currentlevel number
	*
	*
	*
	* @return int
	*/
	int LevelNumber();

	/**
	* @author Shane Martinez
	*
	* @brief mutes the world sound
	*
	*
	*
	* @return int
	*/
	void muteLevel();

	/**
	* @author Shane Martinez
	*
	* @brief returns true if the level is complete
	*
	*
	*
	* @return bool
	*/
	bool levelComplete();

	/**
	* @author Shane Martinez
	*
	* @brief returns true if the level is failed
	*
	*
	*
	* @return bool
	*/
	bool levelFailed();

	/**
	* @author Shane Martinez
	*
	* @brief sets the level
	*
	* @param const int levelNum
	*
	* @return void
	*/
	void SetLevel(const int levelNum);

	void SetLevelRandom();

	void ContinueLevel();


private:
	ImageLoader j; // object to load images
	Cube cube; // object of type cube - draws cubes for pillars
	Coin coin; // object of type coin - draws coins

	LevelManager levelmanager; //loads the level from a file

	// variables for skyCylinder rotation
	float rotates = 0.0f;
	float rotateSPEED = 10.0f;
};

