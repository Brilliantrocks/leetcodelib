/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <2) return 0;
        if (k >= n){
            int pre = prices[0],cnt=0;
            for(int x : prices){
                int d = x-pre;
                if(d) cnt += d;
                pre = x;
            }
            return cnt;
        }
        else{
            // 每日股价操作有两种 买入 卖出
            // 分别记录每日股价进行第j次的两种操作所能带来的最大收益
            // 并和不操作时前i-1个日期的dp比较
            vector<int> buy(k+1,INT_MAX),sell(k+1,0);
            for (int i =0; i <n;++i){
                for(int j = 1; j<=k;++j){
                    buy[j] = max(buy[j],sell[j-1]-prices[i]);
                    sell[j] = max(sell[j],prices[i]+buy[j]);
                }
            }
            return sell[k];
        }
    }
};
// @lc code=end

