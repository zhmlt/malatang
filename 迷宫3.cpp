#include<bits/stdc++.h>
using namespace std;
int num[10][10];
int w;
int min1=100;                               // �������100�� 
int n;
struct book{								//x����x���ϵ�λ�ã�y�����y���ϵ��˶� 
	int x;
	int y;
}p[100];
void search(int n1)							//n1Ϊ��ǰ�ߵĲ��� 
{
	if(p[n1].x==n-2&&p[n1].y==n-2)			//��n1��Ϊ�յ㣬��¼�����յ�Ĳ���
	{
		if(min1>n1)
		min1=n1;
		return;
	}                                       
	if(num[p[n1].y-1][p[n1].x]==0)			//��
	{
		p[n1+1].x=p[n1].x;
		p[n1+1].y=p[n1].y-1;				//���ƶ���ֵ���浽��һλ�����У��Թ�search(n+1)ʹ�� 
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;			//���һ��������ֵ�Ļ��� �������Ҳ�����Сֵ 
	}
	if(num[p[n1].y][p[n1].x+1]==0)          //��
	{
		p[n1+1].x=p[n1].x+1;
		p[n1+1].y=p[n1].y;
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;
	}
	if(num[p[n1].y+1][p[n1].x]==0)          //��
	{
		p[n1+1].x=p[n1].x;
		p[n1+1].y=p[n1].y+1;
		num[p[n1].y][p[n1].x]=1;
		search(n1+1);
		num[p[n1].y][p[n1].x]=0;
	}
	if(num[p[n1].y][p[n1].x-1]==0)          //��
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
	printf("������n��ֵ��"); 
	cin>>n;
	printf("������%d*%d���Թ���",n,n); 
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>num[i][j];
	p[0].x=1;
	p[0].y=1;												//����Ϊ�����㣬��n-2,n-2��Ϊ�յ� 
	search(0);
	if(min1==100)											//���min��ֵ���ı䣬˵��û���ҵ�·�� 
	cout<<"No solution"<<endl;
	else
	cout<<min1<<endl;                                       //�ҵ�·���ˣ��������
}
