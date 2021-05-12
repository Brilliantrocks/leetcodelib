#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int h = 0,t = s.size()-1,count = 2,sh,st;
        if (t < 2) return true;
        while(h < t){
            if (s[h] != s[t]) {
                if (!count)  return false;
                if (count ==2){    
                    if (s[h+1] != s[t] && s[h] != s[t-1]) return false;
                    sh = h;
                    st = t-1;
                    ++h;
                }
                else {
                    h = sh;
                    t = st;
                }
                --count;
            }
            ++h;
            --t;
        }
        return true;
    }
};
main(){
    Solution s;
    string st = "cdbeeeabddddbaeedebdc";//"acxcybycxcxa";//"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    // string s1 = st.substr(19,5),s2 = st.substr(76,5);
    // cout<<s1<<endl<<s2<<endl;
    bool ans = s.validPalindrome(st);
    if (ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}

//cupuu uupucu   
// abc-cbab
// abc-cbab