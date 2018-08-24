#include "JpegLoader.h"

#include <iostream>

//--------------------------------------------------
//	Texture #defines					
//--------------------------------------------------
#define SWIRL 0

//--------------------------------------------------
//	Global Variables					
//--------------------------------------------------

// global variable for camera settings
GLdouble viewer[] = { 0.0, 0.0, 0.0,
					 0.0, 0.0, 5.0,
					 0.0, 1.0, 0.0 };

//--------------------------------------------------
//	Object Declarations					
//--------------------------------------------------
JpegLoader j;

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
	
	glutMainLoop();

	return 0;
}

//--------------------------------------------------
//	Initialize Settings
//--------------------------------------------------
void MyInit()
{
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
	/* sets the camera to viewer array */
	gluLookAt(	viewer[0], viewer[1], viewer[2],
				viewer[3], viewer[4], viewer[5],
				viewer[6], viewer[7], viewer[8]	);
	glEnable(GL_TEXTURE_2D);

	glTranslatef(0, 0, 5);
	DrawSwirl();

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void CreateTexturesPortalWorld()
{
	// draw swirl
	j.setJPEGTexList(j.CreateTexture("data/portalswirl.jpg"));
}

void DrawSwirl()
{
	glBindTexture(GL_TEXTURE_2D, j.getJPEGTexList(SWIRL));

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
		viewer[2] += 0.1;
		std::cout << "hello!" << std::endl;
		break;
	case 's':
		viewer[2] -= 0.1;
		break;
	case 'a':
		viewer[0] += 0.1;
		break;
	case 'd':
		viewer[0] -= 0.1;
		break;
	case 'q':
		exit(0);
	}
}