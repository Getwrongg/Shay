#pragma once
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <IL/il.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//for gif?? https://stackoverflow.com/questions/49385200/loading-gif-with-devil-c
//http://openil.sourceforge.net/docs/DevIL%20Manual.pdf



	/**
	* @class JpegLoader
	* @brief  Used to load in .jpg images to use as textures.
	*
	*
	* @author ClickBait Inc - Mostly Shane Martinez, some Manu Murray
	* @version 01
	* @date 20/08/2018 // date is in Australian format.
	*
	* @todo
	*
	* @bug none
	*/
class ImageLoader
{
public:
	~ImageLoader();
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
	/**
	* @brief Removes textures which are loaded into GPU memory (only textures which are loaded in with this loader)
	*
	*
	*@param none
	*
	* @return void
	*/
	void UnloadAllTextures();


private:
	/**
	* @brief  Sets textureID into the map for storage
	*
	*
	*@param const string TName, const GLuint TexID
	*
	* @return void
	*/
	bool setTextureList(const std::string TName, const GLuint TexID);

	//--------------------------------------------------
	//	Variables
	//--------------------------------------------------

	std::map<std::string, GLuint> TextureList; // MAP to store type GLuint with a string as key for storage of textureIDs
	std::vector<std::string> Texture_Names; //Stores the names of all Texture names(
};