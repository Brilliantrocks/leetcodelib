/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nsub = strs.size();
        // dp为前x个字串在m,n限制下的最大数量
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (const string &s : strs){
            auto [cnt0,cnt1] = countnum(s);
            for(int i = m; i >= cnt0; --i){
                for(int j = n; j >= cnt1; --j){
                    dp[i][j] = max(dp[i][j],dp[i-cnt0][j-cnt1]+1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int,int> countnum(const string &s){
        int cnt0 = 0;
        for(const char &x : s){
            if (x == '0') ++cnt0;
        }
        return {cnt0,s.size()-cnt0};
    }
};
// @lc code=end

