/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

int dir[] = {1,0,-1,0,1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 坐标四个方向遍历的偏移量 x+dir[k],y+dir[k+1]
        int n = grid.size(),m = n ? grid[0].size() : 0,maxsize = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    maxsize = max(maxsize,dfs(grid,i,j));
                }
            }
        }
        return maxsize;
    }

    int dfs(vector<vector<int>>& grid, int i , int j){
        if (!grid[i][j]) return 0;
        int n = grid.size(),m = n ? grid[0].size() : 0,maxsize = 0;
        int x,y,size = 1;
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k){
            x = i + dir[k], y = j + dir[k+1];
            if (x>=0 && x < n && y >= 0 && y < m && grid[x][y]) {
                size += dfs(grid,x,y);
            }
        }
        return size;
    }
};
// @lc code=end

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         // 坐标四个方向遍历的偏移量 x+dir[k],y+dir[k+1]
//         int dir[] = {1,0,-1,0,1};
//         int n = grid.size(),m = n ? grid[0].size() : 0,maxsize = 0, size = 0,x,y;

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j]) {
//                     size = 1;
//                     grid[i][j] = 0;
//                     stack<pair<int,int>> island;
//                     island.push({i,j});
//                     while(!island.empty()){
//                         auto [nowx,nowy] = island.top();
//                         island.pop();
//                         for (int k = 0;k < 4; ++k){
//                             x = nowx + dir[k], y = nowy + dir[k+1];
//                             if(x>=0 && x < n && y >= 0 && y < m && grid[x][y]){
//                                 ++size;
//                                 grid[x][y] = 0;
//                                 island.push({x,y});
//                             }
//                         }
//                     }
//                     maxsize = max(maxsize,size);
//                 }
//             }
//         }
//         return maxsize;
//     }
// };


    // int dfs(vector<vector<int>>& grid, int i , int j){
    //     if (i<0 || i > grid.size() || j <0 || j > grid.size() || !grid[i][j]) return 0;
    //     int x,y,size = 1;
    //     grid[i][j] = 0;
    //     return 1 + dfs(grid,i+1 ,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
    // }