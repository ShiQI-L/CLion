//
// PreThreadTree.c is Created by ShiQI on 2023/10/13 14:45.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct PreThreadTree {
    char data;
    struct PreThreadTree *lChild;
    struct PreThreadTree *rChild;
    int ltag;
    int rtag;
} PreThreadTree;

void createThreadTree(PreThreadTree **T, char *data, int *index) {
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#') {
        //此时树为空
        *T = NULL;
    } else {
        //此时不为空
        *T = (PreThreadTree *) malloc(sizeof(PreThreadTree));
        (*T)->data = ch;
        (*T)->rtag = 0;
        (*T)->ltag = 0;
        //创建左右子树 逻辑一致 进行递归操作
        createThreadTree(&((*T)->lChild), data, index);
        createThreadTree(&((*T)->rChild), data, index);
    }
}

void preThreadTree(PreThreadTree *T, PreThreadTree **pre) {
    if (T) {
        if (T->lChild == NULL) {//左子树为空,建立前驱线索
            T->lChild = *pre;
            T->ltag = 1;
        }
        if (*pre != NULL && (*pre)->rChild == NULL) {
            (*pre)->rChild = T;//建立前驱结点的后继线索
            (*pre)->rtag = 1;
        }
        (*pre) = T;//标记当前结点成为刚刚访问过的结点
        if (T->ltag == 0) {
            preThreadTree(T->lChild, pre);//递归,线索化左子树
        }
        preThreadTree(T->rChild, pre);//递归,线索化右子树
    }
}

void creatPreThreadTree(PreThreadTree *T){
    PreThreadTree *pre=NULL;
    if(T!=NULL){
        preThreadTree(T,&pre);
        pre->rChild=NULL;
        pre->rtag=1;
    }
}

PreThreadTree *getPreThreadTreeNext(PreThreadTree *node) {
    if(node->ltag==1||node->rtag==1){
        return node->rChild;
    } else{
        return node->lChild;
    }
}


void preThreadTreeTest() {
    PreThreadTree *tree;
    int index=0;
    createThreadTree(&tree,"AB##C##",&index);
    creatPreThreadTree(tree);
    for (PreThreadTree *node = tree; node !=NULL ; node= getPreThreadTreeNext(node)) {
        printf("%c ",node->data);
    }
    printf("\n");
}
