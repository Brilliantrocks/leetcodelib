/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

int dir[] = {1,0,-1,0,1};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (board[i][j] == word[0] && backtrace(board,word,i,j,1)){
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrace(vector<vector<char>>& board, string &word, int &i, int &j, int lv){
        if (lv == word.size()) return true;
        char temp = board[i][j];
        board[i][j] = '\0';
        int x,y;
        bool ans = 0;
        for (int k = 0; k < 4; ++k){
            x = i + dir[k], y = j + dir[k+1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[lv]){
                if (backtrace(board,word,x,y,lv+1)) return true;
            }
        }
        board[i][j] = temp;
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size(), n = m ? board[0].size() : 0;
//         vector<vector<bool>> visited(m,vector<bool>(n,0));
//         for (int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 if (board[i][j] == word[0] && backtrace(board,word,i,j,1,visited)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool backtrace(vector<vector<char>>& board, string word, int i, int j, int lv,vector<vector<bool>> &visited){
//         if (lv == word.size()) return true;
//         visited[i][j] = 1;
//         int x,y;
//         bool ans = 0;
//         for (int k = 0; k < 4; ++k){
//             x = i + dir[k], y = j + dir[k+1];
//             if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y] && board[x][y] == word[lv]){
//                 ans = backtrace(board,word,x,y,lv+1,visited);
//             }
//             if (ans) return true;
//         }
//         visited[i][j] = 0;
//         return ans;
//     }
// };

// int dir[] = {1,0,-1,0,1};
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size(), n = m ? board[0].size() : 0;
//         for (int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 if (backtrace(board,word,i,j,0)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool backtrace(vector<vector<char>>& board, string &word, int i, int j, int lv){
//         if (lv == word.size()) return true;
//         if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[lv]){
//             return false;
//         }
//         char temp = board[i][j];
//         board[i][j] = '\0';
//         int x,y;
//         for (int k = 0; k < 4; ++k){
//             x = i + dir[k], y = j + dir[k+1];
//             if (backtrace(board,word,x,y,lv+1)){
//                 return true;
//             }
//         }
//         board[i][j] = temp;
//         return false;
//     }
// };