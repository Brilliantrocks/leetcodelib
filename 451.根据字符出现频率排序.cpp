/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <vector>
// #include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int count[128] = {0};
        int maxc=0;

        for (const char &x:s){
            maxc = max(++count[x],maxc);
        }

        vector<vector<char>> bucket(maxc + 1,vector<char>());

        for (int i = 0; i < 128; ++i){
            if (count[i]) bucket[count[i]].push_back((char)i);
        }

        string ans;

        for(int i = maxc; i >= 0; --i){
            if (!bucket[i].empty()) {
                for(const auto & x : bucket[i]){
                    ans.insert(ans.end(),i,x);
                }
            }
        }

        return ans;        
    }
};
// @lc code=end

// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> count;
//         int n = s.size() - 1;
//         int maxc=0;

//         for (const char &x:s){
//             maxc = max(++count[x],maxc);
//         }

//         vector<vector<int>> bucket(maxc + 1);

//         for (const auto & x : count){
//             bucket[x.second].push_back(x.first);
//         }

//         string ans;

//         for(int i = maxc; i >= 0; --i){
//             for(const auto & x : bucket[i]){
//                 ans.insert(ans.end(),i,x);
//             }
//         }

//         return ans;        
//     }
// };