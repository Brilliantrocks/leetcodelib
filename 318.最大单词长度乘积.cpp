/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),ans=0;
        sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size()<b.size();});
        int* mask = new int[n];
        memset(mask, 0, sizeof(int)*n);
        int* size = new int[n];
        for(int i =0;i<n;++i){
            size[i]=words[i].size();
            for(auto x :words[i]){
                mask[i] |= 1<<(x-'a');
            }
        }
        for(int i=0;i<n-1;++i){
            for(int j=n-1;j>i;--j){
                if(!(mask[i]&mask[j])){
                    ans = max(ans,size[i]*size[j]);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int n = words.size(),ans=0;
//         vector<int> mask(n,0);
//         vector<int> size(n,0);
//         for (int i = 0; i < n; ++i)
//         {
//             size[i] = words[i].size();
//             for(auto x:words[i]){
//                 mask[i] |= 1 << (x - 'a');
//             }
//             for(int j =0;j<i;++j){
//                 if((mask[j]&mask[i])==0){
//                     ans=max(ans,size[i]*size[j]);
//                 }
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int n = words.size(),ans=0,temp=0;
//         int* mask = new int[n];
//         memset(mask, 0, sizeof(int)*n);
//         int* size = new int[n];
//         for(int i =0;i<n;++i){
//             size[i]=words[i].size();
//             for(auto x :words[i]){
//                 mask[i] |= 1<<(x-'a');
//             }
//         }
//         for(int i=0;i<n-1;++i){
//             for(int j=i+1;j<n;++j){
//                 temp = size[i]*size[j];
//                 if(temp > ans){
//                     if(!(mask[i]&mask[j])) ans = temp;
//                 }
//             }
//         }
//         return ans;
//     }
// };