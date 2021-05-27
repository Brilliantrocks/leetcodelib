/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if (n!=t.size()) return false;
        int cnt[26] = {0};
        for(int i =0;i<n;++i){
            ++cnt[s[i]-'a'];
            --cnt[t[i]-'a'];
        }
        for(int x:cnt){
            if (x!=0) return false;
        }
        return true;
    }
};
// @lc code=end

