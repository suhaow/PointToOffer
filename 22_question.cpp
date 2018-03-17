
//输入一个链表，输出该链表中倒数第k个结点。
//需要注意的点：
//1、链表为NULL或者k为0
//2、链表长度不足k

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;

		ListNode* slow = pListHead;
		ListNode* fast = pListHead;

		//fast先走k-1步
		for (int i = 0; i<k - 1; ++i) {
			if (fast->next != NULL)
				fast = fast->next;
			else
				return NULL;
		}

		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
}
