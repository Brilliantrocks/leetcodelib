/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
// {1,2,3,4,5}
// {3,1,2,3,4,5} -> {1,1,2,3,4,5}
// {1,6,2,3,4,5} -> {1,1,2,3,4,5}
// {1,2,3,2,1,5}

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return true;
        int count = 0, limit = nums[0], pos;
        for (int i = 1; i < n; ++i){
            if (nums[i] < limit) {
                ++count;
                pos = i;
            }
            limit = nums[i];
            if (count > 1) return false;
        }
        // 对于nums[pos] < nums[pos-1]
        // 补救措施为在二者中选取一个数
        // 使其在[nums[pos-2],nums[pos+1]]的范围内
        // 当二者都不在范围内时return false
        if (count && pos > 1 && pos < n - 1 && nums[pos] < nums[pos-2] && nums[pos-1] > nums[pos+1]) return false;
        return true;
    }
};
// @lc code=end

// class Solution {
// public:
//     bool checkPossibility(vector<int> &nums) {
//         int n = nums.size(), cnt = 0;
//         for (int i = 0; i < n - 1; ++i) {
//             int x = nums[i], y = nums[i + 1];
//             if (x > y) {
//                 cnt++;
//                 if (cnt > 1) {
//                     return false;
//                 }
//                 if (i > 0 && y < nums[i - 1]) {
//                     nums[i + 1] = x;
//                 }
//             }
//         }
//         return true;
//     }
// };


