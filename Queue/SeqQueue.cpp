/*
* ���У�ֻ������һ�˲��룬��һ��ɾ�������Ա�
* �ص㣺�Ƚ��ȳ���First In First Out   FIFO)
* status: Archived
*
*/

#include<stdio.h>
#include<math.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];
	int front, rear;
	//int size;										//�����ж϶��г���
	//int flag										//������һ�β�������ӻ��ǳ���
													//ֻ�г��Ӳ������ܵ��¶ӿգ�ֻ����Ӳ������ܵ��¶���
}SqQueue;


/*
* ��ʼ������
*/
bool InitSqQueue(SqQueue& Q){
	Q.rear = Q.front = 0;
	return true;
}


/*
* �п�
*/
bool IsSqQueueEmpty(SqQueue Q){
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}


/*
* ����
*/
bool IsSqQueueFull(SqQueue Q) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		return true;
	}
	else {
		return false;
	}
}


/*
* ���ٶ���
* ��̬����ϵͳ�Զ�����
*/
//bool DestorySqQueue(SqQueue &Q){
//	
//}


/*
* ���
*/
bool EnSqQueue(SqQueue &Q, int value){
	//if (IsSqQueueEmpty(Q)) {
	//	return false;
	//}
	Q.data[Q.rear] = value;
	//Q.rear++;
	Q.rear = (Q.rear + 1) % MAXSIZE;				//ѭ������
	return true;
}


/*
* ����
*/
bool DeSqQueue(SqQueue &Q, int &value){
	//if (IsSqQueueEmpty(Q)) {
	//	return false;
	//}
	value = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;				//ѭ��
	return true;
}


/*
* ����ͷ
*/
int GetSqQueueHead(SqQueue Q){
	return Q.data[Q.front];
}

int GetSqQueueSize(SqQueue Q){
	int i = 0;
	i = abs(((Q.front - Q.rear) % MAXSIZE));		//ȡ�˸�����ֵ
	return i;
}


void main() {
	//SqQueue Q;
	//int e = 9;
	//InitSqQueue(Q);
	//e = (int)IsSqQueueEmpty(Q);
	//printf("%d\t", e);
	//EnSqQueue(Q, 2);
	//EnSqQueue(Q, 4);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//EnSqQueue(Q, 6);
	//int i = GetSqQueueSize(Q);
	//printf("%d\t",i);
	//int b = (int)IsSqQueueFull(Q);
	//printf("%d\t", b);
	//e = (int)IsSqQueueEmpty(Q);
	//printf("%d\t", e);
}