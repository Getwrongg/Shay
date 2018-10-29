#include "World.h"
#include "Cam.h"
#include "ImageLoader.h"
#include "Player.h"
#include "LevelManager.h"
#include "Shop.h"
#include <fstream>

#pragma once

/**
* @class Portal World
* @brief  used to manage the portal world engine
*
*
* @author ClickBait Inc - Manu Murray
* @version 01
* @date 14/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class PortalWorld
{
public:

	/**
	* @author Manu Murray
	*
	* @brief Default Constructor
	*
	* Sets default values to private variables
	*
	*/
	PortalWorld();

	/**
	* @author Manu Murray
	*
	* @brief handle passive mouse looking
	*
	* @param int x, int y
	*
	* @return void
	*/
	void MouseMovement(int x, int y);
	
	/**
	* @author Manu Murray
	*
	* @brief displays everything to the screen
	*
	* 
	*
	* @return void
	*/
	void Display();

	/**
	* @author Manu Murray
	*
	* @brief handles response to key clicks
	*
	* @param unsigned char key, int x, int y
	*
	* @return void
	*/
	void Keyboard(unsigned char key, int x, int y);

	/**
	* @author Manu Murray
	*
	* @brief handles response to key releases
	*
	* @param unsigned char key, int x, int y
	*
	* @return void
	*/
	void ReleaseKeyboard(unsigned char key, int x, int y);

	/**
	* @author Shane Martinez
	*
	* @brief creates texures used in portal world
	*
	* 
	*
	* @return void
	*/
	void CreateTexturesPortalWorld();

	/**
	* @author Shane Martinez
	*
	* @brief conducts animation for portal world
	*
	*
	*
	* @return void
	*/
	void AnimatePortalWorld();

	/**
	* @author Manu Murray
	*
	* @brief initalises variables for portal world
	*
	*
	*
	* @return void
	*/
	void MyInit();

	/**
	* @author Manu Murray
	*
	* @brief ensures the window resizes properly
	*
	* @param int w, int h
	*
	* @return void
	*/
	void Resize(int w, int h);

	/**
	* @author Manu Murray
	*
	* @brief manages mouse clicks
	*
	* @param int button, int state, int x, int y
	*
	* @return void
	*/
	void Mouse(int button, int state, int x, int y);

	/**
	* @author Manu Murray
	*
	* @brief Displays the exit screen
	*
	* 
	*
	* @return void
	*/
	void DisplayExitScreen();

	/**
	* @author Jacob
	*
	* @brief Displays Menu Screen
	*
	*
	*
	* @return void
	*/
	void DisplayMenuScreen();

	/**
	* @author Manu Murry
	*
	* @brief Display Menu Splash
	*
	*
	*
	* @return void
	*/
	void DisplayMenuSplash();

	/**
	* @author Jacob
	*
	* @brief Displays Level
	*
	*
	*
	* @return void
	*/
	void DisplayLevel();

	/**
	* @author Jacob
	*
	* @brief Display Level Number
	*
	*
	*
	* @return void
	*/
	void DisplayLevelNumber();

	/**
	* @author Jacob
	*
	* @brief Display locked symbol if you don't have enough money for skins
	*
	*
	*
	* @return void
	*/
	void DisplayLocked();

	/**
	* @author Jacob
	*
	* @brief Display coin shop
	*
	*
	*
	* @return void
	*/
	void DisplayCoinsShop();

	/**
	* @author Jacob
	*
	* @brief Display Number of coins Collected
	*
	*
	*
	* @return void
	*/
	void DisplayCoinsCollected();

	/**
	* @author Jacob
	*
	* @brief draws the menu pointer
	*
	*
	*
	* @return void
	*/
	void arrowMenu();

	/**
	* @author Jacob
	*
	* @brief Performs the key actions that require special keys
	*
	* such as the arrow keys.
	*
	* @param int key, int x, int y
	*
	* @return void
	*/
	void SpecialKeys(int key, int x, int y);

	/**
	* @author Manu Murray
	*
	* @brief Exits the game and performs tasks that need to be done before exiting
	*
	* such as the log
	*
	* 
	*
	* @return void
	*/
	void ExitGame();

private:
	// camera variables
	GLfloat moveSpeed; // walking sensitivity
	GLfloat rotateSpeed; // mouse sensitivity

	GLfloat prevTime; // used for animation
	bool leftclickedMouse; // used to determine if the user clicked left
	bool rightclickedMouse; // used to determine if the user clicked right

	int getCoinsCollected; 

	int deltaX, deltaY; // the rotation variables for mouse x and y

	// position of the camera
	GLfloat pos[3];
	GLfloat upVec[3];
	GLfloat angle;

	// objects for portal world
	Cam ourCam;
	World world;
	ImageLoader pic;
	Player player;

	// shop variables
	Shop shop;
	bool inShop;
	int xCounter;
	int yCounter;

	// resize variables
	int width, height;

	// various bool variables used to determine game states
	bool DisplayExit;
	bool DisplayMenu;
	bool startRun;

	bool gameselect=false;

	int testcount=0;

	bool down;
	bool up;

	std::string menuOption; // holds the menu choice that is displayed by the menu function
	std::ofstream log;
};

