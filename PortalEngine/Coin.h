#pragma once
#include "ImageLoader.h" 

const int rotateSpeed = 400;

class Coin
{
public:
	void CreateTexture();

	void DrawCoin(const GLfloat x1, const GLfloat y1, const GLfloat z1);

	void AnimateCoin(const GLfloat timeSincePrevFrame);

private:
	ImageLoader image;
	int rotate = 0;
};

