#include <stdlib.h>
#include <GL/glut.h>
#include <IL/il.h>

#pragma once

	/**
	* @class JpegLoader
	* @brief  Used to load in .jpg images to use as textures.
	*
	*
	* @author ClickBait Inc
	* @version 01
	* @date 20/08/2018 // date is in Australian format.
	*
	* @todo
	*
	* @bug Program has no bugs.
	*/
class JpegLoader
{
public:
		/**
		* @brief  Binds image to texture
		*
		* reads in image by calling LoadImage() then binds that image to a texture to use with opengl.
		*
		*@param const char * filename
		*
		* @return void
		*/
	void BindTexture(const char * filename);

		/**
		* @brief  Load jpeg image
		*
		* reads a jpeg image from file and returns it.
		*
		*@param const char * filename
		*
		* @return int image
		*/
	int LoadImage(const char * filename);
};

