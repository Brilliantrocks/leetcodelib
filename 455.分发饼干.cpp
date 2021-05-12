/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(),m = s.size(),i = 0;
        for (int j=0; i < n && j < m; ++j){
            if (g[i] <= s[j]) ++i;
        }
        return i;
    }
};
// @lc code=end

