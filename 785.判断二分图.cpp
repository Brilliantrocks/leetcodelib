/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n==0) return true;
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;++i){
            if(!color[i]){
                q.emplace(i);
                color[i]=1;
            }
            while(!q.empty()){
                int index=q.front();
                q.pop();
                int targetcol=-color[index];
                for(auto x:graph[index]){
                    if(color[x]==0) {
                        color[x]=targetcol;
                        q.emplace(x);
                    }
                    else if(color[x]!=targetcol) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

