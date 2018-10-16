#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "Cube.h"
#include "Coin.h"
#include "audio.h"

const int MAX_HEIGHT = 9;

class LevelManager{
public:
	/**
	* @author
	*
	* @brief Pre-loads all textures
	*
	*
	*
	* @return void
	*/
	void LoadTexture();

	/**
	* @author
	*
	* @brief Animates the coins
	*
	* @param const Glfloat timeSincePrevFrame
	*
	* @return void
	*/
	void AnimateCoin(const GLfloat timeSincePrevFrame);

	/**
	* @author
	*
	* @brief Reads level name from files and places them in a map with levelname being the key
	*
	* @param const std::string levelName, const char *file
	*
	* @return void
	*/
	void LoadLevel(const std::string levelName, const char *file);

	/**
	* @author
	*
	* @brief Reads level name from file and places them in a map with levelname being the key
	*
	* @param const const char *file
	*
	* @return void
	*/
	void LoadLevelIndex(const char *file);// ./levels/level_index.txt

	/**
	* @author
	*
	* @brief Set the currentlevel
	*
	* @param const std::string levelName
	*
	* @return void
	*/
	void SetLevel(const std::string levelName);

	/**
	* @author
	*
	* @brief Draws level
	*
	* @param const Coordinates pos
	*
	* @return void
	*/
	void DrawLevel(const Coordinates pos);

	/**
	* @author
	*
	* @brief Increase currentLevel
	*
	* 
	*
	* @return void
	*/

	int GetEndPoint();

	void SetNextLevel();

	/**
	* @author
	*
	* @brief return number of coins collected
	*
	* 
	*
	* @return int
	*/
	int GetCoinsCollected();

	/**
	* @author
	*
	* @brief Returns bool
	*
	* 
	*
	* @return bool
	*/
	bool HasEndedRound();

	/**
	* @author
	*
	* @brief Returns bool
	*
	*
	*
	* @return bool
	*/
	bool HasFailed();

	/**
	* @author
	*
	* @brief Resets stats to default
	*
	*
	*
	* @return void
	*/
	void ResetLevel();

	std::string getLevelName();

	int getLevelNumber();

	void muteLevel();

private:
	
	bool CheckCollision(Coordinates pos, unsigned x, unsigned y);

	std::map<std::string, std::vector<std::string> > LevelStorage; //Stores all the levels
	std::vector<std::string> Level_Index; //Stores all loaded level names for easy access
	std::vector<std::string> currentLevel; //used to create a copy of the level in storage
	std::string currentLevelName; // Used to reset current level

	bool failed = false; //if player fails level
	bool endRound = false; //if player completes level
	int coinscollected=0;
	int currentlevelNumber = 0;

	bool mute = false;

	Audio audio;
	Cube cubedraw;
	Coin coindraw;
};

