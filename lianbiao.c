#include"yuesefu.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


LinkList* CreateList() {
	LinkList *head;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	return head;
} 

//求链表的元素个数			
int Size(LinkList *l){
	node *p = l->next;
	int k = 0;
	while(p) {
		k++;
		p = p->next;

	}
	return k;

} 

//在链表的l的第k个位置插入元素x
void Insert(LinkList *l,int k ,dataType x){
	if (k<1) exit(1);
	node *p = l;
	int i = 0;
	while (p && i<k-1){
		p = p->next;
		i++;
	}
	if(!p) exit(1);
	node *s = (node*)malloc(sizeof(node));
	s->data = x;
	s->next = p->next;
	p->next = s;
} 

//删除链表l的第k个元素
void Felete(LinkList *l,int k){
	if(k<1)exit(1);
	node *p = l;
	int i = 0;
	while (p->next && i<k-1){
		p =p->next;
		i++;
	}
	if (p->next==NULL) exit(1);
	node *q = p->next;
	p->next = q->next;
	free(q);
} 

//判断链表是否为空
int Empty(LinkList *l){
	return l->next == NULL;

} 

//求链表l的第k个元素的值
dataType GetData(LinkList *l, int k){
	if (k<1) exit(1);
	node *p = l;
	int i=0;
	while (p&&i<k){
		p=p->next;
		i++;
	}
	if(!p)exit(1);
	return p->data;

} 

//在链表l中查找x的元素
node* Find(LinkList *l,dataType x){
	node *p = l->next;
	while(p && p->data!=x)
		p = p->next;
	return p;
} 

//输出链表
void Print(LinkList *l){
	node *p=l->next;
	while (p){
		printf("%d", p->data);
		p=p->next;

	}
	printf("\n");

} 

//清空链表
void ClearList(LinkList *l){
	node *p, *q;
	p=l->next;
	while (p){
		q=p;
		p=p->next;
		free(q);

	}
	l->next=NULL;

} 






void yuesefu(){
	int k = 0;
	LinkList *p, *q, *r;
	p = q = (LinkList*)malloc(sizeof(LinkList));    //创建第一个节点
	p -> data = 1;
	for (int i=2;i<=n; i++){                                        //建立链表
		r = (LinkList*)malloc(sizeof(LinkList));
		r->data = i;
		q->next = r;
		q = r;
	}
	q->next = p;                            //构成一个环

	q = p;
	while (q->next != q){
		k++;
		if (k == m) {
			p->next = q->next;
			free(q);
			q = p->next;
			k = 0;
		}else {
			p = q;
			q = q->next;
		}
	}
	printf("最后一个获胜者的编号是：%d\n", q->data);
}
