#include <iostream>

#include <fstream>
#include <highgui.h>
#include <math.h>
#define nbpoint 20
using namespace std;
using namespace cv;
double comp(int  *a,int *b){
int p,g,h,l;
 double som,max,x;som=0;
  int *c=new int[256*nbpoint];
for(int t=0; t<nbpoint*256;t++)
  c[t]=a[t];
 
for (int i=0;i<nbpoint ;i++){
	p=0;
	for(int k=0;k<nbpoint ;k++){
		g=l=h=0;
	    if(c[k*256]!=-1){ // 1st if
			for (int j=0;j<256;j++){
			g+=b[i*256+j]*c[k*256+j];
	        l+=b[i*256+j]*b[i*256+j];
	        h+=c[k*256+j]*c[k*256+j];
			
			}//end j
	   x=(float) g/(sqrt(double (l))*sqrt(double (h)));
	   if (k==0)
		   max=x;
	   else {
		   if (max<x){max=x;p=k; }
		   	   }//end else
	   		}//end 1st if
	} // end of k
		som+=max;
	c[p*256]=-1;
}
return som;
}
