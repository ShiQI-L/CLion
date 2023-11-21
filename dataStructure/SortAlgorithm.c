#include <stdio.h>

/*************************************************************************
* File Name: SortAlgorithm.c
* Author: ShiQI
* E-mail: l3480342572@gmail.com
* Created Time: 2023/11/4 22:59
 ************************************************************************/
typedef int E;


void bubbleSort(E *a, int size) {
    E temp;
    for (int i = 0; i < size - 1; ++i) {
        _Bool flag = 1;
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                flag = 0;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (flag == 1) break;
    }
}

void insertSort(E *a, int size) {
    for (int i = 1; i < size - 1; ++i) {
        E temp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];

            j--;
        }
        a[j] = temp;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectSort(int arr[], int size) {
    int left = 0, right = size - 1;   //相当于左端和右端都是已经排好序的，中间是待排序的，所以说范围不断缩小
    while (left < right) {
        int min = left, max = right;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min]) min = i;   //同时找最小的和最大的
            if (arr[i] > arr[max]) max = i;
        }
        swap(&arr[max], &arr[right]);   //这里先把大的换到右边
        //注意大的换到右边之后，有可能被换出来的这个就是最小的，所以说需要判断一下
        //如果遍历完发现最小的就是当前右边排序的第一个元素
        //此时因为已经被换出来了，所以说需要将min改到换出来的那个位置
        if (min == right) min = max;
        swap(&arr[min], &arr[left]);   //接着把小的换到左边
        left++;    //这一轮完事之后，缩小范围
        right--;
    }
}


void quickSort(E *a, int start, int end) {
    if(start>end)return;
    int left = start, right = end;
    E value = a[left];
    while (left < right) {
        while (left < right && value <= a[right])right--;
        a[left] = a[right];
        while (left < right && value >= a[left])left++;
        a[right] = a[left];
    }
    a[left]=value;
    quickSort(a,start,left-1);
    quickSort(a,left+1,end);
}

void SortAlgorithm() {
    int a[] = {1, 2, 3, 4, 5, 3, 2, 3, 4, 5, 6, 5, 4, 7, 8};
    int n = 15;
    insertSort(a, n);
    int i = 0;
    while (i < n) {
        printf("%d\t", a[i]);
        i++;
    }
}