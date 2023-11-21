//
// Created by ShiQI on 2023/9/16 21:06.
//
#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
//双链表 操作:初始化 头插法 尾插法 删除 打印
typedef struct DoubleLinkedList {
    int data;
    struct DoubleLinkedList *pre;
    struct DoubleLinkedList *next;
} DoubleLinkedList;





/**
 * 初始化一个双链表
 * @return
 */
DoubleLinkedList *initDoubleLinkList() {
    DoubleLinkedList *L = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

/**
 * 双链表的头插法
 * @param L
 * @param data
 */
void headInsertDoubleLinkedList(DoubleLinkedList *L, int data) {
    DoubleLinkedList *node = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    node->data = data;
    if (L->data == 0) {
        //链表为空
        node->next = L->next;
        node->pre = L;
        L->next = node;
        L->data++;
    } else {
        node->pre = L;
        node->next = L->next;
        L->next->pre = node;
        L->next = node;
        L->data++;
    }

}

/**
 * 双链表的尾插法
 * @param list
 * @param data
 */
void tailInsertDoubleLinkedList(DoubleLinkedList *L, int data) {
    DoubleLinkedList *node = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    DoubleLinkedList *list = L;
    node->data = data;
    while (list->next != NULL) {//遍历找到最后一个节点,最后一个节点的next指针指向NULL
        list = list->next;
    }
    node->next = list->next;
    list->next = node;
    node->pre = list;
    L->data++;
}

/**
 * 双链表的删除操作
 * @param L
 * @param data
 * @return
 */
int deleteDoubleLinkedList(DoubleLinkedList *L, int data) {
    DoubleLinkedList *node = L->next;
    while (node) {
        if (node->data == data) {
            //删除操作
            node->pre->next = node->next;
            node->next->pre = node->pre;
            free(node);
            L->data--;
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}


/**
 * 打印双链表
 * @param L
 */
void printDoubleLinkedList(DoubleLinkedList *L) {
    DoubleLinkedList *node = L->next;
    while (node) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\t");
    printf("共有%d个元素\n", L->data);

}

void DoubleLinkedLists() {
    //双链表
    DoubleLinkedList *doubleLinkedList = initDoubleLinkList();
    headInsertDoubleLinkedList(doubleLinkedList, 1);
    headInsertDoubleLinkedList(doubleLinkedList, 2);
    headInsertDoubleLinkedList(doubleLinkedList, 3);
    headInsertDoubleLinkedList(doubleLinkedList, 4);
    headInsertDoubleLinkedList(doubleLinkedList, 5);
    tailInsertDoubleLinkedList(doubleLinkedList, 6);
    tailInsertDoubleLinkedList(doubleLinkedList, 7);
    tailInsertDoubleLinkedList(doubleLinkedList, 8);
    tailInsertDoubleLinkedList(doubleLinkedList, 9);
    tailInsertDoubleLinkedList(doubleLinkedList, 10);
    deleteDoubleLinkedList(doubleLinkedList, 4);
    deleteDoubleLinkedList(doubleLinkedList, 5);
    printDoubleLinkedList(doubleLinkedList);
}