/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),
        dictionary.end(),
        [](string &a,string& b){
            return a.size()>b.size() || (a.size() == b.size() && a < b);
            }
        );
        int n = dictionary.size(),len = s.size(),p1, p2,m=0;
        string temp;
        for (int i = 0; i < n; ++i){
            temp = dictionary[i];
            m = temp.size();
            for (p1 = 0,p2 = 0;p1 < len;){
                if (s[p1] == temp[p2]) {
                    ++p1;
                    ++p2;
                }
                else ++p1;
                if (p2 == m) return temp;
            }
        }            
        return "";
    }
};
// @lc code=end
// 测试例中不排序更快
// class Solution {
// public:
//     string findLongestWord(string s, vector<string>& dictionary) {
//         int n = dictionary.size(),len = s.size(),maxlen = 0,p1 =0, p2=0,m=0;
//         string ans = "";
//         for (int i = 0; i < n; ++i){
//             string temp = dictionary[i];
//             m = temp.size();
//             if (maxlen > m) continue;
//             p1=0,p2=0;
//             for (int j = len; j >= maxlen;){
//                 if (p2 == m) {
//                     if (m == maxlen && temp > ans) break;
//                     maxlen = m;
//                     ans = temp;
//                     break;
//                 }
//                 if (p1 == len) break;
//                 if (s[p1] == temp[p2]) {
//                     ++p1;
//                     ++p2;
//                 }
//                 else {
//                     ++p1;
//                     --j;
//                 }
//             }
//         }            
//         return ans;
//     }
// };
