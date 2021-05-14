/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
// 只能向右或者向下移动
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        // 按照每一行遍历
        for (int i = 0; i < m; ++i){
            // 再对每一列遍历
            // 更新dp[j]为遍历到这个坐标时的距离
            for (int j = 0; j < n;++j){
                if (i == 0 && j == 0){
                    dp[0] = grid[0][0];
                }
                // 最上行只能由左侧移动来
                else if (i == 0){
                    dp[j] = grid[i][j] + dp[j-1];
                }
                // 最左列只能由上侧移动来
                else if (j == 0){
                    dp[j] = grid[i][j] + dp[j];
                }
                else {
                    dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

