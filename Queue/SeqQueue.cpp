/*
* 队列：只允许在一端插入，另一端删除的线性表
* 特点：先进先出（First In First Out   FIFO)
* status: Archived
*
*/

#include<stdio.h>
#include<math.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];
	int front, rear;
	//int size;										//单独判断队列长度
	//int flag										//标记最近一次操作是入队还是出队
													//只有出队操作可能导致队空，只有入队操作可能导致队满
}SqQueue;


/*
* 初始化队列
*/
bool InitSqQueue(SqQueue& Q){
	Q.rear = Q.front = 0;
	return true;
}


/*
* 判空
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
* 判满
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
* 销毁队列
* 静态数组系统自动回收
*/
//bool DestorySqQueue(SqQueue &Q){
//	
//}


/*
* 入队
*/
bool EnSqQueue(SqQueue &Q, int value){
	//if (IsSqQueueEmpty(Q)) {
	//	return false;
	//}
	Q.data[Q.rear] = value;
	//Q.rear++;
	Q.rear = (Q.rear + 1) % MAXSIZE;				//循环队列
	return true;
}


/*
* 出队
*/
bool DeSqQueue(SqQueue &Q, int &value){
	//if (IsSqQueueEmpty(Q)) {
	//	return false;
	//}
	value = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;				//循环
	return true;
}


/*
* 读队头
*/
int GetSqQueueHead(SqQueue Q){
	return Q.data[Q.front];
}

int GetSqQueueSize(SqQueue Q){
	int i = 0;
	i = abs(((Q.front - Q.rear) % MAXSIZE));		//取了个绝对值
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