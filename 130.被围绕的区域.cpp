/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;

int dir[] = {1,0,-1,0,1};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i){
            if (board[i][0] == 'O') q.emplace(i,0);
            if (board[i][n-1] == 'O') q.emplace(i,n-1);
        }
        for (int i = 1; i < n-1; ++i){
            if (board[0][i] == 'O') q.emplace(0,i);
            if (board[m-1][i] == 'O') q.emplace(m-1,i);
        }
        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            board[x][y] = 'P';
            for (int k = 0; k < 4; ++k){
                int nx = x + dir[k], ny = y + dir[k+1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 'O'){
                    continue;
                }
                q.emplace(nx,ny);
            }
        }
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'P') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int m = board.size(), n = m ? board[0].size() : 0;
//         for (int i = 0; i < m; ++i){
//             dfs(board,i,0,m,n);
//             dfs(board,i,n-1,m,n);
//         }
//         for (int i = 1; i < n-1; ++i)
//         {
//             dfs(board,0,i,m,n);
//             dfs(board,m-1,i,m,n);            
//         }

//         for (int i = 0; i < m; ++i){
//             for (int j = 0; j < n; ++j){
//                 if (board[i][j] == 'P') board[i][j] = 'O';
//                 else if (board[i][j] == 'O') board[i][j] = 'X';
//             }
//         }
//     }
//     void dfs(vector<vector<char>> &board,int i, int j, int m, int n){
//         if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O'){
//             return;
//         }
//         board[i][j] = 'P';
//         dfs(board,i+1,j,m,n);
//         dfs(board,i-1,j,m,n);
//         dfs(board,i,j+1,m,n);
//         dfs(board,i,j-1,m,n);
//     }
// };