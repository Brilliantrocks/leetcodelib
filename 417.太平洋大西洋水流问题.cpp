/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
#include<vector>
using namespace std;

int dir[] = {1,0,-1,0,1};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = m ? heights[0].size() : 0;
        vector<vector<bool>> rec_p(m,vector<bool>(n,0));
        vector<vector<bool>> rec_a(m,vector<bool>(n,0));
        for(int i = 0; i < m; ++i){
            dfs(heights,rec_p,i,0);
            dfs(heights,rec_a,i,n-1);
        }
        for(int i = 0; i < n; ++i){
            dfs(heights,rec_p,0,i);
            dfs(heights,rec_a,m-1,i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rec_a[i][j] && rec_p[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<bool>> &rec, int i, int j){
        if (rec[i][j]) return;
        rec[i][j] = 1;
        int x,y;
        for (int k = 0; k < 4; ++k){
            x = i + dir[k], y = j + dir[k+1];
            if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && heights[i][j] <= heights[x][y]){
                dfs(heights, rec, x,y);
            }
        }
    }
};
// @lc code=end

