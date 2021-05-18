/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 4的幂为x*4= x * 0b100 即x=x<<2 1在奇数位；
        // 01010101010101010101010101010101 = 1,431,655,765
        if (n<0) return false;
        if ((n&(n-1))!=0) return false;
        else return n&1431655765;
    }
};
// @lc code=end

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<0) return false;
//         int nums[] = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
//         for (int x :nums){
//             if (x==n) return true;
//             else if(x>n) return false;
//         }
//         return false;
//     }
// };