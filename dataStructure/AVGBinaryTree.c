/*************************************************************************
* File Name: AVGBinaryTree.c
* Author: ShiQI
* E-mail: l3480342572@gmail.com
* Created Time: 2023/10/13 21:00
 ************************************************************************/
typedef int E;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b);//求两数最大值

typedef struct AVGTree {
    E element;
    struct AVGTree *lChild;
    struct AVGTree *rChild;
    int height;//每个结点记录一下当前子树的高度,便于计算平衡因子
} AVGTree, *AVGTreeNode;

AVGTreeNode initAVGTree(E element) {
    AVGTreeNode node = (AVGTree *) malloc(sizeof(AVGTree));
    node->lChild = node->rChild = NULL;
    node->element = element;
    node->height = 1;//初始化时高度为1
    return node;
}

int getHeight(AVGTreeNode root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}


AVGTreeNode leftRotation(AVGTreeNode root) {//RR左旋操作,传入原本的根节点(最小不平衡子树的根节点),返回新的根节点
    AVGTreeNode newRoot = root->rChild;
    root->rChild = newRoot->lChild;//原本根节点的右边等于新的根节点的左边
    newRoot->lChild = root;//新的根节点的左边是原本的根节点

    //变换高度
    //只有变换的两个节点的高度发生了变化,所以root和newRoot的高度为其左右子树最高的一方加一
    //移动一个结点时,对于其子树的高度变化是不影响的,或者说将一个节点及其子树拎出来,其高度并没有发生改变
    //左旋操作造成高度改变的原因是root变成了newRoot的左子树,newRoot原来的的左子树变成了root的右子树,其高度发生了变化,进而引起newRoot的高度也发生了变化
    root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1;//
    newRoot->height = max(getHeight(newRoot->lChild), getHeight(newRoot->rChild)) + 1;
    return newRoot;
}

AVGTreeNode rightRotation(AVGTreeNode root) {//LL右旋操作,传入原本的根节点(最小不平衡子树的根节点),返回新的根节点
    AVGTreeNode newRoot = root->lChild;
    root->lChild = newRoot->rChild;//root的左孩子等于newRoot的右孩子
    newRoot->rChild = root;//newRoot的右孩子是root

    //变换高度
    //只有变换的两个节点的高度发生了变化,所以root和newRoot的高度为其左右子树最高的一方加一
    //移动一个结点时,对于其子树的高度变化是不影响的,或者说将一个节点及其子树拎出来,其高度并没有发生改变
    //左旋操作造成高度改变的原因是root变成了newRoot的左子树,newRoot原来的的左子树变成了root的右子树,其高度发生了变化,进而引起newRoot的高度也发生了变化
    root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1;//
    newRoot->height = max(getHeight(newRoot->lChild), getHeight(newRoot->rChild)) + 1;
    return newRoot;
}
/**
 *
 * @param root
 * @return
 */
//                  15                              15                             13                             /
//                /    \                          /    \                         /    \                           /
//              12     20                       13     20                       12     15                         /
//             /  \           ---->            /  \            ---->           /      /   \                       /
//           11    13                        12    14                         11    14     20                     /
//                   \                       /                                                                    /
//                   14                    11                                                                     /
AVGTreeNode LRRotation(AVGTreeNode root) {
    root->lChild = leftRotation(root->lChild);
    return rightRotation(root);
}
/**
 * 先右旋再左旋,
 * @param root
 * @return
 */
//                  15                              15                             17                             /
//                /    \                          /    \                         /    \                           /
//              13     20                       13     17                       15    20                          /
//                    /   \     ---->                 /  \     ---->           /  \     \                         /
//                   17   21                         16  20                   13  16    21                        /
//                  /                                      \                                                      /
//                 16                                      21                                                     /
AVGTreeNode RLRotation(AVGTreeNode root) {
    root->rChild = rightRotation(root->rChild);
    return leftRotation(root);
}


AVGTreeNode AVGInsert(AVGTreeNode root, E element) {
    if (root == NULL) {
        root = initAVGTree(element);
    } else {
        if (element < root->element) {
            root->lChild = AVGInsert(root->lChild, element);
            if (getHeight(root->lChild) - getHeight(root->rChild) > 1) {
                if (root->lChild->element > element) {//LL型
                    root = rightRotation(root);
                } else {//LR型
                    root = LRRotation(root);
                }
            }
        }
        if (element > root->element) {
            root->rChild = AVGInsert(root->rChild, element);
            if (getHeight(root->rChild) - getHeight(root->lChild) > 1) {
                if (root->rChild->element < element) {//RR型
                    root = leftRotation(root);
                } else {//RL型
                    root = RLRotation(root);
                }
            }
        }
//        if (root->element == element) {
//            return 0;
//        }
    }
    root->height = max(getHeight(root->rChild), getHeight(root->lChild)) + 1;
    return root;
}


int width, height;

//T为二叉树的根节点,a是数组的起始地址,i,j是当前节点在数组中的位置
//如果节点有孩子,其孩子的j坐标为 j±(height-i+1)/2
void fillArray(AVGTreeNode T, E *a, int i, int j) {
    int ti, tj;
    if (T) { //如果该位置有节点
        *(a + (i * width) + j) = T->element; //向数组该点填入字符
        if (T->lChild) //有左右孩子给对应的连接线,左右孩子的值在下一层递归赋
        {
            //将该点与其左孩子之间的连线全部填上'/'
            for (ti = i + 1, tj = j - 1; tj > j - (height - i + 1) / 2; tj--) {
                *(a + ((ti) * width) + tj) = -1;
                ti++;
            }
        }
        if (T->rChild) {
            for (ti = i + 1, tj = j + 1; tj < j + (height - i + 1) / 2; tj++) {
                *(a + ((ti) * width) + tj) = 1;
                ti++;
            }
        }
        //经过循环,ti恰好指到其孩子所在的层
        fillArray(T->lChild, a, ti, j - (height - i + 1) / 2);
        fillArray(T->rChild, a, ti, j + (height - i + 1) / 2);
    }
}   

void printTreeNode(AVGTreeNode root) {
    int i, j;
    int n = root->height;
    //在计算机中数据以二进制形式存储,所以一个数据左移1位就相当于乘以2的1次方
    width = (2 << n) - 3;  // 2^(n+1)-3
    height = (2 << (n - 1)) - 1; // 2^n-1
    E *a = (E *) malloc(sizeof(E) * (width * height)); // 申请空间
    // 空间初始化为0
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *(a + (i * width) + j) = 0;
        }
    }
    //调用之前定义好的函数,填充打印数组
    fillArray(root, a, 0, (width - 1) / 2);

    //根据打印数组的内容来实现打印
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (*(a + (i * width) + j) == -1) {
                printf("/");
            } else if (*(a + (i * width) + j) == 1) {
                printf("\\");
            } else if (*(a + (i * width) + j) == 0) {
                printf(" ");
            } else {
                printf("%d", *(a + (i * width) + j));
            }
        }
        printf("\n");
    }
}

void avgTreeTest() {
    AVGTreeNode root = NULL;
    int index = 1;
    while (index != 9999) {
        E e;
        scanf_s("%d", &e);
        index = e;
        if (index != 9999) {
            root = AVGInsert(root, e);
            printf("");
        }
    }
    printTreeNode(root);
}