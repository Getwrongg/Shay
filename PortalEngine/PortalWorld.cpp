#include "PortalWorld.h"

PortalWorld::PortalWorld()
{
	// move and rotate mouse sensitivity
	moveSpeed = 0.05;
	rotateSpeed = 0.005;
	
	// rotation values for camera
	deltaX = 0;
	deltaY = 0;

	// sets the angle the camera faces
	angle = 0;

	// position of camera
	pos[0] = 0.0;
	pos[1] = 0.0;
	pos[2] = 5.0;

	// upvector of camera
	upVec[0] = 0.0;
	upVec[1] = 1.0;
	upVec[2] = 0.0;

	// screen width and height
	width = 1280;
	height = 720;
}

void PortalWorld::MyInit()
{
	// initialises DevIL library
	ilInit();

	// initalises glew
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 1, 1, 0);
	glColor3f(0.5, 0.0, 0.5);
	glLineWidth(5.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat fov = 45.0f;
	GLfloat aspect = 1.0f * width/height;
	GLfloat zNear = 0.1f;
	GLfloat zFar = 1000.0f;

	gluPerspective(fov, aspect, zNear, zFar);

	glMatrixMode(GL_MODELVIEW);

	CreateTexturesPortalWorld();

	ourCam.SetMoveSpeed(moveSpeed); // sets movement speed of camera
	ourCam.SetRotateSpeed(rotateSpeed); // sets rotate speed of camera
	ourCam.SetPosition(pos, upVec, angle); // sets position of the camera in the world
}

void PortalWorld::Display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// updates camera position
	ourCam.Update();

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();

	world.SkyCylinder();
	world.Axis();//Draws the axis for testing
	world.Cubes();

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void PortalWorld::AnimatePortalWorld()
{
	world.AnimatePortalWorld();
}

void PortalWorld::CreateTexturesPortalWorld()
{
	world.CreateTextures("SWIRL3", "data/portalswirl.jpg");
}

void PortalWorld::MouseMovement(int x, int y)
{
	// gets the difference between the current position of the mouse and the center of the screen
	deltaX = x - (width / 2);
	deltaY = y - (height / 2);

	glutWarpPointer(width / 2, height / 2); // returns the cursur to the center of the screen after each frame

	ourCam.Rotate(deltaX, deltaY); // rotates the camera
}

void PortalWorld::Resize(int w, int h)
{
	width = w;
	height = h;

	// prevents trying to make a window of zero width
	if (h == 0)
	{
		h = 1;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	GLfloat fov = 45.0f;
	GLfloat aspect = 1.0f * width / height;
	GLfloat zNear = 0.1f;
	GLfloat zFar = 1000.0f;

	gluPerspective(fov, aspect, zNear, zFar);

	glMatrixMode(GL_MODELVIEW);
}

void PortalWorld::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		ourCam.DirectionForwardBack(1);
		break;
	case 's':
		ourCam.DirectionForwardBack(-1);
		break;
	case 'a':
		ourCam.DirectionLeftRight(-1);
		break;
	case 'd':
		ourCam.DirectionLeftRight(1);
		break;
	case 'q':
		exit(0);
	}
}

void PortalWorld::ReleaseKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 's':
		ourCam.DirectionForwardBack(0);
		break;
	case 'a':
	case 'd':
		ourCam.DirectionLeftRight(0);
		break;
	}
}


