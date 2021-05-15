/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size()) return addStrings(num2,num1);
        string ans;
        auto itr1 = num1.rbegin();
        int addbit = 0;
        for(auto itr2 = num2.rbegin();itr2 != num2.rend();++itr2,++itr1){
            int sum = (*itr2-'0')+(*itr1-'0')+addbit;
            ans += to_string(sum%10);
            addbit = sum<10 ? 0 : 1;
        }
        for(;itr1!=num1.rend();++itr1){
            int sum = (*itr1-'0')+addbit;
            ans += to_string(sum%10);
            addbit = sum<10 ? 0 : 1;
        }
        if(addbit) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

