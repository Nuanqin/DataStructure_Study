#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


bool InitLinkList_NOT_HEAD(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->data = NULL;
	L->next = NULL;
	return true;
}


bool InsertLinkListByOrder_NOT_HEAD(LinkList &L, int pos, int value) {
	if (pos < 1) {
		return false;
	}
	if (pos == 1) {
		LNode *s = (LNode*)malloc(sizeof(LNode));
		s->data = value;
		s->next = L;
		L = s;
		return true;
	}
	LNode *p=L;
	int i = 1;
	while (p != NULL && i < pos - 1) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = value;
	s->next = p->next;
	p->next = s;
	return true;
}


bool DeleteLinkListByOrder_NOT_HEAD(LinkList &L, int pos) {
	if (pos < 1) {
		return false;
	}
	if (pos == 1) {
		L = L->next;
		return true;
	}
	LNode* p = L;
	int i = 1;
	while (p != NULL && i < pos -1) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return false;
	}
	p->next = p->next->next;
	return true;
}


LNode* GetElem_NOT_HEAD(LinkList L ,int pos) {
	if (L->data == NULL) {

		return NULL;
	}
	LNode* p = L;
	int i = 1;
	while (p != NULL && i < pos) {
		p = p->next;
		i++;
	}
	return p;
}


bool Alter_NOT_HEAD(LinkList &L, int pos, int value) {
	if (L == NULL) {
		return false;
	}
	if (pos < 1) {
		return false;
	}
	LNode* p = GetElem_NOT_HEAD(L, pos);
	p->data = value;
	return true;
}


bool isEmpty_NOT_HEAD(LinkList L) {
	LNode* p = L;
	if (L->data = NULL) {
		return true;
	}
	else {
		return false;
	}
}


int Length(LinkList L) {
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}


bool ReverseLink_NOT_HEAD(LinkList& L) {
	if (L->data == NULL) {
		return false;
	}
	int i = 1;
	LNode* tmp = (LNode*)malloc(sizeof(LNode));
	tmp->next = NULL;
	int len = Length(L);
	while (i < len) {
		LNode* x = (LNode*)malloc(sizeof(LNode));
		x->data = GetElem_NOT_HEAD(L, i)->data;
		x->next = tmp->next;
		tmp->next = x;
		i++;
	}
	free(L);
	L = tmp;
	return L;
}


int main() {
	LinkList L = NULL;
	InsertLinkListByOrder_NOT_HEAD(L, 1, 27);
	InsertLinkListByOrder_NOT_HEAD(L, 2, 16);
	InsertLinkListByOrder_NOT_HEAD(L, 3, 10);
	printf("%d\t", GetElem_NOT_HEAD(L, 1)->data);
	printf("%d\t", GetElem_NOT_HEAD(L, 2)->data);
	printf("%d\t", GetElem_NOT_HEAD(L, 3)->data);
	ReverseLink_NOT_HEAD(L);
	printf("%d\t", GetElem_NOT_HEAD(L, 1)->data);
	printf("%d\t", GetElem_NOT_HEAD(L, 2)->data);
	printf("%d\t", GetElem_NOT_HEAD(L, 3)->data);

	return 0;
}