#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int dir[] = {1,0,-1,0,1};
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = m ? A[0].size() : 0;
        bool once = 0;
        queue<pair<int,int>> border;
        for (int i = 0; i < m; ++i){
            if (once) break;
            for (int j = 0; j < n; ++j){
                if (A[i][j]  == 1) {
                dfs(A,border,i,j,m,n);
                once = 1;
                break;
                }
            }
        }
        // bfs
        int x,y,lv=0;
        while(!border.empty()){
            ++lv;
            int len = border.size();
            while(len--){
                auto [i,j] = border.front();
                border.pop();
                for (int k = 0; k < 4; ++k){
                    x = i + dir[k], y = j + dir[k+1];
                    if (x >= 0 && y >= 0 && x < m && y < n){
                        if (A[x][y] == 1) return lv;
                        else if (A[x][y] == 2) continue;
                        border.push({x,y});
                        A[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(vector<vector<int>>& A, queue<pair<int,int>> &border, int i, int j, int m ,int n){
        if (i < 0 || j < 0 || i >= m || j >= n || A[i][j] == 2) return;
        if (A[i][j] ==0) {
            border.push({i,j});
            return;
        }
        A[i][j] = 2;
        dfs(A,border,i+1,j,m,n);
        dfs(A,border,i-1,j,m,n);
        dfs(A,border,i,j-1,m,n);
        dfs(A,border,i,j+1,m,n);
    }
};

main(){
    vector<vector<int>> s ={{0,1,0},{0,0,0},{0,0,1}};
    Solution sl;
    auto ret = sl.shortestBridge(s);
    cout<<ret<<endl;
}