#include "stdafx.h"
#include "video.h"
#include <iostream>

int main()
{
	CvCapture * video = loadVideo("F:\\pic\\myx.avi");
	int picwidth = cvGetCaptureProperty(video,CV_CAP_PROP_FRAME_WIDTH);
	int picheight = cvGetCaptureProperty(video, CV_CAP_PROP_FRAME_HEIGHT);
	CvSize size = cvSize(picwidth*0.5, picheight*0.5);
	IplImage *tmp_3c_1 = cvCreateImage(cvSize(picwidth, picheight), IPL_DEPTH_8U, 3);
	IplImage *tmp = cvCreateImage(size, IPL_DEPTH_8U, 3);
	IplImage *tmp_3c_2 = cvCreateImage(cvSize(picwidth, picheight), IPL_DEPTH_8U, 3);
	cvNamedWindow("win0");
	IplImage *frame;
	while (true) {
		frame = cvQueryFrame(video);
		if (frame == NULL) {
			break;
		}
		cvResize(frame, tmp);
		tmp_3c_1 = cvtColor(tmp);
		//std::cout<< tmp_1c->nChannels << std::endl;
		tmp_3c_2 = doCanny(tmp_3c_1);
		showImage(tmp, tmp_3c_1, tmp_3c_2, "win0");
		//cvShowImage("win0", tmp_1c);
		if (cvWaitKey(30) == 27) {
			break;
		}
	}
}