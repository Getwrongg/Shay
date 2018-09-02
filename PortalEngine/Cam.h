#pragma once

#include <GL/glut.h>
#include <math.h>

#define PI 3.1415962654 // probs not needed

/**
* @class Cam
* @brief  used to represent a camera object
*
*
* @author ClickBait Inc
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

	void Rotest(GLdouble deltaX);

	/**
	* @brief updates the position of the camera
	*
	* calls CallGluLookAt() - should be called in display
	*
	*
	* @return void
	*/
	void UpdateCamera();

	//--------------------------------------------------
	//	Setters
	//--------------------------------------------------
	void SetMoveSpeed(const GLdouble speed);
	void SetRotateSpeed(const GLdouble speed);
	void SetPosition(const GLdouble pos[9]);

	//--------------------------------------------------
	//	Getters
	//--------------------------------------------------
	GLdouble * GetPosition();
	
private:
	
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

	GLdouble view[9]; // for gluLookAt

	int dirLR, dirFB; // direction either 1 or -1

	GLdouble rotateAngle; // probs delete
	GLdouble rotateVector[3];

	GLdouble moveSpeed; // speed of camera movement

	GLdouble rotateSpeed; // speed of camera rotation
};
