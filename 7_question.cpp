#include <iostream>
#include <vector>

//面试题7.给定前序和中序遍历序列，重建二叉树
//思路：前序遍历的第一个元素也就是当前树的根节点
//在中序遍历序列中找到对应元素，该元素左侧的为左子树节点；反之为右子树节点

typedef struct BinaryTreeNode{
    int _value;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;

    BinaryTreeNode(const int& x)
        :_value(x)
        ,_left(NULL)
        ,_right(NULL)
    {}
}Node;

//第一种：每次都使用新的vector，存放当前遍历序列
//Node* Construct(std::vector<int> prevorder, std::vector<int> inorder)
//{
//    if(prevorder.size() == 0)
//        return NULL;
//
//    size_t len = prevorder.size();
//    std::vector<int> left_prev, right_prev, left_in, right_in;
//
//    //创建根节点，也就是前序遍历的第一个元素
//    Node* root = new Node(prevorder[0]);
//
//    //在中序遍历中，找到对应元素，该元素左侧为左树元素，右侧为右树
//    //注意此处一定不能直接将rootindex作为for循环的条件，否则就算循环条件不满足
//    //rootindex也会被++为1，导致程序崩溃
//    int rootindex = 0;
//    for(size_t i=0; i<inorder.size(); ++i){
//        if(inorder[i] == prevorder[0]){
//            rootindex = i;
//            break;
//        }
//    }
//
//    //获取到左右子树，重新向遍历序列中添加元素，准备递归
//    for(int i=0; i<rootindex; ++i){
//        left_prev.push_back(prevorder[i+1]);
//        left_in.push_back(inorder[i]);
//    }
//
//    for(int i=rootindex+1; i<len; ++i){
//        right_prev.push_back(prevorder[i]);
//        right_in.push_back(inorder[i]);
//    }
//
//    root->_left = Construct(left_prev, left_in);
//    root->_right = Construct(right_prev, right_in);
//    return root;
//}

//第二种：通过下标访问控制
Node* Find
    (const std::vector<int>& prevorder, size_t pbegin, size_t pend,
        const std::vector<int>& inorder, size_t ibegin, size_t iend) 
{
    if (pbegin >= pend || ibegin >= iend)
        return NULL;

    Node* root = new Node(prevorder[pbegin]);  
    size_t rootindex = ibegin;
    for (size_t i = ibegin; i < iend; ++i) {
        if (inorder[i] == prevorder[pbegin]) {
            rootindex = i;
            break;
        }
    }

    int rootleft = rootindex - ibegin;
    root->_left = Find(prevorder, pbegin + 1, pbegin + rootleft + 1, inorder, ibegin, rootindex);
    root->_right = Find(prevorder, pbegin + rootleft + 1, pend, inorder, rootindex + 1, iend);
    return root;
}

Node* Construct(std::vector<int> prevorder, std::vector<int> inorder) {
        return Find(prevorder, 0, prevorder.size(), inorder, 0, inorder.size());
}


void PrevOrder(Node* root){
    if(root == NULL)
        return;

    std::cout<<root->_value<<" ";
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}

int main(){
    std::vector<int> prevorder;
    prevorder.push_back(1);
    prevorder.push_back(2);
    prevorder.push_back(3);
    prevorder.push_back(4);
    
    std::vector<int> inorder;
    inorder.push_back(3);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(4);
    
    Node* root = Construct(prevorder, inorder);
    PrevOrder(root);
    std::cout<<std::endl;
    return 0;
}
