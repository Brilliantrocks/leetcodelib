/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool col[9][9] = {0},row[9][9] = {0},sq[9][9] = {0};
    vector<pair<int,int>> space;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9 ;++i){
            for (int j = 0; j < 9; ++j){
                char c = board[i][j];
                if (c == '.'){
                    space.emplace_back(i,j);
                }
                else{
                    int num = c - '1';
                    col[i][num] = 1;
                    row[j][num] = 1;
                    sq[i/3 * 3 + j/3][num] = 1;
                }
            }
        }
        int nsp = space.size();
        dfs(board,0,nsp);
    }
    bool dfs(vector<vector<char>>& board,int n,int nsp){
        if (n == nsp) return true;
        auto [i,j] = space[n];
        for(char k = '1'; k <= '9'; ++k){
            int num = k - '1';
            if (!col[i][num] && !row[j][num] && !sq[i/3 * 3 + j/3][num]){
                board[i][j] = k;
                col[i][num] = 1;
                row[j][num] = 1;
                sq[i/3 * 3 + j/3][num] = 1; 
                if (dfs(board,n+1,nsp)) return true;
                col[i][num] = 0;
                row[j][num] = 0;
                sq[i/3 * 3 + j/3][num] = 0;                
            }
        }
        return false;
    }
};
// @lc code=end

