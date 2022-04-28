/**
静态链表：数组方式实现的链表
优：crud操作不用大量移动指针
缺：无法随机存取，容量固定
**/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct Node {
	int data;//数据
	int next;//游标
}SLinkList [MAXSIZE];//定义链表类型的结构体数组


/*
初始化静态链表
*/
bool InitSLinkList(SLinkList &L) {
	L[0].data = -1;
	for (int i = 1; i < MAXSIZE; i++) {
		L[i].next = NULL;
	}
	return true;
}

/*
插入
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
判空
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
判满
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