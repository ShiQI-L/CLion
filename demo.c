//
// Created by Hoshikage on 2023/5/25.
//

#include <stdio.h>

void sumOneTo();
int searchMainElement(int A[],int n);
void testSearchMainElement();
void printArr(int nums[],int n);
int searchMainElementKey(int A[],int n);
void merge_sort(int arr[], int len);
int findMissMin022313(int A[],int n);//求数组中未出现的最小正整数

void sumOneTo(){
    printf("222\n");
    //求1-100所有数字的和 不是最优解 最优解为高斯求和
    int sum=0;
    for(int i=1;i<=100;i++){
        sum+=i;
    }
    printf("sum=%d\n",sum);
    printf("%d\n",(1+100)*100/2);//高斯求和,最优解
    //算法优先考虑时间,再考虑空间
}
/**
 * 找到主元素,主元素是数组中相同元素个数大于n/2的元素,若有返回该元素,若无返回-1
 * 思想:用count来进行计数
 * @param A
 * @param n
 * @return
 */
int searchMainElement(int A[],int n){
    int count=1;
    int i,c;
    c=A[0];
    for(i=1;i<n;i++){
        if(A[i]==c){
            count++;
        } else{
            if(count>0){
                count--;
            } else{
                c=A[i];
                count=1;
            }
        }
    }
    if(count>0){
        for(i=count=0;i<n;i++){
            if(A[i]==c){
                count++;
            }
        }
    }
    if(count>n/2) return c;
    else return -1;
}

void testSearchMainElement(){
    int a[]={1,3,3,2,3,1,1,3,3,4,5,2,5,5,5,5,5,5,5,5,5,5,5};
    int test=searchMainElementKey(a,23);
    printf("%d\n",test);
}

typedef struct keyValue{
    int key;
    int value;
}keyValue;

int searchMainElementKey(int A[],int n){
    merge_sort(A,n);
//    printArr(A,n);
//    const int num=2*n;
//    int a[num];
    int i=0;
    int count=1;
    int c=A[0];
    while (i<n){
        if(c==A[i+1]){
            count++;
            i++;
        } else{
            if(count>n/2){
                return A[i];
            } else{
                c=A[i+1];
                count=0;
            }
        }
    }
    return -1;
}

int searchMainElementThird(int A[],int n){
    const int num=n;
    int a[num];
    int i=0,j=0;
    int count;
    int c=A[0];
    while (i<n){

    }
    return -1;
}

void printArr(int nums[],int n){
    for(int i=0;i<n;i++){
        printf("%d-->",nums[i]);
    }
    printf("\n");
}

void demo(){
//    sumOneTo();
//    testSearchMainElement();
    int a[]={-1,-3,2,4,1};
    int b=findMissMin022313(a,5);
    printf("%d\n",b);
}