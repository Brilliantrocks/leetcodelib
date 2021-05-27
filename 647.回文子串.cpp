/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(),ans=0;
        for(int i=0;i<len;++i){
            ans += countchar(s,i,i,len);
            ans += countchar(s,i,i+1,len);
        }
        return ans;
    }
    
    int countchar(const string &s,int l, int r,int len){
        int count = 0;
        while(l>=0 && r < len && s[l]==s[r]){
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};
// @lc code=end

