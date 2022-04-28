/**
链表：链式存储
优：离散小空间分配方便、改变容量简单
缺：不可随机存取、存储密度低;
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;


bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}


bool InsertNextNode(LNode *p, int value) {
	if (p == NULL) {
		return false;
	}
	LNode* swap = (LNode*)malloc(sizeof(LNode));
	if (swap == NULL) {
		return false;
	}
	swap->data = value;
	swap->next = p->next;
	p->next = swap;
	return true;
}


bool InsertLink(LinkList& L, int pos, int value) {
	if (pos < 1) {
		return false;
	}

	LNode* p;
	int i = 0;
	p = L;
	while (p != NULL && i < pos - 1) {
		p = p->next;
		i++;
	}//定位节点
	return InsertNextNode(p, value);
}


bool InsertPriorNode(LNode *p ,int value) {
	if (p == NULL) {
		return false;
	}
	LNode* swap = (LNode*)malloc(sizeof(LNode));
	swap->data = p->data;
	p->data = value;
	swap->next = p->next;
	p->next = swap;
	return true;
}


bool LinkDelete(LinkList &L, int pos ,int &value) {
	if (pos < 1) {
		return false;
	}
	LNode* p;
	int i = 0;
	p = L;
	while (p!= NULL && i< pos-1){
		p = p->next;
		i++;
	}
	if (p == NULL) {
		return false;
	}
	if (p->next == NULL) {
		return false;
	}
	LNode* q = p->next;
	value = q->data;
	p->next = q->next;
	free(q);
	return true;
}


bool NodeDelete(LNode *p){
	if (p == NULL) {
		return false;
	}
	LNode *swap = p->next;
	p->data = swap->data;
	p->next = swap->next;
	free(swap);
	return true;
}


LNode* GetElem(LinkList L ,int pos) {
	if (pos < 0) {
		return NULL;
	}
	LNode* p;
	int i = 0;
	p = L;
	while (p != NULL && i < pos) {
		p = p->next;
		i++;
	}
	return p;
}


LNode* LocateElem(LinkList L, int value) {
	LNode* p = L->next;
	while (p != NULL && p->data != value) {
		p = p->next;
	}
	return p;
}


int Lenght(LinkList L) {
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}


LinkList ReverseLink(LinkList& L) {
	int i = 1;
	LNode* tmp = (LNode*)malloc(sizeof(LNode));
	tmp->next = NULL;
	int len = Lenght(L);
	while (i <= 3) {
		LNode* x = (LNode*)malloc(sizeof(LNode));
		x->data = GetElem(L, i)->data;
		x->next = tmp->next;
		tmp->next = x;
		i++;
	}
	free(L);
	L = tmp;
	return L;
}


//int main() {
//	LinkList L;
//	InitList(L);
//	InsertLink(L, 1, 27);
//	InsertLink(L, 2, 16);
//	InsertLink(L, 3, 10);
//	printf("%d\t", GetElem(L, 1)->data);
//	printf("%d\t", GetElem(L, 2)->data);
//	printf("%d\t", GetElem(L, 3)->data);
//	ReverseLink(L);
//	printf("%d\t", GetElem(L, 1)->data);
//	printf("%d\t", GetElem(L, 2)->data);
//	printf("%d\t", GetElem(L, 3)->data);
//}