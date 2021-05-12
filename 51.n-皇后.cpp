/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n==0) return ans;
        vector<string> board(n,string(n,'.'));
        vector<bool> col(n,0), ldia(2*n-1,0), rdia(2*n-1,0);
        backtrace(board, col, ldia, rdia, ans, 0, n);
        return ans;
    }

    void backtrace(vector<string> &board, vector<bool> &col, vector<bool> &ldia, vector<bool> &rdia, vector<vector<string>> &ans, int row, int &n){
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i){
            if (col[i]  || ldia[row+i] || rdia[n + row - i -1]) continue;
            board[row][i] = 'Q';
            col[i] = true, ldia[row+i] = true, rdia[n+row-i-1] = true;
            backtrace(board, col, ldia, rdia, ans, row+1, n);
            col[i] = false, ldia[row+i] = false, rdia[n+row-i-1] = false;
            board[row][i] = '.';
        }
        return;
    }
};
// @lc code=end

