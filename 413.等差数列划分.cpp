/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
// #include<vector>
// #include<numeric>
// using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n,0);
        int d = 0,pred = nums[1]-nums[0];
        for (int i = 2; i < n; ++i){
            d = nums[i] - nums[i-1];
            if (d == pred){
                dp[i] = dp[i-1] + 1;
            }
            pred = d;
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
// @lc code=end

