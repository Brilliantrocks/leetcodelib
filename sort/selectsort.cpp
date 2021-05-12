#include <vector>
using namespace std;

void select_sort(vector<int> &nums, int n){
    int mid;
    for (int i = 0; i < n -1; ++i){
        mid = i;
        for (int j = i + 1; j < n; ++j){
            if (nums[j] < nums[mid]){
                mid = j;
            }
        }
        swap(nums[mid],nums[i]);
    }
}

// 每次排序将右侧未排序数列中最小的数和当前数字交换位置

// [5,4,3,2,1]

// [1,4,3,2,5]

// [1,2,3,4,5]

// [1,2,3,5,4]

// [1,2,3,4,5]