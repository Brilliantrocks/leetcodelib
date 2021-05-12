/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// #include <vector>
// using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int h = 0,t = nums.size()-1;
        while(h < t){
            int m = quickSelection(nums, h, t);
            if (m == k-1) return nums[m];
            else if (m < k) h = m + 1;
            else t = m - 1;
        }
        return nums[h];
    }

    int quickSelection(vector<int>& nums, int left, int right) {
        int head = left + 1,tail = right;
        int key = nums[left];
        while(1){
            while (head < right && nums[head] >= key) ++head;
            while (left < tail && nums[tail] <= key) --tail;
            if (head >= tail) break;
            swap(nums[head],nums[tail]);
        }
        swap(nums[left],nums[tail]);
        return tail;
    }
};
// @lc code=end

