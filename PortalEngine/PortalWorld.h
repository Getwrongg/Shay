#include "World.h"
#include "Cam.h"
#include "JpegLoader.h"

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

	void Mouse(int button, int state, int x, int y);

	void DisplayExitScreen();

private:
	// camera variables
	GLdouble moveSpeed; // walking sensitivity
	GLdouble rotateSpeed; // mouse sensitivity

	int deltaX, deltaY; // the rotation variables for mouse x and y

	// position of the camera
	GLdouble pos[3];
	GLdouble upVec[3];
	GLdouble angle;

	// objects for portal world
	Cam ourCam;
	World world;
	JpegLoader pic;

	int width, height;

	bool DisplayExit;
};

