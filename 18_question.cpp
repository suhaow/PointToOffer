#include <iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _next;
};

//O(1)删除单链表节点
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
	if(!pListHead || !pToBeDeleted)
		return;

    //一般情况，删除非尾节点，替换删除法
	if(pToBeDeleted->_next != NULL){
		ListNode* next = pToBeDeleted->_next;
		pToBeDeleted->_value = next->_value;
		pToBeDeleted->_next = next->next;

		delete next;
		next = NULL;
	}
    
    //只有一个节点
	else if(*pListHead == pToBeDeleted){
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}

    //删除多个节点的尾节点
	else{
		//delete node not tail
		ListNode* cur = *pListHead;
		while(cur->_next != pToBeDeleted){
			cur = cur->_next;
		}
		cur->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
