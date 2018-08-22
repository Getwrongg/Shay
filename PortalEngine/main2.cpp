#include "JpegLoader.h"

#include <iostream>

//--------------------------------------------------
//	Global Variables					
//--------------------------------------------------

// global variable for camera settings
GLfloat viewer[] = { 0.0, 1.0, 0.0,
					 0.0, 0.0, 5.0,
					 0.0, 1.0, 0.0 };


//--------------------------------------------------
//	Method Prototypes					
//--------------------------------------------------
void Display2();
void MyInit();
void keyboard(unsigned char key, int x, int y);

//--------------------------------------------------
//	Main Program					
//--------------------------------------------------

int main2()
{
	std::cout << "Welcome to Portal World!" << std::endl;

	MyInit();

	glutDisplayFunc(Display2);
	glutKeyboardFunc(keyboard);

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

	glTranslatef(0, 0, 5);
	glutWireCube(1);

	glutSwapBuffers();
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
	}
}