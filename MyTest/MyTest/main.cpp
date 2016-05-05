#include "stdafx.h"
#include "threshold.h"
#include <iostream>

int main()
{
	IplImage *tmp = cvLoadImage("F:\\pic\\wenli.jpg");
	IplImage *src = cvCreateImage(cvSize(tmp->width / 2, tmp->height / 2), tmp->depth, 3);
	IplImage *dst = cvCreateImage(cvSize(tmp->width / 2, tmp->height / 2), tmp->depth, 1);
	cvNamedWindow("win0");
	cvNamedWindow("win1");
	int i;
	cvPyrDown(tmp, src);
	src = toGray(src);
	while (std::cin >> i) {
		if (i == 0)break;
		cvSmooth(src, dst, CV_GAUSSIAN, i, i); 
		cvShowImage("win0", src);
		cvShowImage("win1", dst);
	}z
	cvWaitKey(0);
}