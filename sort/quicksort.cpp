#include <vector>
using namespace std;

void quick_sort(vector<int> &nums, int l, int r){
    if (l + 1 >= r) return;
    int first = 1,last = r - 1, key = nums[first];
    while (first < last){
        while (first < last && nums[last] >= key) --last;
        nums[first] = nums[last];
        while (first < last && nums[first] <= nums[last]) ++first;
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums,l,first);
    quick_sort(nums,first,r);
}

// 对当前数字 将所有比它小的放在前面 大的放在后面 递归排序