/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        dp[0][0] = true;
        // 初始化空字符串仍能匹配的'*'正则字符
        for (int i = 2; i <=m;++i){
            if (p[i-1]=='*'){
                dp[0][i] = dp[0][i-2];
            }
        }
        for (int i = 1; i <=n; ++i){
            for (int j = 1; j <= m; ++j){
                // 当为'.'匹配任意字符
                if (p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                // 不为'*'的情况
                else if (p[j-1] !=  '*'){
                    dp[i][j]=dp[i-1][j-1] && s[i-1]==p[j-1];
                }
                // 当前正则字符为'*'时
                // 前个正则字符不匹配 跳过任意次数匹配"s[i-1]*" 前向追溯两个正则字符
                else if (p[j-2] != s[i-1] && p[j-2]!='.'){
                    dp[i][j]=dp[i][j-2];
                }
                // 前个正则字符匹配 统计所有可能匹配的情况
                // 1.前i-1个字符已匹配前j个正则字符
                // 2.前i个字符已匹配前j-1个正则字符
                // 3.前i个字符已匹配两个正则字符之前的条件
                else {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i][j-2];
                }
            }
        }
        return dp[n][m];
    }
};

// @lc code=end


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         // 当正则表达式全部匹配完时，判断字符串是否还有未匹配的字符
//         if (p.empty()) return s.empty();
//         bool Firstmatch = !s.empty() && (p[0] == '.'||s[0] == p [0]);
//         // 当p中出现*时
//         if (p.size() >=2 && p[1] == '*'){
//             // 统计截断s或者截断p的可能情况
//             return isMatch(s,p.substr(2)) || (Firstmatch&&isMatch(s.substr(1),p));
//         }
//         // 通常状况，二者截断一位递归调用
//         return Firstmatch && isMatch(s.substr(1),p.substr(1));
//     }
// };