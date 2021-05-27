/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<vector>
// #include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        for(int i=n-2;i>=0;--i){
            int j=i+1,temp=temperatures[i];
            while(temp>=temperatures[j]){
                if(ans[j]==0) break;
                j += ans[j];
            }
            if (temp<temperatures[j]) ans[i]=j-i;
            else ans[i]=0;
        }
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n=temperatures.size();
//         vector<int> ans(n);
//         stack<int> minst;
//         for(int i=0;i<n;++i){
//             int temp = temperatures[i];
//             while(!minst.empty()){
//                 int pre=minst.top();
//                 //维护最小栈
//                 if(temperatures[pre]>=temp) break;
//                 minst.pop();
//                 ans[pre]=i-pre;
//             }
//             minst.emplace(i);
//         }
//         return ans;
//     }
// };