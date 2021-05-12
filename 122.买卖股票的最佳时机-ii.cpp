/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int size = prices.size();
        for (int i = 1; i < size; ++i){
            ans += max(0,prices[i] - prices[i-1]);
        }
        return ans;
    }
};
// @lc code=end

