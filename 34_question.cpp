/*
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    vector<vector<int> >buffer;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)
            return buffer;
     
        tmp.push_back(root->val);
        //规定路径必须为到叶子节点
        if((expectNumber-root->val == 0) && root->left == NULL && root->right == NULL)
            buffer.push_back(tmp);
        
        //开始递归
        FindPath(root->left, expectNumber-root->val);
        FindPath(root->right, expectNumber-root->val);
        
        //回溯
        if(tmp.size() > 0)
            tmp.pop_back();
    
        return buffer;
    }
};

