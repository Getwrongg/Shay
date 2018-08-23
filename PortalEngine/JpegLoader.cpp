#include "JpegLoader.h"

GLuint JpegLoader::CreateTexture(const char * filename){

	ILuint image;
	GLuint textureID;

	ilGenImages(1, &image); // Generation of one image name
	ilBindImage(image);
	ilLoadImage(filename); // Loading of the image by DevIL
	
	int const width = ilGetInteger(IL_IMAGE_WIDTH);
	int const height = ilGetInteger(IL_IMAGE_HEIGHT);
	int const type = ilGetInteger(IL_IMAGE_TYPE);
	int const format = ilGetInteger(IL_IMAGE_FORMAT);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, type, ilGetData());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	ilDeleteImages(1, &image);

	return textureID;
}

void JpegLoader::setJPEGTexList(GLuint TexID) {
	JPEGTexList.setData(TexID);
}

GLuint JpegLoader::getJPEGTexList(const int ID) {
	return JPEGTexList.getData(ID);
}



