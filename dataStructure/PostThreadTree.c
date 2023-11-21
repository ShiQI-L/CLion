//
// PostThreadTree.c is Created by ShiQI on 2023/10/13 15:22.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct PostThreadTree {
    char data;
    struct PostThreadTree *lChild;
    struct PostThreadTree *rChild;
    struct PostThreadTree *parent;
    int ltag;
    int rtag;
} PostThreadTree;

void createPThreadTree(PostThreadTree **T, char *data, int *index, PostThreadTree *parent) {
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#') {
        //此时树为空
        *T = NULL;
    } else {
        //此时不为空
        *T = (PostThreadTree *) malloc(sizeof(PostThreadTree));
        (*T)->data = ch;
        (*T)->rtag = 0;
        (*T)->ltag = 0;
        (*T) -> parent = parent;//根节点的父节点为空,二叉树中出了根节点都有父节点
        //创建左右子树 逻辑一致 进行递归操作
        createPThreadTree(&((*T)->lChild), data, index, *T);
        createPThreadTree(&((*T)->rChild), data, index, *T);
    }
}

void postThreadTree(PostThreadTree *T, PostThreadTree **pre) {
    if (T) {
        postThreadTree(T->lChild, pre);//递归,线索化左子树
        postThreadTree(T->rChild, pre);//递归,线索化右子树
        if (T->lChild == NULL) {//左子树为空,建立前驱线索
            T->lChild = *pre;
            T->ltag = 1;
        }
        if (*pre != NULL && (*pre)->rChild == NULL) {
            (*pre)->rChild = T;//建立前驱结点的后继线索
            (*pre)->rtag = 1;
        }
        (*pre) = T;//标记当前结点成为刚刚访问过的结点
    }
}

void createPostThreadTree(PostThreadTree *T) {
    PostThreadTree *pre = NULL;
    if (T != NULL) {
        postThreadTree(T, &pre);//后序最后一个结点是根节点,不需要改变lChild指向
    }
}
/**
 * 找到后序二叉树第一个结点,要注意,如果找到的结点只有右子树时,第一个结点是它右子树最左边的结点
 * @param tree
 * @return
 */
PostThreadTree *getPostThreadTreeFirst(PostThreadTree *tree) {
    while (tree->ltag == 0) {
        tree = tree->lChild;
    }
    if (tree->rtag == 0) {
        return getPostThreadTreeFirst(tree->rChild);
    }
    return tree;
}
/**
 * 找到当前结点的下一个结点
 * 当前结点有右线索,直接是其右孩子指针指向的结点
 * 若没有
 * * 1.当前结点为根节点,那么没有下一个节点;
 * * 2.当前结点为右孩子,那么下一个节点为其父节点;
 * * 3.当前结点为左孩子,
 * * * 那么下一个节点为其父节点右子树后序的第一个结点,
 * * * 若其父子树没有右孩子,那么下一个节点就是其父节点.
 * @param node
 * @return
 */
PostThreadTree *getPostThreadTreeNext(PostThreadTree *node) {
    if (node->rtag == 1)
        return node->rChild;
    else {
        // 如果是根节点
        if (node->parent == NULL) {
            return NULL;
        }
            // 如果是右孩子
            // 当前结点为右孩子,那么下一个节点为其父节点
        else if (node->parent->rChild == node) {
            return node->parent;
        }
            // 如果是左孩子
        else {
            if (node->parent->ltag == 0) {
                //那么下一个节点为其父节点右子树后序的第一个结点
                return getPostThreadTreeFirst(node->parent->rChild);
            } else {
                //若其父子树没有右孩子,那么下一个节点就是其父节点
                return node->parent;
            }
        }
    }
}

void postThreadTreeTest() {
    PostThreadTree *tree;
    int index = 0;
    PostThreadTree *parent=NULL;
    createPThreadTree(&tree, "AB##C##", &index, parent);
    createPostThreadTree(tree);
    for (PostThreadTree *node = getPostThreadTreeFirst(tree); node != NULL; node = getPostThreadTreeNext(node)) {
        printf("%c ", node->data);
    }
    printf("\n");
}