//
// Created by ShiQI on 2023/7/7 19:10.
//
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

void LeetCode(){
    int nums[]={2,3,4,5};

    int target=1;
    int a=searchInsert(nums,4,target);
    printf("%d\n",a);
}

/**
 * 35. 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 请必须使用时间复杂度为 O(log n) 的算法。
 * @param nums
 * @param numsSize
 * @param target
 * @return
 */
int searchInsert(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target) break;
        else if(nums[mid<target]) low=mid+1;
        else high=mid-1;
    }
    if(nums[mid==target]) return mid;
    if(low>high&&nums[mid]>target){
        return mid-1;
    }
    return 0;
}

/**LeetCode704给定一个n个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，
如果目标值存在返回下标，否则返回 -1。*/
int search(int * nums,int numsSize, int target){
    for(int i=0;i<numsSize;i++){//简单粗暴,
        if(nums[i]==target) {// '=='判断两边是否相等
            return i;
        }
    }
    return -1;
}
//第一次优化,由于数组是从小到大的.找一个较小的数时,当nums[i]大于目标值就可以直接结束
//但是,当要找的数足够大时,算法依然不够优化
int searchA(int * nums,int numsSize, int target){
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target) return i;
        if(nums[i]>target) break;
    }
    return -1;
}

int searchB(int * nums,int numsSize, int target){
    int binarySearch(int * nums,int target ,int left, int right);
    return binarySearch(nums,target,0,numsSize-1);
}
//递归分治算法,数量到n时的最优解
//最终优化,当n足够大时的最优解,
int binarySearch(int * nums,int target ,int left, int right){//left 代表左边界,right 代表右边界
    if(left>right) return -1;//如果左边大于右边，那么肯定找完了，直接返回
    int mid = (left+right)/2;//取出中间位置
    if(nums[mid]==target) return mid;//比较中间值是否是要找的,是则直接返回
    if(nums[mid]>target)//如果中间值大于要找的数,那么就在左边继续寻找
        return binarySearch(nums,target,left,mid-1);
    else//否则就在右边寻找
        return binarySearch(nums,target,mid+1,right);
}