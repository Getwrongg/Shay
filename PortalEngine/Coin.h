#pragma once
#include "ImageLoader.h" 

const GLfloat rotateSpeed = 200.0f;

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
	ImageLoader image;
	GLfloat rotate = 0.0f;
};

