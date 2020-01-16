#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 51
int n=5;
double W=100;                                                                     //W限重 
struct NodeType
{
	double w;                                                                     //记录每个物品的重量 
	double v;                                                                     //记录每个物品所对应的价值 
	double p;                                                                     //p=v/w 
	bool operator<(const NodeType &s) const
	{
		return p>s.p;                                                              //按p递减排序 
	}
};
NodeType A[]={{0},{10,20},{20,30},{30,60},{40,40},{50,60}};                 //A为一个数组，记录每个不同物体及其所对应的价值，下标为0的元素不用 
double V;                                                                     //V为最大价值 
double x[MAXN];
void Knap()            															//求解背包问题并返回总价值 
{     
	V=0;                														//最大价值V初始化为0 
	double weight=W;      														//背包能装入的余下重量 
	memset(x,0,sizeof(x));       												//初始化x向量 
	int i=1;
	while(A[i].w<weight)        												//物品i能够全部装入时进行的循环 
	{
		x[i]=1;             													//装入物品i 
		weight-=A[i].w;       													//减少背包中能装入的余下重量 
		V+=A[i].v;                												//累计总价值 
		i++;                 													 //继续进行循环 
	} 
	if(weight>0)                 												//当余下重量大于0时执行此if语句 
	{
		x[i]=weight/A[i].w;       												 //将物品i的一部分装入 
		V+=x[i]*A[i].v;                         								//累计总价值 
	}
}

void dispA()              														//此函数用于输出A   
{
	int i;
	printf("\tW\tV\tV\tW/\n");
	for(i=1;i<=n;i++)
		printf("\t%g\t%g\t%3.lf\n",A[i].w,A[i].v,A[i].p);
}

int main()
{
	printf("求解过程\n");
	for(int i=1;i<=n;i++)            											//此for循环用来求v/w 
		A[i].p=A[i].v/A[i].w;
	printf("(1)排序前\n");dispA();        										//打印排序前的物品、价值及其关系表 
	sort(A+1,A+n+1);
	printf("(2)排序后\n");dispA();                     							//打印排序前的物品、价值及其关系表  
	Knap();           															//通过此函数求解背包问题并返回总价值后 ，得到排序的结果
	printf("(3)求解结果\n");               										// 输出结果 
	printf("x:[");
	for(int j=1;j<=n;j++)
		printf("%g,",x[j]);
	printf("%g]\n",x[n]);
	printf("总价值=%g\n",V);
}
