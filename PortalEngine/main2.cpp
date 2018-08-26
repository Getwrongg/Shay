#include "JpegLoader.h"
#include "Cam.h"

#include <iostream>

//--------------------------------------------------
//	Global Variables					
//--------------------------------------------------
GLdouble moveSpeed = 0.3;

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
void keyboard(unsigned char key, int x, int y);
void CreateTexturesPortalWorld();
void DrawSwirl();

//--------------------------------------------------
//	Main Program					
//--------------------------------------------------

int main2()
{
	std::cout << "Welcome to Portal World!" << std::endl;

	MyInit();

	glutKeyboardFunc(keyboard);
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
	// initialises up DevIL library
	ilInit();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 1, 1, 0); /* draw on light blue background */
	glColor3f(0.5, 0.0, 0.5);
	glLineWidth(5.0);

	/* switch matrix mode to 'projection' and load an identity matrix as the projection matrix */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble fov = 60.0;
	GLdouble aspect = 1.0;
	GLdouble zNear = 0.1;
	GLdouble zFar = 100.0;

	gluPerspective(fov, aspect, zNear, zFar);

	/* switch matrix mode back to 'model view'*/
	glMatrixMode(GL_MODELVIEW);

	CreateTexturesPortalWorld();
}

//--------------------------------------------------
//	Main Display Function
//--------------------------------------------------
void Display2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /*clear the window to background colour specified by glClearColor(...)*/
														/* viewing transformation  */
	glLoadIdentity();
	// sets glLookAt to camera coordinates
	ourCam.CallGluLookat();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(0, 0, 5);
	DrawSwirl();

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
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		ourCam.MoveForwardBack(moveSpeed);
		break;
	case 's':
		ourCam.MoveForwardBack(-moveSpeed);
		break;
	case 'a':
		ourCam.MoveLeftRight(moveSpeed);
		break;
	case 'd':
		ourCam.MoveLeftRight(-moveSpeed);
		break;
	case 'q':
		exit(0);
	}
}