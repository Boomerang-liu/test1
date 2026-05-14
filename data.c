#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef struct
{
	int *elem;
	int length;
}LiuList;

int InitList(LiuList *pL)
{
	pL->elem=(int*)malloc(MAXSIZE*sizeof(int));
	if(pL->elem==NULL)
	{
		printf("内存分配失败！\n");
		return ERROR;
	}
	else
	{
		pL->length=0;
		return OK;
	}
}

int InsertList(LiuList *pL,int i,int e)
{
	if(i<1 || i>pL->length+1)
	{
		return ERROR;
	}
	if(pL->length==MAXSIZE)
	{
		return ERROR;
	}
	for(int j=pL->length;j>=i;j--)
	{
		pL->elem[j]=pL->elem[j-1];
	}
	pL->elem[i-1]=e;
	++pL->length;
	return OK;
}

int LocateElem(LiuList L,int e)
{
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i]==e)
		{
			return i+1;
		}
	}
	return 0;
}

int DeleteList(LiuList *pL,int i,int *pe)
{
	if((i<1)||(i>pL->length))
	{
		return ERROR;
	}
	*pe=pL->elem[i-1];
	for(int j=i+1;j<=pL->length;j++)
	{
		pL->elem[j-2]=pL->elem[j-1];
	}
	--pL->length;
	return OK;
}

void TraverseList(LiuList L)
{
	if(L.length == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for(int i=0;i<L.length;i++)
	{
		printf("%d ",L.elem[i]);
	}
}

void DestroyList(LiuList *pL)
{
	if(pL->elem!=NULL)
	{
		free(pL->elem);
		pL->elem=NULL;
	}
	pL->length=0;
}

int main()
{
	LiuList L;
	int e, pos;
	
	if(InitList(&L))
	{
		printf("顺序表构造成功\n");
	}
	else
	{
		printf("顺序表构造失败，程序退出\n");
		return -1;
	}
	if(InsertList(&L,1,30))
	{
		printf("插入元素30成功\n");
	}
	else
	{
		printf("插入元素30失败\n");
	}
	
	if(InsertList(&L,1,29))
	{
		printf("插入元素29成功\n");
	}
	else
	{
		printf("插入元素29失败\n");
	}
	
	if(InsertList(&L,1,28))
	{
		printf("插入元素28成功\n");
	}
	else
	{
		printf("插入元素28失败\n");
	}
	
	if(InsertList(&L,4,11))
	{
		printf("插入元素11成功\n");
	}
	else
	{
		printf("插入元素11失败\n");
	}
	
	if(InsertList(&L,7,12))
	{
		printf("插入元素12成功\n");
	}
	else
	{
		printf("插入元素12失败\n");
	}
	
	if(InsertList(&L,5,13))
	{
		printf("插入元素13成功\n");
	}
	else
	{
		printf("插入元素13失败\n");
	}
	
	TraverseList(L);
	pos = LocateElem(L, 29);
	if(pos > 0)
	{
		printf("元素29在位置%d\n", pos);
	}
	else
	{
		printf("元素29不存在\n");
	}
	
	pos = LocateElem(L, 100);
	if(pos > 0)
	{
		printf("元素100在位置%d\n", pos);
	}
	else
	{
		printf("元素100不存在\n");
	}
	printf("删除元素测试\n");
	if(DeleteList(&L, 3, &e))
	{
		printf("删除位置3的元素成功，删除的元素值为：%d\n", e);
	}
	else
	{
		printf("删除失败\n");
	}
	if(DeleteList(&L, 10, &e))
	{
		printf("删除位置10的元素成功，删除的元素值为：%d\n", e);
	}
	else
	{
		printf("删除位置10失败\n");
	}
	printf("删除元素后的顺序表\n");
	TraverseList(L);
	printf("清理资源\n");
	DestroyList(&L);
	
	return 0;
}