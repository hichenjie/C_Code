#include <malloc.h>
#include <stdio.h>
#include <ctype.h> 
#include<math.h>

char shuhuanfu[8]={'+','-','*','/','^','(',')',';'};  //把数字转换成字符
int lei[8]={3,3,5,5,8,1,9,0};//栈内优先级
int wai[8]={2,2,4,4,7,9,1,0};//栈外优先级

struct stack 
{int biaodashi[50];
int top;
};

void zhikong(struct stack *s)     //置空
{s->top=0;
}

void ruzhan(struct stack *s,int x)      //入栈
{if(s->top==49) printf("栈满，不能入栈");
else{s->top++;
     s->biaodashi[s->top]=x; 
		}
}

void chuzhan(struct stack *s,int *x)   //出栈
{if(s->top==0) printf("栈空，不能出栈");
else {*x=s->biaodashi[s->top];
s->top--;
	}
}

int quzhi(struct stack s)    //去除top的值
{if(s.top==0)
		{printf("栈空，不能取值");
              return 0;
		}
else return s.biaodashi[s.top];
}

int fuhuanshu(char c)      
{switch(c)
	{case '+':  return 0;
	case '-':  return 1;
	case '*':  return 2;
	case '/':  return 3;
	case '^':  return 4;
	case '(':  return 5;
	case ')':  return 6;
	default:   return 7;
	}
}

char youxian(char c1,char c2) 
{
int i1=fuhuanshu(c1);
int i2=fuhuanshu(c2);
if(lei[i1]>wai[i2])
return '>';
else if(lei[i1]<wai[i2])
return '<';
else 
return '=';
}


int suanfa(int a,int suan,int b)  
{int sum;
switch(suan)
{
case 0: sum=a+b; break;
case 1: sum=a-b; break;
case 2: sum=a*b; break;
case 3: sum=a/b; break;
default:
sum=pow(a,b);
}
return sum;
}

qiubiaodashi()      
{
char c;
int sum=0;
int x,suan,a,b;
struct stack fuhao,shuzhi;//建立两个栈，一个放符号，一个放数字

zhikong(&fuhao);
ruzhan(&fuhao,fuhuanshu(';'));

zhikong(&shuzhi);

c=getchar();
while(c!=';'||shuhuanfu[quzhi(fuhao)]!=';')  
{
if(isdigit(c))    //如果是数字，那么返回非零值
	{sum=0;
	while(isdigit(c))  
		{sum=sum*10+(c-'0');
		c=getchar();
		}		
	ruzhan(&shuzhi,sum);
		}
	else switch(youxian(shuhuanfu[quzhi(fuhao)],c))
			{
				case'<': ruzhan(&fuhao,fuhuanshu(c));
					c=getchar();
				
					break;
				case'=':
					chuzhan(&fuhao,&x);
					c=getchar();	
					break;
				case'>':chuzhan(&fuhao,&suan);
					chuzhan(&shuzhi,&b);
					chuzhan(&shuzhi,&a);
					ruzhan(&shuzhi,suanfa(a,suan,b));
					break;
			}
}	
	return(quzhi(shuzhi));
}

void main()
{int s;
printf("请输入一个表达式（输入;表示表达式输入结束）：\n");
s=qiubiaodashi();
printf("结果是 :%d\n",s);
}