#pragma once
#include "JpegLoader.h"
#include <GL/glut.h>

#include "Structs.h"
#include "Cube.h"

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
	World();
	void CreateTextures(const std::string name, const char * filePath);
	void Ground();
	void Cubes();
	void Axis();
	void Bushes(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	void DrawBushes();
	void AnimatePortalWorld();
	void SkyCylinder();

private:
	JpegLoader j;
	Cube cube;
	float rotates = 1;
	float rotateSPEED = 1;
};

