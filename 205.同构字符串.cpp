/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        if (n!=t.size()) return false;
        int cnt1[256]={0},cnt2[256]={0},temp=0,snow,tnow;
        for(int i=0;i<n;++i){
            snow=s[i];
            tnow=t[i];
            if(cnt1[snow]!=cnt2[tnow]) return false;
            if(cnt1[snow]==0) {
                cnt1[snow]=++temp;
                cnt2[tnow]=temp;
            }
        }
        return true;
    }
};
// @lc code=end

