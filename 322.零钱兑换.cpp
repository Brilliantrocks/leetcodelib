/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+2);
        dp[0] = 0;
        for (const int x:coins){
            for(int i = x; i <= amount; ++i){
                dp[i] = min(dp[i],dp[i-x]+1);
            }
        }
        if (dp[amount] == amount+2) return -1;
        else return dp[amount];
    }
};
// @lc code=end

