/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 *
 * [1223] 掷骰子模拟
 */

// @lc code=start
// #include <vector>
// #include <algorithm>
// #include <math.h>
// using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        if (n == 1) return 6;
        int mod = 1000000007;
        vector<vector<long long> > count(n+1,vector<long long>(7,0));
        for (int i = 1; i < 7; ++i){
            count[1][i] = 1;
        }
        count[0][0] = 1;
        count[1][0] = 6;
        for (int i = 2; i <= n; ++i){
            for (int k = 1; k < 7; ++k){
                int limit = rollMax[k-1];
                (count[i][k] += count[i-1][0]) %= mod;
                if ((i - limit) > 0){
                    (count[i][k] -= count[i-limit-1][0] - count[i-limit-1][k]) %= mod;
                    if (count[i][k] < 0) count[i][k] += mod;
                }
                (count[i][0] += count[i][k]) %= mod;
            }
        }
        return count[n][0];
    }
};
// @lc code=end

