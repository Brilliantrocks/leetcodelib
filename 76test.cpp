#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        bool flag[128] = {0};
        int nums[128] = {0};
        int n=s.size(),m=t.size(),count=0,p=0;
        int size = n + 1;
        // nums初始化为字符需要出现的次数
        for (char x:t){
            flag[x] = 1;
            ++nums[x];
        }
        for (int i = 0,j = 0; i < n; ++i){
            if (flag[s[i]]){
                if (nums[s[i]] > 0) ++count;
                --nums[s[i]];
            }
            while(count == m){
                if (flag[s[j]] && ++nums[s[j]] > 0) 
                    --count;
                if (i - j + 1 < size){
                    size = i -j + 1;
                    p = j;
                }
                ++j;
            }
        }
        return size > n ? "" : s.substr(p,size);
    }
};

main(){
    string s ="ADOBECODEBANC", b = "ABC" , c = "aa";
    Solution sl;
    auto ret = sl.minWindow(c,c);
        cout<<ret<<endl;
    
}