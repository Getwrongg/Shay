#include "Cam.h"



Cam::Cam()
{
	// looking at
	view[0] = 0.0;
	view[1] = 0.0;
	view[2] = 0.0;

	// position
	view[3] = 0.0;
	view[4] = 0.0;
	view[5] = 5.0;

	// up vector
	view[6] = 0.0;
	view[7] = 1.0;
	view[8] = 0.0;
}

