////////////////////////////////////////////////////////////////
// Draw talking face shape.
//
////////////////////////////////////////////////////////////////
//
// Written by:
//		Xiaoguang Yan
// Email:
//		xiaoguang.yan@gmail.com
// Homepage:
//		http://sites.google.com/site/xgyanhome/
// Version:
//		0.9
// Date:
//		June, 2011.
////////////////////////////////////////////////////////


#include "StdAfx.h"


#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "CLM_Lib/CLM.h"



static int orFace[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 24, 23, 22, 21, 0};
static int orEbrowL[] = {24, 23, 22, 21, 26, 25, 24};
static int orEbrowR[] = {18, 19, 20, 15, 16, 17, 18};
static int orEyeL[] = {27, 30, 29, 31, 27, 31, 29, 28, 27};
static int orEyeR[] = {34, 35, 32, 36, 34, 36, 32, 33, 34};
static int orNose[] = {37, 38, 39, 40, 46, 41, 47, 42, 43, 44, 45, 37};
static int orMouth[] = {48, 59, 58, 57, 56, 55, 54, 53, 52, 50, 49, 48, 60, 61, 62, 63, 64, 65, 48};


void DrawConnected(IplImage *image, float *pdat, int step, int *order, int cnt);

void DrawFaceShape(IplImage *image, CvMat *xy)
{

	// Draw face:
	float *pdat =xy->data.fl;
	int step = xy->step/sizeof(float);

	DrawConnected(image, pdat, step, orFace, sizeof(orFace)/sizeof(int));
	DrawConnected(image, pdat, step, orEbrowL, sizeof(orEbrowL)/sizeof(int));
	DrawConnected(image, pdat, step, orEbrowR, sizeof(orEbrowR)/sizeof(int));
	DrawConnected(image, pdat, step, orEyeL, sizeof(orEyeL)/sizeof(int));
	DrawConnected(image, pdat, step, orEyeR, sizeof(orEyeR)/sizeof(int));
	DrawConnected(image, pdat, step, orNose, sizeof(orNose)/sizeof(int));
	DrawConnected(image, pdat, step, orMouth, sizeof(orMouth)/sizeof(int));

}


void DrawConnected(IplImage *image, float *pdat, int step, int *order, int cnt)
{
	int i;

	double x0, x1, y0, y1;

	for(i=0;i<cnt-1; i++)
	{
		x0 = pdat[order[i]*2];
		y0 = pdat[order[i]*2 + 1];

		x1 = pdat[order[i+1]*2];
		y1 = pdat[order[i+1]*2+ 1];

		cvLine(image, cvPoint((int)x0, (int)y0), cvPoint((int)x1, (int)y1), CV_RGB(255, 0, 0), 1, 8);
		cvCircle(image, cvPoint((int)x0, (int)y0), 1, CV_RGB(0, 255, 0), 2, 8, 0);
		cvCircle(image, cvPoint((int)x1, (int)y1), 1, CV_RGB(0, 255, 0), 2, 8, 0);
	}

}

