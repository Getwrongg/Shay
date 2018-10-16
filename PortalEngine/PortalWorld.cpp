#include "PortalWorld.h"

int first1 = 180;
int first2 = 200;
int first3 = 130;
int first4 = 145;

int arrowCounter = 0;
int escapeCounter = 0;

std::string menuOption = "MENU";

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

	shop.LoadSounds();
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
		glClearColor(0, 0, 0, 0);
	}
	else
	{
		//ourCam.Follow(camPos);
		ourCam.Update();
		DisplayMenuSplash(); // displays screen with controls at the start of the level
		glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	}

	DisplayLevel(); //Draw level UI


	//Draw World and reset player and world if needed
	world.DrawLevel(player.GetPosition());
	if (world.levelFailed())
	{
		world.ResetLevel();
		player.ResetPlayer();
	}
	if (world.levelComplete())
	{
		player.AddCoins(world.GetCoins());
		world.ResetLevel();
		player.ResetPlayer();
	}


	world.SkyCylinder(); //Draw Cylinder
	player.DrawPlayer(); //Draw ball

	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
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

	pic.CreateTexture("LEVEL", "data/UI/level.jpg");

	pic.CreateTexture("COINS", "data/UI/coincount.jpg");

	pic.CreateTexture("MENU", "data/UI/menu.png");

	pic.CreateTexture("SHOP", "data/UI/shopMenu.png");

	pic.CreateTexture("SKINS", "data/UI/skinsMenu.png");

	pic.CreateTexture("CONTROLSMENU", "data/UI/controlsMenu.png");

	pic.CreateTexture("MENUPOINTER", "data/UI/MenuPointer.jpg");

	pic.CreateTexture("LOCKED", "data/UI/locked.jpg");


	player.LoadTexture();
	player.LoadSounds();


	//ALL THE COIN NUMBERS________________________________
	pic.CreateTexture("ZERO", "data/UI/zero.jpg");
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

	if (startRun) {
		ourCam.Rotate(deltaX, deltaY); // rotates the camera
	}
	
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
	if (!inShop)
	{
		switch (key)
		{
		case 'i':
			ourCam.DirectionForwardBack(1);
			break;
		case 'k':
			ourCam.DirectionForwardBack(-1);
			break;
		case 'j':
			ourCam.DirectionLeftRight(-1);
			break;
		case 'l':
			ourCam.DirectionLeftRight(1);
			break;
		case 'o':
			ourCam.DirectionUpDown(1);
			break;
		case 'u':
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

		case 27: //escape button			

			if (startRun == true)
			{
				ourCam.SetPosition(pos, upVec, angle);
				ourCam.SetMoveSpeed(0.0f);
				ourCam.SetRotateSpeed(0.0f);
				startRun = false;
			}
			break;
		case 32: // space bar to start
			if (arrowCounter == 0 && !startRun)
			{
				player.SetMoveSpeed(25.0f); // sets movespeed to 25
				player.SetPosition(10.0f, 100.0f, 7.0f); // starting position of player
				startRun = true;
			}
			else if (arrowCounter == 1)
			{
				menuOption = "SKINS";

				first1 = 180 - 12;
				first2 = 200 - 12;
				first3 = 195 - 30;
				first4 = 200 - 30;

				escapeCounter++;

				inShop = true;
			}
			else if (arrowCounter == 2)
			{
				first1 = 0;
				first2 = 0;
				first3 = 0;
				first4 = 0;

				escapeCounter++;

				menuOption = "CONTROLSMENU";

			}
			else if (arrowCounter == 3)
			{
				first1 = 0;
				first2 = 0;
				first3 = 0;
				first4 = 0;

				escapeCounter++;


				DisplayExit = true;
			}

			break;
		case 'm':
			player.muteSound();
			world.muteLevel();
			shop.Mute();
			break;
		}
		if (startRun == false)
		{
			player.SetPosition(-525.0f, 0.0f, -50.0f);

			switch (key)
			{
			case 'm':
				player.muteSound();
				world.muteLevel();
				shop.Mute();
				break;
			case 's': //down key needs changing
				if (down == false)
				{
					arrowCounter++;

					if (arrowCounter > 3)
					{
						arrowCounter = 3;
					}
					else if (arrowCounter < 0)
					{								
						arrowCounter = 0;
					}

					else if (arrowCounter == 1)
					{
						first1 = 180;
						first2 = 200;
						first3 = 155;
						first4 = 170;
						arrowMenu();
					}
					else if (arrowCounter == 2)
					{
						first1 = 180;
						first2 = 200;
						first3 = 185;
						first4 = 200;
						arrowMenu();
					}
					else if (arrowCounter == 3)
					{
						first1 = 180;
						first2 = 200;
						first3 = 210;
						first4 = 225;
						arrowMenu();
					}

				}
				break;
			case 'w'://up key needs changing
				if (up == false)
				{
					arrowCounter--;

					if (arrowCounter > 3)
					{
						arrowCounter = 3;
					}
					else if (arrowCounter < 1)
					{
						
						arrowCounter = 0;
					}

					if (arrowCounter == 0)
					{
						first1 = 180;
						first2 = 200;
						first3 = 130;
						first4 = 145;
						arrowMenu();
					}
					else if (arrowCounter == 1)
					{
						first1 = 180;
						first2 = 200;
						first3 = 155;
						first4 = 170;
						arrowMenu();
					}
					else if (arrowCounter == 2)
					{
						first1 = 180;
						first2 = 200;
						first3 = 185;
						first4 = 200;
						arrowMenu();
					}
					else if (arrowCounter == 3)
					{
						first1 = 180;
						first2 = 200;
						first3 = 210;
						first4 = 225;
						arrowMenu();
					}
				}
				break;
			}
		}
	}
	else

	if(inShop)
	{
		switch (key)
		{
			case 'm':
				player.muteSound();
				world.muteLevel();
				shop.Mute();
				break;
			case 'e':
				shop.showShop(player.GetTotalCoins());
				break;
			case 'a': 
				if (xCounter <= 1)
				{
					xCounter = 1;
				}
				else
				{
					xCounter--;
				}

				switch (xCounter) {
				case 1:
					first1 = 180 - 12;
					first2 = 200 - 12;
					break;

				case 2:
					first1 = 180 + 60;
					first2 = 200 + 60;
					break;
				case 3:
					first1 = 180 + 132;
					first2 = 200 + 132;
					break;
				}
				arrowMenu();


				std::cout << "Position: " << xCounter << yCounter << std::endl;
				std::cout << std::endl;
				break;
			case 'd': 
				if (xCounter >= 3)
				{
					xCounter = 3;
				}
				else
				{
					xCounter++;
				}

				switch (xCounter) {
				case 1:
					first1 = 180 - 12;
					first2 = 200 - 12;
					break;

				case 2:
					first1 = 180 + 60;
					first2 = 200 + 60;
					break;
				case 3:
					first1 = 180 + 132;
					first2 = 200 + 132;
					break;
				}
				arrowMenu();

				std::cout << "Position: " << xCounter << yCounter << std::endl;
				std::cout << std::endl;
				break;
			case 'w': 
				if (yCounter <= 1)
				{
					yCounter = 1;
				}
				else
				{
					yCounter--;
				}

				switch (yCounter) {
				case 1:
					first3 = 195 - 30;
					first4 = 200 - 30;
					break;

				case 2:
					first3 = 195 + 35;
					first4 = 200 + 35;
					break;
				}
				arrowMenu();

				std::cout << "Position: " << xCounter << yCounter << std::endl;
				std::cout << std::endl;
				break;
			case 's':
				if (yCounter >= 2)
				{
					yCounter = 2;
				}
				else
				{
					yCounter++;
				}

				switch (yCounter) {
				case 1:
					first3 = 195 - 30;
					first4 = 200 - 30;
					break;

				case 2:
					first3 = 195 + 35;
					first4 = 200 + 35;
					break;
				}
				arrowMenu();

				std::cout << "Position: " << xCounter << yCounter << std::endl;
				std::cout << std::endl;
				break;
			case 32: //enter
				shop.SetCurrent(xCounter, yCounter);
				player.SetCoins(shop.BuySkin(player.GetTotalCoins()));
				player.SetSkin(shop.GetCurrentSkin());

				std::cout <<"CurrentSkin: "<< shop.GetCurrentSkin() << std::endl;
				std::cout << std::endl;
				break;
			case 27:

				menuOption = "MENU";
				inShop = false;
				xCounter = 1;
				yCounter = 1;
				first1 = 180;
				first2 = 200;
				first3 = 155;
				first4 = 170;
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

void PortalWorld::DisplayMenuSplash()
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
	

	glTranslatef(-256, -100, 0);
	glScalef(2, 2, 0);

	arrowMenu();

	
	if (menuOption == "SKINS") {
		DisplayLocked();
		DisplayCoinsShop();
	}
	
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID(menuOption));
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

void  PortalWorld::arrowMenu()
{


	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("MENUPOINTER"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(first1, first3);
	glTexCoord2i(0, 1); glVertex2i(first1, first4);
	glTexCoord2i(1, 1); glVertex2i(first2, first4);
	glTexCoord2i(1, 0); glVertex2i(first2, first3);
	glEnd();
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

	DisplayLevelNumber();
	DisplayCoinsCollected();

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void PortalWorld::DisplayLevelNumber()
{
	std::string levelnumber;
	switch (world.LevelNumber() + 1) // level number starts at 0 so add 1 
	{
	case 1:
		levelnumber = "ONE";
		break;
	case 2:
		levelnumber = "TWO";
		break;
	case 3:
		levelnumber = "THREE";
		break;
	case 4:
		levelnumber = "FOUR";
		break;
	case 5:
		levelnumber = "FIVE";
		break;
	case 6:
		levelnumber = "SIX";
		break;
	case 7:
		levelnumber = "SEVEN";
		break;
	case 8:
		levelnumber = "EIGHT";
		break;
	case 9:
		levelnumber = "NINE";
		break;
	default:
		levelnumber = "ZERO";
	}

	//LEVEL NUMBER
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID(levelnumber));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(10, 0);
	glTexCoord2i(0, 1); glVertex2i(10, 20);
	glTexCoord2i(1, 1); glVertex2i(25, 20);
	glTexCoord2i(1, 0); glVertex2i(25, 0);
	glEnd();

	//LEVEL UI
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID("LEVEL"));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(-50, 0);
	glTexCoord2i(0, 1); glVertex2i(-50, 20);
	glTexCoord2i(1, 1); glVertex2i(30, 20);
	glTexCoord2i(1, 0); glVertex2i(30, 0);
	glEnd();
}

void PortalWorld::DisplayLocked()
{
	int x1[3] = { 152, 225, 297 }; //coordinates for shop 
	int x2[3] = { 205, 278, 349 }; 
	int y1[2] = { 152, 215};
	int y2[2] = { 162, 225};
	int counter = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (!shop.IsUnlocked(counter)) {
				glBindTexture(GL_TEXTURE_2D, pic.getTextureID("LOCKED"));
				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(x1[j], y1[i]);
				glTexCoord2i(0, 1); glVertex2i(x1[j], y2[i]);
				glTexCoord2i(1, 1); glVertex2i(x2[j], y2[i]);
				glTexCoord2i(1, 0); glVertex2i(x2[j], y1[i]);
				glEnd();
			}
			counter++;
		}
	}
}

void PortalWorld::DisplayCoinsShop() 
{
	std::string firstNumber;
	std::string secondNumber;

	int totalCoins = player.GetTotalCoins();

	int firstNum = totalCoins / 10;
	int secondNum = totalCoins % 10;

	switch (firstNum)
	{
	case 0:
		firstNumber = "ZERO";
		break;
	case 1:
		firstNumber = "ONE";
		break;
	case 2:
		firstNumber = "TWO";
		break;
	case 3:
		firstNumber = "THREE";
		break;
	case 4:
		firstNumber = "FOUR";
		break;
	case 5:
		firstNumber = "FIVE";
		break;
	case 6:
		firstNumber = "SIX";
		break;
	case 7:
		firstNumber = "SEVEN";
		break;
	case 8:
		firstNumber = "EIGHT";
		break;
	case 9:
		firstNumber = "NINE";
		break;
	default:
		firstNumber = "ZERO";
	}

	switch (secondNum)
	{
	case 0:
		secondNumber = "ZERO";
		break;
	case 1:
		secondNumber = "ONE";
		break;
	case 2:
		secondNumber = "TWO";
		break;
	case 3:
		secondNumber = "THREE";
		break;
	case 4:
		secondNumber = "FOUR";
		break;
	case 5:
		secondNumber = "FIVE";
		break;
	case 6:
		secondNumber = "SIX";
		break;
	case 7:
		secondNumber = "SEVEN";
		break;
	case 8:
		secondNumber = "EIGHT";
		break;
	case 9:
		secondNumber = "NINE";
		break;
	default:
		secondNumber = "ZERO";
	}

	glBindTexture(GL_TEXTURE_2D, pic.getTextureID(firstNumber));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(240-13, 230+40);
	glTexCoord2i(0, 1); glVertex2i(240-13, 235+50);
	glTexCoord2i(1, 1); glVertex2i(260-9, 235+50);
	glTexCoord2i(1, 0); glVertex2i(260-9, 230+40);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, pic.getTextureID(secondNumber));
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2i(240+9, 230+40);
	glTexCoord2i(0, 1); glVertex2i(240+9, 235+50);
	glTexCoord2i(1, 1); glVertex2i(260+13, 235+50);
	glTexCoord2i(1, 0); glVertex2i(260+13, 230+40);
	glEnd();
}

void PortalWorld::DisplayCoinsCollected()
{
	std::string uiNumber;

	switch (world.GetCoins())
	{
	case 0:
		uiNumber = "ZERO";
		break;
	case 1:
		uiNumber = "ONE";
		break;
	case 2:
		uiNumber = "TWO";
		break;
	case 3:
		uiNumber = "THREE";
		break;
	case 4:
		uiNumber = "FOUR";
		break;
	case 5:
		uiNumber = "FIVE";
		break;
	case 6:
		uiNumber = "SIX";
		break;
	case 7:
		uiNumber = "SEVEN";
		break;
	case 8:
		uiNumber = "EIGHT";
		break;
	case 9:
		uiNumber = "NINE";
		break;
	default:
		uiNumber = "ZERO";
	}

	//COINS UI COUNT
	glBindTexture(GL_TEXTURE_2D, pic.getTextureID(uiNumber));
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

}
