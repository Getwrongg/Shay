#include <GL/glut.h>

#include "Structs.h"
#include "JpegLoader.h"

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
class Player
{
public:
	Player();
	void DrawPlayer();
	void LoadTexture(const std::string name, const char * filePath);
	void Update();
	Coordinates & GetPosition();
	void SetPosition(const GLdouble x, const GLdouble y, const GLdouble z);

private:
	Coordinates pos;
	GLfloat size;
	GLint slices, stacks;
	GLUquadricObj *sphere;

	// jpegloader object for textures
	JpegLoader pj;

	GLdouble gravity;

};

