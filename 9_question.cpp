#include <iostream>
#include <stack>

//面试题9：用两个栈实现队列
//实现appendTail和deleteHead接口


template<class T>
class CQueue{
public:
    CQueue() {};
    ~CQueue() {};

    void appendTail(const T& x){
        PushStack.push(x);
    }

    void deleteHead(){
        if(DeleteStack.size() == 0){
            while(!PushStack.empty()){
                DeleteStack.push(PushStack.top());
                PushStack.pop();
            }
        }
        if(!DeleteStack.empty()){
            DeleteStack.pop();
        }
    }

    
private:
    std::stack<T> PushStack; //用来插入数据
    std::stack<T> DeleteStack;  //用来删除数据
};


int main(){
    CQueue<int> q;
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    q.deleteHead();
    return 0;
}
