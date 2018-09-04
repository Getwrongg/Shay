#include "Cam.h"

Cam::Cam()
{
	// Camera Position
	pos.x = 0;
	pos.y = 5;
	pos.z = 0;

	// Look at
	look.x = 0;
	look.y = 0;
	look.z = 0;

	// Up Vector
	upVector.x = 0;
	upVector.y = 1;
	upVector.z = 0;

	moveSpeed = 0;
	rotateSpeed = 0;
	dirLR = 0;
	dirFB = 0;

	// variables for rotation
	rotateAngle = 0;
	rotateUD = 0;
	rotateVector[0] = 0;
	rotateVector[1] = 0;
	rotateVector[2] = 0;
}

void Cam::CallGluLookat()
{
	//glLoadIdentity();
	gluLookAt(	pos.x, pos.y, pos.z,
				look.x + rotateVector[0], look.y + rotateVector[1], look.z + rotateVector[2],
				upVector.x, upVector.y, upVector.z);
}

void Cam::DirectionLeftRight(const int dir)
{
	dirLR = dir;
}

void Cam::DirectionForwardBack(const int dir)
{
	dirFB = dir;
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

void Cam::MoveLeftRight()
{
	pos.x += (dirLR * moveSpeed);
	look.x += (dirLR * moveSpeed);
}

void Cam::MoveForwardBack()
{
	pos.z += (dirFB * moveSpeed);
	look.z += (dirFB * moveSpeed);
}

void Cam::Rotate(int deltaX, int deltaY)
{
	rotateAngle -= deltaX * rotateSpeed; // maybe change to +=
	rotateUD += deltaY * rotateSpeed;

	rotateVector[0] = sin(rotateAngle);
	rotateVector[2] = -cos(rotateAngle);
	rotateVector[1] = sin(rotateUD);

}

void Cam::Update()
{
	if (CanMoveLR())
	{
		MoveLeftRight();
	}
	if (CanMoveFB())
	{
		MoveForwardBack();
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

Coordinates & Cam::GetPosition()
{
	return pos;
}

void Cam::SetPosition(const GLdouble pos2[9])
{
	// looking at
	pos.x = pos2[0];
	pos.y = pos2[1];
	pos.z = pos2[2];

	// position
	look.x = pos2[3];
	look.y = pos2[4];
	look.z = pos2[5];

	// up vector
	upVector.x = pos2[6];
	upVector.y = pos2[7];
	upVector.z = pos2[8];

	CallGluLookat();
}
