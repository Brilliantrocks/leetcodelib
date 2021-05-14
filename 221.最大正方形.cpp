/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n =matrix[0].size(),maxl=0;
        // 右下方向遍历
        // dp[i][j]表示以(i-1,j-1)为右下角的正方形的最大边长
        // 当坐标为1时 当剩余三个dp都不小于k-1时 当前dp为k
        // 为最上和最左留出一行一列
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    maxl = max(maxl,dp[i][j]);
                }
            }
        }
        return maxl*maxl;
    }
};
// @lc code=end

