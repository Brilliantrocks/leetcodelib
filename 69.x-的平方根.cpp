/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
// x > 1 注意整型越界问题

// 牛顿迭代法
// f(x) = 0 求其零点(r,0)
// 对于一个初始近似值 x1 过点(x0,f(x0))作切线
// L : y = f(x0) + f'(x0)(x-x0)
// L的零点为x0 - f(x0))/f'(x0) 为一次近似值x1
// n+1次近似值为  xn+1 = xn - f(xn)/f'(xn)
// 
// 对于求平方根 f= x^2 - a
// xn+1 = xn - xn/2 + a/2xn = xn/2 + a/2xn
// 则 ans = ans/2 + x/2*ans
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long ans = x;
        while (x/ans < ans) {
            ans = (ans + (x/ans))/2;
        }
        return ans;
    }
};
// @lc code=end


// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x < 2) return x;
//         int r = x, l = 0,now = 1,n;
//         while (r >= l){
//             now = l + (r-l)/2;
//             n = x/now;
//             if (n == now) return now;
//             else if (now < n) l = now +1;
//             else r = now - 1;
//         }
//         return r;
//     }
// };
