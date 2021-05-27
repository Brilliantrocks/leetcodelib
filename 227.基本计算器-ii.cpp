/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        char op ='+';
        long l=0,r=0;
        int i = 0,n=s.size();
        while(i<n){
            if (s[i]!=' '){
                long num = parsenum(s,i,n);
                switch(op){
                    case '+' : l += r; r = num; break;
                    case '-' : l += r; r = -num; break;
                    case '*' : r *= num; break;
                    case '/' : r /= num; break;
                }
                if (i < n) op = s[i];
            }
            ++i;
        }
        return l + r;
    }

    int parsenum(const string &s,int i,int n){
        long num = 0;
        while(i<n && isdigit(s[i])){
            num = num*10 + (s[i++]-'0');
        }
        return num;
    }
};
// @lc code=end

