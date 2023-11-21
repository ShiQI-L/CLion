//
// Created by ShiQI on 2023/9/30 10:44.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct String {
    char *data;
    int len;
} String;

void StringTest();

String *initString();

void stringAssign(String *s, char *data);

void printString(String *s);

/**
 * 字符串的初始化
 * @return
 */
String *initString() {
    String *s = (String *) malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

/**
 * 往数组中插入元素
 * @param s
 * @param data
 */
void stringAssign(String *s, char *data) {
    if (s->data) {
        free(s->data);
    }
    int len = 0;
    char *temp = data;
    while (*temp) {
        len++;
        temp++;
    }
    if (len == 0) {
        s->data = NULL;
        s->len = 0;
    } else {
        temp = data;
        s->len = len;
        s->data = (char *) malloc(sizeof(char) * (len + 1));//为什么是len+1,因为字符数组最后需要'\0'标识数组结束
        for (int i = 0; i < len; i++, temp++) {
            s->data[i] = *temp;
        }
    }
}

/**
 * 打印字符串
 * @param s
 */
void printString(String *s) {
    for (int i = 0; i < s->len; i++) {
        printf(i == 0 ? "%c" : "->%c", s->data[i]);
    }
    printf("\n");
}

/**
 * 暴力匹配算法
 * @param master
 * @param sub
 */
void forceMarchString(String *master, String *sub) {
    int i = 0;
    int j = 0;
    while (i < master->len && j < sub->len) {
        if (master->data[i] == sub->data[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == sub->len) {
        printf("success!\n");
    } else {
        printf("fail.\n");
    }
}

int *getNext(String *s) {
    int *next = (int *) malloc(sizeof(int) * s->len);
    int i=0;
    int j=-1;
    next[i]=j;
    while (i<s->len-1){
        if(j==-1||s->data[i]==s->data[j]){
            i++;
            j++;
            next[i]=j;
        } else{
            j=next[j];
        }
    }
    return 0;
}

/**
 * KMP算法
 * @param master
 * @param sub
 * @return
 */
int KMPMarchString(String *master, String *sub) {

    return 0;
}

void StringTest() {
    String *s = initString();
    String *s1 = initString();
    stringAssign(s, "HELLO");
    stringAssign(s1, "LOo");
    forceMarchString(s, s1);
    printString(s);
}















