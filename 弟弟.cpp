#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;//������
	struct Node * pNext;
 }NODE,*PNODE;//NODE�ȼ��� struct Node ��PNODE�ȼ���struct Node *
  //��������
PNODE create_list(void);
void traverse_list(PNODE pHead);

void deletex_list(PNODE , int);
 
int main()
{
	PNODE pHead = NULL;//�ȼ���struct Node *pHead =NULL 

	pHead = create_list();//create_list()���ܣ�����һ����ѭ�������������������ͷ��㸳��pHead 
//	traverse_list(pHead);//�������� 
	printf("%d\n",pHead->pNext->data);
	deletex_list(pHead->pNext,2);
    printf("%d",pHead->pNext->data);
	traverse_list(pHead);
	return 0;
}
PNODE create_list(void)
{
	int i;
	int len;
	int val;//������ʱ����û�����ڵ��ֵ
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("����ʧ�ܣ�������ֹ��");
		exit(-1);
	 } 
	 PNODE pTail = pHead;
	 pTail->pNext = NULL;
	 printf("����������Ҫ��������ڵ�ĸ�����len = ");
	 scanf("%d",&len); 
	 for(i=0; i<len ;++i)
	 {
	 	printf("�������%d���ڵ��ֵ��",i+1);
	 	scanf("%d",&val);
	 	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	 		if(pNew == NULL)
			{
				printf("����ʧ�ܣ�������ֹ��");
				exit(-1);
	 		} 
	 	pNew->data = val;
	 	pTail->pNext = pNew;
	 	pNew->pNext = NULL;
	 	pTail = pNew;
	 }
	 return pHead;
}
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	printf("%d ",p->data);
	int i = 0;
	while(i++ <= 4)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

void deletex_list(PNODE pHead, int x)
{
	PNODE p;
	if(pHead == NULL)
	return;
	if(pHead->pNext->data == x)
	{
		p = pHead->pNext;
		pHead->pNext = p->pNext;
		free(p);
	//	deletex_list(pHead,x);
	}
	else
	deletex_list(pHead->pNext,x);
}

