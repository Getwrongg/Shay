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
GLdouble moveSpeed = 0.003;
GLdouble rotateSpeed = 0.005;
GLdouble angle = 0;

int deltaX = 0;
int deltaY = 0;
//int prevX = 0;	


// used for position of the camera
GLdouble pos[] = {	0.0, 0.0, 5.0,
					0.0, 0.0, 0.0,
					0.0, 1.0, 0.0 };

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
void MouseButton(int button, int state, int x, int y); // not used atm
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
	glutReshapeFunc(Resize);

	glutPassiveMotionFunc(MouseMovement);
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
	ourCam.SetPosition(pos, angle); // sets position of the camera in the world

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
	//player.Update();

	glEnable(GL_TEXTURE_2D);

	//DrawSwirl();
	//player.DrawPlayer();

	world.Ground(); ///Draws the ground with texture

	world.Axis();///Draws the axis for testing
	world.Cubes();

	glutWireCube(1.0);

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void CreateTexturesPortalWorld()
{
	// draw swirl
	j.CreateTexture("SWIRL", "data/portalswirl.jpg");
	player.LoadTexture("SWIRL2", "data/portalswirl.jpg");
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

	GLdouble aspect = 1.0 * (w / h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(60.0, aspect, 0.1, 100.0);

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
		ourCam.DirectionForwardBack(-1);
		break;
	case 's':
		ourCam.DirectionForwardBack(1);
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

void MouseMovement(int x, int y)
{
	deltaX = x - (screenWidth / 2);
	deltaY = y - (screenHeight / 2);
	//prevX = x;

	glutWarpPointer(screenWidth / 2, screenHeight / 2); // returns the cursur to the center of the screen after each frame

	ourCam.Rotate(deltaX, deltaY); // rotates the camera
}