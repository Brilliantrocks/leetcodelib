#include <vector>
#include<iostream>
#include <string>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        char x;
        int n = expression.size();
        for (int i = 1; i<n;i+=2){
            x = expression[i];
            vector<int> left = diffWaysToCompute(expression.substr(0,i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));
            for(int l : left){
                for(int r : right){
                    switch(x){
                        case '+': ans.push_back(l+r);break;
                        case '-': ans.push_back(l-r);break;
                        case '*': ans.push_back(l*r);break;
                    }
                }
            }
        }
        if (ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};

main(){
    Solution s1;
    string s = "11";
    // auto ans = s1.diffWaysToCompute(s);
    // for(auto x :ans){
    // cout<<x<<endl; 
    // }
    cout<<stoi(s);
}