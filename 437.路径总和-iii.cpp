/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    //由于节点数值可为负数 不同路径和可能相同
    unordered_map<int,int> prefix;

    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        prefix[0]=1;
        dfs(root,targetSum,0,ans);
        return ans;
    }
    void dfs(TreeNode* node,int targetSum,int cur,int &ans){
        if (!node) return;
        cur += node->val;
        if(prefix.find(cur-targetSum)!=prefix.end()) ans += prefix[cur-targetSum];
        ++prefix[cur];
        dfs(node->left,targetSum,cur,ans);
        dfs(node->right,targetSum,cur,ans);
        --prefix[cur];
    }
};
// @lc code=end

// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root) return 0;
//         //递归处理每个节点为起点的情况
//         return countpath(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
//     }
//     int countpath(TreeNode *node, int target){
//         if(!node) return 0;
//         int cnt = node->val==target ? 1 : 0;
//         cnt += countpath(node->left,target-node->val);
//         cnt += countpath(node->right,target-node->val);
//         return cnt;
//     }
// };