//xueji.cppc:����ѧ�����ֱ��������룬ɾ�������룬��ѯ�����,�޸ģ����ٵȺ������ж��ѽ���ѧ���ĸĶ���

//  �������½�     ѧ�ţ�2012210533   �༶��0101203

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define NULL 0

typedef struct stu         //������һ��˫������
{char number[10];
char name[10];
float score;
struct stu *pre;
struct stu *next;
}student;

int n;  //n��Ϊ�ڵ�λ�ã�������룬ɾ������ѯ���޸ĵȲ���

student *creat(void) //����һ��ָ�����ͺ�����ָ��struct student�������ݴ˺�������һ���������ʼ��ַ
{student *head;
 student *p1,*p2;
 n=0;
 p1=p2=( student*)malloc(sizeof( student));
 printf("������ѧ��,ѧ������\"#\"��ʾ����\n");
 printf("������ѧ��:"); scanf("%s",p1->number);
 printf("����������:");scanf("%s",p1->name);
 printf("������ɼ�:");scanf("%f",&p1->score);
 p1->pre = NULL;
 p1->next =NULL;
 head=NULL;
 while(p1->number[0]!='#')//�ж����������Ƿ����
 {	n=n+1;	 
	if(n==1) head=p1;
	p2->next=p1;
	p1->pre=p2;
	p2=p1;
	p1=( student*)malloc(sizeof( student));
	printf("������ѧ��:");scanf("%s",&p1->number);
	if(p1->number[0]!='#') 
	{printf("����������:");scanf("%s",p1->name);
	 printf("������ɼ�:");scanf("%f",&p1->score);
	}
	p1->next = NULL;
}
return(head);                  //����headֵ��Ҳ��������ĵ�һ���ڵ����ʼ��ַ
}

 
student *del(student *head,int n)   //����ɾ���ڵ㺯��del,nΪɾ���Ľ��
{student *p1,*p2;
     int i;
if(head==NULL)
{	printf("���Ǹ�������\n");
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

student *charu(student *head,student* zhengjia,int n)  //����һ�����뺯��
{student *p1,*p0,*p2;
  int i;
  p1=p2=head;
  p0=zhengjia;
if(head==NULL)
{	printf("���Ǹ�������\n");
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


student *find(student *head,int n)        //����һ����ѯ����
	{student *p;
	int i;
if(head==NULL)
{printf("���Ǹ�������\n");return(head);}
p=head;
for(i=0;i<n-1;i++)//ͨ��n��ֵ�ҵ�һ����Ӧ��ָ��
	p=p->next ;
printf("��%d��ѧ������Ϣ����",i++);
printf("ѧ��:%s\n����:%s\nרҵ�ɼ�:%f\n",p->number ,p->name,p->score);	
return(head);
}

student *gaidong(student *head,int n)//����һ���Ķ�����
	{student *p1;
	int i;
if(head==NULL)
	{printf("���Ǹ�������\n");return(head);}
p1=head;
for(i=0;i<n-1;i++)//ͨ��n��ֵ�ҵ���Ӧ��ָ��
	p1=p1->next ;
printf("������ѧ��:");scanf("%s\n",p1->number);
printf("����������:");scanf("%s\n",p1->name);
printf("������ɼ�:");scanf("%f\n",&p1->score);
printf("�Ѿ��ɹ��޸�Ϊ:\nѧ��:%s\n����:%s\nרҵ�ɼ���%f\n",p1->number,p1->name ,p1->score);
	return(head);
}

void print(student *head)  //�������ĺ���print
{student *p;
p=head;
printf("��������ѧ��ѧ������:\n");
	while(p!=NULL)
	{
printf("ѧ��:%s\n����:%s\nרҵ�ɼ�:%f\n",p->number ,p->name,p->score);	
	p=p->next;
	}	
}

void xiaohui(student *head)//����һ�����ٺ���
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
	print(head);                             //�����������
int m,a;
printf("��ѡ����:\n����1:����ɾ������\n����2:���в������\n����3:���в�ѯ����\n����4:�����޸Ĳ���\n����5�������ǰѧ��\n����6����������\n����0:��������\n");
scanf("%d",&m);
for(;m!=0;printf("��ѡ����:\n����1:����ɾ������\n����2:���в������\n����3:���в�ѯ����\n����4:�����޸Ĳ���\n����5�������ǰѧ��\n����6����������\n����0:��������\n"))
	{
	if(m==1)
		{
		printf("������Ҫɾ����ѧ��λ��:");                 //ɾ��
		scanf("%d",&a);
		head=del(head,a);	
		}
	else if(m==2)
		{
		zhengjia=(student*)malloc(sizeof(student));      //����		
		printf("�����������ӵ�ѧ����Ϣ:\n");
        printf("���������λ�ã�");scanf("%d",&a);
		printf("������ѧ��:");scanf("%s",zhengjia->number);
	    printf("����������:");scanf("%s",zhengjia->name);
		printf("������ɼ�:");scanf("%f",&zhengjia->score);
		head=charu(head,zhengjia,a);	
		}
	else if(m==3)
	{                                                  //��ѯ
		printf("�������ѯѧ���Ľ��");
		scanf("%d",&a);
		head=find(head,a);
		}
	else if (m==4) 
		{
		printf("��������Ҫ�޸ĵĽ��:");
		scanf("%d",&a);
		head=gaidong(head,a);
		}
	else if(m==5) print(head);            //�����ǰ�ѽ���ѧ��
	else if(m==6) {xiaohui(head) ;break ;}   //��������
	else if(m==0) break;                  //������Ϊ��ʱ����ѭ��

	else printf("error\n");                //���������ѡ����ʱ���ѳ���

	printf("��ѡ���ܣ�");

	scanf("%d",&m);
	
}
}