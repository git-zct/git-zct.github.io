#include<stdio.h>
void fun(int *a,int len){
	int i=0,j=0;
	int temp;
	for(i=0;i<=len;i+=2){
		for(j=0;j<=len-2-i;j+=2){
			if(a[j]>a[j+2]){
				temp=a[j];
				a[j]=a[j+2];
				a[j+2]=temp;
			}
		}
	}
}
int main()
{
	int a[10]={3,7,6,5,2,8,1,4,9,10};//3 6 2 1 9
	fun(a,9);
	int i=0;
	for(;i<10;i+=2){
		printf("%d ",a[i]);
	}
	
} 
