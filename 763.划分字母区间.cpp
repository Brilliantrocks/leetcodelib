/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

@lc code=start
// #include <vector>
// #include <string>
// #include <map>
// #include <algorithm>
// using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int fin[26] = {0};
        for (int i = 0; i < S.length(); ++i){
            fin[S[i]-'a'] = i;
        }
        int front = 0,back = 0;
        for (int i = 0; i < S.length(); ++i){
            back = max(back,fin[S[i]-'a']);
            if (i == back){
                ans.push_back(back - front +1);
                front = back + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

    // vector<int> partitionLabels(string S) {
    //     vector<int> ans;
    //     map<char,int> fin;
    //     for (int i = 0; i < S.length(); ++i){
    //         fin[S[i]] = i;
    //     }
    //     int front = 0,back = 0;
    //     for (int i = 0; i < S.length(); ++i){
    //         back = max(back,fin[S[i]]);
    //         if (i == back){
    //             ans.push_back(back - front +1);
    //             front = back + 1;
    //         }
    //     }
    //     return ans;
    // }