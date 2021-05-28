/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        depth(root,dia);
        return dia;
    }
    int depth(TreeNode *node,int &dia){
        if(!node) return 0;
        int left=depth(node->left,dia),right=depth(node->right,dia);
        dia = max(left+right,dia);
        return 1+max(left,right);
    }
};
// @lc code=end

