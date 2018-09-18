#pragma once
#include <GL/glut.h>
#include <math.h>
#include "audio.h"

class objectaudio
{
public:

	static float FindDistance(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);

	static int FindVolume(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble startDis);

private:

};