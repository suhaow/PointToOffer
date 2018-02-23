#include <iostream>
#include <stdio.h>

//面试题5：替换字符串空格
//实现一个函数，把字符串中的每个空格替换成"%20"
//例如 "We are happy."
//替换完成后 "We%20are%20happy."


char* Replace(const char* str, int len){
    if(str == NULL || len <= 0)
        return NULL;

    int CountOfBlank = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ')
            ++CountOfBlank;
        ++i;
    }

    int newLen = 2*CountOfBlank + len;
    char* ret = new char[newLen];
    int indexOfNew = newLen;
    int indexOfOld = len;

    while(indexOfOld >= 0){
        if(str[indexOfOld] == ' '){
            ret[indexOfNew--] = '0';
            ret[indexOfNew--] = '2';
            ret[indexOfNew--] = '%';
        }else{
            ret[indexOfNew--] = str[indexOfOld];
        }
        --indexOfOld;
    }
    
    return ret;
}

int main(){
    char arr[] = "We are happy.";
    printf("origin string : We are happy.\n");
    char* ret = Replace(arr, sizeof(arr)/sizeof(arr[0]));
    printf("after replace : %s\n", ret);

    return 0;
}
