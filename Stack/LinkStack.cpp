/*
* 链表实现栈
* status: Issue
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
} * LinkStack;					

/*
* 初始化：带头/不带头（与链表近似
* 推荐及本例使用的均为不带头
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
 * 判空
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
* 入栈
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
* 出栈
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
* 取顶
*/
int GetLinkStackTopElem(LinkStack S) {
	return S->data;
}



void main(){}
