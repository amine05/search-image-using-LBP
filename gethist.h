#include <iostream>
#include <cv.h>
#include <fstream>
#include <highgui.h>
#include <dirent.h>
#define nbpoint 20

using namespace std;
using namespace cv;


void gethist(IplImage * img,int * hist){
	int p;
	for (int z=0;z<256;z++) hist[z]=0;

	CvScalar pix;
	for (int i=0;i<img->height;i++){
		for (int j=0;j<img->width;j++){
	
			pix=cvGet2D(img,i,j);
			p=(int)pix.val[0];
			hist[p]++;
			
		}

}
}
