/*
* 利用Stack实现中缀表达式到前缀的转化
* 1.右优先
* 2.依次扫描操作数和运算符
* 3.操作数压栈，运算符弹出
* status:Some Questions
*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

//typedef struct {
//    char* data;
//    char* top;
//    int StackSize;
//}SqStack;
//
//
//void InitStack(SqStack &s) {
//    s.data = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
//    if (!s.data)
//        exit(0);
//
//    s.top = s.data;
//    s.StackSize = STACK_INIT_SIZE;
//}
//
//
//void Push(SqStack* s, char e) {
//    if (s->top - s->data >= s->StackSize) {         //存储空间增量
//        s->data = (char*)realloc(s->data, (s->StackSize + STACKINCREMENT) * sizeof(char));    
//        if (!s->data) {
//            exit(0);
//        }
//        s->top = s->data + s->StackSize;
//        s->StackSize = s->StackSize + STACKINCREMENT;                                         
//    }
//
//    *(s->top) = e;      // 存放数据
//    s->top++;
//}
//
//
//void Pop(SqStack* s, char* e) {
//    if (s->top == s->data)
//        return;
//
//    *e = *--(s->top);   // 将栈顶元素弹出并修改栈顶指针
//    //*e=*(s->top)
//    //s->top--
//}
//
//
//int StackLen(SqStack s) {
//    return (s.top - s.data);
//}


int Priority(char c) {
    switch (c) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '(':
        return 3;
    default:
        return -1;
    }
}


//void PrefixMethod(SqStack &s) {
    //SqStack ops;
    //InitStack(ops);
    //while (StackLen(s)) {
    //    char c,e;
    //    Pop(&s, &c);
    //    if ('0' <= c && '9' >= c) {
    //        printf("%c", c);
    //        if (c < '0' || c>'9') {
    //            printf(" ");
    //        }
    //    }
    //    else if (')' == c) {
    //        Pop(&s, &e);
    //        while ('('!=e) {
    //            printf("%c", e);
    //            Pop(&s, &e);
    //        }
    //    }
    //    else if ('+' == c || '-' == c) {
    //        if (!StackLen(s)) {
    //            exit(0);
    //        }
    //        else {

    //        }
    //    }
    //}
    //Some Questions
//}


//int main() {
//    SqStack s;
//    char c, e;
//    InitStack(s);
//
//    printf("请输入中缀表达式，以#作为结束标志：");
//    scanf("%c", &c);
//    while ('#' != c) {
//        Push(&s, c);
//        scanf("%c", &c);
//    }
//}