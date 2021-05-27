/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
// kmp算法 处理needle串前数个相同的字符
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len1 = haystack.size(),len2 = needle.size();
        // 计算失配时从needle的何处继续匹配
        // 比较当前位置的相同的前缀后缀长度
        // 失配时从对应前缀末尾处继续匹配   
        vector<int> next(len2,0);
        next[0]=-1;
        for(int i=0,j=-1;i<len2-1;){
            if(j==-1 || needle[i]==needle[j]){
                ++i,++j;
                next[i]=j;
            }
            else j=next[j];
        }
        for(int i=0,j=0;i<len1;){
            if(j==-1||haystack[i]==needle[j]) {
                ++j,++i;
                if(j==len2) return i-len2;
            }
            else j=next[j];
        }
        return -1;
    }
};
// @lc code=end

