/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1;
        vector<int> dp;
        int cur,pre = nums[0],cnt=1;
        dp.push_back(nums[0]);
        for (int i = 1; i< n; ++i){
            cur = nums[i];
            if (pre < cur){
                ++cnt;
                pre = cur;
                dp.push_back(cur);
            }
            else {
                auto itr = lower_bound(dp.begin(),dp.end(),cur);
                *itr = cur;
                pre = dp.back();
            }
        }
        return cnt;
    }
};
// @lc code=end

