// MyTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include <iostream>

void myMouseCallback(int, int, int, int, void *);
CvRect box;
bool drawing_box = false;
void draw_box(IplImage *img, CvRect rect)
{
	cvRectangle(img, cvPoint(rect.x, rect.y), cvPoint(rect.x + rect.width, rect.y + rect.height), cvScalar(255, 0, 0));
}

int main() {
	box = cvRect(-1, -1, 0, 0);
	IplImage *pic = cvLoadImage("F:\\pic\\123.jpg");
	IplImage *tmp = cvCloneImage(pic);
	cvNamedWindow("Win0");
	cvSetMouseCallback("Win0", myMouseCallback, (void *)pic);
	while (true) {
		cvCopy(pic, tmp);
		if (drawing_box) draw_box(tmp, box);
		cvShowImage("Win0", tmp);
		if (cvWaitKey(15) == 27) {
			break;
		}
	}
	cvReleaseImage(&pic);
	cvReleaseImage(&tmp);
	cvDestroyAllWindows();
}

void myMouseCallback(int event, int x, int y, int flag, void * param)
{
	IplImage *image = (IplImage *)param;
	switch (event) {
	case CV_EVENT_MOUSEMOVE:
	{
		if (drawing_box) {
			box.width = x - box.x;
			box.height = y - box.y;
		}
	}break;
	case CV_EVENT_LBUTTONDOWN:
	{
		drawing_box = true;
		box = cvRect(x, y, 0, 0);
	}break;
	case CV_EVENT_LBUTTONUP:
	{
		drawing_box = false;
		//if (box.width < 0) {
		//	box.x = box.width;
		//	box.width *= -1;
		//}
		//if (box.height < 0) {
		//	box.y = box.height;
		//	box.height *= -1;
		//}
		draw_box(image, box);
	}break;
	}
}
