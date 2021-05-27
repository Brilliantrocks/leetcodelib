/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
// #include<vector>
// using namespace std;


class NumMatrix {
    vector<vector<int>> all_sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        all_sums.resize(m+1, vector<int>(n+1));
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0) all_sums[i][j] = 0;
                else all_sums[i][j] = matrix[i-1][j-1] + all_sums[i-1][j] + all_sums[i][j-1] - all_sums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return (all_sums[row2+1][col2+1] - all_sums[row2+1][col1] - all_sums[row1][col2+1] + all_sums[row1][col1]);
    }
};



/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

// class NumMatrix {
// public:
//     vector<vector<int>> sums;

//     NumMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         if (m > 0) {
//             int n = matrix[0].size();
//             sums.resize(m + 1, vector<int>(n + 1));
//             for (int i = 0; i < m; i++) {
//                 for (int j = 0; j < n; j++) {
//                     sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
//                 }
//             }
//         }
//     }

//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
//     }
// };



// class NumMatrix {
// public:
//     vector<vector<int>> m_sum;
//     NumMatrix(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         if(!m) return;
//         int n =matrix[0].size();
//         m_sum.resize(m+1,vector<int>(n+1));
//         for(int i=1;i<=m;++i){
//             for(int j=1;j<=n;++j){
//                 m_sum[i][j]=m_sum[i][j-1]+m_sum[i-1][j]+matrix[i-1][j-1]-m_sum[i-1][j-1];
//             }
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return m_sum[row2+1][col2+1]-m_sum[row1][col2+1]-m_sum[row2+1][col1]+m_sum[row1][col1];
//     }
// };
