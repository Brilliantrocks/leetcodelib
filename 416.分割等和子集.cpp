/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2) return false;
        int target = sum/2,n=nums.size(),cur;
        // dp[j]为前i个数是否能够和为j
        vector<bool> dp(target+1,0);
        dp[0]=true;
        for (int i =1; i <= n; ++i){
            cur = nums[i-1];
            for (int j=target; j >=cur; --j){
                dp[j] = dp[j] || dp[j-cur];
            }
        }
        return dp[target];
    }
};
// @lc code=end

