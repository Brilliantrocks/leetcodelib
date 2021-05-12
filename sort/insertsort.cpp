#include <vector>
using namespace std;

void insert_sort(vector<int> &nums, int n){
    for(int i = 0; i < n; ++i){
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j){
            swap(nums[j],nums[j-1]);
        }
    }
}

// 将已经序列化的数列放在左边
// 每次排序将下一个字符插入序列化数列相应的位置
// [5,4,3,2,1]
// [4,5,3,2,1]
// [4,3,5,2,1]
// [3,4,5,2,1]
// [3,4,2,5,1]
// [3,2,4,5,1]
// [2,3,4,5,1]
