/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
// #include<vector>
// using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int h = 0,t = nums.size()/2,mid;
        if (!t) return nums[0];
        while (t - h > 0) {
            mid = h + (t-h)/2;
            if (nums[2*mid] == nums[2*mid+1]) {
                h = mid + 1;
            }
            else {
                t = mid;
            }
        }
        return nums[h*2] == nums[h*2+1] ? nums[h*2+2] : nums[h*2];
    }
};
// @lc code=end

