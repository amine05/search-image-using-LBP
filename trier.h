#include <iostream>
void trier(double ** a,int s){
	double min ;double p;
	for(int i=0;i<s-1;i++)
		for(int j=i+1;j<s;j++)
		if (a[i][0]<a[j][0]){
			min=a[i][0];p=a[i][1];
	        a[i][0]=a[j][0];a[i][1]=a[j][1];
			a[j][0]=min;a[j][1]=p;
		}
}
