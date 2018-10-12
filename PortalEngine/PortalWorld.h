#include "World.h"
#include "Cam.h"
#include "ImageLoader.h"
#include "Player.h"
#include "LevelManager.h"
#include "Shop.h"

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
	* @author 
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
	* @author
	*
	* @brief Displays Level
	*
	*
	*
	* @return void
	*/

	void DisplayLevel();

	/**
	* @author
	*
	* @brief Display Level Number
	*
	*
	*
	* @return void
	*/
	void DisplayLevelNumber();

	/**
	* @author
	*
	* @brief Display Number of coins Collection
	*
	*
	*
	* @return void
	*/
	void DisplayCoinsShop();
	void DisplayCoinsCollected();

	void arrowMenu();

private:
	// camera variables
	GLfloat moveSpeed; // walking sensitivity
	GLfloat rotateSpeed; // mouse sensitivity

	GLfloat prevTime; // used for animation
	bool leftclickedMouse;
	bool rightclickedMouse;

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

	Shop shop;
	bool inShop = false;
	int xCounter = 1;
	int yCounter = 1;

	int width, height;

	bool DisplayExit;
	bool DisplayMenu;
	bool startRun;
	bool paused = true;

	bool down = false;
	bool up = false;

	std::string menuOption = "MENU";
};

