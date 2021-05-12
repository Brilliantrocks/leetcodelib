/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans = {};
        unordered_set<string> dic;
        for (auto x : wordList){
            dic.insert(x);
        }
        if(dic.find(endWord) == dic.end()) return ans;
        dic.erase(beginWord);
        dic.erase(endWord);
        // 双向搜索
        unordered_set<string> query1{beginWord},query2{endWord};
        // 记录顺序
        unordered_map<string,vector<string>> next;
        // 查询顺序标志位 查找完成标志位
        bool reserved=0,found=0;
        while(!query1.empty()){
            // 临时搜寻集 用于下一层搜索
            unordered_set<string> q;
            // 对于搜索集中的每个单词 搜索只相差一个字符的单词
            for (const auto &x : query1){
                string w = x;
                // 单词的每一位 
                for (size_t i = 0; i < w.size(); ++i){
                    char ch = w[i];
                    // 搜索所有可能的单字
                    for (int j = 0; j < 26; j++){
                        w[i] = j + 'a';
                        // 比对另一个搜索集 当存在则已找到最短转换序列 添加接龙顺序
                        if (query2.count(w)){
                            reserved ? next[w].push_back(x) : next[x].push_back(w);
                            found = true;
                        }
                        // 比对字典 存在则插入临时集q 添加接龙顺序
                        if (dic.count(w)){
                            reserved ? next[w].push_back(x) : next[x].push_back(w);
                            q.insert(w);
                        }
                    }
                    w[i] = ch;
                }
            }
            if (found) break;
            // 由于相邻单词只相差一个字符且求最短单词序列 
            // 删除临时集中已使用的单词
            for (const auto &x : q){
                dic.erase(x);
            }
            // 选择正反搜索集中较少的一个继续搜索
            // 临时集中单词数量小于另一个搜索集时替换本搜索集
            if (q.size() < query2.size()){
                query1 = q;
            }
            // 临时集单词数大于另一个搜索集时反转搜索方向
            // 替换为另一个搜寻集
            else {
                reserved = !reserved;
                query1 = query2;
                query2 = q;
            }
        }
        if (found){
            vector<string> path = {beginWord};
            backload(beginWord,endWord,next,path,ans);
        }
        return ans;
    }
    void backload(const string &src, const string &dst, unordered_map<string,vector<string>> &next, vector<string> &path, vector<vector<string>> &ans){
        if (src == dst){
            ans.push_back(path);
            return;
        }
        for (const auto &x: next[src]){
            path.push_back(x);
            backload(x,dst,next,path,ans);
            path.pop_back();
        }

    }
};
// @lc code=end

