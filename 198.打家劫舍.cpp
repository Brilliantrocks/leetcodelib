/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        int cur, pre = 0,ppre = 0;
        for (int i = 0; i < n; ++i) {
            cur = max(ppre + nums[i], pre);
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

