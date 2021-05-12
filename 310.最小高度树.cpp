/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> degree(n,0);
        vector<vector<int>> g(n,vector<int>());
        for (const auto &x: edges){
            ++degree[x[0]];
            ++degree[x[1]];
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (degree[i] == 1) q.emplace(i);
        }
        while(n -= q.size()){
            int a;
            for (int len = q.size(); len > 0; --len){
                a = q.front();
                q.pop();
                --degree[a];
                for(const auto &x:g[a]){
                    if (degree[x]){
                        --degree[x];
                        if (degree[x] == 1) q.emplace(x);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

