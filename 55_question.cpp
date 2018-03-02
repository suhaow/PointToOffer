//题目一：求树的深度

//class Solution {
public:
    
    bool IsBanlance(TreeNode* node, int& depth){
        if(node == NULL){
            depth = 0;
            return true;
        }
        
        int left , right;
        if(IsBanlance(node->left, left) && IsBanlance(node->right,right)){
            int sub = abs(left - right);
            if(sub <= 1){
                depth = left > right ? left + 1 : right + 1;
                return true;
            }
        }
        return false;
    }
    
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBanlance(pRoot, depth);
    }
};



//题目二：判断平衡二叉树
//最笨的方法：需要重复遍历计算多次，效率低下
class Solution {
public:
    
    int GetHeight(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        
        int left = GetHeight(node->left);
        int right = GetHeight(node->right);
        return left > right ? left + 1 : right + 1;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        
        int left = GetHeight(pRoot->left);
        int right = GetHeight(pRoot->right);
        
        int sub = abs(left - right);
        
        return sub <= 1 ? true : false && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};


//后序遍历思想
class Solution {
public:
    
    bool IsBanlance(TreeNode* node, int& depth){
        if(node == NULL){
            depth = 0;
            return true;
        }
        
        int left , right;
        if(IsBanlance(node->left, left) && IsBanlance(node->right,right)){
            int sub = abs(left - right);
            if(sub <= 1){
                depth = left > right ? left + 1 : right + 1;
                return true;
            }
        }
        return false;
    }
    
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBanlance(pRoot, depth);
    }
};


