#include "stdafx.h"
#include "video.h"
#include <iostream>

int main()
{
	

	while (true) {
		frame = cvQueryFrame(video);
		if (frame == NULL) {
			break;
		}

		cvResize(frame, tmp);




		if (cvWaitKey(0) == 27) {
			break;
		}
	}
}