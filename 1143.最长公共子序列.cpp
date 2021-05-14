/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(2,vector(n+1,0));
        char c1,c2;
        for (int i = 1; i <= m; ++i){
            c1 = text1[i-1];
            for(int j = 1; j <=n; ++j){
                c2 = text2[j-1];
                if (c1 == c2){
                    dp[1][j] = dp[0][j-1] + 1;
                }
                else{
                    dp[1][j] = max(dp[0][j],dp[1][j-1]);
                }
            }
            swap(dp[0],dp[1]);
        }
        return dp[0][n];
    }
};
// @lc code=end

