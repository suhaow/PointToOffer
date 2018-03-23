#include <iostream>
#include <stdio.h>
using namespace std;

//字符串的排列

void Permutation(char* pstr, char* begin){
    if(*begin == '\0'){
        printf("%s\n", pstr);
        return;
    }

    for(char* cur = begin; *cur != '\0'; ++cur){
        swap(*cur, *begin);
        Permutation(pstr, begin+1);
        swap(*cur, *begin);
    }
}


void permutation(char *pstr){
	if(pstr == NULL)
		return;

	Permutation(pstr, pstr);
}



int main(){
	char str[] = "abc";
	permutation(str);
	return 0;
}
