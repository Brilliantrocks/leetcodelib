#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;
        int count = 0, limit = nums[0],i = 1;
        int rcount = 0, limit2 = nums[n-1];
        for (; i < n; ++i){
            if (count < 2){
                if (nums[i] < limit) ++count;
                else limit = nums[i];
            }
            if (rcount < 2){
                if (nums[n - i -1] > limit2) ++rcount;
                else limit2 = nums[n - i -1];
            }
            if (count + rcount > 3) return false;
        }
        return true;
    }
};

main(){
    Solution s;
    vector<int> input = {3,4,2,3};
    // 正向遍历
    // 对于犯规的情形 nums[x] > nums[x+1]
    // 局部最优补救措施为 nums[x] = nums[x-1] 
    // 或者 当nums[x+1] < nums[x-1]时
    // 次优 nums[x+1] = nums[x]
    // vector<int> input = {0,4,2,3} ture {3,4,2,3} false;
    bool ans = s.checkPossibility(input);
    if (ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return true;
//         if (n == 2) return nums[0] <= nums[1];
//         int count = 0, limit = nums[0],i = 1;
//         for (; i < n; ++i){
//             if (nums[i] < limit) ++count;
//             else limit = nums[i];
//             if (count > 1) {
//                 int rcount = 0, limit2 = nums[n-1];
//                 for (n = n-2; n > -1; --n){
//                     if (nums[n] > limit2) ++rcount;
//                     else limit2 = nums[n];
//                     if (rcount > 1) return false;
//                 }
//             }
//         }
//         return true;
//     }
// };