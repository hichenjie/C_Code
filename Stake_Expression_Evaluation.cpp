#include <malloc.h>
#include <stdio.h>
#include <ctype.h> 
#include<math.h>

char shuhuanfu[8]={'+','-','*','/','^','(',')',';'};  //������ת�����ַ�
int lei[8]={3,3,5,5,8,1,9,0};//ջ�����ȼ�
int wai[8]={2,2,4,4,7,9,1,0};//ջ�����ȼ�

struct stack 
{int biaodashi[50];
int top;
};

void zhikong(struct stack *s)     //�ÿ�
{s->top=0;
}

void ruzhan(struct stack *s,int x)      //��ջ
{if(s->top==49) printf("ջ����������ջ");
else{s->top++;
     s->biaodashi[s->top]=x; 
		}
}

void chuzhan(struct stack *s,int *x)   //��ջ
{if(s->top==0) printf("ջ�գ����ܳ�ջ");
else {*x=s->biaodashi[s->top];
s->top--;
	}
}

int quzhi(struct stack s)    //ȥ��top��ֵ
{if(s.top==0)
		{printf("ջ�գ�����ȡֵ");
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
struct stack fuhao,shuzhi;//��������ջ��һ���ŷ��ţ�һ��������

zhikong(&fuhao);
ruzhan(&fuhao,fuhuanshu(';'));

zhikong(&shuzhi);

c=getchar();
while(c!=';'||shuhuanfu[quzhi(fuhao)]!=';')  
{
if(isdigit(c))    //��������֣���ô���ط���ֵ
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
printf("������һ�����ʽ������;��ʾ���ʽ�����������\n");
s=qiubiaodashi();
printf("����� :%d\n",s);
}