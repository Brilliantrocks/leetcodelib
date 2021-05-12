/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
// #include<vector>
// #include<algorithm>
// using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> set;
        vector<bool> visited(n,0);
        vector<vector<int>> ans;
        backtrack(ans,set,nums,visited,n);
        return ans;
    }
    void backtrack(vector<vector<int>> &ans, vector<int> &set, vector<int> &nums, vector<bool> &visited, int &n){
        if (set.size() == n) {
            ans.push_back(set);
            return;
        }
        for (int i = 0; i < n; ++i){
            // 访问过的nums跳过
            // 本次循环的set位 后续已使用过相同数字跳过
            // 对于之后的set位 若相同数字已被使用过 则顺延至下个未被使用过的相同数字
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])){
                continue;
            }
            set.emplace_back(nums[i]);
            visited[i] = 1;
            backtrack(ans,set,nums,visited,n);
            visited[i] = 0;
            set.pop_back();
        }
    }
};
// @lc code=end

