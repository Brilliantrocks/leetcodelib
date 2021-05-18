#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),ans=0;
        vector<int> mask(n,0);
        vector<int> size(n,0);
        for (int i = 0; i < n; ++i)
        {
            size[i] = words[i].size();
            for(auto x:words[i]){
                mask[i] |= 1 << (x - 'a');
            }
            cout<<"mask["<<i<<"] "<<mask[i]<<endl;
            for(int j =0;j<i;++j){
                int m =mask[j]&mask[i];
                cout<<m<<endl;
                if(m==0){
                    ans=max(ans,size[i]*size[j]);
                }
            }
        }
        return ans;
    }
};

main(){
    Solution s1;
    vector<string> s = {"abcw","baz","foo","bar","xtfn","abcdef"};
    int ans = s1.maxProduct(s);
    cout<<ans<<endl; 
    // int a = 0,b='w'-'a';
    // a= 1 << b;
    // cout<<b<<endl;
    // cout<<a<<endl;
}

