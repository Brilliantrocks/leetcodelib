/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return 1;
        // 两个方向累加 
        // 正反看去都是连续递增数列 
        // limit为正向递增边界值
        int ans = 1,front = 1,limit = 1,back = 0;
        for (int i = 0; i < n-1; ++i){
            // 正向累加 重置反向递增数列
            if (ratings[i+1] > ratings[i]){
                back = 0;
                ans += ++front;
                limit = front;
            }
            // 同位叠1 重置双向递增
            else if(ratings[i+1] == ratings[i]) {
                ++ans;
                back = 0;
                front = 1;
                limit = 1;
            }
            // 反向累加 重置正向递增数列
            else {
                front = 1;
                ++back;
                // 反向累加到达正向边界时额外计算边界
                if (back == limit) ++back;
                ans += back;
            }
        }
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         if (n < 2) return 1;
//         vector<int> candy(n,1);
//         for (int i = 0; i < n - 1; ++i){
//             if (ratings[i+1] > ratings[i]) 
//                 candy[i+1] = candy[i] + 1;
//         }
//         for (int i = n - 1; i > 0; --i){
//             if (ratings[i-1] > ratings[i] && candy[i-1] <= candy[i]) 
//                 candy[i-1] = candy[i] + 1;
//         }
//         return accumulate(candy.begin(),candy.end(),0);
//     }
// };