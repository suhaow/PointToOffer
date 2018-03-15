#include <iostream>


//求二进制中1的个数

int GetNum2(int num){
    int count = 0;
    while(num){
        ++count;
        num = (num-1) & num;
    }
    return count;
}

//利用一个临时的变量来与num的每一位进行与运算
int GetNum(int num){
    int count = 0;
    int value = 1;
    while(value){
        if(value & num)
            ++count;
        value = value << 1;
    }
    return count;
}

int main(){
    int num = 0;
    std::cin>>num;
    int res = GetNum2(num);
    std::cout<<res<<std::endl;
    return 0;
}

