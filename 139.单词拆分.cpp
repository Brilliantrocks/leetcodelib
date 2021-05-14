/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for (const auto &x : wordDict){
                int len = x.size();
                if (i >= len && s.substr(i-len,len) == x){
                    dp[i] = dp[i] || dp[i-len];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

