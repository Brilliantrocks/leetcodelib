/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return n;
        int cur, pre = 2, ppre = 1;
        for(int i = 2; i < n; ++i){
            cur = pre + ppre;
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

