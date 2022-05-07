/*
* ����ʵ��ջ
* status: Issue
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
} * LinkStack;					

/*
* ��ʼ������ͷ/����ͷ�����������
* �Ƽ�������ʹ�õľ�Ϊ����ͷ
*/
bool InitLinkStack(LinkStack &S) {
	S = (LinkNode*)malloc(sizeof(LinkNode));
	if (S == NULL) {
		return false;
	}
	S->data = NULL;
	S->next = NULL;
	return true;
}


/*
 * �п�
 */
bool IsLinkStackEmpty(LinkStack S) {
	if (S->data == NULL) {
		return true;
	}
	else {
		return false;
	}
}


/*
* ��ջ
*/
bool PushLinkStack(LinkStack &S, int value) {
	LinkNode *n = (LinkNode*)malloc(sizeof(LinkNode));
	if (n == NULL) {
		return false;
	}
	n->data = S->data;
	n->next = S->next;
	S = n;
	S->data = value;
	S->next = n;
	return true;
}

/*
* ��ջ
*/
bool PopLinkStack(LinkStack& S, int &value) {
	if (IsLinkStackEmpty(S)) {
		return false;
	}
	LinkNode* n = (LinkNode*)malloc(sizeof(LinkNode));
	n = S;
	S->next = S->next->next;
	value = n->data;
	return true;
}

/*
* ȡ��
*/
int GetLinkStackTopElem(LinkStack S) {
	return S->data;
}



void main(){}
