/*
循环链表
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;


bool InitCSLink(LinkList &L){
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->data = NULL;
	L->next = L;
	return true;
}
//尾结点next指向头结点


bool InitCDLink(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->data = NULL;
	L->next = L;
	L->prior = L;
	return true;
}
/*
尾结点next指向头结点
头结点prior指向尾结点
*/


bool IsCDLinkListEmpty(DLinkList L){
	if (L->next == L) {
		return true;
	}//便捷判空
}


bool IsCDLinkTail(DLinkList L, DNode* t) {
	if (t->prior == L) {
		return true;
	}//便捷判尾
}


bool InsertDLinkAtNode(DNode* s, DNode* pos) {
	if (s == NULL || pos == NULL) {
		return false;
	}
	s->next = pos->next;
//	if (pos->next != NULL) {
	pos->next->prior = s;
//	}
//循环双链表中尾结点不用判空
	s->prior = pos;
	pos->next = s;
	return true;
}