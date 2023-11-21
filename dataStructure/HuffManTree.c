/*************************************************************************
* File Name: HuffManTree.c
* Author: ShiQI
* E-mail: l3480342572@gmail.com
* Created Time: 2023/10/13 22:17
 ************************************************************************/
 //哈夫曼树
#include <stdio.h>
#include <stdlib.h>

typedef struct HuffManTree {
    int weight;
    int parent;
    int lChild;
    int rChild;
}HuffManTree;

typedef struct HFTree {
    HuffManTree* data;
    int length;
}HFTree;

HFTree* initHFTree(int* weight,  int length) {
    HFTree* T = (HFTree*)malloc(sizeof(HFTree));
    T -> data = (HuffManTree*)malloc(sizeof(HuffManTree) * (2 * length - 1));
    T -> length = length;
    for (int i = 0; i < length; i++) {
        T -> data[i].weight = weight[i];
        T -> data[i].parent = 0;
        T -> data[i].lChild = -1;
        T -> data[i].rChild = -1;
    }
    return T;
}

int* selectHFMin(HFTree* T) {
    int min = 10000;
    int secondMin = 10000;
    int minIndex;
    int secondIndex;
    for (int i = 0; i < T -> length; i++) {
        if (T -> data[i].parent == 0) {
            if (T -> data[i].weight < min) {
                min = T -> data[i].weight;
                minIndex = i;
            }
        }
    }
    for (int i = 0; i < T -> length; i++) {
        if (T -> data[i].parent == 0 && i != minIndex) {
            if (T -> data[i].weight < secondMin) {
                secondMin = T -> data[i].weight;
                secondIndex = i;
            }
        }
    }
    int* res = (int*)malloc(sizeof(int)* 2);
    res[0] = minIndex;
    res[1] = secondIndex;
    return res;
}

void createHFTree(HFTree* T) {
    int* res;
    int min;
    int secondMin;
    int length = T -> length * 2 - 1;
    for (int i = T -> length; i < length; i++) {
        res = selectHFMin(T);
        min = res[0];
        secondMin = res[1];
        T -> data[i].weight = T -> data[min].weight + T -> data[secondMin].weight;
        T -> data[i].lChild = min;
        T -> data[i].rChild = secondMin;
        T -> data[i].parent = 0;
        T -> data[min].parent = i;
        T -> data[secondMin].parent = i;
        T -> length ++;
    }
}

void preOrder(HFTree* T, int index) {
    if (index != -1) {
        printf("%d ", T -> data[index].weight);
        preOrder(T, T -> data[index].lChild);
        preOrder(T, T -> data[index].rChild);
    }
}

void haffManTree() {
    int weight[7] = {5,1,3,6,11,2,4};
    HFTree* T = initHFTree(weight, 7);
    createHFTree(T);
    preOrder(T, T -> length - 1);
    printf("\n");
}