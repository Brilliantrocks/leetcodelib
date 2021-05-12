/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后往前插入空位
        int p = n + m;
        while (n > 0){
            nums1[--p] = m < 1 || nums2[n-1] > nums1[m-1] ? nums2[--n] : nums1[--m];
        }
    }
};
// @lc code=end

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         // 从后往前插入空位
//         if (n < 1) return;
//         if (m < 1) nums1 = nums2;
//         int p = n + m -1;
//         for (--n,--m; m > -1 && n > -1;--p){
//             if (nums1[m] > nums2[n]) {
//                 nums1[p] = nums1[m--];
//             }
//             else nums1[p] = nums2[n--];
//         }
//         for (;n > -1; --p){
//             nums1[p] = nums2[n--];
//         }
//     }
// };