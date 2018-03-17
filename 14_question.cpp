#include <iostream>
#include <vector>
using namespace std;



//剑指offer面试题14：割绳子
//将给定长度的绳子割成n段，使得各段长度之积
//

int GetMax(int len){
    if(len < 2)
        return 0;
    if(len == 2)
        return 1;
    if(len == 3)
        return 2;
    
    vector<int> res(len, 0);
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    res[3] = 3;
    
    int max = 0;
    for(int i=4; i<=len; ++i){
        max = 0;
        for(int j=1; j<=i/2; ++j){
            int tmp = res[j] * res[i-j];
            if(tmp > max)
                max = tmp;
            res[i] = max;
        }
    }
    max = res[len];
    
    return max;
}

int main(){
    int len = 0;
    cin>>len;
    int max = GetMax(len);
    cout<<max<<endl;
    return 0;
}
