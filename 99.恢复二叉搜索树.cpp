z/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
class Solution {
public:
    TreeNode *error1=nullptr, *error2=nullptr,*prev=nullptr; 
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(error1 && error2) {
            int temp=error1->val;
            error1->val=error2->val;
            error2->val=temp;
        }
    }

    void inorder(TreeNode *node){
        if(!node) return;
        if(node->left) inorder(node->left);
        if(prev && node->val < prev->val){
            if(!error1) {
                error1 = prev;
                error2 = node;
            }
            else{
                error2 = node;
            }
        }
        prev=node;
        if(node->right) inorder(node->right);
    }
};
// @lc code=end

