#include "stdafx.h"
#include "threshold.h"


IplImage *toGray(IplImage *src) {
	IplImage * tmp = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	cvCvtColor(src, tmp, CV_RGB2GRAY);
	return tmp;
}