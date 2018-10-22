#include <string>
#include <vector>
#include <iostream>
#include "audio.h"

#pragma once

/**
* @class skin
* @brief struct that holds information needed for a skin
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 03/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
struct skin {
	std::string name; // name of skin
	int location; // location of skin
	int cost; // how many coins it costs
	bool isUnlocked; // if the skin is already unlocked

	/**
	* @author Shane Martinez
	*
	* @brief constructor
	*
	* @param string S_name, int S-location, int S_cost
	*
	* @return void
	*/
	skin(std::string S_name, int S_location, int S_cost)
	{
		name = S_name;
		location = S_location;
		cost = S_cost;
		isUnlocked = false;
	}
};

/**
* @class Shop
* @brief manages the shop in the game
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 03/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class Shop
{
public:
	/**
	* @author Shane Martinez
	*
	* @brief default constructor 
	*
	* 
	*
	* @return void
	*/
	Shop();

	/**
	* @author Shane Martinez
	*
	* @brief load sounds for the shop
	*
	* 
	*
	* @return void
	*/
	void LoadSounds();

	/**
	* @author Shane Martinez
	*
	* @brief mute shop sounds
	*
	*
	*
	* @return void
	*/
	void Mute();

	/**
	* @author Shane Martinez
	*
	* @brief displays shop information to the screen
	*
	* @param const int totalCoins
	*
	* @return void
	*/
	void showShop(const int totalCoins);

	/**
	* @author Shane Martinez
	*
	* @brief set current shop item
	*
	* @param const int x, const int y
	*
	* @return void
	*/
	void SetCurrent(const int x, const int y);

	/**
	* @author Shane Martinez
	*
	* @brief buys and applies skin to the player
	*
	* @param int totalCoins
	*
	* @return int totalCoins
	*/
	int BuySkin(int totalCoins);

	/**
	* @author Shane Martinez
	*
	* @brief gets the name of the current skin
	*
	* 
	*
	* @return string currentSkin
	*/
	std::string GetCurrentSkin();

	/**
	* @author Shane Martinez
	*
	* @brief checks if a skin is unlocked
	*
	* @param const int i
	*
	* @return bool
	*/
	bool IsUnlocked(const int i);



private:
	int currentLocation = 0; // current location of the menu selector
	std::string currentSkin; // current sckin of player
	
	std::vector < skin > SkinList; // list of skins

	Audio audio; // audio object used to load shop audio
	bool mute = false; // controls whether shop sounds are muted
};

