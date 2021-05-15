#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m=p.size();
        vector<bool> dp(n+1,0);
        dp[0] = true;
        char x,pre,cur=p[0];
        int j = 0;
        for (int i =1; i<=n && j < m;++i){
            x = s[i-1];
            if(cur == '.' || x==cur) {
                dp[i]= dp[i-1];
                pre = cur;
                if(++j < m) cur = p[j];
            }
            else if (cur == '*'){
                if (pre == '.' || x==pre){
                    dp[i] = dp[i-1];
                }
                else{
                    pre = cur;
                    if(++j < m) cur = p[j];
                    --i;
                }
            }
            else if (j+2<m && p[j+1]=='*'){
                j += 2;
                cur = p[j];
                pre = p[j-1];
                --i;
            }
            else break;
        }
        return dp[n];
    }
};


main(){
    Solution sl;
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,8);
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,6);
    // vector<int> fb = {0,1};
    // auto ret = sl.searchRange(fb,1);
    string in1 ="aab",in2="c*a*b";
    auto ret = sl.isMatch(in1,in2);
    cout<<ret<<endl;

}