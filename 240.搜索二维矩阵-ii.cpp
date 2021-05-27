/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include<vector>
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
// @lc code=end

