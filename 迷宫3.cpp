#include<bits/stdc++.h>
using namespace std;
int num[10][10];
int w;
int min1=100;                               // 最多能走100步 
int n;
struct book{								//x代表x轴上的位置，y轴代表y轴上的运动 
	int x;
	int y;
}p[100];
void search(int n1)							//n1为当前走的步数 
{
	if(p[n1].x==n-2&&p[n1].y==n-2)			//第n1步为终点，记录到达终点的步数
	{
		if(min1>n1)
		min1=n1;
		return;
	}                                       
	if(num[p[n1].y-1][p[n1].x]==0)			//上
	{
		p[n1+1].x=p[n1].x;
		p[n1+1].y=p[n1].y-1;				//将移动的值储存到下一位数组中，以供search(n+1)使用 
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;			//完成一次搜索后将值改回来 ，否则将找不到最小值 
	}
	if(num[p[n1].y][p[n1].x+1]==0)          //下
	{
		p[n1+1].x=p[n1].x+1;
		p[n1+1].y=p[n1].y;
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;
	}
	if(num[p[n1].y+1][p[n1].x]==0)          //左
	{
		p[n1+1].x=p[n1].x;
		p[n1+1].y=p[n1].y+1;
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;
	}
	if(num[p[n1].y][p[n1].x-1]==0)          //右
	{
		p[n1+1].x=p[n1].x-1;
		p[n1+1].y=p[n1].y;
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;
	}
}
int main()
{
	int i,j;
	printf("请输入n的值："); 
	cin>>n;
	printf("请输入%d*%d的迷宫：",n,n); 
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>num[i][j];
	p[0].x=1;
	p[0].y=1;												//这里为出发点，（n-2,n-2）为终点 
	search(0);
	if(min1==100)											//如果min的值不改变，说明没有找到路劲 
	cout<<"No solution"<<endl;
	else
	cout<<min1<<endl;                                       //找到路径了，输出步数
}
