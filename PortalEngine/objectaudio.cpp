#include "objectaudio.h"

double objectaudio::FindDistance(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double objectaudio::FindDistance(GLdouble x1, GLdouble x2) {
	return sqrt(pow(x2 - x1, 2));
}

int objectaudio::FindVolume(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble startDis)
{
	int volume=0;
	double change;

	double distance = FindDistance(x1, y1, x2, y2);
	
	if (distance < startDis) {
		change=distance-startDis;
		change = (change / startDis);
		if (change < 0) {
			change = -change;
		}
		change = change * 128;
		volume = (int)change;
	}
	return volume;
}
