/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int pos,n=nums.size();
        for(int x:nums){
            pos = abs(x)-1;
            if(nums[pos]>0){
                nums[pos] = -nums[pos];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
// @lc code=end

