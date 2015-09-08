//xueji.cppc:建立学籍，分别定义了输入，删除，插入，查询，输出,修改，销毁等函数进行对已建立学籍的改动。

//  姓名：陈杰     学号：2012210533   班级：0101203

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define NULL 0

typedef struct stu         //定义了一个双向链表
{char number[10];
char name[10];
float score;
struct stu *pre;
struct stu *next;
}student;

int n;  //n作为节点位置，方便插入，删除，查询，修改等操作

student *creat(void) //定义一个指针类型函数，指向struct student类型数据此函数带回一个链表的起始地址
{student *head;
 student *p1,*p2;
 n=0;
 p1=p2=( student*)malloc(sizeof( student));
 printf("请输入学籍,学号输入\"#\"表示结束\n");
 printf("请输入学号:"); scanf("%s",p1->number);
 printf("请输入姓名:");scanf("%s",p1->name);
 printf("请输入成绩:");scanf("%f",&p1->score);
 p1->pre = NULL;
 p1->next =NULL;
 head=NULL;
 while(p1->number[0]!='#')//判断链表输入是否完成
 {	n=n+1;	 
	if(n==1) head=p1;
	p2->next=p1;
	p1->pre=p2;
	p2=p1;
	p1=( student*)malloc(sizeof( student));
	printf("请输入学号:");scanf("%s",&p1->number);
	if(p1->number[0]!='#') 
	{printf("请输入姓名:");scanf("%s",p1->name);
	 printf("请输入成绩:");scanf("%f",&p1->score);
	}
	p1->next = NULL;
}
return(head);                  //返回head值，也就是链表的第一个节点的起始地址
}

 
student *del(student *head,int n)   //定义删除节点函数del,n为删除的结点
{student *p1,*p2;
     int i;
if(head==NULL)
{	printf("这是个空链表\n");
	return(head);
}
	p2=p1=head;
	if(n==1)
	{	head=p1->next ;
	p1->pre=head;
	}
	else 
	{for(i=0;i<n-2;i++) p2=p1=p1->next ;
	p2=p1->next->next ;
	p1->next=p2;
	p2->pre=p1;
	}				
return (head);	
}

student *charu(student *head,student* zhengjia,int n)  //定义一个插入函数
{student *p1,*p0,*p2;
  int i;
  p1=p2=head;
  p0=zhengjia;
if(head==NULL)
{	printf("这是个空链表\n");
	return(head);
}
if(n==1)
	{p1->pre=p0;
	 p0->next=p1;
	 head=p0->pre=p0;
	}
else 
	{for(i=0;i<n-2;i++) p2=p1=p1->next ;
	p2=p1->next;
	p1->next=p0;
	p0->pre=p1;
	p0->next=p2;
	p2->pre=p0;
	}
return(head);
}


student *find(student *head,int n)        //定义一个查询函数
	{student *p;
	int i;
if(head==NULL)
{printf("这是个空链表\n");return(head);}
p=head;
for(i=0;i<n-1;i++)//通过n的值找到一个对应的指针
	p=p->next ;
printf("第%d个学生的信息如下",i++);
printf("学号:%s\n姓名:%s\n专业成绩:%f\n",p->number ,p->name,p->score);	
return(head);
}

student *gaidong(student *head,int n)//定义一个改动函数
	{student *p1;
	int i;
if(head==NULL)
	{printf("这是个空链表\n");return(head);}
p1=head;
for(i=0;i<n-1;i++)//通过n的值找到对应的指针
	p1=p1->next ;
printf("请输入学号:");scanf("%s\n",p1->number);
printf("请输入姓名:");scanf("%s\n",p1->name);
printf("请输入成绩:");scanf("%f\n",&p1->score);
printf("已经成功修改为:\n学号:%s\n姓名:%s\n专业成绩：%f\n",p1->number,p1->name ,p1->score);
	return(head);
}

void print(student *head)  //输出链表的函数print
{student *p;
p=head;
printf("现在所有学生学籍如下:\n");
	while(p!=NULL)
	{
printf("学号:%s\n姓名:%s\n专业成绩:%f\n",p->number ,p->name,p->score);	
	p=p->next;
	}	
}

void xiaohui(student *head)//定义一个销毁函数
{student *p,*p1;
p=head;
if(head!=NULL)
	while(p)
	{p1=p->next ;
 free(p);
	p=p1;
	}		
}

void main()
{ student *head,*zhengjia;
    head=creat();
	print(head);                             //输出已有链表
int m,a;
printf("请选择功能:\n输入1:进行删除操作\n输入2:进行插入操作\n输入3:进行查询操作\n输入4:进行修改操作\n输入5：输出当前学籍\n输入6：销毁链表\n输入0:操作结束\n");
scanf("%d",&m);
for(;m!=0;printf("请选择功能:\n输入1:进行删除操作\n输入2:进行插入操作\n输入3:进行查询操作\n输入4:进行修改操作\n输入5：输出当前学籍\n输入6：销毁链表\n输入0:操作结束\n"))
	{
	if(m==1)
		{
		printf("请输入要删除的学生位置:");                 //删除
		scanf("%d",&a);
		head=del(head,a);	
		}
	else if(m==2)
		{
		zhengjia=(student*)malloc(sizeof(student));      //增加		
		printf("请输入所增加的学生信息:\n");
        printf("请输入插入位置：");scanf("%d",&a);
		printf("请输入学号:");scanf("%s",zhengjia->number);
	    printf("请输入姓名:");scanf("%s",zhengjia->name);
		printf("请输入成绩:");scanf("%f",&zhengjia->score);
		head=charu(head,zhengjia,a);	
		}
	else if(m==3)
	{                                                  //查询
		printf("请输入查询学生的结点");
		scanf("%d",&a);
		head=find(head,a);
		}
	else if (m==4) 
		{
		printf("请输入你要修改的结点:");
		scanf("%d",&a);
		head=gaidong(head,a);
		}
	else if(m==5) print(head);            //输出当前已建立学籍
	else if(m==6) {xiaohui(head) ;break ;}   //销毁链表
	else if(m==0) break;                  //当输入为零时跳出循环

	else printf("error\n");                //当输入非所选这项时提醒出错

	printf("请选择功能：");

	scanf("%d",&m);
	
}
}