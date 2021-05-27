/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
// #include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> premax(n),suffmax(n);
        for(int i=0;i<n;++i){
            if(i%k==0) premax[i]=nums[i];
            else premax[i]=max(premax[i-1],nums[i]);
        }
        for(int i=n-1;i>-1;--i){
            if(i==n-1||i%k==0) suffmax[i]=nums[i];
            else suffmax[i]=max(suffmax[i+1],nums[i]);
        }
        for(int i = 0;i<=n-k;++i) ans.emplace_back(max(suffmax[i],premax[i+k-1]));
        return ans;
    }
};
// @lc code=end

// 308ms 48.46% 128.6mb 72.61%
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         deque<int> dq;
//         int n = nums.size();
//         for(int i=0;i<n;++i){
//             if(!dq.empty()&&i-k==dq.front()) dq.pop_front();
//             int x = nums[i];
//             while(!dq.empty()&&nums[dq.back()]<x) dq.pop_back();
//             dq.emplace_back(i);
//             if(i>=k-1) ans.emplace_back(nums[dq.front()]);
//         }
//         return ans;
//     }
// };