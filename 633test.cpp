#include<iostream>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0;
        while(a*a < c){
            ++a;
        }
        if (a*a == c) return true;
        --a;
        for (int b = 0; a > b; --a){
            b = 1;
            int target = c - a*a;
            while (b*b < target) ++b;
            if (b*b == target) return true;
        }
        return false;
    }
};
main(){
    Solution sl;
    bool ret = sl.judgeSquareSum(2147482647);
    if (ret) cout<<"ok"<<endl;
    else cout<<"nop"<<endl;
}