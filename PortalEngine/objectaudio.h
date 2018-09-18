#pragma once
#include <GL/glut.h>
#include <math.h>
#include "audio.h"

class objectaudio
{
public:

	static float FindDistance(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);

	static int FindVolume(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble startDis);//x1, y1 player coordinates, x2, y2 location of where sound is to play from, startDis distance when audio should start

private:

};