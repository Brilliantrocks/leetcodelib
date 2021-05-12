#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inp=prices[0],outp=prices[0],ans=0;
        enum state{none,hold};
        state st = none;
        vector<int>::iterator now = prices.begin();
        vector<int>::iterator back = prices.end() -1;
        for (now;now != back; ++now){
            int temp = *now;
            switch (st){
                case none:{
                    if (temp> inp){
                        outp = temp;
                        st = hold;
                    }
                    else inp = temp;
                    continue;
                }
                case hold:{
                    if (temp < outp){
                        ans += outp - inp;
                        inp = temp;
                        st = none;
                    }
                    else outp = temp;
                    continue;
                }
            }
        }
        if (st == none && *back > inp){
            ans += *back - inp;
        }
        else if (st == hold){
            outp = max(outp,*back);
            ans += outp - inp;
        }
        return ans;
    }
};

main(){
    Solution s1;
    vector<int> a = {1,2};
    int ans = s1.maxProfit(a);
    cout<<ans<<endl; 
}