#include "Cam.h"

Cam::Cam()
{
	// Camera Position
	view[0] = 0.0;
	view[1] = 0.0;
	view[2] = 5.0;

	// Look at
	view[3] = 0.0;
	view[4] = 0.0;
	view[5] = -1.0;

	// Up Vector
	view[6] = 0.0;
	view[7] = 1.0;
	view[8] = 0.0;

	moveSpeed = 0;
	rotateSpeed = 0;
	dirLR = 0;
	dirFB = 0;
	dirRotate = 0;
	rotateAngle = 0;
}

void Cam::CallGluLookat()
{
	//glLoadIdentity();
	gluLookAt(	view[0], view[1], view[2],
				view[3], view[4], view[5],
				view[6], view[7], view[8]	);
}

void Cam::DirectionLeftRight(const int dir)
{
	dirLR = dir;
}

void Cam::DirectionForwardBack(const int dir)
{
	dirFB = dir;
}

void Cam::DirectionRotateLR(const GLdouble dir)
{
	dirRotate = dir * rotateSpeed;
}

bool Cam::CanMoveLR()
{
	if (dirLR < 0 || dirLR > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cam::CanMoveFB()
{
	if (dirFB < 0 || dirFB > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cam::CanRotateLR()
{
	if (dirRotate/rotateSpeed < 0 || dirRotate/rotateSpeed > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Cam::MoveLeftRight()
{
	view[0] += (dirLR * moveSpeed);
	view[3] += (dirLR * moveSpeed);
}

void Cam::MoveForwardBack()
{
	view[2] += (dirFB * moveSpeed);
	view[5] += (dirFB * moveSpeed);
}

void Cam::RotateLR()
{
	rotateAngle += dirRotate;

	view[3] = sin(rotateAngle);
	view[5] = -cos(rotateAngle);

	view[6] = sin(rotateAngle + (float)PI / 2.0);
	view[8] = -cos(rotateAngle + (float)PI / 2.0);
}

void Cam::UpdateCamera()
{
	if (CanMoveLR())
	{
		MoveLeftRight();
	}
	if (CanMoveFB())
	{
		MoveForwardBack();
	}
	if (CanRotateLR())
	{
		RotateLR();
	}

	CallGluLookat();
}

void Cam::SetMoveSpeed(const GLdouble speed)
{
	moveSpeed = speed;
}

void Cam::SetRotateSpeed(const GLdouble speed)
{
	rotateSpeed = speed;
}

GLdouble * Cam::GetPosition()
{
	GLdouble pos[] = { view[3], view[4], view[5] };

	return pos;
}

void Cam::SetPosition(const GLdouble pos[9])
{
	// looking at
	view[0] = pos[0];
	view[1] = pos[1];
	view[2] = pos[2];

	// position
	view[3] = pos[3];
	view[4] = pos[4];
	view[5] = pos[5];

	// up vector
	view[6] = pos[6];
	view[7] = pos[7];
	view[8] = pos[8];

	CallGluLookat();
}
