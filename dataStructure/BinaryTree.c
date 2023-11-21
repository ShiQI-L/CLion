//
// Created by ShiQI on 2023/10/2 13:14.
#include <stdio.h>
#include <stdlib.h>

//二叉树的相关操作
typedef struct BinaryTree {
    char data;
    struct BinaryTree *lChild;
    struct BinaryTree *rChild;
} BinaryTree;

/**
 * 定义一个链式循环队列
 */
typedef struct QueueNode{
    BinaryTree *data;
    struct QueueNode* pre;
    struct QueueNode* next;
}QueueNode;

/**
 * 创建一个树
 * 先序遍历入树
 * @param T
 * @param data
 * @param index
 */
void createBinaryTree(BinaryTree **T, char *data, int *index) {
    char ch;
    ch = data[*index];
    *index+=1;
    if (ch == '#') {
        //此时树为空
        *T = NULL;
    } else {
        //此时不为空
        *T = (BinaryTree *) malloc(sizeof(BinaryTree));
        (*T)->data = ch;
        //创建左右子树
        createBinaryTree(&((*T)->lChild), data, index);
        createBinaryTree(&((*T)->rChild), data, index);
    }
}

/**
 * 先序遍历
 * @param T
 */
void preOrder_BinaryTree(BinaryTree *T) {
    if (T == NULL) {
        return;
    } else {
        //先办事
        printf("%c ", T->data);
        //处理左孩子
        preOrder_BinaryTree(T->lChild);
        //处理右孩子
        preOrder_BinaryTree(T->rChild);
    }

}
/**
 * 中序遍历
 * @param T
 */
void inOrder_BinaryTree(BinaryTree *T) {
    if (T == NULL) {
        return;
    } else {
        //先处理左孩子
        inOrder_BinaryTree(T->lChild);
        //再办事
        printf("%c ", T->data);
        //再处理右孩子
        inOrder_BinaryTree(T->rChild);
    }
}
/**
 * 后序遍历
 * @param T
 */
void postOrder_BinaryTree(BinaryTree *T) {
    if (T == NULL) {

        return;
    } else {
        //先处理左孩子
        postOrder_BinaryTree(T->lChild);
        //再处理右孩子
        postOrder_BinaryTree(T->rChild);
        //最后办事
        printf("%c ", T->data);
    }
}
/**
 * 初始化队
 * @return
 */
QueueNode *initBinaryTreeQueue(){
    QueueNode *Q=(QueueNode*) malloc(sizeof(QueueNode));
    Q->data=NULL;
    Q->pre=Q;
    Q->next=Q;
    return Q;
}
/**
 * 入队
 * @param data 二叉树的头结点地址
 * @param Q
 */
void enBinaryTreeQueue(BinaryTree *data,QueueNode*Q){
    QueueNode *node=(QueueNode*) malloc(sizeof(QueueNode));
    node->data=data;
    node->pre=Q->pre;//
    node->next=Q;
    Q->pre->next=node;
    Q->pre=node;
}
/**
 * 判空,若为空返回 1;不为空返回 0;
 * @param Q
 * @return
 */
int isEmpty(QueueNode*Q){
    if(Q->next==Q){
        return 1;
    } else{
        return 0;
    }
}
/**
 * 出队
 * @param Q
 * @return
 */
QueueNode *deBinaryTreeQueue(QueueNode*Q){
    if(isEmpty(Q)){
        return NULL;
    } else{
        QueueNode *q=Q->next;
        q->next->pre=Q;
        Q->next=q->next;
        return q;
    }
}
/**
 * 利用循环队列层次遍历树
 * @param T
 * @param Q
 */
void levelTraverse(BinaryTree*T,QueueNode*Q){
    enBinaryTreeQueue(T,Q);//将树的根节点(第一次)传入队中
    while (!isEmpty(Q)){//若队列非空继续循环
        QueueNode*node= deBinaryTreeQueue(Q);//将该结点出队
        printf("%c ",node->data->data);//打印该结点
        if(node->data->lChild){//若该结点左子树非空,传入队列
            enBinaryTreeQueue(node->data->lChild,Q);
        }
        if(node->data->rChild){//若该结点右子树非空,传入队列
            enBinaryTreeQueue(node->data->rChild,Q);
        }
    }
}
/**
 * 测试
 */
void BinaryTrees() {
    BinaryTree *T;
    int index = 0;
    createBinaryTree(&T, "ABZ##B##CX##G##", &index);
    QueueNode *Q= initBinaryTreeQueue();
    preOrder_BinaryTree(T);
    printf("\n");
    inOrder_BinaryTree(T);
    printf("\n");
    postOrder_BinaryTree(T);
    printf("\n");
    levelTraverse(T,Q);
}