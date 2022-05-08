/*
* 利用Stack实现中缀表达式到后缀的转化
* 1.左优先
* 2.依次扫描操作数和运算符
* 3.操作数压栈，运算符弹出
* status:Archived
*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef struct {
    char* data;
    char* top;
    int StackSize;
}SqStack;


void InitStack(SqStack* s) {
    s->data = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
    if (!s->data)
        exit(0);

    s->top = s->data;
    s->StackSize = STACK_INIT_SIZE;
}


void Push(SqStack* s, char e) {
    if (s->top - s->data >= s->StackSize) {
        s->data = (char*)realloc(s->data, (s->StackSize + STACKINCREMENT) * sizeof(char));
        if (!s->data) {
            exit(0);
        }
        s->top = s->data + s->StackSize;
        s->StackSize = s->StackSize + STACKINCREMENT;
    }

    *(s->top) = e;      // 存放数据
    s->top++;
}


void Pop(SqStack* s, char* e) {
    if (s->top == s->data)
        return;

    *e = *--(s->top);   // 将栈顶元素弹出并修改栈顶指针
    //*e=*(s->top)
    //s->top--
}


int StackLen(SqStack s) {
    return (s.top - s.data);
}


//int main() {
//    SqStack s;
//    char a[STACK_INIT_SIZE] = {};
//    int i = 0;
//    char c, e;
//
//    InitStack(&s);
//
//    printf("请输入中缀表达式，以#作为结束标志：");
//    scanf("%c", &c);
//
//    while (c != '#') { 
//        while (c >= '0' && c <= '9') {
//            printf("%c", c);
//            a[i++] = c;
//            scanf("%c", &c);
//            if (c < '0' || c>'9') {
//                printf(" ");
//            }
//        }
//        if (')' == c) {
//            Pop(&s, &e);
//            while ('(' != e) {
//                a[i++] = e;
//                printf("%c ", e);
//                Pop(&s, &e);
//            }
//        }
//        else if ('+' == c || '-' == c) {
//            if (!StackLen(s)) {
//                Push(&s, c);
//            }
//            else {
//                do {
//                    Pop(&s, &e);
//                    if ('(' == e) {
//                        Push(&s, e);
//                    }
//                    else {
//                        a[i++] = e;
//                        printf("%c ", e);
//                    }
//                }
//                while (StackLen(s) && '(' != e);
//                Push(&s, c);
//            }
//        }
//        else if ('*' == c || '/' == c || '(' == c) {
//            Push(&s, c);
//        }
//        else if ('#' == c) {
//            break;
//        }
//        else {
//            printf("\n出错：输入格式错误！\n");
//            return -1;
//        }
//        scanf("%c", &c);
//    }
//    while (StackLen(s)) {
//        Pop(&s, &e);
//        a[i++] = e;
//        printf("%c ", e);
//    }
//    printf("\n");
//    for (int i = 0; i < STACK_INIT_SIZE; i++) {
//        printf("%c", a[i]);
//    }
//    return 0;
//}