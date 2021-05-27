/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        int ans;
        for(int x:nums){
            hash.insert(x);    
        }
        int cnt,temp;
        for(int x:hash){
            if(!hash.count(x-1)){
                cnt=1;
                temp = x;
                while(hash.count(++temp)){
                    ++cnt;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
// @lc code=end


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> hash;
//         for(int x : nums){
//             hash.insert(x);
//         }
//         int ans=0;
//         while(!hash.empty()){
//             int cur = *(hash.begin());
//             hash.erase(cur);
//             int next =cur+1,pre =cur-1;
//             while(hash.count(next)) hash.erase(next++);
//             while(hash.count(pre)) hash.erase(pre--);
//             ans=max(ans,next-pre-1);
//         }
//         return ans;
//     }
// };