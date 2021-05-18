/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        int temp,cnt;
        for(int i=0;i<=num;++i){
            temp=i,cnt=0;
            while(temp){
                temp &= (temp-1);
                ++cnt;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};
// @lc code=end

