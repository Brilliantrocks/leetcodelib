/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp[i]表示整数i最少由几个完全平方数组成
        // 则dp[i]与i-j^2有关
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i = 1; i <=n;++i){
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

