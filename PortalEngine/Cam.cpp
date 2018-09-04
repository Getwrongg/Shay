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
}

void Cam::CallGluLookat()
{
	//glLoadIdentity();
	gluLookAt(	pos.x, pos.y, pos.z,
				pos.x + look.x, pos.y + look.y, pos.z + look.z,
				0, 1, 0);
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
	pos.z += (dirLR * (upVector.z) * moveSpeed);
	pos.x += (dirLR * (upVector.x) * moveSpeed);
}

void Cam::MoveForwardBack()
{
	pos.z += (dirFB * (look.z) * moveSpeed);
	pos.x += (dirFB * (look.x) * moveSpeed);
}

void Cam::Rotate(const int deltaX, const int deltaY)
{
	rotateAngle += deltaX * rotateSpeed;
	rotateUD -= deltaY * rotateSpeed;

	// left and right
	look.x = sin(rotateAngle);
	look.z = -cos(rotateAngle);

	// up and down
	look.y = sin(rotateUD);

	// used to allow strafing
	upVector.x = sin(rotateAngle+ (float)PI / 2.0);
	upVector.z = -cos(rotateAngle + (float)PI / 2.0);


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

void Cam::SetPosition(const GLdouble xyz[3], const GLdouble upVec[3], const GLdouble angle)
{
	// position
	pos.x = xyz[0];
	pos.y = xyz[1];
	pos.z = xyz[2];

	// up vector
	upVector.x = upVec[0];
	upVector.y = upVec[1];
	upVector.z = upVec[2];

	// looking at
	rotateAngle = angle * (PI / 180);

	// left and right
	look.x = sin(rotateAngle);
	look.z = -cos(rotateAngle);

	CallGluLookat();
}
