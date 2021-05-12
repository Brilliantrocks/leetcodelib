#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        map<char,vector<int> > char_range;
        for (int i = 0; i < S.size(); ++i){
            if (char_range.find(S[i]) == char_range.end()){
                char_range[S[i]] = {i,i};
            }
            else {
                char_range[S[i]][1] = i;
            }
        }
        vector<vector<int> > char_range_arry;
        for (pair<char,vector<int> > x :char_range)
            char_range_arry.push_back(x.second);
        sort(char_range_arry.begin(),char_range_arry.end(),[](vector<int>& a,vector<int>& b){return a[0]<b[0];});
        int back = char_range_arry[0][1];
        int front = 0;
        int size = char_range_arry.size();
        for (int i = 1; i < size; ++i){
            int tempf = char_range_arry[i][0];
            int tempb = char_range_arry[i][1];
            if (tempf > back){
                ans.push_back(back - front +1);
                front = back +1;
                back = tempb;
            }
            if (tempb > back){
                back = tempb;
            }            
        }
        ans.push_back(back - front +1);
        return ans;
    }
};

main(){
    string s ="ababcbacadefegdehijhklij";
    Solution sl;
    auto ret = sl.partitionLabels(s);
    for (int x:ret){
        cout<<x<<endl;
    }
}

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

