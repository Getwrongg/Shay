#include "PortalWorld.h"
std::string hello;

PortalWorld::PortalWorld()
{
	// move and rotate mouse sensitivity
	moveSpeed = 0.25f;
	rotateSpeed = 0.005f;

	// animation
	prevTime = 0.0f;
	leftclickedMouse = false;
	rightclickedMouse = false;

	// rotation values for camera
	deltaX = 0;
	deltaY = 0;

	// sets the angle the camera faces
	angle = 0;

	// position of camera
	pos[0] = -500.0f;
	pos[1] = 0.0f;
	pos[2] = 5.0f;

	// upvector of camera
	upVec[0] = 0.0f;
	upVec[1] = 1.0f;
	upVec[2] = 0.0f;

	// screen width and height
	width = 1280;
	height = 720;

	DisplayExit = false;
	DisplayMenu = false;
	startRun = false;
}

void PortalWorld::MyInit()
{
	// initialises DevIL library
	ilInit();

	// initalises glew
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);
	glColor3f(0.5, 0.0, 0.5);
	glLineWidth(5.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat fov = 45.0f;
	GLfloat aspect = 1.0f * width / height;
	GLfloat zNear = 0.1f;
	GLfloat zFar = 1000.0f;

	gluPerspective(fov, aspect, zNear, zFar);

	glMatrixMode(GL_MODELVIEW);

	CreateTexturesPortalWorld();

	//ourCam.SetMoveSpeed(moveSpeed); // sets movement speed of camera
	//ourCam.SetRotateSpeed(rotateSpeed); // sets rotate speed of camera
	ourCam.SetPosition(pos, upVec, angle); // sets position of the camera in the world 

	player.SetMoveSpeed(0.0f); // so player doesn't start until ready
	player.SetPosition(-525.0f, 0.0f, -50.0f);
}

void PortalWorld::Display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);

	if (DisplayExit == true)
	{
		DisplayExitScreen();
	}
	
	if (DisplayMenu == true)
	{
		DisplayMenuScreen();
	}
	AnimatePortalWorld();

	// only starts portal world animation if startRun is true
	if (startRun == true)
	{
		ourCam.Follow(player.GetPosition());
		paused = false;
	}
	else
	{
		//ourCam.Follow(camPos);
		ourCam.Update();
		DisplayLevelSplash(); // displays screen with controls at the start of the level
	}

	DisplayLevel();

	world.SkyCylinder();

	if (world.DrawLevel(player.GetPosition())) { // draw level and reset the player and level if they fail
		world.ResetLevel();
		player.ResetPlayer();
	}

	//world.Axis();//Draws the axis for testing
	//world.Track1();

	player.DrawPlayer();

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void PortalWorld::DisplayCoinsCollected(std::string setCoinImage)
{
	int coinCount = LevelManager().GetCoinsCollected();
	
	if (coinCount == 0)
	{
		pic.CreateTexture("ZERO", "data/UI/zero.jpg");
	}
}

void PortalWorld::AnimatePortalWorld()
{
	GLfloat currTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;     // to convert the returned time into seconds
	GLfloat timeSincePrevFrame = currTime - prevTime;	// time since previous frame

	prevTime = currTime;

	if (paused) 
	{
		timeSincePrevFrame = 0.1f;
	}

	player.Update(timeSincePrevFrame, leftclickedMouse, rightclickedMouse, startRun);

	world.AnimatePortalWorld(timeSincePrevFrame);

	glutPostRedisplay();
}

void PortalWorld::CreateTexturesPortalWorld()
{
	world.CreateTextures("SWIRL3", "data/portalswirl.jpg");

	pic.CreateTexture("EXITSCREEN", "data/facePics/exitWindow.jpg");

	pic.CreateTexture("PBAR", "data/UI/progressbar.png");

	pic.CreateTexture("LEVELONE", "data/UI/level1.jpg");

	pic.CreateTexture("COINS", "data/UI/coincount.jpg");

	pic.CreateTexture("MENU", "data/UI/menu.png");

	pic.CreateTexture("STARTLEVEL", "data/UI/levelMenu.png");

	player.LoadTexture("PLAYER", "data/portalswirl.jpg"); // default texture for player

	player.LoadSounds();

	//ALL THE COIN NUMBERS________________________________
	
	pic.CreateTexture("ONE", "data/UI/one.jpg");
	pic.CreateTexture("TWO", "data/UI/two.jpg");
	pic.CreateTexture("THREE", "data/UI/three.jpg");
	pic.CreateTexture("FOUR", "data/UI/four.jpg");
	pic.CreateTexture("FIVE", "data/UI/five.jpg");
	pic.CreateTexture("SIX", "data/UI/six.jpg");
	pic.CreateTexture("SEVEN", "data/UI/seven.jpg");
	pic.CreateTexture("EIGHT", "data/UI/eight.jpg");
	pic.CreateTexture("NINE", "data/UI/nine.jpg");
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
	case 'e':
		ourCam.DirectionUpDown(1);
		break;
	case 'r':
		ourCam.DirectionUpDown(-1);
		break;
	case 'q':
		ourCam.SetMoveSpeed(0.0f);
		ourCam.SetRotateSpeed(0.0f);
		if (DisplayExit == false)
		{			
			DisplayExit = true;
		}
		break;
	case 27:
		ourCam.SetMoveSpeed(0.0f);
		ourCam.SetRotateSpeed(0.0f);
		if (DisplayMenu == false)
		{
			DisplayMenu = true;
		}
		else if (DisplayMenu == true)
		{
			DisplayMenu = false;
		}
		break;
	case 32: // space bar to start
		player.SetMoveSpeed(25.0f); // sets movespeed to 25
		player.SetPosition(10.0f, 100.0f, 7.0f); // starting position of player
		startRun = true;
		break;
	}

	//  used for changing skin
	if (startRun == false)
	{
		player.SetPosition(-525.0f, 0.0f, -50.0f);

		switch (key)
		{
		case '1':

			player.LoadTexture("PLAYER", "data/portalswirl.jpg");
			break;
		case '2':
			player.LoadTexture("PLAYER", "data/8ball.jpg");
			break;
		case '3':
			player.LoadTexture("PLAYER", "data/stars.jpg");
			break;
		}
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
	case 'e':
		ourCam.DirectionUpDown(0);
		break;
	case 'r':
		ourCam.DirectionUpDown(0);
		break;
	case 27:
		ourCam.SetMoveSpeed(0.25f);
		ourCam.SetRotateSpeed(0.005f);
	}
}

void PortalWorld::Mouse(int button, int state, int x, int y)
{
	// exit tour if clicked on exit splash screen
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if ((DisplayExit) && (x <= width / 2.0 + 256.0) && (x >= width / 2.0 - 256.0)
			&& (y <= height / 2.0 + 256.0) && (y >= height / 2.0 - 256.0))
		{
			exit(1);
		}
		else
		{
			leftclickedMouse = true;
		}
	}

	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
		rightclickedMouse = true;
	}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
	{
		leftclickedMouse = false;
	}

	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP))
	{
		rightclickedMouse = false;
	}
}

void PortalWorld::DisplayMenuScreen()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(width / 2 - 256.0f, -height / 2 - 256.0f, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("MENU"));

	glTranslatef(-256, -100, 0);
	glScalef(2, 2, 0);

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(100, 50);
	glTexCoord2i(0, 1); glVertex2i(100, 300);
	glTexCoord2i(1, 1); glVertex2i(400, 300);
	glTexCoord2i(1, 0); glVertex2i(400, 50);
	glEnd();

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void PortalWorld::DisplayExitScreen() 
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(width / 2 - 256.0f, -height / 2 - 256.0f, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("EXITSCREEN"));

	glTranslatef(-256, -100, 0);
	glScalef(2, 2, 0);

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(100, 50);
	glTexCoord2i(0, 1); glVertex2i(100, 300);
	glTexCoord2i(1, 1); glVertex2i(400, 300);
	glTexCoord2i(1, 0); glVertex2i(400, 50);
	glEnd();

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void PortalWorld::DisplayLevelSplash()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(width / 2 - 50.0f, -height / 2 - 256.0f, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("STARTLEVEL"));

	glTranslatef(-256, -100, 0);
	glScalef(2, 2, 0);

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(100, 50);
	glTexCoord2i(0, 1); glVertex2i(100, 300);
	glTexCoord2i(1, 1); glVertex2i(400, 300);
	glTexCoord2i(1, 0); glVertex2i(400, 50);
	glEnd();

	/*glBegin(GL_QUADS);
	glVertex3f(-550, 10, -8);
	glVertex3f(-510, 10, -8);
	glVertex3f(-510, 0, -8);
	glVertex3f(-550, 0, -8);
	glEnd();*/

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void PortalWorld::DisplayLevel()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(width / 2 - 256.0f, -height / 2 - 256.0f, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-256, -100, 0);
	glScalef(2, 2, 0);
	//LEVEL NUMBER
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("ONE"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(10, 0);
	glTexCoord2i(0, 1); glVertex2i(10, 20);
	glTexCoord2i(1, 1); glVertex2i(25, 20);
	glTexCoord2i(1, 0); glVertex2i(25, 0);
	glEnd();

	//LEVEL UI
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("LEVELONE"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(-50, 0);
	glTexCoord2i(0, 1); glVertex2i(-50, 20);
	glTexCoord2i(1, 1); glVertex2i(30, 20);
	glTexCoord2i(1, 0); glVertex2i(30, 0);
	glEnd();

	//COINS UI COUNT
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("ONE"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(10, 22);
	glTexCoord2i(0, 1); glVertex2i(10, 42);
	glTexCoord2i(1, 1); glVertex2i(25, 42);
	glTexCoord2i(1, 0); glVertex2i(25, 22);
	glEnd();
	//COINS UI MANAGER
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("COINS"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(-50, 22);
	glTexCoord2i(0, 1); glVertex2i(-50, 42);
	glTexCoord2i(1, 1); glVertex2i(30, 42);
	glTexCoord2i(1, 0); glVertex2i(30, 22);
	glEnd();
	
	

	////TRACK COMPLETION BAR UI
	//glBindTexture(GL_TEXTURE_2D, pic.getTextureID("PBAR"));
	//glBegin(GL_QUADS);
	//glTexCoord2i(0, 0); glVertex2i(530, 70);
	//glTexCoord2i(0, 1); glVertex2i(530, 270);
	//glTexCoord2i(1, 1); glVertex2i(550, 270);
	//glTexCoord2i(1, 0); glVertex2i(550, 70);
	//glEnd();

	

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
