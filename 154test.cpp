#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int h = 0,t = nums.size()-1;
        if (t == 0) return nums[0];
        int mid;
        while(h < t){
            if (nums[h] < nums[t]) return nums[h];
            mid = h + (t-h)/2;
            if (nums[mid] == nums[h]) ++h;
            // [mid,t] 递增
            else if (nums[mid] <= nums[t]){
                t = mid;
            }
            // [h,mid] 递增 min 在 [mid,t] 或者为h
            else {
                h  = mid + 1;
            }
        }
        return nums[h];
    }
};


main(){
    Solution s1;
    vector<int> a = {3,1};
    int ans = s1.findMin(a);
    cout<<ans<<endl; 
}