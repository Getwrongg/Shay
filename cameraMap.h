//  cameraMap.h
//  Header file for the cameraMap class
//  Displays a map and welcome screen in 2D on the screen
//  
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------


#include <GL/glut.h>

//--------------------------------------------------------------------------------------

class CameraMap
{
public:
	CameraMap() {};
	virtual ~CameraMap() {};

	//----------------------------------------------------------------------------------

	// display the map
	void DisplayMap(const int & screenWidth, const int & screenHeight,
				    const GLdouble & xPos, const GLdouble & zPos,
					const GLuint & tempImage);

	// display the welcome screen
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, 
		                       const int & tempExit, const GLuint & tempImage);

	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);

private:
    // Privatised copy constructor and assignment operator
    CameraMap (const CameraMap &cam) {};
    CameraMap &operator = (const CameraMap &cam) {};
};


//--------------------------------------------------------------------------------------