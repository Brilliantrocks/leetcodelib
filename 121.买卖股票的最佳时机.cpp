/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0,buy=INT_MAX;
        for(int x:prices){
            buy = min(buy,x);
            sell = max(sell,x-buy);
        }
        return sell;
    }
};
// @lc code=end

