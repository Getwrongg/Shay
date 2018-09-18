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

void Cam::DirectionUpDown(const int dir)
{
	dirUD = dir;
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

bool Cam::CanMoveUD()
{
	if (dirUD < 0 || dirUD > 0)
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

void Cam::MoveUpDown()
{
	pos.y += dirUD * moveSpeed;
}

void Cam::Rotate(const int deltaX, const int deltaY)
{
	rotateAngle += deltaX * rotateSpeed;
	if (rotateUD > 1.7f) { //Stops camera from looking to high
		rotateUD = 1.7f;
	}
	if (rotateUD < -1.7f) { // Stops camera from looking to low
		rotateUD = -1.7f;
	}
	rotateUD -= deltaY * rotateSpeed;

	// left and right
	look.x = sin(rotateAngle);
	look.z = -cos(rotateAngle);

	// up and down
	look.y = sin(rotateUD);

	// used to allow strafing
	upVector.x = sin(rotateAngle+ (float)PI / 2.0f);
	upVector.z = -cos(rotateAngle + (float)PI / 2.0f);
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
	if (CanMoveUD())
	{
		MoveUpDown();
	}

	CallGluLookat();
}

void Cam::SetMoveSpeed(const GLfloat speed)
{
	moveSpeed = speed;
}

void Cam::SetRotateSpeed(const GLfloat speed)
{
	rotateSpeed = speed;
}

Coordinates & Cam::GetPosition()
{
	return pos;
}

void Cam::SetPosition(const GLfloat xyz[3], const GLfloat upVec[3], const GLfloat angle)
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
