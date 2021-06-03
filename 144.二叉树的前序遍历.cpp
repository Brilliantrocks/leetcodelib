/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(!root) return ans;
        st.emplace(root);
        TreeNode* cur;
        while(!st.empty()){
            cur=st.top();
            st.pop();
            ans.emplace_back(cur->val);
            if(cur->right!=nullptr) st.emplace(cur->right);
            if(cur->left!=nullptr) st.emplace(cur->left);
        }
        return ans;
    }
};
// @lc code=end

