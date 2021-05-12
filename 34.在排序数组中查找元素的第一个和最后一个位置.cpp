/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int h = 0,n = nums.size();
        if (n == 1 && nums[0] == target) return {0,0};
        vector<int> ans = {-1,-1};
        int t = n - 1,mid;
        // 搜索第一个为target的值
        // 不存在target时终止条件为搜索区间小于0 全搜索
        // 未找到时不触发第二个else
        while (t - h >= 0){
            mid = h + (t - h)/2;
            if (nums[mid] < target) h = mid+1;
            else if (nums[mid] > target) t = mid-1;
            else {
                // 搜索到第一个为target的值 就地分别进行双向搜索第一个不为target的值
                // 对于此时的h t,
                int x = h,y = mid,z;
                // 终止条件为搜索区间等于0 x=y 而nums[y]总是为target
                // 对于nums[h]=target 则一直走else if 直到y = z = x = h
                while(x < y){
                    z = x + (y - x)/2;
                    if (nums[z] < target) x = z+1;
                    else if (nums[z] == target) y = z;
                }
                ans[0] = y;
                x = mid, y = t;
                // 终止条件为搜索区间等于0 x=y 而nums[x]总是为target 
                // 对于nums[t]=target 一直走if 直到 x = z = y = t
                while(x < y){
                    z = x + (y - x + 1)/2;
                    if (nums[z] == target) x = z;
                    else if (nums[z] > target) y = z-1;
                }
                ans[1] = x;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

// 双边界分别计算
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.empty()) return vector<int>{-1, -1};
//         int lower = lower_bound(nums, target);
//         int upper = upper_bound(nums, target) - 1; // 这里需要减1位
//         if (lower == nums.size() || nums[lower] != target) {
//         return vector<int>{-1, -1};
//         }
//         return vector<int>{lower, upper};
//         }
//     // 辅函数
//     int lower_bound(vector<int> &nums, int target) {
//         int l = 0, r = nums.size(), mid;
//         while (l < r) {
//             mid = l + (r - l) / 2;
//             if (nums[mid] >= target) {
//                 r = mid;
//             } else {
//                 l = mid + 1;
//             } 
//         }
//         return l;
//     }
// // 辅函数
//     int upper_bound(vector<int> &nums, int target) {
//         int l = 0, r = nums.size(), mid;
//         while (l < r) {
//             mid = l + (r - l) / 2;
//             if (nums[mid] > target) {
//             r = mid;
//             } else {
//                 l = mid + 1;
//             } 
//         }
//         return l;
//     }
// };