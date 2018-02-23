#include <iostream>

//剑指offer面试题8：给定一个二叉树和其中的一个节点，
//找出对应中序遍历序列的下一个节点。（树的结构为三叉链）

//思路：中序的遍历顺序为左根右，分情况讨论
//如果当前节点有右子树，则下一个节点为右子树的最左节点
//否则 当前节点无右子树，则判断当前节点是父节点的左还是右
//     如果是父节点的左节点，那么下一个节点就是父节点
//     否则说明该节点是父节点的右孩子，一直向上找，直到找到当前节点是父节点的左孩子，返回该父节点
typedef struct TreeNode{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

	TreeNode(const int& x)
		:_value(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
}Node;

Node* FindNext(Node* node) {
	if (node == NULL)
		return NULL;

	Node *pnext = NULL;
	if (node->_right != NULL) {
    //右不为空，则返回右子树最左节点
		Node* right = node->_right;
        while(right != NULL)
            right = right->_left;
        pnext = right;
	}
	else if (node->_parent != NULL) {

		Node *cur = node;
		Node *parent = node->_parent;
		if (cur == parent->_left) {
			pnext = parent;
		}
		else {
			//cur == parent->_right，一直向上找到第一个当前节点为父节点的左节点
			//该父节点就为下一个节点
			while (parent != NULL && cur == parent->_right) {
				cur = parent;
				parent = cur->_parent;
			}
			pnext = parent;
		}
	}
	return pnext;
}


int main() {
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(4);
	Node *d = new Node(3);
	a->_left = b; a->_right = c;
	b->_parent = a; b->_left = d; 
	c->_parent = a; 
	d->_parent = b;
	/*   a(1)   
	  b(2)     c(4)
	d(3)            */
	Node* ret = FindNext(d);
	std::cout << "3 next node : " << ret->_value << std::endl;
	return 0;
}
