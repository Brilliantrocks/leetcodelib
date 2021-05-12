/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
// 2c = (a + b)^2 + (a - b)^2
#include<math.h>
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a= (int)sqrt(c),b=0;
        while (a >= b){
            long x = a*a + b*b;
            if (x > c) --a;
            else if (x == c) return true;
            else ++b;
        }
        return false;
    }
};
// @lc code=end

