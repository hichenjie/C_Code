#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 20

typedef struct{//�����������
char name[10];
}Name;

typedef struct{//����һ��ͼ
Name mingzi[max];
int arcs[max][max];
int dian,bian;
}Graph;


int weizhi(Graph *G,char* v)//����һ�����ݽ�������ҵ���Ӧλ�õĺ���
{int c=-1,i;
for(i=0;i<G->dian;i++)
	if(strcmp(v,G->mingzi[i].name)==0)
		{c=i;break;}
return c;
}

Graph *jianli(Graph *G)//��ʼ��ͼ�����Ҹ��丳ֵ
{int i,j,k;
char v1[10],v2[10];
printf("������ͼ�Ķ�����,����:");
scanf("%d%d",&G->dian,&G->bian);
printf("�������:\n");
	for(i=0;i<G->dian;i++)
	{	printf("No.%d:",i+1);
		scanf("%s",G->mingzi[i].name);
	}
	for(i=0;i<G->dian;i++)
	for(j=0;j<G->dian;j++)
		G->arcs[i][j]=0;
	printf("������һ�������ӵ���������:\n");
	for(k=0;k<G->bian;k++)
		{	printf("��%d����:\n",k+1);
			printf("��ʼ���:"); scanf("%s",v1);
			printf("�������:"); scanf("%s",v2);
			i=weizhi(G,v1);//�ҵ���������ڱ��е�λ�� 
			j=weizhi(G,v2);
				if(i>=0&&j>=0)
				{G->arcs[i][j]=1;
				 G->arcs[j][i]=G->arcs[i][j] ;
				}
	
	}
		printf("�ڽӾ���Ϊ��\n");//�����ͼ���ڽӾ���
			for(i=0;i<G->dian;i++)
			for(j=0;j<G->dian;j++)
			{printf("%2d",G->arcs[i][j]);
			if(j==G->dian-1 )printf("\n");
			}
	return G;
}

int visited[max]={0};

void dfs(Graph *G,int v)//��ͼ����������ȱ���
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
	printf("��������ʼ�������:");
	scanf("%s",v);
	printf("������ȱ���Ϊ:\n");
	dfs(G,weizhi(G,v));
	printf("\n");
	
}