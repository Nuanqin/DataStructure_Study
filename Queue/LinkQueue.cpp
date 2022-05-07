/*
* ��ʽ�洢ʵ�ֶ���
* status: Archived
*/


#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;														//�����д�ͷ�򲻴�ͷ����

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
* ��ʼ��
* �˴�ʹ�ô�ͷ
*/
bool InitLinkQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));		//���벢ָ��ͷ���
	if (Q.front == NULL || Q.rear == NULL) {
		return false;
	}
	Q.front->next = NULL;
	return true;
}


/*
* ����ͷ��ʼ��
*/
bool InitLinkQueue_NOT_HEAD(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
	return true;
}


/*
* �п�
* ��ͷ���
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
* �п�
* ����ͷ���
*/
bool IsLinkQueueEmpty(LinkQueue Q) {
	if (Q.front == NULL || Q.rear == NULL) {
		return true;
	}
	else {
		return false;
	}
}


//bool isFull() {}													//��ʽ�ṹ����Ҫ����������ʱ���Ӵ洢�ռ�


/*
*���
*��ͷ���
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
* ���
* ����ͷ���
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
* ����
* ��ͷ���
*/
bool DeLinkQueue(LinkQueue& Q, int &value) {
	if (IsLinkQueueEmpty(Q)) {
		return false;
	}
	LinkNode* p = Q.front->next;
	value = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {												//�жϳ���Ԫ���Ƿ�Ϊ��β
		Q.rear = Q.front;
	}
	free(p);
	return true;
}


/*
* ����
* ����ͷ���
*/
bool DeLinkQueue_NOT_HEAD(LinkQueue& Q, int& value) {
	if (IsLinkQueue_NOT_HEAD_Empty(Q)) {
		return false;
	}
	LinkNode* p = Q.front;
	value = p->data;
	Q.front = p->next;
	if (Q.rear == p) {												//�ж϶�β���޸�rearָ��
		Q.front = Q.rear = NULL;
	}
	free(p);
	return true;
}


/*
* ��ѯ����
*/
int GetLinkQueueSize(LinkQueue Q){
	int i = 0;														
	LinkNode* p = Q.front->next;									//����ͷ���
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
