/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2,nums1);
        // 将nums1下标扩充至[0,2n]来处理不同奇偶性数列的中位数
        // 若为奇数序列则mid/2= (mid-1)/2 中位数 nums1[mid1/2] + nums2[(mid-1)/2]
        // 若为偶数序列 中位数仍为nums1[mid1/2] + nums2[(mid-1)/2]
        int h = 0, t = 2*n;
        int mid1,mid2,limit_l1,limit_r1,limit_l2,limit_r2;
        while (h <= t){
            // 尝试从nums1正向和nums2反向寻找中位数
            mid1 = h + (t-h)/2;
            // 尝试将mid1左侧和mid2左侧放在一堆 剩余部分归为另一堆
            // 首先保证每堆元素下标数目一致
            // 调整使得前者元素总是小于后者元素
            mid2 = n + m - mid1;
            // 设置数列中位数界限
            limit_l1 = (mid1 == 0) ? INT_MIN:nums1[(mid1-1)/2];
            limit_r1 = (mid1 == 2*n) ? INT_MAX:nums1[mid1/2];
            limit_l2 = (mid2 == 0) ? INT_MIN:nums2[(mid2-1)/2];
            limit_r2 = (mid2 == 2*m) ? INT_MAX:nums2[mid2/2];
            // 当nums1的    
            if (limit_l1 > limit_r2) {t = mid1-1;}
            else if (limit_r1 < limit_l2) {h = mid1+1;}
            // 如果一个数列的中位数界限 包含了另一个，则退出循环
            else break;
        }
        return (max(limit_l1 ,limit_l2)+min(limit_r1,limit_r2))/2.0;
    }
};
// @lc code=end

