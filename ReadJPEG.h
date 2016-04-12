/*
 * ReadJPEG.h
 *
 *  Created on: 25/11/2015
 *      Author: ubuntu
 */

#ifndef READJPEG_H_
#define READJPEG_H_


#include <stdlib.h>
#include <time.h>
#include <set>
#include <stdio.h>
//#include <stdexcept>
//#include <GL/glut.h>


#include <string>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <jpeglib.h>
#include <GL/gl.h>
#include <map>
#include <iostream>

int ReadJPEG(std::string const filename,std::vector<uint8_t> *image,int *width, int *height);

//void ReadJPEG(char *filename,unsigned char **image,int *width, int *height);


#endif /* READJPEG_H_ */
