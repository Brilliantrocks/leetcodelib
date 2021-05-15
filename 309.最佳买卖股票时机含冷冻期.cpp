/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if (n<2) return 0;
        // 对于每个日期的股价 有四种对应的操作状态
        // 1.买入 2.卖出 3.买入冷却期 4.卖出冷却期
        vector<int> buy(n),sell(n),buycd(n),sellcd(n);
        buy[0] = buycd[0] = -prices[0];
        for (int i =1;i<n;++i){
            buy[i] = sellcd[i-1]-prices[i];
            buycd[i] = max(buycd[i-1],buy[i-1]);
            sell[i] = max(buycd[i-1],buy[i-1])+prices[i];
            sellcd[i] = max(sell[i-1],sellcd[i-1]);
        }
        return max(sell[n-1],sellcd[n-1]);
    }
};
// @lc code=end

