//
// BinarySearchTree.c is Created by ShiQI on 2023/10/13 17:18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree {
    int data;
    struct BinarySearchTree *lChild;
    struct BinarySearchTree *rChild;
} BinarySearchTree;

BinarySearchTree *binarySearchTreeSearch(BinarySearchTree *tree, int key) {
    if (tree) {
        if (tree->data == key) {
            return tree;
        }
        if (tree->data > key) {
            return binarySearchTreeSearch(tree->lChild, key);
        }
        if (tree->data < key) {
            return binarySearchTreeSearch(tree->rChild, key);
        }
    } else {
        return NULL;
    }
}

void binarySearchTreeInsert(BinarySearchTree **T, int data) {
    if (*T == NULL) {
        *T = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
        (*T)->data = data;
        (*T)->rChild = NULL;
        (*T)->lChild = NULL;
    }
    if(data!=(*T)->data){
        if (data < (*T)->data) {
            binarySearchTreeInsert(&((*T)->lChild), data);
        } else{
            binarySearchTreeInsert(&((*T)->rChild), data);
        }
    } else{
        return;
    }
//    else if (data == (*T)->data) {
//        return;
//    }
//    else if (data < (*T)->data) {
//        binarySearchTreeInsert(&((*T)->lChild), data);
//    }
//    else {
//        binarySearchTreeInsert(&((*T)->rChild), data);
//    }
}

void proBST(BinarySearchTree *T) {
    if (T) {
        printf("%d ", T->data);
        proBST(T->lChild);
        proBST(T->rChild);
    }
}

void binarySearchTreeTest() {
    BinarySearchTree *T;
    int nums[6] = {8, 6, 10, 9, 11, 23};
    for (int i = 0; i < 6; i++) {
        binarySearchTreeInsert(&T, nums[i]);
    }
    proBST(T);
    printf("\n");
}