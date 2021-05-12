/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),
            intervals.end(),
            [](vector<int>& a,vector<int>& b){
                return a[1]<b[1];
                }
            );
        int n = intervals.size(),limit = intervals[0][1],count = 0;
        for (int i = 1; i < n; ++i){
            if (intervals[i][0] < limit) ++count;
            else limit = intervals[i][1];
        }
        return count;
    }
};
// @lc code=end

