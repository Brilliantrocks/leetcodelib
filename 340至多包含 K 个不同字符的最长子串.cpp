// 给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。
// 输入: s = "eceba", k = 2
// 输出: 3
// 解释: 则 T 为 "ece"，所以长度为 3。

// 输入: s = "aa", k = 1
// 输出: 2
// 解释: 则 T 为 "aa"，所以长度为 2。

#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n < 0 || k < 0) return 0;
        int nums[26] = {0};
        int r=0,l=0,len=0,cnt=k;
        while (r < n){
            if (cnt){
                if (nums[s[r]-'a']) {
                    --cnt;
                }
                ++nums[s[r]-'a'];
                ++r;
                len = max(len,r-l);
            }
            else {
                while (nums[s[l]-'a']) {
                    if (nums[s[l]-'a'] == 1) ++cnt;
                    --nums[s[l]-'a'];
                    ++l;
                }
            }
        }
        return len;
    }
};


main(){
    Solution s1;
    string s = "eceba";
    int ans = s1.lengthOfLongestSubstringKDistinct(s,2);
    cout<<ans<<endl; 
}