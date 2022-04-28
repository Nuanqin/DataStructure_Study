/**
��̬�������鷽ʽʵ�ֵ�����
�ţ�crud�������ô����ƶ�ָ��
ȱ���޷������ȡ�������̶�
**/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct Node {
	int data;//����
	int next;//�α�
}SLinkList [MAXSIZE];//�����������͵Ľṹ������


/*
��ʼ����̬����
*/
bool InitSLinkList(SLinkList &L) {
	L[0].data = -1;
	for (int i = 1; i < MAXSIZE; i++) {
		L[i].next = NULL;
	}
	return true;
}

/*
����
*/
bool InsertSLinkList(SLinkList &L, int pos, int value){
	if (isSLinkListFull) {
		return false;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		if (L[i].data == NULL) {
			L[i].data = value;
			Node p= L[0];
			while (p.next != NULL) {
				p = L[p.next];
			}
			p.next = i;
		}
	}
}

/*
�п�
*/
bool isSLinkListEmpty(SLinkList L) {
	if (L->next != NULL) {
		return false;
	}
	else {
		return true;
	}
}

/*
����
*/
bool isSLinkListFull(SLinkList L) {
	for (int i = 0; i < MAXSIZE; i++) {
		if (L[i].next == 9)
			return true;
	}
	return false;
}





//void main() {
//	SLinkList L;
//	InitSLinkList(L);
//	InsertSLinkList(L, 1, 10);
//	InsertSLinkList(L, 2, 20);
//	InsertSLinkList(L, 3, 30);
//}