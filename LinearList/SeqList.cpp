/*
* 顺序表：顺序存储
* 优：随机存取、高密存储
* 缺：大片连续空间分配不方便，改变容量不方便;
* status: Archived
*/

#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct {
	int* data;
	int Maxsize;
	int Length;;
}SeqList;


void InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.Length = 0;
	L.Maxsize = InitSize;
}//动态初始化使用malloc函数进行，需手动free


void IncreaseList(SeqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.Maxsize + len) * sizeof(int));
	for (int i = 0; i < L.Length; i++){
		L.data[i] = p[i];
	}
	L.Maxsize = L.Maxsize + len;
	free(p);
}


bool InsertList(SeqList& L, int pos, int value){
	if (pos < 1 || pos > L.Length + 1)
		return false;
	if (pos >= L.Maxsize)
		return false;

	for (int i = L.Length; i >= pos; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[pos - 1] = value;
	L.Length++;
	return true;
}


bool DeleteList(SeqList& L ,int pos ,int& value) {
	if (pos < 1 || pos > L.Length)
		return false;
	value = L.data[pos - 1];
	for (int i = pos; i < L.Length; i++){
		L.data[i-1] = L.data[i];
	}
	L.Length--;
	return true;
}


int GetElem(SeqList L, int pos) {
	return L.data[pos - 1];
}


int LocateElem(SeqList L, int value) {
	for (int i = 0; i < L.Length; i++){
		if (L.data[i] == value) {
			return i + 1;
		}
		else{
			return 0;
		}
	}

}


//int main() {
//	SeqList L;
//	InitList(L);
//	printf("%d\t", L.Maxsize);
//	IncreaseList(L, 5);
//	printf("%d\t", L.Maxsize);
//	printf("%d\t", L.Length);
//	InsertList(L, 1, 1);
//	InsertList(L, 2, 3);
//	InsertList(L, 3, 2);
//	printf("%d\t", L.Length);
//	int delval = -1;
//	if (DeleteList(L, 3, delval)) {
//		printf("%d\t", delval);
//	}
//	else {
//		printf("error\t");
//	}
//	return 0;
//}
