// MyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include <iostream>

void saturate_sv(IplImage *);
void drawROI(IplImage *);
void doInvert(IplImage *, IplImage *);

int main() {
	IplImage *pic = cvLoadImage("F:\\pic\\baboon.jpg");
	IplImage *tmp = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	cvCvtColor(pic, tmp, CV_RGB2GRAY);
	cvNamedWindow("MyWin1");
	drawROI(tmp);
	cvShowImage("MyWin1", tmp);
	std::cout << pic->depth << std::endl;

	doInvert(pic, pic);
	cvNamedWindow("MyWin2");
	cvShowImage("MyWin2", pic);

	cvWaitKey(0);
	cvReleaseImage(&tmp);
	cvReleaseImage(&pic);
	cvDestroyAllWindows();
}

void saturate_sv(IplImage *in)
{
	int width = in->width;
	int height = in->height;
	for (int y = 50; y < 200; y++) {
		uchar * ptr = (uchar *)(in->imageData + y*in->widthStep);
		for (int x = 50; x < 200; x++) {
			ptr[1 * x + 1] = ptr[1 * x + 1] + 120;
			//ptr[3 * x + 2] = ptr[3 * x + 2] + 12;
			//ptr[3 * x + 3] = ptr[3 * x + 3] + 80;
		}
	}
}
void drawROI(IplImage *in)
{
	
	cvRectangle(in, cvPoint(50, 50), cvPoint(200, 200), cvScalar(188,0,0), 2);
	//cvSetImageROI(in, cvRect(50, 50, 150, 150));
	saturate_sv(in);
	//cvAddS(in, cvScalar(150,0,0), in);
	//cvResetImageROI(in);
}
void doInvert(IplImage *src, IplImage *dst)
{
	int sWidth = src->width;
	int sHeight = src->height;
	CvSize sSize = cvGetSize(src);
}