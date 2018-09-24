#include "ImageLoader.h"
#include <GL/glut.h>

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
class Player
{
public:
	Player();
	void DrawPlayer();
	void LoadTexture(const std::string name, const char * filePath);
	void Update();
	Coordinates & GetPosition();
	void SetPosition(const GLfloat x, const GLfloat y, const GLfloat z);
	void PointCounter(int amount);

private:
	Coordinates pos;
	GLfloat size;
	GLint slices, stacks;
	GLUquadricObj *sphere;
	std::string texName;

	// jpegloader object for textures
	ImageLoader pj;

	GLfloat gravity;

};

