
//合并两个有序链表

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        
        ListNode* newHead = NULL;
        if(pHead1->val < pHead2->val){
            newHead = pHead1;
            pHead1->next = Merge(pHead1->next, pHead2);
        }
        else{
            newHead = pHead2;
            pHead2->next = Merge(pHead1, pHead2->next);
        }
        return newHead;
    }
};
