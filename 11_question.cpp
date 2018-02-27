#include <iostream>
#include <stdio.h>
#include <assert.h>
//2.4.2查找和排序
//随手写一个快排（左右指针法）
void QuickSort(int *arr, int left, int right){
    if(left >= right)
        return;

    int begin = left;
    int end = right;
    int key = arr[end];
    while(begin < end){
        while(begin < end && arr[begin] <= key)
            ++begin;
        while(begin < end && arr[end] >= key)
            --end;

        if(begin < end)
            std::swap(arr[begin], arr[end]);
    }

    std::swap(arr[begin], arr[right]);

    QuickSort(arr, left, begin-1);
    QuickSort(arr, begin+1, right);
}

//面试题11：旋转数组的最小数字
//把一个数组最开始的若干个元素搬到数组的末尾
//输入一个递增排序的数组的一个旋转
//输出旋转数组的最小元素
//例如：数组[3,4,5,1,2} 是 {1,2,3,4,5}的一个旋转，该数组最小值为1

//思路：如果直接遍历一遍，O(n)的算法，那么就没有意义了
//既然数组可以划分为两个排序的子数组，并且前面的子数组的元素都大于或等于后面数组的元素
//同时，最小元素恰好是两个子数组的分界线。
//所以可以使用二分查找法O(logn)来实现


//准备的遍历找最小值的算法
int MinInOrder(int* arr, int index1, int index2){
    int Min = arr[index1];
    for(int i=index1; i<=index2; ++i){
        if(Min >= arr[i])
            Min = arr[i];
    }
    return Min;
}

//利用二分的思想实现
int Min(int *arr, int len){
    assert(arr != NULL);
        
    int index1 = 0;
    int index2 = len-1;
    int MidIndex = index1; //适用于数组一开始就已经全部有序，则直接返回index1

    while(arr[index1] >= arr[index2]){
        if(index2 - index1 == 1){
        //index2所标记的元素即为最小值
            MidIndex = index2;
            break;
        }

        MidIndex = (index2 + index1) >> 1;

        //避免类似于 0 1 1 1 1   旋转为 1 0 1 1 1情况，
        //若idnex1 ,index2, midindex对应元素都相等则顺序遍历
        if(arr[index1] == arr[index2] && arr[index1] == arr[MidIndex])
            return MinInOrder(arr, index1, index2);

        if(arr[index1] <= arr[MidIndex])
        //此条件满足，说明arr[index1]和arr[MidIndex]都在前面的递增序列中
            index1 = MidIndex;

        else if(arr[MidIndex] <= arr[index2])
        //说明arr[index2]和arr[MidIndex]在后面的递增序列中
            index2 = MidIndex;
    }
    return arr[MidIndex];
}


int main(){
  //  int arr[] = {1,5,6,7,2,3};
  //  int len = sizeof(arr)/sizeof(arr[0]);
  //  QuickSort(arr, 0, len-1);
  //  for(int i=0; i<len; ++i)
  //      std::cout<<arr[i]<<" ";
  //  printf("\n");
    int arr[] = {1, 0, 1, 1, 1};
    int ret = Min(arr, sizeof(arr)/sizeof(arr[0]));
    std::cout<<"最小值为"<<ret<<std::endl;
    return 0;
}
