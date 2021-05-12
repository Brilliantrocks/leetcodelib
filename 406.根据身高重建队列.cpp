/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),
            people.end(),
            [](vector<int>& a,vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);}
            );
        // 先从高的人开始插入 保证ans里的人总是不矮于插入的人 x[1] < 已排序身高
        // 一定有一个拥有最高身高的人 他前面没有高于他的人 其k为0
        // 依据k从小到大插入
        // 保证插入后前面有k个人 即队首+k
        vector<vector<int>> ans;
        for (vector<int> x:people){
            ans.insert(ans.begin() + x[1],x);
        }
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         sort(people.begin(),
//             people.end(),
//             [](vector<int>& a,vector<int>& b){
//             return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);}
//             );
            // 从矮到高插入 ans中的人总是不高于插入的人 插入位置尽量靠前
            // 对于插入的人 要保证插入位置前至少还可以插入k个人 则先从k大的开始插入
            // 对于最矮身高的人 一定有个人 所有人中他前面不矮于他的人数最多 即k最大
            // 且前面不存在高于他的人 可以根据最大k直接 确定第一个人的位置
//         int size = people.size();
//         vector<vector<int>> ans(size);
//         for (vector<int> x:people){
//             int space = x[1] + 1;
//             for (int i = 0; i < size; ++i){
//                 if (ans[i].empty()) --space;
//                 if (!space) {
//                     ans[i] = x;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };