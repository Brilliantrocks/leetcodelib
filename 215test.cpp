#include <vector>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int h = 0,t = nums.size()-1;
//         int first = 0,last = t,key,p;
//         do{
//             p = first;
//             key = nums[first];            
//             while(first < last){
//                 while (first < last && nums[last] < key) --last;
//                 nums[first] = nums[last];
//                 while (first < last && nums[first] > key) ++first;
//                 nums[last] = nums[first];
//             }
//             nums[first] = key;
//             if (first - p + 1< k) last = t, ++first, k -= first;
//             else if (first - p + 1 > k) first = 0,--last;
//         }while(first + 1 - p != k);
//         return nums[first];
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int h = 0,t = nums.size()-1;
//         int first = 0,last = t,key;
//         while(1){
//             key = nums[first];            
//             while(first < last){
//                 while (first < last && nums[last] <= key) --last;
//                 nums[first] = nums[last];
//                 while (first < last && nums[first] >= key) ++first;
//                 nums[last] = nums[first];
//             }
//             nums[first] = key;
//             if (first + 1< k) last = t, ++first;
//             else if (first + 1 > k) first = 0,--last;
//             else break;
//         }
//         return nums[first];
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int h = 0,t = nums.size()-1;
        int first = 0,last = t,key;
        while(1){
            int head = first + 1;
            int tail = last;
            key = nums[first];            
            while(1){
                while (head < last && nums[head] >= key) ++head;
                while (first < tail && nums[tail] <= key) --tail;
                if (head >= tail) break;
                swap(nums[head],nums[tail]);
            }
            swap(nums[first],nums[tail]);
            if (tail + 1 < k) first = tail, ++first;
            else if (tail + 1 > k) last = tail,--last;
            else return nums[k-1];
        }
    }
};

main(){
    Solution s1;
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    int ans = s1.findKthLargest(a,4);
    cout<<ans<<endl; 
}