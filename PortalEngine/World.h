#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

#include "Structs.h"
#include "Cube.h"
#include "ImageLoader.h"
#include "LevelLoader.h"

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
	* @brief default constructor
	*
	*
	*
	*
	*/
	World();

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
	* @brief draws the ground
	*
	*
	*
	* @return void
	*/
	void Ground();

	/**
	* @author Christopher Gemmell
	*
	* @brief draws the pillars out of cubes
	*
	*
	*
	* @return void
	*/
	void DrawLevel();

	void Track1();

	/**
	* @author Christopher Gemmell
	*
	* @brief draws an xyz axis
	*
	*
	*
	* @return void
	*/
	void Axis();

	/**
	* @author Christopher Gemmell
	*
	* @brief create the bushes
	*
	* @param const GLfloat x1, const GLfloat y1, const GLfloat z1
	*
	* @return void
	*/
	void Bushes(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	/**
	* @author Christopher Gemmell
	*
	* @brief draws the bushes
	*
	*
	*
	* @return void
	*/
	void DrawBushes();

	/**
	* @author Shane Martinez
	*
	* @brief performs animations in portal world
	*
	*
	*
	* @return void
	*/
	void AnimatePortalWorld();

	/**
	* @author Christopher Gemmell
	*
	* @brief draws a skybox/cylinder
	*
	*
	*
	* @return void
	*/
	void SkyCylinder();

private:
	ImageLoader j; // object to load images
	Cube cube; // object of type cube - draws cubes for pillars

	LevelLoader levelloader; //loads the level from a file

	// variables for skyCylinder rotation
	float rotates = 1.0f;
	float rotateSPEED = 0.2f;
};

