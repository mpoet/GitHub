// MyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include <iostream>

void saturate_sv(IplImage *, int);
void drawROI(IplImage *);
void doInvert(IplImage *, IplImage *);

int main() {
	IplImage *pic = cvLoadImage("F:\\pic\\baboon.jpg");
	IplImage *grayImg = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	IplImage *fullImg = cvCreateImage(cvGetSize(pic), pic->depth, 3);

	cvShowImage("MyWin0", pic);

	cvCvtColor(pic, grayImg, CV_RGB2GRAY);
	cvNamedWindow("MyWin1");
	drawROI(grayImg);
	cvShowImage("MyWin1", grayImg);
	std::cout << pic->depth << std::endl;

	cvCvtColor(pic, fullImg,CV_RGB2BGR);
	cvFlip(fullImg,0,-1);
	//doInvert(pic, pic);
	cvNamedWindow("MyWin2");
	cvShowImage("MyWin2", fullImg);

	cvWaitKey(0);
	cvReleaseImage(&grayImg);
	cvReleaseImage(&fullImg);
	cvReleaseImage(&pic);
	cvDestroyAllWindows();
}

void saturate_sv(IplImage *in,int code)
{
	int width = in->width;
	int height = in->height;
	switch(code){
		case 1: {
			for (int y = 50; y < 200; y++) {
				uchar * ptr = (uchar *)(in->imageData + y*in->widthStep);
				for (int x = 50; x < 200; x++) {
					ptr[1 * x + 1] = ptr[1 * x + 1] + 120;
					//ptr[3 * x + 2] = ptr[3 * x + 2] + 12;
					//ptr[3 * x + 3] = ptr[3 * x + 3] + 80;
				}
			}
			break;
		}
		case 3: {
			for (int y = 50; y < 200; y++) {
				uchar * ptr = (uchar *)(in->imageData + y*in->widthStep);
				for (int x = 50; x < 200; x++) {
					ptr[3 * x + 1] = ptr[3 * x + 1] + 120;
					ptr[3 * x + 2] = ptr[3 * x + 2] + 12;
					ptr[3 * x + 3] = ptr[3 * x + 3] + 80;
				}
			}
			break;
		}
	}
	
}
void drawROI(IplImage *in)
{
	std::cout << cvCountNonZero(in) << std::endl;
	cvRectangle(in, cvPoint(50, 50), cvPoint(200, 200), cvScalar(188,0,0), 2);
	//cvSetImageROI(in, cvRect(50, 50, 150, 150));
	saturate_sv(in,1);
	//cvAddS(in, cvAvg(in), in);
	cvResetImageROI(in);
}
void doInvert(IplImage *src, IplImage *dst)
{
	int sWidth = src->width;
	int sHeight = src->height;
	CvSize sSize = cvGetSize(src);
}	