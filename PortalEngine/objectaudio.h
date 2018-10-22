#pragma once
#include <GL/glut.h>
#include <math.h>
#include "audio.h"

/**
* @class objectaudio
* @brief manages distance and volume between player and audio
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 03/09/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class objectaudio
{
public:

	/**
	* @author Shane Martinez
	*
	* @brief finds distance between player and audio
	*
	* @param GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2
	*
	* @return double distance
	*/
	static double FindDistance(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);

	/**
	* @author Shane Martinez
	*
	* @brief finds distance between player and audio
	*
	* @param GLdouble x1, GLdouble x2
	*
	* @return double distance
	*/
	static double FindDistance(GLdouble x1, GLdouble x2);

	/**
	* @author Shane Martinez
	*
	* @brief finds the volume of the audio
	*
	* @param GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble startDis
	*
	* @return int volume
	*/
	static int FindVolume(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble startDis);//x1, y1 player coordinates, x2, y2 location of where sound is to play from, startDis distance when audio should start

};