#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{unsigned int weight; 
 unsigned int parent,lchild,rchild; 
}jiedian,*hafuman; 

typedef char **ma;

void xuanzhe(hafuman shu,int t,int&s1,int&s2)
{  
 int i,m,n;
 m=n=1000;   
 for(i=1;i<=t;i++)
 {if(shu[i].parent==0&&(shu[i].weight<m||shu[i].weight<n))
	{	if(m<n)	{n=shu[i].weight;s2=i;} 
		else {m=shu[i].weight;s1=i;}
	}
 }
 if(s1>s2) 
  {i=s1;s1=s2;s2=i;}
 printf("ok4\n");
}

void jianli(hafuman &shu,unsigned int *w,int n)
{
 int i,m;
 int s1,s2;
 hafuman p;
 if(n<=1) return;
 m=2*n-1; 
 shu=(hafuman)malloc((m+1)*sizeof(jiedian)); 
 for(p=shu+1,i=1;i<=n;++i,++p,++w) 
 {p->weight=*w;
p->parent=0;
p->lchild=0;
p->rchild=0;
  }
 for(;i<=m;++i,++p)
  {p->weight=0;
p->parent=0;
p->lchild=0;
p->rchild=0;
  }
 for(i=n+1;i<=m;++i) 
  {xuanzhe(shu,i-1,s1,s2);
  shu[s1].parent=i; shu[s2].parent=i; 
  shu[i].lchild=s1; shu[i].rchild=s2;
  shu[i].weight=shu[s1].weight+shu[s2].weight; 
  }
 printf("ok3\n");
}

void bianma(hafuman shu,ma &biao,int n)
{
 int i,c,f,start;
 char *cd;
	 biao=(ma)malloc((n+1)*sizeof(char *)); 
		cd=(char *)malloc(n*sizeof(char)); 
		cd[n-1]='\0'; 
 for(i=1;i<=n;++i) 
	{start=n-1; 
		for(c=i,f=shu[i].parent;f!=0;c=f,f=shu[f].parent)
			if(shu[f].lchild==c) cd[--start]='0'; 
			 else cd[--start]='1'; 
	biao[i]=(char *)malloc((n-start)*sizeof(char)); 
	strcpy(biao[i],&cd[start]); 
	}
 free(cd); 
 printf("ok1");
}

void xianshi(ma biao,unsigned int *w,int n,int *num)
{
 int i;int j=0;int p=0;
 printf("字母编码如下 :\n");
 printf("ok\n");
 for(i=1;i<=n;i++)
  {
for(;j<26;j++)
   if(num[j]>0){ printf("%c出现%2d次--",j+'a',w[p]);j++;p++;break;}
  puts(biao[i]);
  }
 printf("ok\n");
}

void main()
{hafuman shu; 
ma biao;
int n,i; 
unsigned int *w;    
char c;
int num[26]={0}; 
printf("请输入一段字符串:\n");
while((c=getchar())!='\n')
{
 if(c>='a'&&c<='z'||c>='A'&&c<='Z')
 {
   if(c>='a'&&c<='z') num[c-'a']++;
   if(c>='A'&&c<='Z') num[c-'A']++;
 }
}
  for(i=0,n=0;i<26;i++)
  
     if(num[i]>0) 
	 { 
	 n++;
	 }
  w=(unsigned int*)malloc(n*sizeof(unsigned int)); 
 for(i=0,n=0;i<26;i++)
     if(num[i]>0) 
	 {w[n]=num[i];n++;
	 }
  jianli(shu,w,n); 
  bianma(shu,biao,n); 
  xianshi(biao,w,n,num); 
  }
