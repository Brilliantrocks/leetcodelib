#include <vector>
using namespace std;

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp){
    if (l + 1 >= r) return;
    int m = l + (r - l)/2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    int p = l, q = m, i =l;
    while (p < m || q < r){
        if (q >= r || (p < m && nums[p] <= nums[q])){
            temp[i++] = nums[p++];
        }else {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i){
        nums[i] = temp[i];
    }
}
// 递归二分排序 左侧和右侧都是序列化数列
// [4,3,2,1]
// [3,4,1,2]
// [1,2,3,4]