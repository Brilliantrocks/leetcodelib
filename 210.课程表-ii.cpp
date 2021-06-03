/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        
        for(const auto &x : prerequisites){
            graph[x[1]].emplace_back(x[0]);
            ++indegree[x[0]];
        }
        
        for(int i=0;i<numCourses;++i){
            if(!indegree[i]) q.emplace(i);
        }

        while(!q.empty()){
            int index=q.front();
            q.pop();
            ans.emplace_back(index);
            for(auto x : graph[index]){
                --indegree[x];
                if(!indegree[x]) q.emplace(x);
            }
        }
        for(auto x:indegree){
            if(x) return {};
        }
        return ans;
    }
};
// @lc code=end

