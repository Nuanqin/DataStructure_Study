/*
* 链式存储实现队列
* status: Archived
*/


#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;														//依旧有带头或不带头区分

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
* 初始化
* 此处使用带头
*/
bool InitLinkQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));		//申请并指向头结点
	if (Q.front == NULL || Q.rear == NULL) {
		return false;
	}
	Q.front->next = NULL;
	return true;
}


/*
* 不带头初始化
*/
bool InitLinkQueue_NOT_HEAD(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
	return true;
}


/*
* 判空
* 带头结点
*/
bool IsLinkQueue_NOT_HEAD_Empty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}


/*
* 判空
* 不带头结点
*/
bool IsLinkQueueEmpty(LinkQueue Q) {
	if (Q.front == NULL || Q.rear == NULL) {
		return true;
	}
	else {
		return false;
	}
}


//bool isFull() {}													//链式结构不需要判满，可随时增加存储空间


/*
*入队
*带头结点
*/
bool EnLinkQueue(LinkQueue &Q, int value) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) {
		return false;
	}
	s->data = value;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}


/*
* 入队
* 不带头结点
*/
bool EnLinkQueue_NOT_HEAD(LinkQueue& Q, int value) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) {
		return false;
	}
	s->data = value;
	s->next = NULL;
	if (Q.front == NULL) {
		Q.front = s;
		Q.rear = s;
		return true;
	}
	else {
		Q.rear->next = s;
		Q.rear = s;
		return true;
	}
}


/*
* 出队
* 带头结点
*/
bool DeLinkQueue(LinkQueue& Q, int &value) {
	if (IsLinkQueueEmpty(Q)) {
		return false;
	}
	LinkNode* p = Q.front->next;
	value = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {												//判断出队元素是否为队尾
		Q.rear = Q.front;
	}
	free(p);
	return true;
}


/*
* 出队
* 不带头结点
*/
bool DeLinkQueue_NOT_HEAD(LinkQueue& Q, int& value) {
	if (IsLinkQueue_NOT_HEAD_Empty(Q)) {
		return false;
	}
	LinkNode* p = Q.front;
	value = p->data;
	Q.front = p->next;
	if (Q.rear == p) {												//判断队尾，修改rear指针
		Q.front = Q.rear = NULL;
	}
	free(p);
	return true;
}


/*
* 查询长度
*/
int GetLinkQueueSize(LinkQueue Q){
	int i = 0;														
	LinkNode* p = Q.front->next;									//跳过头结点
	while (p != NULL) {
		p = p->next;
		i++;
	}
	return i;
}


void main() {
	//LinkQueue Q;
	//int i = 0;
	//InitLinkQueue(Q);
	//EnLinkQueue(Q, 2);
	//DeLinkQueue(Q, i);
	//printf("%d\t", i);
	//EnLinkQueue(Q, 3);
	//DeLinkQueue(Q, i);
	//printf("%d\t", i);
	//EnLinkQueue(Q, 5);
	//DeLinkQueue(Q, i);
	//printf("%d\t", i);
	//EnLinkQueue(Q, 6);
	//DeLinkQueue(Q, i);
	//i = GetLinkQueueSize(Q);
	//printf("%d", i);
}
