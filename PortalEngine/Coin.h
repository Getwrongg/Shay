#pragma once
#include "ImageLoader.h" 

const GLfloat rotateSpeed = 400.0f;

class Coin
{
public:
	void CreateTexture();

	void DrawCoin(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	void AnimateCoin(const GLfloat timeSincePrevFrame);

private:
	ImageLoader image;
	GLfloat rotate = 0.0f;
};

