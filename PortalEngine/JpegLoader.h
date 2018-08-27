#pragma once

#include <stdlib.h>
#include <GL/glut.h>
#include <IL/il.h>
#include <iostream>
#include <map>
#include <string>

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
	* @brief  Creates and binds a texture and creates a textureID for the imputed texture
	*
	*
	*
	*@param const string textureName, const char * filename
	*
	* @return void
	*/
	void CreateTexture(const std::string textureName, const char * filename);

	/**
	* @brief  Gets textureID from the map for use
	*
	*
	*@param const string TName
	*
	* @return void
	*/
	const GLuint getTextureID(const std::string TName) const;


private:
	/**
	* @brief  Sets textureID into the map for storage
	*
	*
	*@param const string TName, const GLuint TexID
	*
	* @return void
	*/
	void setTextureList(const std::string TName, const GLuint TexID);

	//--------------------------------------------------
	//	Variables
	//--------------------------------------------------

	std::map<std::string, GLuint> TextureList; // MAP to store type GLuint with a string as key for storage of textureIDs
};