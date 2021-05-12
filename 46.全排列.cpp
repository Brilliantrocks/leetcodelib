/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrace(nums,0,ans);
        return ans;
    }

    void backtrace(vector<int>& nums,int lv, vector<vector<int>>& ans){
        if (lv == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for (int i = lv; i < nums.size(); ++i){
            swap(nums[i],nums[lv]);
            backtrace(nums,lv+1,ans);
            swap(nums[i],nums[lv]);
        }
    }
};
// @lc code=end

