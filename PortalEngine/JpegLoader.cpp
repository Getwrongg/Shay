#include "JpegLoader.h"

JpegLoader::~JpegLoader() {
	UnloadAllTextures();
}


void JpegLoader::CreateTexture(const std::string textureName, const char * filename){

	ILuint image;
	GLuint textureID;

	ilGenImages(1, &image); // Generation of one image name
	ilBindImage(image);
	try {
		if (!ilLoadImage(filename)) { // Loading of the image by DevIL
			throw "Cannot Load File ";
		}
	}catch (const char* e) {
		std::cout << e << filename << std::endl;
		}
	
	int const width = ilGetInteger(IL_IMAGE_WIDTH);
	int const height = ilGetInteger(IL_IMAGE_HEIGHT);
	int const type = ilGetInteger(IL_IMAGE_TYPE);
	int const format = ilGetInteger(IL_IMAGE_FORMAT);

	glGenTextures(1, &textureID);

	if (setTextureList(textureName, textureID)) {
		glBindTexture(GL_TEXTURE_2D, textureID);

		glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
		glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
		glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, type, ilGetData());
		glGenerateTextureMipmap(textureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		ilDeleteImages(1, &image);
		Texture_Names.push_back(textureName);
	}
	else {
		return;
	}
}

bool JpegLoader::setTextureList(const std::string TName, const  GLuint TexID) {
	if (TextureList.find(TName)->first == TName) {
		std::cout << "TEXTURE NAME \""<<TName<<"\" ALREADY EXISTS, TEXTURE NOT LOADED" << std::endl;
		return false;
	}
	else {
		TextureList[TName]=TexID;
		return true;
	}
}

const GLuint JpegLoader::getTextureID(const std::string TName) const{
	return TextureList.find(TName)->second;
}

void JpegLoader::UnloadAllTextures() {
	GLuint tempID;
	for (int i = 0; i < Texture_Names.size(); i++) {
		tempID = getTextureID(Texture_Names[i]);
		glDeleteTextures(1, &tempID);
	}
}



