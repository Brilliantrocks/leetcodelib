/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <stdint.h> 

class Solution {
public:
const uint32_t m1 = 0x55555555;//01010101010101010101010101010101
const uint32_t m2 = 0x33333333;//00110011001100110011001100110011
const uint32_t m3 = 0x0f0f0f0f;//00001111000011110000111100001111
const uint32_t m4 = 0x00ff00ff;//00000000111111110000000011111111
    uint32_t reverseBits(uint32_t n) {
        n = (n&m1)<<1 |(n>>1 &m1);
        n = (n&m2)<<2 |(n>>2 &m2);
        n = (n&m3)<<4 |(n>>4 &m3);
        n = (n&m4)<<8 |(n>>8 &m4);
        return n>>16|n<<16;
    }
};
// @lc code=end

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t ans = 0;
//         for(int i =0; i<32;++i){
//             ans<<=1;
//             ans += n&1;
//             n>>=1;
//         }
//         return ans;
//     }
// };