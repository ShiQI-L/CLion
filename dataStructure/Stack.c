//
// Created by ShiQI on 2023/9/21 14:55.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//栈;操作:初始化 入栈 出栈 判空
typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

/**
 * 栈的初始化
 * @return
 */
Stack *initStack() {
    Stack *S = (Stack *) malloc(sizeof(Stack));
    S->data = 0;
    S->next = NULL;
    return S;
}

/**
 * 判空操作,空为1,否则为0
 * @param S
 * @return
 */
int isEmptyStack(Stack *S) {
    if (S->data == 0 || S->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 获取栈顶元素
 * @param S
 * @return
 */
int getTopStack(Stack *S) {
    if (isEmptyStack(S)) {//栈空,报错
        return -1;
    } else {
        int a = S->next->data;
        return a;
    }
}

/**
 * 出栈
 * @param S
 * @return
 */
int popStack(Stack *S) {
    if (isEmptyStack(S)) {//栈空,报错
        return -1;
    } else {
        Stack *node = S->next;
        S->next = node->next;
        int data = node->data;
        free(node);
        S->data--;
        return data;
    }
}

/**
 * 进栈
 * @param S
 * @param data
 */
void pushStack(Stack *S, int data) {
    Stack *node = (Stack *) malloc(sizeof(Stack));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

/**
 * 遍历栈中元素
 * @param S
 */
void printStack(Stack *S) {
    Stack *node = (Stack *) malloc(sizeof(Stack));
    node = S->next;
    printf("L->");
    while (node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
/**
 * 栈在括号匹配中的应用
 * @param c
 * @param length
 * @return
 */
bool bracketCheck(char c[], int length) {
    Stack *S;
    S = initStack();
    for(int i=0;i<length;i++){
        if(c[i]=='('||c[i]=='{'||c[i]=='['){
            pushStack(S,c[i]);
        } else{
            if(isEmptyStack(S)){
                return false;
            } else{
                int top;
                top=popStack(S);
                if(top=='('&&c[i]!=')')
                    return false;
                if(top=='{'&&c[i]!='}')
                    return false;
                if(top=='['&&c[i]!=']')
                    return false;
            }
        }
    }
    return isEmptyStack(S);
}

void stacks() {
    Stack *S = initStack();
    pushStack(S, 1);
    pushStack(S, 2);
    pushStack(S, 3);
    pushStack(S, 4);
    printStack(S);
    int a = popStack(S);
    printf("%d\n", a);
    printStack(S);
    char c[]={'(','{',']','}',')'};
    int s=bracketCheck(c,5);
    printf("%d\n",s);
}