/*
* ˳��ջ��ջ��˳��洢�ṹʵ��
* ջ��ֻ������һ�˽��в����ɾ�������Ա�
* �ص㣺����ȳ�
* ������(Catalan)����n����ͬԪ�ؽ�ջ����ջԪ��������ϸ���Ϊ(1/(n+1))Cn2n
*/

#define MAXSIZE 10
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data[MAXSIZE];				//��̬������ջ��Ԫ��
	int top;						//ջ��ָ��
}SqStack;

//�����÷�������ջ
typedef struct {
	int data[MAXSIZE];
	int top0;						//0��ջͷ
	int top1;						//1��ջͷ
}ShStack;

/*
* ����ջ�ж�ջ��
*/
bool IsShStackFull(ShStack& S) {
	if (S.top0 + 1 == S.top1) {
		return true;
	}
	else {
		return false;
	}
}

/*
* ��ʼ��
*/
void InitSqStack(SqStack& S) {
	S.top = -1;						//��ʼջ��ָ���ָ��-1��Ҳ��ָ��0������д����Ҫ����΢��
}								

/*
* �п�
*/ 
bool IsSqStackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	else {
		return false;
	}
}

/*
* ��ջ/ѹջ
*/
bool Push(SqStack& S, int value) {
	if (S.top == MAXSIZE - 1) {		//����
		return false;
	}
	//S.top = S.top + 1;				//ջ��ָ������
	//S.data[S.top] = value;			//��Ԫ����ջ
	S.data[++S.top] = value;			
	return true;
}

/*
* ��ջ/��ջ
*/
bool Pop(SqStack& S, int& value) {
	if (IsSqStackEmpty) {			//�п�
		return false;
	}
	value = S.data[S.top--];		//ͬ��
}

/*
* ��ȡջ��Ԫ��
*/
bool GetTopElem(SqStack& S, int& value) {
	if (IsSqStackEmpty) {
		return false;
	}
	value = S.data[S.top];
}


