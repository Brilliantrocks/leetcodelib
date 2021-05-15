/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <vector>
#include <string>
#include<sstream>
#include<iostream>
// #include <cstring>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        istringstream ss(expression+'+');
        int num;
        char op;
        while(ss>>num && ss>>op){
            nums.push_back(num);
            ops.push_back(op);
        }
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>()));
        for (int i = 0; i < n; ++i){
            for(int j = i; j>=0;--j){
                if(i==j) dp[j][i].push_back(nums[i]);
                else{
                    for(int k = j;k<i;++k){
                        for(auto l:dp[j][k]){
                            for(auto r:dp[k+1][i]){
                                switch(ops[k]){
                                    case '+':dp[j][i].push_back(l+r);break;
                                    case '-':dp[j][i].push_back(l-r);break;
                                    case '*':dp[j][i].push_back(l*r);break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

// class Solution {
// public:
//     vector<int> diffWaysToCompute(string expression) {
//         vector<int> ans;
//         char x;
//         int n = expression.size();
//         for (int i = 0; i<n;++i){
//             x = expression[i];
//             if(x=='+'||x=='-'||x=='*'){
//                 vector<int> left = diffWaysToCompute(expression.substr(0,i));
//                 vector<int> right = diffWaysToCompute(expression.substr(i+1));
//                 for(int l : left){
//                     for(int r : right){
//                         switch(x){
//                             case '+': ans.push_back(l+r);break;
//                             case '-': ans.push_back(l-r);break;
//                             case '*': ans.push_back(l*r);break;
//                         }
//                     }
//                 }
//             }
//         }
//         if (ans.empty()) ans.push_back(stoi(expression));
//         return ans;
//     }
// };