#pragma once
#include "ImageLoader.h"
#include "Structs.h"


/**
* @class Cube
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
class Cube
{
public:

	/**
	* @author Christopher Gemmel
	*
	* @brief default constructor
	*
	* 
	*
	*
	*/
	Cube();

	/**
	* @author Christopher Gemmel
	*
	* @brief constructor that takes in values
	*
	* @param const GLdouble x1, const GLdouble y1, const GLdouble z1
	*
	* 
	*/
	Cube(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	/**
	* @author Christopher Gemmel
	*
	* @brief method that draws a cube to the screen
	*
	* @param const GLdouble x1, const GLdouble y1, const GLdouble z1
	*
	* @return void
	*/
	void Draw(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	/**
	* @author Christopher Gemmel
	*
	* @brief creates texture to be used in cube
	*
	* 
	*
	* @return void
	*/
	void CreateTexture();
	
private:
	ImageLoader j; // object to load in jpeg textures
	Coordinates pos; // struct that holds position of cube
};

