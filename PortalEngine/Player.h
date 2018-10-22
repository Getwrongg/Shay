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
	
	/**
	* @brief Default constructor
	*
	* Sets default values to private variables
	*
	*/
	Player();

	/**
	* @brief Draws the player object
	*
	* using expected texture
	*
	* 
	* 
	* @return void
	*/
	void DrawPlayer();

	/**
	* @Author Shane Martinez
	* @brief loads sounds for the player's boost mechanic
	*
	* 
	*
	*
	*
	* @return void
	*/
	void LoadSounds();

	/**
	* @brief loads the textures for the player skin
	*
	* 
	*
	*
	*
	* @return void
	*/
	void LoadTexture();

	/**
	* @brief Handles the player animations/movement
	*
	* 
	*
	* @param const GLfloat timeSincePrevFrame, const bool leftClickedMouse, const bool rightClickedMouse, const bool startRun
	*
	* @return void
	*/
	void Update(const GLfloat timeSincePrevFrame, const bool leftclickedMouse, const bool rightclickedMouse, const bool startRun);

	/**
	* @brief Gets the position of the player object
	*
	* used for collision detection
	*
	* 
	*
	* @return Coordinates pos
	*/
	Coordinates & GetPosition();

	/**
	* @brief Sets the position of the player
	*
	* 
	*
	* @param const GLfloat x, const GLfloat y, const GLfloat z
	*
	* @return void
	*/
	void SetPosition(const GLfloat x, const GLfloat y, const GLfloat z);

	/**
	* @brief Sets the movement speed of the player
	*
	*
	*
	* @param const GLfloat speed
	*
	* @return void
	*/
	void SetMoveSpeed(const GLfloat speed);

	/**
	* @Author Shane Martinez
	* @brief Add collected items to the player
	*
	*
	*
	* @param const int coins, const int trophy
	*
	* @return void
	*/
	void AddCollectables(const int coins, const int trophy);

	/**
	* @Author Shane Martinez
	* @brief Returns the total coins collected
	*
	*
	*
	* 
	*
	* @return int total coins
	*/
	int GetTotalCoins();

	/**
	* @Author Shane Martinez
	* @brief Returns total trophys collected
	*
	*
	*
	*
	*
	* @return int total trophys
	*/
	int GetTotalTrophys();

	/**
	* 
	* @brief sets the number of coins
	*
	*
	*
	* @param const int coins
	*
	* @return void
	*/
	void SetCoins(const int coins);

	/**
	*
	* @brief sets the skin of the player
	*
	*
	*
	* @param const string name
	*
	* @return void
	*/
	void SetSkin(const std::string name);

	/**
	* @author Shane Martinez
	* @brief mutes the sound of the player
	*
	*
	*
	* 
	*
	* @return void
	*/
	void muteSound();

	/**
	* @author Shane Martinez
	* @brief gives the player a short boost of speed
	*
	*
	*
	*
	*
	* @return void
	*/
	void BoostPlayer();

	/**
	* @author Shane Martinez
	* @brief resets the player to default stats
	*
	*
	*
	*
	*
	* @return void
	*/
	void ResetPlayer();

private:
	Coordinates pos; // position of the player
	GLfloat size; // size of the player
	GLint slices, stacks; // used for player sphere variables

	GLUquadricObj *sphere; // used for sphere texturing
	std::string texName; // texture name used to choose player texture

	// jpegloader object for textures
	ImageLoader pj;
	Audio audio;

	// animation variables for the player
	GLfloat gravity, vertSpeed, jumpSpeed, moveSpeed, rot;

	// Boost Variables
	GLfloat boostSpeed, boostAmount;
	float boostDelay; //How often you can boost in seconds
	int boostTotal;
	bool boostSound = true;
	bool boostReady = true;
	bool boostActive = false;
	GLfloat boostTimer = 0;

	// items collected variables
	int totalcoinsCollected;
	int totaltrophysCollected;

	bool mute = false; // chooses if the player is muted

};

