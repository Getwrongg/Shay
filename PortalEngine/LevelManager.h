#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "Cube.h"
#include "Coin.h"
#include "audio.h"
#include "LevelGen.h"

const int MAX_HEIGHT = 9;

/**
* @class LevelManager
* @brief  Manages the levels
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 20/10/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class LevelManager{
public:
	/**
	* @author Shane Martinez
	*
	* @brief Pre-loads all textures
	*
	*
	*
	* @return void
	*/
	void LoadTexture();

	/**
	* @author Shane Martinez
	*
	* @brief Animates the coins
	*
	* @param const Glfloat timeSincePrevFrame
	*
	* @return void
	*/
	void AnimateCoin(const GLfloat timeSincePrevFrame);

	/**
	* @author Shane Martinez
	*
	* @brief Reads level name from files and places them in a map with levelname being the key
	*
	* @param const std::string levelName, const char *file
	*
	* @return void
	*/
	void LoadLevel(const std::string levelName, const char *file);

	/**
	* @author Shane Martinez
	*
	* @brief Reads level name from file and places them in a map with levelname being the key
	*
	* @param const const char *file
	*
	* @return void
	*/
	void LoadLevelIndex(const char *file);// ./levels/level_index.txt

	/**
	* @author Shane Martinez
	*
	* @brief Set the currentlevel
	*
	* @param const std::string levelName
	*
	* @return void
	*/
	void SetLevel(const std::string levelName);

	/**
	* @author Shane Martinez
	*
	* @brief Draws level
	*
	* @param const Coordinates pos
	*
	* @return void
	*/
	void DrawLevel(const Coordinates pos);

	/**
	* @author Shane Martinez
	*
	* @brief Gets the end of the level
	*
	* 
	*
	* @return int currentlevel.size()
	*/
	int GetEndPoint();

	/**
	* @author Shane Martinez
	*
	* @brief Sets the next level
	*
	*
	*
	* @return void
	*/
	void SetNextLevel();

	/**
	* @author Shane Martinez
	*
	* @brief return number of coins collected
	*
	* 
	*
	* @return int
	*/
	int GetCoinsCollected();

	/**
	* @author Shane Martinez
	*
	* @brief return number of trophys collected
	*
	*
	*
	* @return int
	*/
	int GetTrophysCollected();

	/**
	* @author Shane Martinez
	*
	* @brief Returns true if level has ended
	*
	* 
	*
	* @return bool endRound
	*/
	bool HasEndedRound();

	/**
	* @author Shane Martinez
	*
	* @brief Returns true if failed
	*
	*
	*
	* @return bool failed
	*/
	bool HasFailed();

	/**
	* @author Shane Martinez
	*
	* @brief Resets stats to default
	*
	*
	*
	* @return void
	*/
	void ResetLevel();

	/**
	* @author Shane Martinez
	*
	* @brief gets the name of the current level
	*
	*
	*
	* @return string currentLevelName
	*/
	std::string getLevelName();

	/**
	* @author Shane Martinez
	*
	* @brief gets the current level number
	*
	*
	*
	* @return int currentLevelNumber
	*/
	int getLevelNumber();

	/**
	* @author Shane Martinez
	*
	* @brief mutes the level sound
	*
	*
	*
	* @return void
	*/
	void muteLevel();

	/**
	* @author Shane Martinez
	*
	* @brief returns the level index
	*
	*
	*
	* @return std::vector<std::string> levelIndex
	*/
	std::vector<std::string> GetLevelIndex();

private:
	
	/**
	* @author Shane Martinez
	*
	* @brief performes collision detection
	*
	* @param Coordinates pos, unsinged x, unsigned y
	*
	* @return bool 
	*/
	bool CheckCollision(Coordinates pos, unsigned x, unsigned y);

	std::map<std::string, std::vector<std::string> > LevelStorage; //Stores all the levels
	std::vector<std::string> Level_Index; //Stores all loaded level names for easy access
	std::vector<std::string> currentLevel; //used to create a copy of the level in storage so it can be modified during gameplay without changing original
	std::string currentLevelName; // Used to reset current level and determine current level name

	bool failed = false; //if player fails level
	bool endRound = false; //if player completes level
	int coinscollected=0; // number of coins collected per level
	int trophyscollected = 0; // number of trophys collected per level
	int currentlevelNumber = 0; // current level number

	bool mute = false; // whether or not sound is muted

	// objects from other classes
	Audio audio;
	Cube cubedraw;
	Coin coindraw;
};

