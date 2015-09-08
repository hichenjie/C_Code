#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 20

typedef struct{//保存结点的名字
char name[10];
}Name;

typedef struct{//定义一个图
Name mingzi[max];
int arcs[max][max];
int dian,bian;
}Graph;


int weizhi(Graph *G,char* v)//定义一个根据结点名字找到相应位置的函数
{int c=-1,i;
for(i=0;i<G->dian;i++)
	if(strcmp(v,G->mingzi[i].name)==0)
		{c=i;break;}
return c;
}

Graph *jianli(Graph *G)//初始化图，并且给其赋值
{int i,j,k;
char v1[10],v2[10];
printf("请输入图的顶点数,边数:");
scanf("%d%d",&G->dian,&G->bian);
printf("结点名字:\n");
	for(i=0;i<G->dian;i++)
	{	printf("No.%d:",i+1);
		scanf("%s",G->mingzi[i].name);
	}
	for(i=0;i<G->dian;i++)
	for(j=0;j<G->dian;j++)
		G->arcs[i][j]=0;
	printf("请输入一条边连接的两个顶点:\n");
	for(k=0;k<G->bian;k++)
		{	printf("第%d条边:\n",k+1);
			printf("起始结点:"); scanf("%s",v1);
			printf("结束结点:"); scanf("%s",v2);
			i=weizhi(G,v1);//找到输入结点的在表中的位置 
			j=weizhi(G,v2);
				if(i>=0&&j>=0)
				{G->arcs[i][j]=1;
				 G->arcs[j][i]=G->arcs[i][j] ;
				}
	
	}
		printf("邻接矩阵为：\n");//输出该图的邻接矩阵
			for(i=0;i<G->dian;i++)
			for(j=0;j<G->dian;j++)
			{printf("%2d",G->arcs[i][j]);
			if(j==G->dian-1 )printf("\n");
			}
	return G;
}

int visited[max]={0};

void dfs(Graph *G,int v)//对图进行深度优先遍历
{
visited[v]=1;
printf("%s ",G->mingzi[v].name);
for(int i=0;i<G->dian;i++)
	if(	visited[i]!=1&&G->arcs[v][i]==1)
	{
	dfs(G,i);
	}
}


void main()
{	Graph *G,b;
	char v[10];
	G=jianli(&b);
	printf("请输入起始结点名称:");
	scanf("%s",v);
	printf("深度优先遍历为:\n");
	dfs(G,weizhi(G,v));
	printf("\n");
	
}