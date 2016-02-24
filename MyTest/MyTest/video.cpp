#include "stdafx.h"
#include "video.h"

CvCapture * loadVideo(char *path) {
	CvCapture * cap = cvCreateFileCapture(path);
	return cap;
}

IplImage *cvtColor(IplImage * pic) {
	IplImage *tmp = cvCreateImage(cvGetSize(pic), IPL_DEPTH_8U, 1);
	IplImage *tmp_3c = cvCreateImage(cvGetSize(pic), IPL_DEPTH_8U, 3);
	cvCvtColor(pic, tmp,CV_RGB2GRAY);
	cvCvtColor(tmp, tmp_3c, CV_GRAY2RGB);
	return tmp_3c;
}

IplImage *doCanny(IplImage *pic) {
	IplImage *tmp = cvCreateImage(cvGetSize(pic), IPL_DEPTH_8U, 1);
	IplImage *tmp_3c = cvCreateImage(cvGetSize(pic), IPL_DEPTH_8U, 3);
	cvCanny(pic, tmp, 10, 100);
	cvCvtColor(tmp, tmp_3c, CV_GRAY2RGB);
	cvPutText(tmp_3c, "HI", cvPoint(10, 100), &cvFont(CV_FONT_HERSHEY_COMPLEX, 1), cvScalar(255, 0, 0));
	return tmp_3c;
}

IplImage * showImage(IplImage *pic1, IplImage *pic2, IplImage *pic3,char * winname) {
	int width = pic1->width+pic2->width+pic3->width;
	int height = pic1->height;
	IplImage * tmp = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	cvSetImageROI(tmp, cvRect(0, 0, pic1->width, pic1->height));
	cvCopy(pic1, tmp);
	cvResetImageROI(tmp);
	cvSetImageROI(tmp, cvRect(pic1->width,0,pic1->width, pic1->height));
	cvCopy(pic2, tmp);
	cvResetImageROI(tmp);
	cvSetImageROI(tmp, cvRect(pic1->width+pic2->width, 0, pic1->width, pic1->height));
	cvCopy(pic3, tmp);
	cvResetImageROI(tmp);
	cvShowImage(winname,tmp);
	return tmp;
}