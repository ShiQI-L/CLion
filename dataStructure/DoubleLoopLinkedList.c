//
// Created by ShiQI on 2023/9/16 20:55.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//双循环链表 操作:初始化 头插法 尾插法 删除 遍历链表
typedef struct DoubleLoopLinkedList {
    int data;
    struct DoubleLoopLinkedList *pre;
    struct DoubleLoopLinkedList *next;
} DoubleLoopLinkedList;

/**
 * 初始化
 * @return
 */
DoubleLoopLinkedList * initDoubleLoopLinkedList(){
    DoubleLoopLinkedList *L=(DoubleLoopLinkedList*) malloc(sizeof(DoubleLoopLinkedList ));
    L->data=0;
    L->next=L;
    L->pre=L;
    return L;
}

/**
 * 头插法
 * @param L
 * @param data
 */
void headInsertDoubleLoopLinkedList(DoubleLoopLinkedList*L,int data){
    DoubleLoopLinkedList *node=(DoubleLoopLinkedList*) malloc(sizeof(DoubleLoopLinkedList));
    node->data=data;
    if(L->data==0){
        //链表为空
        node->pre=L;
        node->next=L->next;
        L->next=node;
        L->pre=node;
    } else{
        //链表不为空
        node->next=L->next;
        node->pre=L;
        L->next->pre=node;
        L->next=node;
    }
    L->data++;
}

/**
 * 尾插法
 * @param L
 * @param data
 */
void tailInsertDoubleLoopLinkedList(DoubleLoopLinkedList*L,int data){
    DoubleLoopLinkedList *node=initDoubleLoopLinkedList();
    node->data=data;
    DoubleLoopLinkedList *theLast;
    theLast=L->pre;//找到最后一个节点
    node->pre=theLast;
    node->next=L;
    L->pre=node;
    theLast->next=node;
    L->data++;

}
/**
 * 结点删除
 * @param L
 * @param data
 */
int  deleteDoubleLoopLinkedList(DoubleLoopLinkedList*L,int data){
    DoubleLoopLinkedList * node=L->next;
    while (node!=L){
        if(node->data==data){
            node->pre->next=node->next;
            node->next->pre=node->pre;
            free(node);
            L->data--;
            return TRUE;
        }
        node=node->next;
    }
    return FALSE;
}

/**
 * 遍历
 * @param L
 */
void printDoubleLoopLinkedList(DoubleLoopLinkedList *L){
    DoubleLoopLinkedList *node=L->next;
    while (node!=L){
        printf("%d->",node->data);
        node=node->next;
    }
    printf("L(头结点)->(%d)\t",L->next->data);
    printf("共有%d个元素",L->data);
}
void DoubleLoopLinkedLists(){
    DoubleLoopLinkedList *L=initDoubleLoopLinkedList();
    headInsertDoubleLoopLinkedList(L,1);
    headInsertDoubleLoopLinkedList(L,2);
    headInsertDoubleLoopLinkedList(L,3);
    headInsertDoubleLoopLinkedList(L,4);
    headInsertDoubleLoopLinkedList(L,5);

    tailInsertDoubleLoopLinkedList(L,6);
    tailInsertDoubleLoopLinkedList(L,7);
    tailInsertDoubleLoopLinkedList(L,8);
    tailInsertDoubleLoopLinkedList(L,9);
    tailInsertDoubleLoopLinkedList(L,10);

    deleteDoubleLoopLinkedList(L,5);
    deleteDoubleLoopLinkedList(L,7);
    printDoubleLoopLinkedList(L);
}