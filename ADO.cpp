//ѧ�ţ�2012210533   �༶��0191201   �������½�

//���ܣ���һ��ѧ������ϵͳ���й��������˶�ѧ���Ĳ�ѯ��ɾ��������ȹ��ܡ�

// ADO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ADOSql.h"


int main(int argc, char* argv[])
{	int m=0;
	char sql[256]={0};
	char sql1[256]={0};
	char val1[32]={0};
	char val2[32]={0};
	char val3[32]={0};
	char val4[32]={0};
	char val5[32]={0};
	char val6[32]={0};
	char val7[32]={0};
	char x1[32]={0};
	char x2[32]={0};
	char x3[32]={0};
	char x4[32]={0};
	char x5[32]={0};
	//��ѯ�������
	{	sprintf(sql,"%s","select * from Student");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			dbconn->Select(i,2,val2,sizeof(val2));//��I�еڶ���
			dbconn->Select(i,3,val3,sizeof(val3));//��I�е�����
			dbconn->Select(i,4,val4,sizeof(val4));//��I�е�����
			dbconn->Select(i,5,val5,sizeof(val5));//��I�е�����
			printf("%-8s	%-8s  %-8s  %-8s  %-8s\n",val1,val2,val3,val4,val5);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
		}
	printf("��ѡ���ܣ�\n1����ѯ��߳ɼ�\n2����ѯ��ͳɼ�\n3����ѯƽ���ɼ�\n4����ѯ����������\n5����ѧ������в���\n6����ѧ�������ɾ��\n7���Ե�ǰѧ������в�ѯ\n8:��ѧ����ͳɼ���������Ӳ�ѯ\n9: ����0����\n�����룺");
	scanf("%d",&m);
	for(;m!=0;)	
{if(m==1)	//��ѯ��߳ɼ�	
			{	sprintf(sql1,"%s","select max(Chenji) from Grade group by Cno"); //��ѯ��䣬��ѯ���м�¼��������
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			printf("�γ̺�Ϊ��%d����߳ɼ��ǣ�%s\n",i,val1);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}
		
else	if(m==2)//��ѯ��ͳɼ�
			{sprintf(sql1,"%s","select min(Chenji) from Grade group by Cno"); //��ѯ��䣬��ѯ���м�¼�������� 
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			printf("�γ̺�Ϊ��%d����ͳɼ��ǣ�%s\n",i,val1);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}
		
else	if(m==3)//��ѯ����ƽ���ɼ�
			{sprintf(sql1,"%s","select avg(Chenji) from Grade group by Cno"); //��ѯ��䣬��ѯ���м�¼��������
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			printf("�γ̺�Ϊ��%d��ƽ���ɼ��ǣ�%s\n",i,val1);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}
else	if(m==4)//��ѯ����������
			{sprintf(sql1,"%s","select count(Sno)  from Grade where Chenji<60 group by Cno"); //��ѯ��䣬��ѯ���м�¼��������
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			printf("�γ̺�Ϊ��%d�Ĳ����������ǣ�%s\n",i,val1);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}
else	if(m==5)//��ѧ������в���
			{printf("��������Ҫ����ѧ�����ѧ����Ϣ��");
			scanf("%s %s %s %s %s",x1,x2,x3,x4,x5);
			sprintf(sql,"insert into Student values('%s','%s','%s','%s','%s')",x1,x2,x3,x4,x5);
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			int i=rc+1;
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			dbconn->Select(i,2,val2,sizeof(val2));//��I�еڶ���
			dbconn->Select(i,3,val3,sizeof(val3));//��I�е�����
			dbconn->Select(i,4,val4,sizeof(val4));//��I�е�����
			dbconn->Select(i,5,val5,sizeof(val5));//��I�е�����
			printf("���������ѧ����Ϣ�ǣ�%-8s	%-8s  %-8s  %-8s  %-8s\n",x1,x2,x3,x4,x5);
			printf("�Ѿ�����ɹ���\n");
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}
else if(m==6)//��ѧ�������ɾ��
			{printf("��������Ҫɾ����ѧ�ţ�");
			scanf("%s",x1);
			sprintf(sql,"delete from Student where Sno=%s",x1);
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			int i=rc-1;
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			dbconn->Select(i,2,val2,sizeof(val2));//��I�еڶ���
			dbconn->Select(i,3,val3,sizeof(val3));//��I�е�����
			dbconn->Select(i,4,val4,sizeof(val4));//��I�е�����
			dbconn->Select(i,5,val5,sizeof(val5));//��I�е�����
			}
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}

else	if(m==7)//��ѯ��ǰѧ�������
			{sprintf(sql,"%s","select * from Student");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			dbconn->Select(i,2,val2,sizeof(val2));//��I�еڶ���
			dbconn->Select(i,3,val3,sizeof(val3));//��I�е�����
			dbconn->Select(i,4,val4,sizeof(val4));//��I�е�����
			dbconn->Select(i,5,val5,sizeof(val5));//��I�е�����
			printf("%-8s	%-8s  %-8s  %-8s  %-8s\n",val1,val2,val3,val4,val5);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;
			printf("�����룺");
			scanf("%d",&m);
		}

else	if(m==8)//��ѧ����ͳɼ���������Ӳ�ѯ
			{	sprintf(sql,"%s","select Student.*,Grade.* from Student,Grade where Student.Sno=Grade.Sno");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//Ĭ��û������
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//��I�е�һ��
			dbconn->Select(i,2,val2,sizeof(val2));//��I�еڶ���
			dbconn->Select(i,3,val3,sizeof(val3));//��I�е�����
			dbconn->Select(i,4,val4,sizeof(val4));//��I�е�����
			dbconn->Select(i,5,val5,sizeof(val5));//��I�е�����
			dbconn->Select(i,7,val6,sizeof(val6));//��I�е�����
			dbconn->Select(i,8,val7,sizeof(val7));//��I�е�����
			printf("%-8s	%-8s  %-8s  %-8s  %-8s  %-8s  %-8s  \n",val1,val2,val3,val4,val5,val6,val7);
			}
			}	
			delete dbconn;//�ͷſռ�
			dbconn=NULL;	
			printf("�����룺");
			scanf("%d",&m);
			}
else break;
	}
		

	return 0;
}

