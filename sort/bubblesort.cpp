#include <vector>
using namespace std;

void bubble_sort(vector<int> &nums, int n){
    bool swapped;
    for(int i = 1; i < n; ++i){
        swapped = false;
        for(int j = 1; j < n - i + 1; ++j){
            if (nums[j] < nums[j-1]){
                swap(nums[j],nums[j-1]);
                swapped = true; 
            }
        }
        if (!swapped) break;
    }
}
// 每次排序将最大的数放在队尾
// 下次排序前面的数列
// [5,4,3,2,1] n =5
// [4,5,3,2,1]
// [4,3,5,2,1]
// [4,3,2,5,1]
// [4,3,2,1,5]

// [3,4,2,1,5]
// [3,2,4,1,5]
// [3,2,1,4,5]

// [2,3,1,4,5]
// [2,1,3,4,5]

// [1,2,3,4,5]