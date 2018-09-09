#pragma once

#include <GL/glut.h>
#include <math.h>

#include "Structs.h"

#define PI 3.1415962654 // probs not needed

/**
* @class Cam
* @brief  used to represent a camera object
*
*
* @author ClickBait Inc - Manu Murray
* @version 01
* @date 27/08/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class Cam
{
public:
	/**
	* @brief Default constructor
	*
	* Sets default values to private variables
	*
	*/
	Cam();

	/**
	* @brief  sets either left or right direction for movement
	*
	*
	*@param const int dir
	*
	* @return void
	*/
	void DirectionLeftRight(const int dir);

	/**
	* @brief  sets either forward or backwards direction for movement
	*
	*
	*@param const int dir
	*
	* @return void
	*/
	void DirectionForwardBack(const int dir);

	/**
	* @brief  sets either up or down direction for movement
	*
	*
	*@param const int dir
	*
	* @return void
	*/
	void DirectionUpDown(const int dir);

	/**
	* @brief Rotates the camera LR and UP
	*
	* using the mouse input xy
	*
	* @param const int deltaX, const int deltaY
	*
	* @return void
	*/
	void Rotate(const int deltaX, const int deltaY);

	/**
	* @brief updates the position of the camera
	*
	* calls CallGluLookAt() - should be called in display
	*
	*
	* @return void
	*/
	void Update();

	//--------------------------------------------------
	//	Setters
	//--------------------------------------------------
	void SetMoveSpeed(const GLdouble speed);
	void SetRotateSpeed(const GLdouble speed);
	void SetPosition(const GLdouble xyz[3], const GLdouble upVec[3], const GLdouble angle);

	//--------------------------------------------------
	//	Getters
	//--------------------------------------------------
	Coordinates & GetPosition();
	
private:

	/**
	* @brief moves the camera left or right
	*
	* depending on DirectionLeftRight
	*
	*
	* @return void
	*/
	void MoveLeftRight();

	/**
	* @brief moves the camera forwards or backwards
	*
	* depending on DirectionForwardBack
	*
	*
	* @return void
	*/
	void MoveForwardBack();

	/**
	* @brief moves the camera up or down
	*
	* depending on DirectionUpDown
	*
	*
	* @return void
	*/
	void MoveUpDown();
	
	/**
	* @brief asks if the camera can move left or right
	*
	* returns true if dirLR is !0
	*
	*
	* @return bool
	*/
	bool CanMoveLR();

	/**
	* @brief asks if the camera can move forwards or backwards
	*
	* returns true if dirFB is !0
	*
	*
	* @return bool
	*/
	bool CanMoveFB();

	/**
	* @brief asks if the camera can move up or down
	*
	* returns true if dirUD is !0
	*
	*
	* @return bool
	*/
	bool CanMoveUD();

	/**
	* @brief calls function gluLookAt()
	*
	* 
	*
	*
	* @return void
	*/
	void CallGluLookat();

	//--------------------------------------------------
	//	Variables
	//--------------------------------------------------

	Coordinates pos; // position of the camera
	Coordinates look; // used for mouse movement
	Coordinates upVector; // used for strafing

	int dirLR, dirFB, dirUD; // direction either 1 or -1

	GLdouble rotateAngle;
	GLdouble rotateUD;

	GLdouble moveSpeed; // speed of camera movement
	GLdouble rotateSpeed; // speed of camera rotation
};
