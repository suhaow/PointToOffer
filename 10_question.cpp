#include <iostream>

//面试题10：斐波那契数列
//要求：输入n，求斐波那契数列的第n项
//f(n) = 0 (n = 0)
//f(n) = 1 (n = 1)
//f(n) = f(n-1) + f(n-2) (n > 1)
//思路：使用递归可能会导致栈溢出，所以采用下面方式

long long Fibonacci(int n){
    if(n <= 0) return -1;  //非法值

    int result[2] = {0,1};
    if(n < 2){
        return result[n];
    }

    long long fibone = 0;
    long long fibtwo = 1;
    long long fibN = 0;
    for(size_t i=2; i<=n; ++i){
        fibN = fibone + fibtwo;
        
        //fibone fibtwo fibN
        fibone = fibtwo;
        fibtwo = fibN;
    }
    return fibN;
}

//变形:一直青蛙一次跳1级台阶，也可以跳2级台阶
//求青蛙跳上n级台阶共有多少种跳法
//思路：一级台阶只有一种跳法，一次跳一个台阶
//两级台阶有两种跳法：一次跳两级 or 两次跳一节
//三级台阶有三种跳法：一次跳一级+一次跳两级 / 一次跳一级+两次跳一级 / 三次一级
//f(n) = f(n-1) + f(n-2)
//(n = 1时 f(n) = 1; n = 2时 f(n) = 2)

long long GetWayCount(int n){
    if(n < 0)
        return -1;

    int way[3] = {0, 1, 2};
    if(n <= 2){
        return way[n];
    }

    long long first = 1;
    long long second = 2;
    long long count = 0;
    for(int i=3; i<=n; ++i){
        count = first + second;
        first = second;
        second = count;
    }
    return count;
}

int main(){
    int n = 5;
    long long ret = Fibonacci(n);
    std::cout<<"第5个斐波那契数为"<<ret<<std::endl;
    ret = GetWayCount(n);
    std::cout<<"5层台阶时，跳法共有"<<ret<<std::endl;
    return 0;
}
