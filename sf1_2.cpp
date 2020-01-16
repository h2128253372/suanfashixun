#include <stdio.h>
#include <stdlib.h>
int Afind(int a[],size_t len,int key)
{
	int left=0,right=len;
	while(left<right)
	{
		int p=left+(right-left)/2;
		if(a[p]==key) 
			return p+1;
		if(a[p]>key)
			right=p;
		else
			left=p+1;
	}
}

int main()
{
	int a[10]={};
	printf("此数组的值为："); 
	for(int i=0;i<10;i++)
	{
		a[i]=i+10;
		printf("%-5d",a[i]);
	}
	printf("\n");
	printf("所要查找的元素值位置为：%d\n",Afind(a,10,17));
}
