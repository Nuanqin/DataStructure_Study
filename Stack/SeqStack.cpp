/*
* 顺序栈：栈的顺序存储结构实现
* 栈：只允许在一端进行插入或删除的线性表
* 特点：后进先出(Last In First Out   LIFO)
* 卡特兰(Catalan)数：n个不同元素进栈，出栈元素排列组合个数为(1/(n+1))Cn2n
* status: SomeQuestion
*/

#define MAXSIZE 20
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data[MAXSIZE];				//静态数组存放栈中元素
	int top;						//栈顶指针
}SqStack;

//特殊用法：共享栈
typedef struct {
	int data[MAXSIZE];
	int top0;						//0号栈头
	int top1;						//1号栈头
}ShStack;

/*
* 共享栈判定栈满
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
* 初始化
*/
void InitSqStack(SqStack& S) {
	S.top = -1;						//初始栈顶指针可指向-1、也可指向0，两种写法需要自行微调
}								

/*
* 判空
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
* 入栈/压栈
*/
bool Push(SqStack& S, int value) {
	if (S.top == MAXSIZE - 1) {		//判满
		return false;
	}
	//S.top = S.top + 1;				//栈顶指针上移
	//S.data[S.top] = value;			//新元素入栈
	S.data[++S.top] = value;			
	return true;
}

/*
* 出栈/弹栈
*/
bool Pop(SqStack& S, int& value) {
	if (IsSqStackEmpty) {			//判空
		return false;
	}
	value = S.data[S.top--];		//同上
	return true;
}

/*
* 获取栈顶元素
*/
bool GetTopElem(SqStack& S, int& value) {
	if (IsSqStackEmpty) {
		return false;
	}
	value = S.data[S.top];
	return true;
}


/*
* 特殊应用：后缀表达式计算
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
	//printf("请输入中缀表达式，以#作为结束标志：");
	//scanf("%c", &c[i++]);
	//while (c[i-1] != '#') {
	//	scanf("%c", &c[i++]);
	//}
	//int value = Calculate(c);
	//printf("%d", value);
}
//这里还有点问题，后期回来搞

//5.8更新：好像问题还挺大..