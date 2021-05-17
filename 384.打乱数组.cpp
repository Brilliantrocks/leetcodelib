/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> ori;
    Solution(vector<int>& nums):ori(move(nums)){}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(ori);
        for(int i = shuffled.size()-1;i>=0;--i){
            swap(shuffled[i],shuffled[rand()%(i+1)]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

    vector<int> shuffle() {
        vector<int> shuffled(ori);
        int n = shuffled.size();
        for(int i = 0;i<n;++i){
            swap(shuffled[i],shuffled[i+(rand()%(n-i))]);
        }
        return shuffled;
    }