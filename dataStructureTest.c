//
// Created by ShiQI on 2023/9/17 14:27
//
//题号由六位数字组成 前两位为章节数,中间两位为小节数和板块数,最后两位为题目数   例如 022313 为2.2.3第13题
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

void merge_sort(int arr[], int len);//归并排序
_Bool xls_min(int a,int b,int c);//判断a是否为三者最小的


int majority022312(int A[],int n);//求主元素
int findMissMin022313(int A[],int n);//求数组中未出现的最小正整数
int findMinOfTrip022314(int A[],int n,int B[],int m,int C[],int p);//三元组的最小距离
int findMinOfTrip022314_BaoLiJieFa(int A[],int n,int B[],int m,int C[],int p);


int majority022312(int A[],int n){//
    merge_sort(A,n);//归并排序
    int i=0;
    int count=1;
    int c=A[0];
    while (i<n){//循环处理
        if(c==A[i+1]){//判断与c相同的元素个数
            count++;
            i++;
        } else{
            if(count>n/2){//遇到与c不同的元素,判断c是否为主元素
                return A[i];
            } else{//c不是主元素,将c挪到A[i+1],继续进行判断直到找到主元素c,或者循环结束返回-1
                c=A[i+1];
                count=0;
            }
        }
    }
    return -1;//没有找到主元素,返回-1
}

int findMissMin022313(int A[],int n){//时间复杂度O(n) 空间复杂度O(n)
    int i,*b;//新建一个标记数组
    b=(int *)malloc(sizeof(int)*n);//给数组分配空间
    for(i=0;i<n;i++){//将标记全为零
        b[i]=0;
    }
    for(i=0;i<n;i++){
        if(A[i]>0&&A[i]<=n){//循环遍历,若A中元素在1~n,则标记b
            b[A[i]-1]=1;
        }
    }
    for(i=0;i<n;i++){//遍历,找到没有标记的最小位序,返回目标值
        if(b[i]!=1){
            return i+1;
        }
    }
    return -1;
}
/**
 * 思想:假设在坐标轴上的三点:a<b<c,d=|a-b|+|a-c|+|b-c|=2*(c-a);a属于数组A中,要使d变小,只有a向右移动
 * 算法中随着遍历的进行三数中的最小值在不停的变换,所以只需要找到最小的a,使其继续向右移动,然后计算d,判断d是否小于d_min
 * 再判断三者中最小值,直到循环结束
 * @param A
 * @param n
 * @param B
 * @param m
 * @param C
 * @param p
 * @return
 */
int findMinOfTrip022314(int A[],int n,int B[],int m,int C[],int p){//时间复杂度:O(n) 空间复杂度:O(1)
    int i=0,j=0,k=0,d;
    int d_min=INT_MAX;//设定最小值d_min,并赋值一个足够大的数
    while (i<n&&j<m&&k<p&&d_min>0){//循环遍历
        d= abs(A[i]-B[j])+ abs(B[j]-C[k])+ abs(A[i]-C[k]);//计算三点间的距离
        if(d<d_min) d_min=d;//
        if(xls_min(A[i],B[j],C[k])){//xls_min判断a是否是三者中的最小值
            i++;
        } else{
            if(xls_min(B[j],A[i],C[k])){
                j++;
            } else{
                k++;
            }
        }
    }
    return d_min;
}
int findMinOfTrip022314_BaoLiJieFa(int A[],int n,int B[],int m,int C[],int p){//时间复杂度:O(n^3) 空间复杂度:O(1)
    int d_min=INT_MAX;
    int d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<p;k++){
                d= abs(A[i]-B[j])+ abs(B[j]-C[k])+ abs(A[i]-C[k]);//计算三点间的距离,每三个数都算一遍
                if(d<d_min) d_min=d;
            }
        }
    }
    return d_min;
}

void dataStructureTest(){
    int a[]={1,2,3};
    int b[]={4,5,6,7};
    int c[]={4,5,6,7,8};
    int re=findMinOfTrip022314_BaoLiJieFa(a,3,b,4,c,5);
    printf("%d\n",re);
}