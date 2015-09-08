//学号：2012210533   班级：0191201   姓名：陈杰

//功能：对一个学籍管理系统进行管理，包括了对学籍的查询，删除，插入等功能。

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
	//查询所有情况
	{	sprintf(sql,"%s","select * from Student");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			dbconn->Select(i,2,val2,sizeof(val2));//地I行第二列
			dbconn->Select(i,3,val3,sizeof(val3));//地I行第三列
			dbconn->Select(i,4,val4,sizeof(val4));//地I行第四列
			dbconn->Select(i,5,val5,sizeof(val5));//地I行第五列
			printf("%-8s	%-8s  %-8s  %-8s  %-8s\n",val1,val2,val3,val4,val5);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
		}
	printf("请选择功能：\n1：查询最高成绩\n2：查询最低成绩\n3：查询平均成绩\n4：查询不及格人数\n5：对学生表进行插入\n6：对学生表进行删除\n7：对当前学生表进行查询\n8:对学生表和成绩表进行连接查询\n9: 输入0结束\n请输入：");
	scanf("%d",&m);
	for(;m!=0;)	
{if(m==1)	//查询最高成绩	
			{	sprintf(sql1,"%s","select max(Chenji) from Grade group by Cno"); //查询语句，查询所有记录更换表名
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			printf("课程号为：%d的最高成绩是：%s\n",i,val1);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}
		
else	if(m==2)//查询最低成绩
			{sprintf(sql1,"%s","select min(Chenji) from Grade group by Cno"); //查询语句，查询所有记录更换表名 
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			printf("课程号为：%d的最低成绩是：%s\n",i,val1);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}
		
else	if(m==3)//查询单科平均成绩
			{sprintf(sql1,"%s","select avg(Chenji) from Grade group by Cno"); //查询语句，查询所有记录更换表名
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			printf("课程号为：%d的平均成绩是：%s\n",i,val1);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}
else	if(m==4)//查询不及格人数
			{sprintf(sql1,"%s","select count(Sno)  from Grade where Chenji<60 group by Cno"); //查询语句，查询所有记录更换表名
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql1);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			printf("课程号为：%d的不及格人数是：%s\n",i,val1);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}
else	if(m==5)//对学生表进行插入
			{printf("请输入你要插入学生表的学生信息：");
			scanf("%s %s %s %s %s",x1,x2,x3,x4,x5);
			sprintf(sql,"insert into Student values('%s','%s','%s','%s','%s')",x1,x2,x3,x4,x5);
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			int i=rc+1;
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			dbconn->Select(i,2,val2,sizeof(val2));//地I行第二列
			dbconn->Select(i,3,val3,sizeof(val3));//地I行第三列
			dbconn->Select(i,4,val4,sizeof(val4));//地I行第四列
			dbconn->Select(i,5,val5,sizeof(val5));//地I行第五列
			printf("您所插入的学生信息是：%-8s	%-8s  %-8s  %-8s  %-8s\n",x1,x2,x3,x4,x5);
			printf("已经插入成功！\n");
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}
else if(m==6)//对学生表进行删除
			{printf("请输入您要删除的学号：");
			scanf("%s",x1);
			sprintf(sql,"delete from Student where Sno=%s",x1);
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			int i=rc-1;
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			dbconn->Select(i,2,val2,sizeof(val2));//地I行第二列
			dbconn->Select(i,3,val3,sizeof(val3));//地I行第三列
			dbconn->Select(i,4,val4,sizeof(val4));//地I行第四列
			dbconn->Select(i,5,val5,sizeof(val5));//地I行第五列
			}
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}

else	if(m==7)//查询当前学生表情况
			{sprintf(sql,"%s","select * from Student");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			dbconn->Select(i,2,val2,sizeof(val2));//地I行第二列
			dbconn->Select(i,3,val3,sizeof(val3));//地I行第三列
			dbconn->Select(i,4,val4,sizeof(val4));//地I行第四列
			dbconn->Select(i,5,val5,sizeof(val5));//地I行第五列
			printf("%-8s	%-8s  %-8s  %-8s  %-8s\n",val1,val2,val3,val4,val5);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;
			printf("请输入：");
			scanf("%d",&m);
		}

else	if(m==8)//对学生表和成绩表进行连接查询
			{	sprintf(sql,"%s","select Student.*,Grade.* from Student,Grade where Student.Sno=Grade.Sno");
			CADOSql* dbconn=new CADOSql();
			BOOL test=dbconn->Connect("127.0.0.1",3306,"sx","root",""); //for MySQL//默认没有密码
			if(test)
			{
			int rc=dbconn->ExecSqlCmd(sql);
			for(int i=1;i<=rc;i++)
			{
			dbconn->Select(i,1,val1,sizeof(val1));//地I行第一列
			dbconn->Select(i,2,val2,sizeof(val2));//地I行第二列
			dbconn->Select(i,3,val3,sizeof(val3));//地I行第三列
			dbconn->Select(i,4,val4,sizeof(val4));//地I行第四列
			dbconn->Select(i,5,val5,sizeof(val5));//地I行第五列
			dbconn->Select(i,7,val6,sizeof(val6));//地I行第六列
			dbconn->Select(i,8,val7,sizeof(val7));//地I行第七列
			printf("%-8s	%-8s  %-8s  %-8s  %-8s  %-8s  %-8s  \n",val1,val2,val3,val4,val5,val6,val7);
			}
			}	
			delete dbconn;//释放空间
			dbconn=NULL;	
			printf("请输入：");
			scanf("%d",&m);
			}
else break;
	}
		

	return 0;
}

