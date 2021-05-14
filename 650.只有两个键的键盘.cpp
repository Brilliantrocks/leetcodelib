/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int limit = sqrt(n);
        vector<int> dp(n+1);
        for (int i = 2; i <=n; ++i){
            // 默认值为拷贝i个单一字符
            dp[i] = i;
            // 一旦找到可以正常地j 在dp[j]之后再进行i/j操作
            for (int j = 2; j <= limit; ++j){
                if (!(i%j)){
                    dp[i] = dp[i/j] + dp[j];
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

