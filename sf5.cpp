#include<iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 51 
int m,n;
string a,b;
int dp[MAX][MAX];
vector<char> subs;
void LCSlength()
{
	int i,j;
	for(i=0;i<=m;i++)
		dp[i][0]=0;
	for(j=0;j<=n;j++)
		dp[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}	
} 

void Buildsubs()
{
	int k=dp[m][n];
	int i=m;
	int j=n;
	while(k>0)
		if(dp[i][j]==dp[i-1][j])
			i--;
		else if(dp[i][j]==dp[i][j-1])
			j--;
		else
		{
			subs.push_back(a[i-1]);
			i--;j--;k--;
		}
}

main()
{
	a="abcbdb";
	b="acbbabdbb";
	m=a.length();
	n=b.length();
	LCSlength();
	Buildsubs();
	cout<<"求解结果"<<endl;
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"最长公共子序列：";
	vector<char>::reverse_iterator rit;
	for(rit=subs.rbegin();rit!=subs.rend();++rit)
		cout<<*rit;
	cout<<endl;
	cout<<"长度："<<dp[m][n]<<endl;
}
