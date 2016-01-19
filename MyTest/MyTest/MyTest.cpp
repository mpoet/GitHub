// MyTest.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include "highgui.h"
#include "cv.h"
#include <iostream>

CvCapture *cap = NULL;
int g_slider_position = 0;
IplImage *frame;
void play(CvCapture *);
void onTracBarSlide(int);

int main()
{
	CvCapture *cap = cvCreateFileCapture("G:\\KwSingMV\\myx.avi");
	cvNamedWindow("mycap");
	int frames = (int)cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_COUNT);
	std::cout << frames << std::endl;
	if (frames != 0) {
		cvCreateTrackbar("position", "mycap", &g_slider_position, frames, onTracBarSlide);
	}
	play(cap);
	cvReleaseCapture(&cap);
	cvDestroyWindow("mycap");
}

void onTracBarSlide(int pos) {
	cvSetCaptureProperty(cap, CV_CAP_PROP_POS_FRAMES, pos);
	std::cout << cvGetCaptureProperty(cap, CV_CAP_PROP_POS_FRAMES) << std::endl;
}


void play(CvCapture *cap) {
	while (1) {
		frame = cvQueryFrame(cap);
		if (!frame) {
			break;
		}
		cvShowImage("mycap", frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
}