/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<bool> vis(n,0);
        vector<int> set;
        vector<vector<int>> ans;
        backtrack(candidates,target,ans,set,vis,n,0);
        return ans;
    }
    void backtrack(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &set, vector<bool> &vis, int &n, int idx){
        if(!target){
            ans.push_back(set);
            return;
        }
        for (int i = idx; i < n; ++i){
            if (vis[i] || i > 0 && candidates[i] == candidates[i-1] && !vis[i-1]){
                continue;
            }
            if (candidates[i] <= target){
                set.push_back(candidates[i]);
                vis[i] = 1;
                backtrack(candidates,target-candidates[i],ans,set,vis,n,i+1);
                vis[i] = 0;
                set.pop_back();
            }
            else break;
        }
    }
};
// @lc code=end

