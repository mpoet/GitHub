#pragma once
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include <iostream>

void myMouseCallback(int, int, int, int, void *);
void draw_box(IplImage *img, CvRect rect);
int draw();