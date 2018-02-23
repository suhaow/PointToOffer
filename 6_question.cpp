#include <iostream>
#include <stack>

//面试题6：
struct ListNode{
    int _value;
    ListNode* _next;

    ListNode(const int& x)
        :_value(x)
        ,_next(NULL)
    {}
};



//1 往链表的尾部插入节点
void AddToTail(ListNode*& phead, const int& x){
    ListNode* newNode = new ListNode(x);

    //先处理头为空的情况
    if(phead == NULL){
        phead = newNode;
    }else{
    //找到next为空的节点，进行插入
        ListNode* cur = phead;
        while(cur != NULL && cur->_next != NULL){
            cur = cur->_next;
        }
        cur->_next = newNode;
    }
    
}

//2 删除值为value的节点
void RemoveNode(ListNode*& phead, const int& x){
    if(phead == NULL)
        return;

    ListNode* DelNode = NULL;
    //如果是头，直接让phead = phead->_next
    //否则就判断节点的next的value是否等于x, 等于则使当前节点的next = next->next
    if(phead->_value == x){
        DelNode = phead;
        phead = phead->_next;
    }else{
        ListNode* cur = phead;
        //找到cur->next->value == x,调整next
        while(cur != NULL && cur->_next->_value != x)
            cur = cur->_next;

        if(cur != NULL){
            DelNode = cur->_next;
            cur->_next = cur->_next->_next;
        }
    }

    if(DelNode != NULL){
        delete DelNode;
        DelNode = NULL;
    }
}

//3 从尾到头打印链表
void PrintListR(ListNode* phead){
    if(phead == NULL)
        return;
    PrintListR(phead->_next);
    std::cout<<phead->_value<<" ";
}

void PrintListS(ListNode* phead){
    std::stack<ListNode*> s;
    //先将所有节点都入栈，再边pop边输出value
    while(phead != NULL){
        s.push(phead);
        phead = phead->_next;
    }
    while(!s.empty()){
        ListNode* top = s.top();
        std::cout<<top->_value<<" ";
        s.pop();
    }
}

int main(){
    ListNode* head = new ListNode(1);
    head->_next = new ListNode(2);
    AddToTail(head, 3);
    PrintListR(head);
    std::cout<<std::endl;

    RemoveNode(head, 1);
    PrintListS(head);
    std::cout<<std::endl;
    return 0;
}
