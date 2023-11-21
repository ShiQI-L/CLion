//
// Created by ShiQI on 2023/9/16 20:58.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//单链表 操作:初始化 头插法 尾插法 删除 打印
typedef struct SingleLinkedList {
    int data;
    struct SingleLinkedList *next;
} SingleLinkedList;

/**
 * 初始化单链表
 * @return
 */
SingleLinkedList *initListNode() {
    SingleLinkedList *L = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    L->data = 0;
    L->next = L;
    return L;
}

/**
 * 单链表头插法
 * @param L
 * @param data
 */
void headInsert(SingleLinkedList *L, int data) {
    SingleLinkedList *node = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

/**
 * 单链表尾插法
 * @param L
 * @param data
 */
void tailInsertNode(SingleLinkedList *L, int data) {
    SingleLinkedList *node = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    SingleLinkedList *n = L;
    while (n->next != L) {//得到L的尾结点
        n = n->next;
    }
    node->next = L;
    n->next = node;
    node->data = data;
    L->data++;
}

/**
 * 单链表删除操作
 * @param L
 * @param data
 * @return
 */
int deleteNode(SingleLinkedList *L, int data) {
    SingleLinkedList *node = L->next;
    SingleLinkedList *pre = L;
    while (node != L) {
        if (node->data == data) {
            //删除操作
            pre->next = node->next;
            free(node);
            L->data--;
            return TRUE;
        }
        pre = node;
        node = node->next;
    }
    return FALSE;
}

/**
 * 打印一个单链表
 * @param L
 */
void printSingleLoopLinkedList(SingleLinkedList *L) {
    SingleLinkedList *node = L->next;
    while (node != L) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\t");
    printf("共有%d个元素\n", L->data);
}

void SingleLinkedLists() {
    //单链表
    SingleLinkedList *L = initListNode();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 5);
    tailInsertNode(L, 6);
    tailInsertNode(L, 7);
    tailInsertNode(L, 8);
    tailInsertNode(L, 9);
    tailInsertNode(L, 10);
    deleteNode(L, 10);
    deleteNode(L, 1);
    printSingleLoopLinkedList(L);
}

