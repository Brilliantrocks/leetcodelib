/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n = nums.size() - 1;
        int maxc=0;

        for (const int &x:nums){
            maxc = max(++count[x],maxc);
        }

        vector<vector<int>> bucket(maxc + 1);

        for (const auto & x : count){
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        for(int i = maxc; i >= 0 && ans.size() < k; --i){
            for(const auto & x : bucket[i]){
                ans.push_back(x);
                if (ans.size() == k) break;
            }
        }
        
        return ans;
    }
};
// @lc code=end

