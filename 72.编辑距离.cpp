/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n =word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i <=n;++i) dp[0][i] = i;
        for(int i = 0; i <=m;++i) dp[i][0] = i;
        for (int i =1; i <=m; ++i){
            for(int j =1; j<=n; ++j){
                    // 统计所有操作，找到最少步骤
                    // 修改：dp[i-1][j-1] + 1 在字符相同时不增加
                    // 增删：dp[i-1][j]+1或者dp[i][j-1]+1
                    dp[i][j] = min(dp[i-1][j-1] + ((word1[i-1]==word2[j-1]) ? 0 : 1) ,
                    min(dp[i-1][j],dp[i][j-1])+1);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int dp[word1.size()][word2.size()];
//         if(word1.size()==0||word2.size()==0)
//             return max(word1.size(),word2.size());

//         for(int i=0;i<word1.size();i++){
//             for(int j=0;j<word2.size();j++){
//                 if(i==0 && j== 0 ){
//                     dp[i][j] = word1[i]!=word2[j];
//                     continue;
//                 }
//                 else if(i==0){
//                     dp[i][j] = word1[i] == word2[j]? j : dp[i][j-1]+1;
//                     continue;
//                 }
//                 else if(j==0){
//                     dp[i][j] = word1[i] == word2[j]? i : dp[i-1][j]+1;
//                     continue;
//                 }

//                 if(word1[i] == word2[j]){
//                     dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]+1),dp[i][j-1]+1);
//                 }
//                 else{
//                     dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
//                 }
//             }
//         }

//         return dp[word1.size()-1][word2.size()-1];
//     }
// };


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n =word2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//         for(int i = 0; i <=n;++i) dp[0][i] = i;
//         for(int i = 0; i <=m;++i) dp[i][0] = i;
//         for (int i =1; i <=m; ++i){
//             for(int j =1; j<=n; ++j){
//                     // 统计所有操作，找到最少步骤
//                     // 修改：dp[i-1][j-1] + 1 在字符相同时不增加
//                     // 增删：dp[i-1][j]+1或者dp[i][j-1]+1
//                     dp[i][j] = min(dp[i-1][j-1] + ((word1[i-1]==word2[j-1]) ? 0 : 1) ,
//                     min(dp[i-1][j],dp[i][j-1])+1);
//             }
//         }
//         return dp[m][n];
//     }
// };