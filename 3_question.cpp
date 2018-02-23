#include <iostream>
#include <map>

//找出数组中重复的数字：
//在一个长度为n的数组里所有的数字都在0~n-1的范围里
//数组中某些数字是重复的，请找出数组中任意一个重复的数字
//例如：数组为{2,3,1,0,2,5,3}
//输出的数字应该为2 or 3；

//思路1：
//从头到尾扫描数组中的每个数字，当扫描到下表为i的数字时
//首先比较该数字和i是否相等，等于的话扫描下一个数字；
//否则判断当前元素的值 与 已当前值做下表的元素的值
//若相等说明找到重复元素，否则交换重复比较
//时间复杂度为O(n), 空间复杂度为O(1)
bool FindRepetNum1(int* arr, int len, int& repetNum){
    if(arr == NULL || len <= 0){
        return false;
    }

    for(int i=0; i<len; ++i){
        if(arr[i] < 0 || arr[i] > len-1){
            return false;
        }
    }

    //开始查找重复的数字
    for(int i=0; i<len; ++i){
        while(arr[i] != i){
            //如果已当前元素值为下标的位置的值 和 当前元素值相等
            //则说明找到重复元素
            if(arr[i] == arr[arr[i]]){
                repetNum = arr[i];
                return true;
            }
            //否则交换元素值，继续循环
            std::swap(arr[i], arr[arr[i]]);
        }
    }
    return false;
}

//思路2：利用map的键值对
//时间复杂度为O(n),空间复杂度为O(n)
bool FindRepetNum(int* arr, int len, int& repetNum){
    std::map<int, int> tmp_map;
    for(int i=0; i<len; ++i){
        ++tmp_map[arr[i]];

        //判断若重复则返回
        if(tmp_map[arr[i]] > 1){
            repetNum = arr[i];
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int repetNum = 0;
    bool ret = FindRepetNum(arr, sizeof(arr)/sizeof(arr[0]), repetNum);
    

    if(ret != false)
        std::cout<<"repetNum = "<<repetNum<<std::endl;
    else
        std::cout<<"no found"<<std::endl;

    return 0;
}
