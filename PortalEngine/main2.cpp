#include "JpegLoader.h"

#include <iostream>

void Display2();
void MyInit();

int main2()
{
	std::cout << "Welcome to Portal World!" << std::endl;
	MyInit();

	glutDisplayFunc(Display2);
	//glutIdleFunc(Display2);


	//glutReshapeFunc(reshape);
	glutMainLoop();

	//system("PAUSE");

	return 0;
}

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

void Display2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /*clear the window to background colour specified by glClearColor(...)*/
														/* viewing transformation  */
	glLoadIdentity();
	/* sets the camera to viewer array */
	gluLookAt(	0.0, 0.5, 0.0,
				0.0, 0.5, 0,
				0.0f, 1.0f, 0.0f );

	glutSolidCube(1);

	glutSwapBuffers();
}