#pragma once
#include "JpegLoader.h"
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
	Cube();
	Cube(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	~Cube();
	void Draw(const GLdouble x1, const GLdouble y1, const GLdouble z1);
	void CreateTexture();
	
private:
	JpegLoader j;
	Coordinates pos;
};

