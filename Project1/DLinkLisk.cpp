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