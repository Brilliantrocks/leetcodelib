/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),cnt = 0;
        vector<int> head(n);
        for (int i = 0; i < n; ++i){
            head[i] = i;
        }
        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                if (isConnected[i][j]){
                    mergecity(head,i,j);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if (head[i] == i) ++cnt;
        }
        return cnt;
    }

    int find_head(vector<int> &head, int i){
        if (head[i] != i){
            head[i] = find_head(head,head[i]);
        }
        return head[i];
    }

    void mergecity(vector<int> &head, int i, int j){
        head[find_head(head,i)] = find_head(head,j);
    }
};
// @lc code=end

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size(),cnt=0;
//         vector<bool> visited(n,0);
//         for (int i = 0; i < n; ++i){
//             if (!visited[i]){
//                 dfs(isConnected,i,visited);
//                 ++cnt;
//             }
//         }
//         return cnt;
//     }
//     void dfs(vector<vector<int>>& isConnected,int i,vector<bool> &visited){
//         visited[i] = true;
//         for (int k =0; k < isConnected.size(); ++k){
//             if (isConnected[i][k] && !visited[k]) {
//                 dfs(isConnected,k,visited);
//             }
//         }

//     }
// };