//
// ClueBinaryTree.c is Created by ShiQI on 2023/10/13 12:16.
//

#include <stdio.h>
#include <stdlib.h>

//线索二叉树的相关操作
typedef struct ClueBinaryTree {
    char data;
    struct ClueBinaryTree *lChild;
    struct ClueBinaryTree *rChild;
    int ltag;
    int rtag;
} ClueBinaryTree;

void createClueBinaryTree(ClueBinaryTree **T, char *data, int *index);

/**
 * 创建线索二叉树
 * @param T
 * @param data
 * @param index
 */
void createClueBinaryTree(ClueBinaryTree **T, char *data, int *index) {
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#') {
        //此时树为空
        *T = NULL;
    } else {
        //此时不为空
        *T = (ClueBinaryTree *) malloc(sizeof(ClueBinaryTree));
        (*T)->data = ch;
        (*T)->rtag = 0;
        (*T)->ltag = 0;
        //创建左右子树 逻辑一致 进行递归操作
        createClueBinaryTree(&((*T)->lChild), data, index);
        createClueBinaryTree(&((*T)->rChild), data, index);
    }
}

/**
 * 中序线索化操作
 *   **pre 需要改变指针的值并影响到全局,使用二重指针
 * @param T
 * @param pre
 */
void inThreadTree(ClueBinaryTree *T, ClueBinaryTree **pre) {
    if (T) {
        inThreadTree(T->lChild, pre);//递归,线索化左子树
        if (T->lChild == NULL) {//左子树为空,建立前驱线索
            T->lChild = *pre;
            T->ltag = 1;
        }
        if (*pre != NULL && (*pre)->rChild == NULL) {
            (*pre)->rChild = T;//建立前驱结点的后继线索
            (*pre)->rtag = 1;
        }
        (*pre) = T;//标记当前结点成为刚刚访问过的结点
        inThreadTree(T->rChild, pre);//递归,线索化右子树
    }
}

void creatInThread(ClueBinaryTree *tree){
    ClueBinaryTree *pre=NULL;
    if(tree!=NULL){//非空树,线索化
        inThreadTree(tree,&pre);//中序线索化二叉树
        pre->rtag = 1;//处理遍历的最后一个节点,此节点只有前驱没有后继,后继指针指向空
        pre->rChild = NULL;
    }
}
/**
 * 获取二叉树最左边的结点
 * @param tree
 * @return
 */
ClueBinaryTree *getClueBinaryTreeFirst(ClueBinaryTree *tree) {
    while (tree->ltag == 0) {
        tree = tree->lChild;
    }
    return tree;
}

/**
 * 获取下一个结点,使用线索遍历二叉树
 * @param node
 * @return
 */
ClueBinaryTree *getClueBinaryTreeNext(ClueBinaryTree *node) {
    if (node->rtag == 1) {
        return node->rChild;
    } else {
        return getClueBinaryTreeFirst(node->rChild);
    }
}


void ClueBinaryTrees() {
    ClueBinaryTree *tree;
    int index = 0;
    createClueBinaryTree(&tree, "AB##C##", &index);
    creatInThread(tree);
    for (ClueBinaryTree *node = getClueBinaryTreeFirst(tree); node != NULL; node = getClueBinaryTreeNext(node)) {
        printf("%c ", node->data);
    }
    printf("\n");
}