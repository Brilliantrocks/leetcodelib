/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        int n=inorder.size();
        for(int i=0;i<n;++i){
            hash[inorder[i]]=i;
        }
        return NodeConstructor(preorder,0,n-1,0);
    }
    TreeNode* NodeConstructor(vector<int> &preoder,int ibegin,int iend,int ipre){
        if(ibegin>iend) return nullptr;
        int val = preoder[ipre],index=hash[val],leftlen=index-ibegin;
        TreeNode *node=new TreeNode(val);
        node->left=NodeConstructor(preoder,ibegin,index-1,ipre+1);
        node->right=NodeConstructor(preoder,index+1,iend,ipre+1+leftlen);
        return node;
    }
};
// @lc code=end

