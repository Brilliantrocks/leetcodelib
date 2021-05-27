/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include<vector>
#include<string>
#include<set>
// #include<queue>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string,multiset<string>> hash;
        for(const auto &x:tickets) hash[x[0]].emplace(x[1]);
        stack<string> st;
        st.emplace("JFK");
        string next;
        while(!st.empty()){
            next=st.top();
            if(hash[next].empty()){
                ans.emplace_back(next);
                st.pop();
            }
            else{
                st.emplace(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end



// class Solution {
// public:
//     unordered_map<string,priority_queue<string,vector<string>,greater<string>>> hash;
//     vector<string> ans;
//     void dfs(const string &x){
//         while(hash.count(x)&&!hash[x].empty()){
//             string next =hash[x].top();
//             hash[x].pop();
//             dfs(move(next));
//         }
//         ans.emplace_back(x);
//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         for(const auto &x:tickets) hash[x[0]].emplace(x[1]);
//         dfs("JFK");
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };





// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         vector<string> ans;
//         unordered_map<string,priority_queue<string,vector<string>,greater<string>>> hash;
//         for(const auto &x:tickets) hash[x[0]].emplace(x[1]);
//         stack<string> st;
//         st.emplace("JFK");
//         string next;
//         while(!st.empty()){
//             next=st.top();
//             if(hash[next].empty()){
//                 ans.emplace_back(next);
//                 st.pop();
//             }
//             else{
//                 st.emplace(hash[next].top());
//                 hash[next].pop();
//             }
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };