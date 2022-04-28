#include<stdio.h>
#include<stdlib.h>

typedef struct DNode {
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;


bool InitDLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = NULL;
	L->next = NULL;
	return true;
}


bool isDLinkEmpty(DLinkList L) {
	if (L->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}


bool InsertDLink(DLinkList& L, int pos, int value) {
	if (pos < 1) {
		return false;
	}
	DNode* s = L;
	int i = 0;
	while (s != NULL && i < pos - 1) {
		s = s->next;
		i++;
	}
	if (s == NULL) {
		return false;
	}
	DNode* p = (DNode*)malloc(sizeof(DNode));
	p->data = value;
	p->next = s->next;
	s->next->prior = p;
	s->next = p;
	p->prior = s;
	return true;
}


bool InsertDLinkAtNode(DNode* s, DNode* pos) {
	if (s == NULL || pos == NULL) {
		return false;
	}
	s->next = pos->next;
	if (pos->next != NULL) {
		pos->next->prior = s;
	}
	s->prior = pos;
	pos->next = s;
	return true;
}


bool DeleteDLinkNodeAfter(DNode *pos) {
	if (pos == NULL) {
		return false;
	}//pos不存在
	DNode* s = pos->next;
	if (s == NULL) {
		return false;
	}//pos后继节点不存在
	pos->next = s->next;
	if (s->next != NULL) {
		s->next->prior = pos;
	}
	free(s);
	return true;
} 


bool PostiveTarversal(DNode* H) {
	int i = 0;
	if (H != NULL) {
		printf("%d", H->data);
		H = H->next;
		i++;
	}
	printf("%d", i);
	return true;
}


bool PriorTarversal(DNode *L) {
	int i = 0;
	while (L != NULL) {
		printf("%d", L->data);
		L = L->prior;
		i++;
	}
	printf("%d", i);
	return true;
}


//int main() {
//	DLinkList L;
//	InitDLinkList(L);
//	DNode* i = NULL, * j = NULL, * k = NULL;
//	i->data = 10;
//	j->data = 13;
//	k->data = 16;
//	InsertDLinkAtNode(i, L);
//	InsertDLinkAtNode(j, L);
//	InsertDLinkAtNode(k, L);
//	PostiveTarversal(L);
//	return 0;
//}