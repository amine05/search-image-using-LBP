#include <iostream>
#include <cv.h>
#include <fstream>
#include <highgui.h>

#define nbpoint 20
using namespace std;
using namespace cv;

int rlbp(int * mat);
void dolbp(IplImage * old,IplImage * news){
	int h= old->height;
 int w = old->width;
 
  CvScalar pix;
  CvScalar s;
int masque[3][3],vect[8];
CvScalar dx; 
	dx.val[0]=255;
	for (int c=0;c<h;c++)
		for (int d=0;d<w;d++)
			cvSet2D(news,c,d,dx);
  
 for(int i=1;i<h-1;i++){
  for(int j=1;j<w-1;j++){
 for(int k=0;k<3;k++){
    for(int p=0;p<3;p++)
    {
 pix = cvGet2D( old,i,j);
  CvScalar pix2=cvGet2D( old,i-1+k,j-1+p);
  if(pix.val[0]<= pix2.val[0])
   masque[k][p] =1;
  else
 masque[k][p]=0;
	}
 }
 vect[0]=masque[0][0];vect[1]=masque[0][1];vect[2]=masque[0][2];vect[3]=masque[1][2];vect[4]=masque[2][2];
 vect[5]=masque[2][1];vect[6]=masque[2][0];vect[7]=masque[1][0];
 
  //int LBP=masque[0][0]+masque[0][1]*2+masque[0][2]*4+masque[1][2]*8+masque[2][2]*16+masque[2][1]*32+masque[2][0]*64+masque[1][0]*128;
      
      s.val[0] = rlbp(vect);
	  cvSet2D(news,i,j,s);
  
  } }
}
int  rlbp(int *mat){
	int g,x=2;
	for(int k=1;k<7;k++){
  
	if(mat[k]==0 &&  mat[k-1]==1 && mat[k+1]==1)
		mat [k]=1;
	if(mat[k]==1 &&  mat[k-1]==0 && mat[k+1]==0)
		mat [k]=0;
	}
	g=mat[0];
	for(int k=1;k<8;k++){
		g+=mat[k]*x;x=x*2;
	}
	return g;
}
