#include <vector>
#include <algorithm>
#include <numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        // vector<bool> vis(n,0);
        vector<int> set;
        vector<vector<int>> ans;
        // backtrack(candidates,target,ans,set,vis,n,0);
        backtrack(candidates,target,ans,set,n,0);
        return ans;
    }
    // void backtrack(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &set, vector<bool> &vis, int &n, int idx){
    void backtrack(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &set, int &n, int idx){
        if(!target){
            ans.push_back(set);
            return;
        }
        for (int i = idx; i < n; ++i){
            // if (vis[i] || i > 0 && candidates[i] == candidates[i-1] && !vis[i-1]){
            //     continue;
            // }
            if (i>0 && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target){
                set.push_back(candidates[i]);
                // vis[i] = 1;
                backtrack(candidates,target-candidates[i],ans,set,n,i+1);
                // vis[i] = 0;
                set.pop_back();
            }
            else break;
        }
    }
};

main(){
    Solution sl;
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,8);
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,6);
    // vector<int> fb = {0,1};
    // auto ret = sl.searchRange(fb,1);
    vector<int> fb = {10,1,2,7,6,1,5};
    auto ret = sl.combinationSum2(fb,8);
    for(auto x : ret){
        for (auto y:x){
            cout<<y<<',';
        }
        cout<<endl;
    }
}