/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> hash;
        int n =points.size();
        int x1,y1,x2,y2,x_cnt,maxcnt=0;
        for(int i=0;i<n-1;++i){
            x1=points[i][0],y1=points[i][1],x_cnt=0;
            for(int j=i+1;j<n;++j){
                x2=points[j][0],y2=points[j][1];
                if(x1==x2) ++x_cnt;
                else{
                    double dx=x1-x2,dy=y1-y2;
                    ++hash[dy/dx];
                }
            }
            maxcnt=max(maxcnt,x_cnt);
            for(auto x:hash){
                maxcnt=max(maxcnt,x.second);
            }
            hash.clear();
        }
        return maxcnt+1;
    }
};
// @lc code=end

