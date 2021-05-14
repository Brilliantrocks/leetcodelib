#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int h = 0,t = nums.size()-1,mid;
        if (!t) return nums[0] == target;
        while (h <= t){
            mid = h + (t - h)/2;
            if (nums[mid] == target) return true;
            // 相等时头指针右移
            if (nums[mid] == nums[h]) ++h;
            // [mid,t] 连续递增
            else if (nums[mid] <= nums[t]){
                // target 在[mid+1,t] 
                if (nums[mid] < target && target <= nums[t]) h = mid +1;
                // target 在[h,mid-1]
                else t = mid -1;
            }
            // [h,mid]连续递增
            else {
                // target 在[h,mid-1]
                if (nums[mid] > target && target >= nums[h])  t = mid - 1;
                else h = mid + 1;
            }
        }
        return false;
    }
};


main(){
    // vector<int> c = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    vector<int> c = {1,0,1,1,1};
    Solution sl;
    auto ret = sl.search(c,0);
        cout<<ret<<endl;
    
}