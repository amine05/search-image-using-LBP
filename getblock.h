#include <iostream>
#include <cv.h>
#include <fstream>
#include <highgui.h>
using namespace std;
using namespace cv;



void getblock(CvPoint2D32f p,IplImage * img,IplImage * blc){
	
	CvScalar pix,hix;
	hix.val[0]=0;int zero=0;
	for (int h=0;h<blc->height;h++)
		for (int d=0;d<blc->width;d++)
			cvSet2D(blc,h,d,hix);
	int a,b,f,e;
	a=(int)p.x;b=(int)p.y;
	e=blc->height/2;
	f=blc->width/2;
	for (int ii=a-e;ii<a+e;ii++){
		for (int jj=b-f;jj<b+f;jj++){
			if(ii>-1 && ii<128 && jj>-1 && jj<128){
			pix=cvGet2D(img,ii,jj);
			
			if (pix.val[0]>-1 && pix.val [0]<256)
				cvSet2D (blc,ii-a+e,jj-b+f,pix);
			


			}
		}}

	



}
	 
	
