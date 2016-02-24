#pragma once
#include "highgui.h"
#include "cv.h"

CvCapture * loadVideo(char *path);

IplImage *cvtColor(IplImage * pic);

IplImage *doCanny(IplImage *pic);

IplImage * showImage(IplImage *pic1, IplImage *pic2, IplImage *pic3,char * winname);