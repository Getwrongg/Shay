#include <stdlib.h>
#include <GL/glut.h>
#include <IL/il.h>
#include "Vector.h"

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
	* @bug none
	*/
class JpegLoader
{
public:

		/**
		* @brief  Creates and binds a texture returning the texture ID
		*
		* reads in image by calling LoadImage() then binds that image to a texture to use with opengl.
		*
		*@param const char * filename
		*
		* @return void
		*/
	GLuint CreateTexture(const char * filename);

		/**
		* @brief  Sets jpeg texture into a vector for storage
		*
		* 
		*
		*@param const GLuint TexID
		*
		* @return void
		*/
	void setJPEGTexList(const GLuint TexID);

		/**
		* @brief  Gets jpeg texture from a vector for use
		*
		*
		*
		*@param const int ID
		*
		* @return const GLuint
		*/
	const GLuint getJPEGTexList(const int ID);

private:
	Vector<GLuint> JPEGTexList; // vector of type GLuint for storage of textures
};
