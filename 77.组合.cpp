/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> set(k,0);
        backtrace(n,k,0,1,ans,set);
        return ans;
    }
    
    void backtrace(int n, int k, int lv, int pos, vector<vector<int>> &ans, vector<int> &set){
        if (lv == k) {
            ans.push_back(set);
            return;
        }
        for (int i = pos; i <= n; ++i){
            set[lv] = i;
            backtrace(n,k,lv+1,i+1,ans,set);
        }
    }
};
// @lc code=end

