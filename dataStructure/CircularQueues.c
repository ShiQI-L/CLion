//
// Created by ShiQI on 2023/9/25 22:33.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
//循环队列 判空 判满 入队 出队 遍历

#define MAXSIZE 10

typedef struct CircularQueue{
    int front;
    int rear;
    int data[MAXSIZE];
}CircularQueue;

/**
 * 循环队列的初始化
 * @return
 */
CircularQueue * initCircularQueue(){
    CircularQueue *Q=(CircularQueue*) malloc(sizeof(CircularQueue ));
    Q->rear=Q->front=0;
    return Q;
}
/**
 * 判断队列是否满
 * @param Q
 * @return
 */
int isCircularQueueFull(CircularQueue *Q){
    if((Q->rear+1)%MAXSIZE==Q->front){
        return 1;
    } else{
        return 0;
    }
}
/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
int isCircularQueueEmpty(CircularQueue*Q){
    if(Q->rear==Q->front){
        return 1;
    }
    return 0;
}
/**
 * 入队
 * @param Q
 * @param data
 * @return
 */
int enCircularQueue(CircularQueue*Q,int data){
    if(isCircularQueueFull(Q)){
        return 0;
    } else{
        Q->data[Q->rear]=data;
        Q->rear=(Q->rear+1)%MAXSIZE;
        return 1;
    }
}
/**
 * 出队
 * @param Q
 * @return
 */
int deCircularQueue(CircularQueue*Q){
    if(isCircularQueueEmpty(Q)){
        return -1;
    } else{
        int data=Q->data[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        return data;
    }
}
/**
 * 遍历;要点:判断队列中有多少个元素
 * @param Q
 */
void printCircularQueue(CircularQueue*Q){
    //要知道当前有多少个元素
    int length=(Q->rear-Q->front+MAXSIZE)%MAXSIZE;
    printf("%d\n",length);
    int index=Q->front;
    for(int i=0;i<length;i++){
        printf("%d->",Q->data[index]);
        index= (index+1)%MAXSIZE;
    }
    printf("NULL\n");
}


void CircularQueues(){
    CircularQueue *Q=initCircularQueue();
    enCircularQueue(Q,1);
    enCircularQueue(Q,2);
    enCircularQueue(Q,3);
    enCircularQueue(Q,4);
    printCircularQueue(Q);
}