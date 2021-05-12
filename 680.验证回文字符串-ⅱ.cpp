/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int h = 0,t = s.size()-1,count = 2,sh,st;;
        if (t < 2) return true;
        while(h < t){
            if (s[h] != s[t]){ 
                if (!count)  return false;            
                if (count ==2){
                    if (s[h+1] != s[t] && s[h] != s[t-1]) return false;    
                    sh = h;
                    st = t -1;
                    ++h;
                }
                else {
                    h = sh;
                    t = st;
                }
                --count;
            }
            ++h;
            --t;
        }
        return true;
    }
};
// @lc code=end


// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int h = 0,t = s.size()-1,count = 2,sh,st;;
//         if (t < 2) return true;
//         while(h < t){
//             if (s[h] != s[t]){ 
//                 if (!count)  return false;            
//                 if (count ==2){
//                     if (s[h+1] != s[t] && s[h] != s[t-1]) return false;    
//                     sh = h;
//                     st = t -1;
//                     ++h;
//                 }
//                 else {
//                     h = sh;
//                     t = st;
//                 }
//                 --count;
//             }
//             ++h;
//             --t;
//         }
//         return true;
//     }
// };
// public:
//     bool validPalindrome(string s) {
//         int h = 0,t = s.size()-1,h1,t1;
//         for (;h < t &&s[h] == s[t];++h,--t);
//         if (h >= t) return true;
//         for (h1=h+1,t1=t;h1 < t1 &&s[h1] == s[t1];++h1,--t1);
//         if (h1 >= t1) return true;
//         for (h1=h,t1=t-1;h1 < t1 &&s[h1] == s[t1];++h1,--t1);
//         if (h1 >= t1) return true;
//         return false;
//     }
// };