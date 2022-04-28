/*
ѭ������
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
//β���nextָ��ͷ���


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
β���nextָ��ͷ���
ͷ���priorָ��β���
*/


bool IsCDLinkListEmpty(DLinkList L){
	if (L->next == L) {
		return true;
	}//����п�
}


bool IsCDLinkTail(DLinkList L, DNode* t) {
	if (t->prior == L) {
		return true;
	}//�����β
}


bool InsertDLinkAtNode(DNode* s, DNode* pos) {
	if (s == NULL || pos == NULL) {
		return false;
	}
	s->next = pos->next;
//	if (pos->next != NULL) {
	pos->next->prior = s;
//	}
//ѭ��˫������β��㲻���п�
	s->prior = pos;
	pos->next = s;
	return true;
}