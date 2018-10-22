#pragma once
#include "ImageLoader.h" 

const GLfloat rotateSpeed = 200.0f;

/**
* @class Coin
* @brief  represents a coin object
*
*
* @author ClickBait Inc - Shane Martinez
* @version 01
* @date 20/10/2018 // date is in Australian format.
*
* @todo
*
* @bug none
*/
class Coin
{
public:
	/**
	* @author
	*
	* @brief Loads in the texture for coin
	*
	*
	*
	* @return void
	*/
	void CreateTexture();

	/**
	* @author
	*
	* @brief Display coin
	*
	* @param const GLfloat x1, const GLfloat y1, const GLfloat z1
	*
	* @return void
	*/
	void DrawCoin(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	void DrawTrophy(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	/**
	* @author
	*
	* @brief Animate coin
	*
	* @param const GLfloat timeSincePrevFrame
	*
	* @return void
	*/
	void AnimateCoin(const GLfloat timeSincePrevFrame);

private:
	ImageLoader image; // image loader object used to load textures
	GLfloat rotate = 0.0f; // used to rotate the coins
};

