/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,rmax=-1;
        for(int i=0;i<arr.size();++i){
            rmax =max(rmax,arr[i]);
            if(rmax==i){
            ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

