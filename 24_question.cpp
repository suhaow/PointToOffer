
//输入一个链表，反转链表后，输出链表的所有元素。
class Solution {
public:
	//将当前节点的next置为前一个节点
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL)
			return NULL;
			
		ListNode* ret = NULL;
		ListNode* cur = pHead;
		ListNode* prev = NULL;
		
		while(cur != NULL){
			ListNode* next = cur->next;
			if(next == NULL){
				ret = cur;
				break;
			}
			
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return ret;
    }
};