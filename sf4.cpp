#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20
#define MAXW 100
int n=5,W=10;
int w[MAXN]={0,2,2,6,5,4};
int v[MAXN]={0,6,3,5,4,6};
int dp[MAXN][MAXW];
int x[MAXN];
int maxv;
void Knap()
{
	int i,r;
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(r=0;r<=W;r++)
		dp[0][r]=0;
	for(i=1;i<=n;i++)
	{
		for(r=1;r<=W;r++)
			if(r<w[i])
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-w[i]]+v[i]);
	}
}

void Buildx()
{
	int i=n,r=W;
	maxv=0;
	while(i>=0)
	{
		if(dp[i][r]!=dp[i-1][r])
		{
			x[i]=1;
			maxv+=v[i];
			r=r-w[i];
		}
		else
			x[i]=0;
		i--;
	}
}

main()
{
	Knap();
	Buildx();
	printf("求解结果（最优方案）\n");
	printf("选取的物品：");
	for(int i=1;i<=n;i++)
		if(x[i]==1)
			printf("%-2d",i);
	printf("\n");
	printf("总价值=%d\n",maxv);
}





