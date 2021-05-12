#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i){
            dfs(board,i,0,m,n);
            dfs(board,i,n-1,m,n);
        }
        for (int i = 1; i < n-1; ++i)
        {
            dfs(board,0,i,m,n);
            dfs(board,m-1,i,m,n);            
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'P') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>> &board,int i, int j, int m, int n){
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'P';
        dfs(board,i+1,j,m,n);
        dfs(board,i-1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i,j-1,m,n);
    }
};

main(){
    Solution s1;
    vector<vector<char>> a = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s1.solve(a);
    for(auto x : a){
        for (auto y : x){
            cout<<y;
        }
    cout<<endl; 
    }
}