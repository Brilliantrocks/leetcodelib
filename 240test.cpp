#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=n? matrix[0].size() : 0;
        for(int i=n-1,j=0;i>=0&&j<m;){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) --i;
            else ++j;
        }
        return false;
    }
};
main(){
    Solution s1;
    vector<vector<int>> s={{-1,3}};
    // auto ans = s1.diffWaysToCompute(s);
    // for(auto x :ans){
    // cout<<x<<endl; 
    // }
    cout<<s1.searchMatrix(s,3);
}