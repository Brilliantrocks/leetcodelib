/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;

class NumArray {
public:
    vector<int> psum;

    NumArray(vector<int>& nums) : psum(nums.size()+1){
        partial_sum(nums.begin(),nums.end(),psum.begin()+1);
    }
    
    int sumRange(int left, int right) {
        return psum[right+1]-psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

