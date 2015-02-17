#include <cv.h>
#include <fstream>
#include <highgui.h>
#define nbpoint 20

using namespace std;
using namespace cv;

void getpoints(IplImage* imge,CvPoint2D32f *pointse){
	IplImage *copy = cvCreateImage (cvGetSize(imge),IPL_DEPTH_32F,1 );
	IplImage *eigimg=cvCloneImage (copy);
	int nbp=nbpoint;
	

	cvGoodFeaturesToTrack(imge,copy,eigimg ,pointse,&nbp ,0.05,32);
	
}
