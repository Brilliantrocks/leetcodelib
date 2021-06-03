/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
#include<queue>
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q{deque{root}};
        int size;
        double sum;
        while(!q.empty()){
            size=q.size();
            sum=0;
            for(int i=0;i<size;++i){
                auto [val, left, right] = *q.front();
                q.pop();
                sum += val;
                if(left) q.emplace(left);
                if(right) q.emplace(right);
            }
            ans.emplace_back(sum/size);
        }
        return ans;
    }
};
// @lc code=end

