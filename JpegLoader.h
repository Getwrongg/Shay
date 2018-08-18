#include <stdlib.h>
#include <GL/glut.h>
#include <IL/il.h>

#pragma once

//#define DEFAULT_WIDTH 800
//#define DEFAULT_HEIGHT 800

class JpegLoader
{
public:
	void BindTexture(const char * filename);
	int LoadImage(const char * filename);
};

