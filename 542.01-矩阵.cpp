/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX-1));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    if (i > 0){
                        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                    }
                    if (j > 0){
                        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                    }
                }
            }
        }
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if (mat[i][j]){
                    if (i < m-1){
                        dp[i][j] = min(dp[i][j],dp[i+1][j]+1);
                    }
                    if (j < n-1){
                        dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                    }
                }
            }
        }
        return dp;
    }
};
// @lc code=end

