

//剑指offer面试题32：从上到下打印二叉树
//思想：层序遍历，利用队列
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL)
            return res;
        
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            res.push_back(front->val);
            q.pop();
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
        return res;
    }
};

