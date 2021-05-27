/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> ans;
        int n =nums.size();
        for(int i=0;i<n;++i){
            int x = nums[i];
            auto pos = hash.find(target-x);
            if(pos==hash.end()) hash[x]=i;
            else {
                ans.emplace_back(pos->second);
                ans.emplace_back(i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

