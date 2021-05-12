#include <vector>
#include <algorithm>
#include <iostream>
// #include <math.h>
using namespace std;

// class Solution {
// public:
//     int dieSimulator(int n, vector<int>& rollMax) {
//         int maxcount = 0;
//         for (int i = 0; i < 6; ++i){
//             maxcount = max(maxcount,rollMax[i]);
//         }
//         vector<vector<vector<int> > > count(n,vector<vector<int> >(6,vector<int>(maxcount,0)));
//         // count[i][j][k] 描述第i次掷出现骰子数字(j+1)时，(j+1)连续出现k次的可能序列数量
//         for (int j = 0; j < 6; ++j){
//             count[0][j][0] = 1;
//         }
//         // 对于每次掷骰子遍历
//         for (int i = 1; i < n; ++i){
//             // 对于掷骰子出现6种数字遍历
//             for (int j = 0; j < 6; ++j){
//                 // 处理当前数字连续出现k次
//                 for (int k = 1; k < rollMax[j]; ++k){
//                     count[i][j][k] = count[i-1][j][k-1];
//                 }
//                 // 处理当前数字非连续出现
//                 for (int j2 = 0; j2 < 6; ++j2){
//                     if (j2 == j) continue;
//                     for (int k2 = 0; k2 < rollMax[j2]; ++k2){
//                         count[i][j][0] += count[i-1][j2][k2];
//                         count[i][j][0] %= 1000000007;
//                     }
//                 }
//             }
//         }
//         int ans = 0;
//         for (int j = 0; j < 6; ++j){
//             for (int k = 0; k < rollMax[j]; ++k){
//                 ans += count[n-1][j][k];
//                 ans %= 1000000007;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        if (n == 1) return 6;
        int mod = 1000000007;
        vector<vector<long long> > count(n+1,vector<long long>(7,0));
        for (int i = 1; i < 7; ++i){
            count[1][i] = 1;
        }
        count[0][0] = 1;
        count[1][0] = 6;
        for (int i = 2; i <= n; ++i){
            for (int k = 1; k < 7; ++k){
                int limit = rollMax[k-1];
                (count[i][k] += count[i-1][0]) %= mod;
                if ((i - limit) > 0){
                    count[i][k] -= count[i-limit-1][0] - count[i-limit-1][k];
                }
                (count[i][0] += count[i][k]) %= mod;
            }
        }
        int ans = count[n][0];
        return ans;
    }
};

main(){
    Solution s1;
    vector<int> a = {2,1,1,3,3,2};
    int ans = s1.dieSimulator(4,a);//1082
    cout<<ans<<endl; 
}