/*
* ˳��ջ��ջ��˳��洢�ṹʵ��
* ջ��ֻ������һ�˽��в����ɾ�������Ա�
* �ص㣺����ȳ�(Last In First Out   LIFO)
* ������(Catalan)����n����ͬԪ�ؽ�ջ����ջԪ��������ϸ���Ϊ(1/(n+1))Cn2n
* status: SomeQuestion
*/

#define MAXSIZE 20
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
	return true;
}

/*
* ��ȡջ��Ԫ��
*/
bool GetTopElem(SqStack& S, int& value) {
	if (IsSqStackEmpty) {
		return false;
	}
	value = S.data[S.top];
	return true;
}


/*
* ����Ӧ�ã���׺���ʽ����
*/
int Calculate(char c[]) {
	SqStack S;
	InitSqStack(S);
	int value;
	for (int i = 0; i < MAXSIZE; i++) {
		if ('0' <= c[i] && '9' >= c[i]) {
			Push(S, c[i]);
		}
		else if ('+' == c[i] || '-' == c[i] || '*' == c[i] || '/' == c[i]) {
			int a, b;
			Pop(S, a);
			Pop(S, b);
			switch (c[i]) {
			case '+':
				Push(S, a - 48 + b - 48);
				break;
			case '-':
				Push(S, a - 48 - b - 48);
				break;
			case '*':
				Push(S, a - 48 * b - 48);
				break;
			case '/':
				Push(S, a - 48 / b - 48);
				break;
			default:
				break;
			}
		}
	}
	GetTopElem(S, value);
	return value;
}


void main() {
	//SqStack S;
	//InitSqStack(S);
	//printf("%d", IsSqStackEmpty(S));
	//Push(S, 5);
	//Push(S, 4);
	//Push(S, 3);
	//Push(S, 2);
	//Push(S, 1);
	//int a = GetTopElem(S, a);
	//printf("%d", a);
	//int b = Pop(S, b);
	//GetTopElem(S, a);
	//printf("%d", a);


	//char c[MAXSIZE];
	//int i = 0;
	//printf("��������׺���ʽ����#��Ϊ������־��");
	//scanf("%c", &c[i++]);
	//while (c[i-1] != '#') {
	//	scanf("%c", &c[i++]);
	//}
	//int value = Calculate(c);
	//printf("%d", value);
}
//���ﻹ�е����⣬���ڻ�����

//5.8���£��������⻹ͦ��..