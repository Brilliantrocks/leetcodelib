/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
// #include <vector>
// #include <iostream>
// using namespace std;

#include <algorithm>
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int size = points.size();
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){return a[1] < b[1];});
        int count = 1, back = points[0][1];
        for (int i = 1; i < size; ++i){
            if (points[i][0] > back){
                back = points[i][1];
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         if (points.empty()) return 0;
//         int size = points.size();
//         sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){return a[1] < b[1];});
//         int count = 1, front = points[0][0], back = points[0][1];
//         for (int i = 1; i < size; ++i){
//             int tempf = points[i][0];
//             int tempb = points[i][1];
//             if (tempf <= front) continue;
//             else if (tempf <= back) {
//                 front = tempf;
//             }
//             else {
//                 front = tempf;
//                 back = tempb;
//                 ++count;
//             }
//         }
//         return count;
//     }
// };