//
// Created by ShiQI on 2023/9/17 14:36.
//

int min(int x, int y);//求两数最小值
int max(int a, int b);//求两数最大值
void sortArr(int nums[],int n);//冒泡排序
void merge_sort(int arr[], int len);//归并排序
_Bool xls_min(int a,int b,int c);//判断a是否为三者最小的




#include <string.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>

/**
 *
 * @param nums
 * @param n
 */
void sortArr(int nums[],int n){
    int i,j,temp;
    //冒泡排序算法：进行 n-1 轮比较
    for(i=0; i<n-1; i++){
        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
        for(j=0; j<n-1-i; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

bool xls_min(int a,int b,int c){
    if (a<b&&a<c){
        return true;
    }
    return false;
}

