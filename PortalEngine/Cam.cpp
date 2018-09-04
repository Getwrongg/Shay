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
	dirLR = 0;
	dirFB = 0;

	// variables for rotation
	rotateSpeed = 0;
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
				pos.x + look.x, pos.y + look.y, pos.z + look.z,
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
}

void Cam::MoveForwardBack()
{
	pos.z += (dirFB * moveSpeed);
}

void Cam::Rotate(int deltaX, int deltaY)
{
	rotateAngle += deltaX * rotateSpeed; // maybe change to +=
	rotateUD -= deltaY * rotateSpeed;

	// left and right
	look.x = sin(rotateAngle);
	look.z = -cos(rotateAngle);

	// up and down
	look.y = sin(rotateUD);


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

void Cam::SetPosition(const GLdouble pos2[9], const GLdouble angle)
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

	rotateAngle = angle * (PI / 180);

	// left and right
	look.x = sin(rotateAngle);
	look.z = -cos(rotateAngle);

	CallGluLookat();
}
