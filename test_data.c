#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStack;

Status InitStack(LinkStack *pS);
Status Push(LinkStack *pS,SElemType e);
Status Pop(LinkStack *pS,SElemType *pe);
Status GetTop(LinkStack S,SElemType *pe);
void DestroyStack(LinkStack *pS);
void Conversion(int N);

int main()
{
	int n;
	for (int i=0;i<3;i++)
	{
		printf("请输入要转换的十进制:");
		scanf("%d",&n);
		if (n < 0)
		{
			printf("输入错误，请输入非负十进制数:\n");
			--i;
			continue;
		}
		printf("转换后的八进制数:");
		Conversion(n);
		printf("\n");
	}
	LinkStack S;
	SElemType e;
	if ( InitStack(&S) )
	{
		printf("链栈初始化成功。\n");
	}
	if( Push(&S,100) )
	{
		printf("入栈成功\n");
	}
	if( Push(&S,200) )
	{
		printf("入栈成功\n");
	}
	if( Push(&S,300) )
	{
		printf("入栈成功\n");
	}
	if ( Pop(&S,&e) )
	{
		printf("出栈成功，出栈元素是%d\n",e);
	}
	if ( GetTop(S,&e) )
	{
		printf("栈顶元素是%d\n",e);
	}
	DestroyStack(&S);
	
	return 0;
}

Status InitStack(LinkStack *pS)
{
	*pS=NULL;
	return OK;
}

Status Push(LinkStack *pS,SElemType e)
{
	StackNode *p=(StackNode *)malloc(sizeof(StackNode));
	if (!p)
	{
		exit(-1);
	}
	p->data=e;
	p->next=*pS;
	*pS=p;
	return OK;
}

Status Pop(LinkStack *pS,SElemType *pe)
{
	StackNode *p;
	if (*pS==NULL)
	{
		printf("栈空，出栈失败。\n");
		return ERROR;
	}
	*pe=(*pS)->data;
	p=*pS;
	*pS=(*pS)->next;
	free(p);
	return OK;
}

Status GetTop(LinkStack S,SElemType *pe)
{
	if (!S)
	{
		printf("栈空，无栈顶元素。\n");
		return ERROR;
	}
	*pe=S->data;
	
	return OK;
}

void DestroyStack(LinkStack *pS)
{
	StackNode *q;
	while( *pS )
	{
		q=*pS;
		*pS=(*pS)->next;
		free(q);
	}
	*pS=NULL;
}

void Conversion(int N)
{
	LinkStack SCon;
	SElemType e;
	
	InitStack(&SCon);
	if(N==0)
	{
		Push(&SCon,0);
	}
	while (N)
	{
		Push(&SCon,N%8);
		N=N/8;
	}
	while (SCon)
	{
		Pop(&SCon,&e);
		printf("%d",e);
	}
	DestroyStack(&SCon);
}