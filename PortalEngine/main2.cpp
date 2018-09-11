#include "JpegLoader.h"
#include "Cam.h"
#include "Player.h"
#include "World.h"

#include <iostream>

//--------------------------------------------------
//	Global Variables					
//--------------------------------------------------

// height and width of the screen
int screenWidth, screenHeight;

// camera variables
GLdouble moveSpeed = 0.05;
GLdouble rotateSpeed = 0.005;

int deltaX = 0;
int deltaY = 0;	

// used to set camera position
GLdouble pos[] = { 0, 0, 5 };
GLdouble upVec[] = { 0, 1, 0 };
GLdouble angle = 0;

//--------------------------------------------------
//	Object Declarations					
//--------------------------------------------------
JpegLoader j;
Cam ourCam;
Player player;
World world;


//--------------------------------------------------
//	Method Prototypes					
//--------------------------------------------------
void Display2();
void MyInit();
void Resize(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void MouseMovement(int x, int y);
void ReleaseKeyboard(unsigned char key, int x, int y);
void CreateTexturesPortalWorld();

//--------------------------------------------------
//	Main Program					
//--------------------------------------------------

int main2()
{
	std::cout << "Welcome to Portal World!" << std::endl;

	MyInit();	

	glutDisplayFunc(Display2);
	glutIdleFunc(Display2);
	glutMouseFunc(NULL);
	

	glutIgnoreKeyRepeat(NULL);
	glutKeyboardUpFunc(ReleaseKeyboard);
	glutKeyboardFunc(Keyboard);

	glutPassiveMotionFunc(MouseMovement);
	ShowCursor(FALSE);

	glutReshapeFunc(Resize);
	glutSetCursor(GLUT_CURSOR_NONE); // hides cursor
	
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
	ourCam.SetRotateSpeed(rotateSpeed); // sets rotate speed of camera
	ourCam.SetPosition(pos, upVec, angle); // sets position of the camera in the world

	player.SetPosition(0, 0, 0); // sets position of the player

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
	ourCam.Update();

	glEnable(GL_TEXTURE_2D);

	//player.DrawPlayer();

	world.Ground(); ///Draws the ground with texture
	world.DrawBushes();
	world.Axis();///Draws the axis for testing
	world.Cubes();

	//glutWireCube(1.0);

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void CreateTexturesPortalWorld()
{
	player.LoadTexture("SWIRL2", "data/portalswirl.jpg");
	world.CreateTextures("SWIRL3", "data/portalswirl.jpg");
	
}

//--------------------------------------------------
//	Resize the screen without problems					
//--------------------------------------------------
void Resize(int w, int h)
{
	screenWidth = w;
	screenHeight = h;

	// prevents trying to make a window of zero width
	if (h == 0)
	{
		h = 1;
	}

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

//--------------------------------------------------
//	Keyboard Functions
//--------------------------------------------------
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		std::cout << "w is clicked" << std::endl;
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

//--------------------------------------------------
//	Mouse Functions
//--------------------------------------------------

// Manu Murray
void MouseMovement(int x, int y)
{
	// gets the difference between the current position of the mouse and the center of the screen
	deltaX = x - (screenWidth / 2);
	deltaY = y - (screenHeight / 2);

	glutWarpPointer(screenWidth / 2, screenHeight / 2); // returns the cursur to the center of the screen after each frame

	ourCam.Rotate(deltaX, deltaY); // rotates the camera
}