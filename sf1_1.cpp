#include<stdio.h>
#include<stdlib.h>
int Afind(int a[],int left,int right,int key)
{
	if(left>=right)
		return -1; 
	int p=left+(right-left)/2;
	if (a[p]==key)
		return p+1;
	if(a[p]>key)
		return Afind(a,left,p,key);
	else
		return Afind(a,p+1,right,key);
}
int Bfind(int a[],size_t len,int mid)
{
	return Afind(a,0,len,mid);
}
int main()
{
	int a[10]={};
	int x;	
	printf("此数组的值为："); 
	for(int i=0;i<10;i++)
	{
	 	a[i]=i+10;
		printf("%-5d",a[i]);
	}
	printf("\n");
	printf("请输入所要查找的数值:");
	scanf("%d",&x);
	printf("所查找的值的位置在第%d位\n",Bfind(a,10,x));
}



