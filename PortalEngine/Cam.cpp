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

void Cam::CallGluLookat()
{
	gluLookAt(	view[0], view[1], view[2],
				view[3], view[4], view[5],
				view[6], view[7], view[8]	);
}

void Cam::MoveLeftRight(const GLdouble amount)
{
	view[0] += amount;
	view[3] += amount;
}

void Cam::MoveForwardBack(const GLdouble amount)
{
	view[2] += amount;
	view[5] += amount;
}

