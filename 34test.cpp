#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int h = 0,n = nums.size();
        if (n == 1 && nums[0] == target) return {0,0};
        vector<int> ans = {-1,-1};
        // if (n == 2) {
        //     bool a = nums[0]==target,b = nums[1]==target;
        //     if (a && !b) ans={0,0};
        //     else if (b && !a) ans={1,1};
        //     else if (a && b) ans = {0,1};
        //     return ans;
        // }  
        int t = n - 1,mid;
        // 搜索第一个为target的值
        // 不存在target时终止条件为搜索区间小于0 全搜索
        // 未找到时不触发第二个else
        while (t - h >= 0){
            mid = h + (t - h)/2;
            if (nums[mid] < target) h = mid+1;
            else if (nums[mid] > target) t = mid-1;
            else {
                // 搜索到第一个为target的值 就地分别进行双向搜索第一个不为target的值
                // 对于此时的h t,
                int x = h,y = mid,z;
                // 终止条件为搜索区间等于0 x=y 而nums[y]总是为target
                // 对于nums[h]=target 则一直走else if 直到y = z = x = h
                while(x < y){
                    z = x + (y - x)/2;
                    if (nums[z] < target) x = z+1;
                    else if (nums[z] == target) y = z;
                }
                ans[0] = y;
                x = mid, y = t;
                // 终止条件为搜索区间等于0 x=y 而nums[x]总是为target 
                // 对于nums[t]=target 一直走if 直到 x = z = y = t
                while(x < y){
                    z = x + (y - x + 1)/2;
                    if (nums[z] == target) x = z;
                    else if (nums[z] > target) y = z-1;
                }
                ans[1] = x;
                break;
            }
        }
        return ans;
    }
};


main(){
    Solution sl;
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,8);
    // vector<int> fb = {5,7,7,8,8,10};
    // auto ret = sl.searchRange(fb,6);
    // vector<int> fb = {0,1};
    // auto ret = sl.searchRange(fb,1);
    vector<int> fb = {2,2};
    auto ret = sl.searchRange(fb,2);
    cout<<ret[0]<<endl;
    cout<<ret[1]<<endl;
}