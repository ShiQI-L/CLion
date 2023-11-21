//
// Created by ShiQI on 2023/9/25 21:33.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

//初始化队 出队 入队
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

/**
 * 初始化操作
 * @return
 */
Queue *initQueue() {
    Queue *Q = (Queue *) malloc(sizeof(Queue));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}
/**
 * 队列是否为空
 * @param Q
 * @return
 */
int isQueueEmpty(Queue*Q){
    if(Q->data==0||Q->next==NULL){
        return 1;
    }
    return 0;
}

/**
 * 进队操作
 * @param Q
 * @param data
 */
void enQueue(Queue *Q, int data) {
    Queue *q = Q;
    Queue *node = (Queue *) malloc(sizeof(Queue));
    node->data=data;
    for(int i=0;i<Q->data;i++){
        q=q->next;
    }
    node->next=q->next;
    q->next=node;
    Q->data++;
}
int deQueue(Queue*Q){
    if(isQueueEmpty(Q)){
        return -1;
    } else{
        Queue *q=Q->next;
        int data=q->data;
        Q->next=q->next;
        return data;
    }
}
/**
 * 遍历队列
 * @param Q
 */
void printQueue(Queue*Q){
    Queue *q=Q->next;
    while (q){
        printf("%d->",q->data);
        q=q->next;
    }
    printf("NULL\n");
}

void QueueTest(){
    Queue *Q= initQueue();
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    enQueue(Q,4);
    enQueue(Q,5);
    printQueue(Q);
    int data=deQueue(Q);
    printf("%d\n",data);
    printQueue(Q);
}