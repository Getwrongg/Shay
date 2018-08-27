#include "JpegLoader.h"
#include "Cam.h"

#include <iostream>

//--------------------------------------------------
//	Global Variables					
//--------------------------------------------------

// movespeed of camera
GLdouble moveSpeed = 0.003;
GLdouble rotateSpeed = 0.005;

// used for position of the camera
GLdouble pos[] = {	0.0, 0.0, 0.0,
					0.0, 0.0, 5.0,
					0.0, 1.0, 0.0 };

//--------------------------------------------------
//	Object Declarations					
//--------------------------------------------------
JpegLoader j;
Cam ourCam;

//--------------------------------------------------
//	Method Prototypes					
//--------------------------------------------------
void Display2();
void MyInit();
void Keyboard(unsigned char key, int x, int y);
void ReleaseKeyboard(unsigned char key, int x, int y);
void CreateTexturesPortalWorld();
void DrawSwirl();

//--------------------------------------------------
//	Main Program					
//--------------------------------------------------

int main2()
{
	std::cout << "Welcome to Portal World!" << std::endl;

	MyInit();

	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(ReleaseKeyboard);
	glutDisplayFunc(Display2);
	glutIdleFunc(Display2);
	
	glutMainLoop();

	return 0;
}

//--------------------------------------------------
//	Initialize Settings
//--------------------------------------------------
void MyInit()
{
	// initialises DevIL library
	ilInit();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 1, 1, 0); 
	glColor3f(0.5, 0.0, 0.5);
	glLineWidth(5.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble fov = 60.0;
	GLdouble aspect = 1.0;
	GLdouble zNear = 0.1;
	GLdouble zFar = 100.0;

	gluPerspective(fov, aspect, zNear, zFar);

	glMatrixMode(GL_MODELVIEW);

	ourCam.SetMoveSpeed(moveSpeed); // sets movement speed of camera
	ourCam.SetPosition(pos); // sets position of the camera in the world

	CreateTexturesPortalWorld();
}

//--------------------------------------------------
//	Main Display Function
//--------------------------------------------------
void Display2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();

	// updates camera position
	ourCam.UpdateCamera();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(0, 0, 5);
	DrawSwirl();

		// shows position of the camera
	//GLdouble *pos = ourCam.GetPosition();
	//std::cout << pos[0] << "   " << pos[1] << "   " << pos[2] << std::endl;

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void CreateTexturesPortalWorld()
{
	// draw swirl
	j.CreateTexture("SWIRL", "data/portalswirl.jpg");
}

void DrawSwirl()
{
	glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));

	glBegin(GL_POLYGON);
	glTexCoord2i(0, 0); glVertex3f(-0.5, 1, 0);
	glTexCoord2i(0, 1); glVertex3f(0.5, 1, 0);
	glTexCoord2i(1, 1); glVertex3f(0.5, 0, 0);
	glTexCoord2i(1, 0); glVertex3f(-0.5, 0, 0);
	glEnd();
}

//--------------------------------------------------
//	Keyboard Functions
//--------------------------------------------------
void Keyboard(unsigned char key, int x, int y)
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
		ourCam.DirectionLeftRight(1);
		break;
	case 'd':
		ourCam.DirectionLeftRight(-1);
		break;
	case 'q':
		exit(0);
	}
}

void ReleaseKeyboard(unsigned char key, int x, int y)
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