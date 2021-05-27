/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre=0,cur=1,count=0,n=s.size();
        for(int i=1;i<n;++i){
            if(s[i]==s[i-1]) ++cur;
            else{
                pre = cur;
                cur = 1;
            }
            //以当前字符结尾的符合条件的字串
            if(pre>=cur) ++count;
        }
        return count;
    }
};
// @lc code=end

