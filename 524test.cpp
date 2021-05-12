#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size(),len = s.size(),maxlen = 0,p1 =0, p2=0,m=0;
        string temp, ans = "";
        for (int i = 0; i < n; ++i){
            temp = dictionary[i];
            m = temp.size();
            p1=0,p2=0;
            if (maxlen > m) continue;
            for (int j = len; j >= maxlen;){
                if (p2 == m) {
                    if (m == maxlen && temp > ans) break;
                    maxlen = m;
                    ans = temp;
                    break;
                }
                if (p1 == len) break;
                if (s[p1] == temp[p2]) {
                    ++p1;
                    ++p2;
                }
                else {
                    ++p1;
                    --j;
                }
            }
        }            
        return ans;
    }
};

main(){
    vector<string> fb = {"aaa","aa","a"};
    string x = "aaa";
    Solution sl;
    auto ret = sl.findLongestWord(x,fb);
    cout<<ret<<endl<<"test";
}