/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        hash[0]=1;
        int cnt=0,sum=0;
        for(int x: nums){
            sum +=x;
            cnt +=hash[sum-k];
            ++hash[sum];
        }
        return cnt;
    }
};
// @lc code=end

