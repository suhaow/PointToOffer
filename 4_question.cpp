#include <iostream>

//杨氏矩阵查找元素
//例如：在如下矩阵中查找4
//1 2 8 9
//2 4 9 12
//4 7 10 13
//6 8 11 15
//思路：从左下或右上开始进行查找

bool Find(int (*arr)[4], int rows, int cols, int searchNum){
    if(arr == NULL || rows < 0 || cols < 0)
        return false;

    //右上角开始查找
    int row = 0;
    int col = cols - 1;
    while(row < rows && col >= 0){
        if(searchNum == arr[row][col])
            return true;
        else if(searchNum > arr[row][col])
            ++row;
        else
            --col;
    }
    return false;
}


int main(){
    int matrix[4][4] = {{1,2,8,9}, {2,4,9,12},
                        {4,7,10,13}, {6,8,11,15}};
    int searchNum = 4;
    bool ret = Find(matrix, 4, 4, searchNum);
    if(ret == false)
        std::cout<<"no find"<<std::endl;
    else
        std::cout<<"find it"<<std::endl;

    return 0;
}
