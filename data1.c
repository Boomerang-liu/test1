#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,* LinkList;

Status InitList(LinkList *pL);
Status InsertList(LinkList L,int i, ElemType e);
Status GetElem(LinkList,int,ElemType * );
Status DeleteList(LinkList,int ,ElemType * );
void DestoryList(LinkList *);

int main(void)
{
	LinkList L=NULL;
	if( InitList(&L) )
	{
		printf("创建单链表成功\n");
	}
	if( InsertList(L,1,10) )
	{
		printf("插入10成功\n");
	}
	else
	{
		printf("插入10失败\n");
	}
	if( InsertList(L,1,5) )
	{
		printf("插入5成功\n");
	}
	else
	{
		printf("插入5失败\n");
	}
	ElemType e;
	if( GetElem(L,3,&e) )
	{
		printf("获取的值是%d\n",e);
	}
	else
	{
		printf("获取失败\n");
	}
	if( DeleteList(L,1,&e) )
	{
		printf("删除的值是%d\n",e);
	}
	else
	{
		printf("删除失败\n");
	}
	if ( DeleteList(L,5,&e) )
	{
		printf("删除的值是%d\n",e);
	}
	else
	{
		printf("删除失败\n");
	}
	DestoryList(&L);
	return 0;
}

Status InitList(LinkList *pL)
{
	*pL=(LNode *)malloc(sizeof(LNode));
	if (*pL==NULL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	(*pL)->next=NULL;
	
	return OK;
}

Status InsertList(LinkList L,int i, ElemType e)
{
	LNode *p=L;
	int j=0;
	
	if (i<1)
	{
		return ERROR;
	}
	while( p&& j<i-1 )
	{
		p=p->next;
		++j;
	}
	if (!p)
	{
		return ERROR;
	}
	LNode * s=(LNode *)malloc(sizeof(LNode));
	if (!s)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	s->data=e;
	s->next=p->next;
	p->next=s;
	
	return OK;
}

Status GetElem(LinkList L,int i,ElemType * pe)
{
	if (i<1)
	{
		return ERROR;
	}
	LNode *p=L->next;
	int j=1;
	
	while( p&& j<i )
	{
		p=p->next;
		++j;
	}
	if (!p)
	{
		return ERROR;
	}
	*pe=p->data;
	
	return OK;
}

Status DeleteList(LinkList L,int i,ElemType * pe)
{
	if (i<1)
	{
		return ERROR;
	}
	LNode *p=L;
	int j=0;
	
	while( p->next&&j<i-1 )
	{
		p=p->next;
		++j;
	}
	
	if ( !(p->next) )
	{
		return ERROR;
	}
	LNode *q=p->next;
	p->next=q->next;
	*pe=q->data;
	free(q);
	
	return OK;
}

void DestoryList(LinkList *pL)
{
	LNode *q;
	
	while ( *pL )
	{
		q=*pL;
		*pL=(*pL)->next;
		free(q);
	}
	*pL=NULL;
}