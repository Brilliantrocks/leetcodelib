/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int> hash;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if(!root) return ans;
        for(int x : to_delete){
            hash.emplace(x);
        }
        root=dfs(root,ans);
        if(root!=nullptr) ans.emplace_back(root);
        return ans;
    }
    TreeNode* dfs(TreeNode *node,vector<TreeNode*> &ans){
        if(!node) return nullptr;
        node->left=dfs(node->left,ans);
        node->right=dfs(node->right,ans);
        if(hash.find(node->val)!=hash.end()){
            if(node->left!=nullptr) ans.emplace_back(node->left);
            if(node->right!=nullptr) ans.emplace_back(node->right);
            node=nullptr;
        }
        return node;        
    }
};
// @lc code=end

// class Solution {
// public:
//     unordered_set<int> hash;
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         vector<TreeNode*> ans;
//         if(!root) return ans;
//         for(int x : to_delete){
//             hash.emplace(x);
//         }
//         dfs(root,nullptr,ans,1);
//         return ans;
//     }
//     void dfs(TreeNode *node,TreeNode *parent,vector<TreeNode*> &ans,bool isleft){
//         if(!node) return;
//         if(hash.find(node->val)!=hash.end()){
//             if(parent!=nullptr){
//                 if(isleft) parent->left=nullptr;
//                 else parent->right=nullptr;
//             } 
//             dfs(node->left,nullptr,ans,1);
//             dfs(node->right,nullptr,ans,0);
//         }
//         else{
//             if(!parent) ans.emplace_back(node);
//             dfs(node->left,node,ans,1);
//             dfs(node->right,node,ans,0);
//         }
//         return;        
//     }
// };