/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
#include <vector>
#include <string>
#include<math.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        string ans;
        bool isnegative=0;
        if(num<0) isnegative=true,num=-num;
        while(num){
            int r = num/7, l = num%7;
            ans = to_string(l) + ans;
            num=r;
        }
        return isnegative ? '-'+ans : ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     string convertToBase7(int num) {
//         if (num==0) return "0";
//         bool isnegative=0;
//         if(num<0) isnegative=true,num=-num;
//         int cnt = 0,i=0;
//         while(cnt<num){
//             cnt = pow(7,++i);
//         }
//         string ans;
//         if (isnegative) ans += '-';
//         if (cnt==num) {
//             ans += '1';
//             for (;i>0;--i) ans +='0';
//         }
//         while(i){
//             cnt = pow(7,--i);
//             if (cnt==1) ans += ('0'+num);
//             else {
//                 int x=0;
//                 while(num>=cnt){
//                     num -= cnt;
//                     ++x;
//                 }
//                 ans += ('0'+x);
//             }
//         }
//         return ans;
//     }
// };