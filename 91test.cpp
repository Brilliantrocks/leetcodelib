#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (!n) return 0;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;
        int pre = s[0] - '0',now,cnt,precnt=1,pprecnt=1;
        for (int i = 1; i < n; ++i){
            now = s[i] - '0';
            if (now == 0){
                if (pre == 0 || pre > 2) return 0;
                else cnt = pprecnt;
            }
            else if (pre == 0 || now + pre*10 > 26){
                cnt = precnt;
            }
            else {
                cnt = precnt + pprecnt;
            }
            pprecnt = precnt;
            precnt = cnt;
            pre = now;
        }
        return cnt;
    }
};

main(){
    // vector<int> c = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    string c = "2101";
    Solution sl;
    auto ret = sl.numDecodings(c);
    cout<<ret<<endl;
    
}