#ifndef yuesefu_h
#define yuesefu_h

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define n 11
#define m 3

typedef int dataType;
typedef struct node {
		dataType data;
			struct node *next;
} LinkList,node;

LinkList* CreateList();
void Insert(LinkList *l,int k ,dataType x);
void Felete(LinkList *l,int k);

int Empty(LinkList *l);


dataType GetData(LinkList *l, int k);
node* Find(LinkList *l,dataType x);

void Print(LinkList *l);
void ClearList(LinkList *l);

void yuesefu ();
#endif
