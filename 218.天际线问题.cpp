/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    //buildings 按 lefti 非递减排序;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int n = buildings.size();
        int x,h,i=0;
        // 默认为大顶堆
        // （高度，右界）依次比较
        priority_queue<pair<int,int>> pqueue;
        while(i<n||!pqueue.empty()){
            // 堆为空或者当前左界在已记录最高区间右界左方
            if(pqueue.empty()||i<n && buildings[i][0]<=pqueue.top().second){
                x=buildings[i][0];
                while(i<n&&x==buildings[i][0]){
                    pqueue.emplace(buildings[i][2],buildings[i][1]);
                    ++i;
                }
            }
            // 当前区间在已记录最高区间右侧
            else{
                x=pqueue.top().second;
                while(!pqueue.empty()&&x>=pqueue.top().second) pqueue.pop();
            }
            h=pqueue.empty() ? 0 : pqueue.top().first;
            if(ans.empty()||h!=ans.back()[1]) ans.push_back({x,h});
        }
        return ans;
    }
};
// @lc code=end

