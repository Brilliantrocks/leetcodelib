/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> prime(n,1);
        // 剔除一半为偶数的情况
        int cnt = n/2,limit=sqrt(n);
        // 遍历所有可能的最小质因数
        // 则必然小于n的根
        for (int i = 3;i<=limit;i+=2){
            if(!prime[i]) continue;
            // 从i倍个最小质因数开始遍历奇数倍
            // 避免重复标记
            for(int j=i*i;j<n;j+=2*i){
                if(prime[j]){
                    prime[j]=0;
                    --cnt;
                }                    
            }
        }
        return cnt;
    }
};
// @lc code=end

// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n<2) return 0;
//         vector<bool> prime(n,1);
//         int cnt = n-2;
//         for (int i=2; i<n;++i){
//             if(prime[i]){
//                 for(int j=2*i;j<n;j+=i){
//                     if(prime[j]){
//                         prime[j]=false;
//                         --cnt;
//                     }
//                 }
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n<2) return 0;
//         vector<bool> prime(n,1);
//         vector<int> primes;
//         for (int i=2; i<n;++i){
//             if(prime[i]){
//                 primes.push_back(i);
//             }
//             for(int j=0;j<primes.size()&&i*primes[j]<n;++j){
//                 prime[primes[j]*i]=false;
//                 if(i%primes[j]==0) break;
//             }
//         }
//         return primes.size();
//     }
// };