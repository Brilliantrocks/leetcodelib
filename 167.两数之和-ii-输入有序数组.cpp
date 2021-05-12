/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0,tail = numbers.size() -1;
        while (head < tail){
            int mid = (head + tail)/2;
            if (numbers[head] + numbers[mid] > target)
                tail = mid - 1;
            else if (numbers[mid] + numbers[tail] < target)
                head = mid + 1;
            else if (numbers[head] + numbers [tail] < target)
                ++head;
            else if (numbers[head] + numbers [tail] > target)
                --tail;
            else break;
        }
        return vector<int>{head+1,tail+1};
    }
};
// @lc code=end

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int head = 0,tail = numbers.size() -1;
//         while (head < tail){
//             int temp = numbers[head] + numbers[tail] - target ;
//             if (temp == 0) break;
//             else if (temp > 0) --tail; 
//             else ++head;
//         }
//         return vector<int>{head+1,tail+1};
//     }
// };