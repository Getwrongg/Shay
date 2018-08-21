#include "JpegLoader.h"

//int width = DEFAULT_WIDTH;
//int height = DEFAULT_HEIGHT;

void JpegLoader::BindTexture(const char * filename)
{
	int image;
	image = LoadImage(filename);

	/* OpenGL texture binding of the image loaded by DevIL  */

	/*Causes small memory leak and not sure if needed*/
	//GLuint texid;
	//glGenTextures(1, &texid); /* Texture name generation */   
	//glBindTexture(GL_TEXTURE_2D, texid); /* Binding of texture name */

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE, ilGetData()); /* Texture specification */

}

int JpegLoader::LoadImage(const char * filename)
{
	ILboolean success;
	ILuint image;

	ilGenImages(1, &image); // Generation of one image name
	success = ilLoadImage(filename); // Loading of the image by DevIL

	if (success)
	{
		success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
		if (!success)
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	return image;
}