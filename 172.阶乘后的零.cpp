/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // 返回阶乘数列中因数5的个数
        return !n ? 0: n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end

