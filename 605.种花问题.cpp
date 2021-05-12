/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
// #include <vector>
// using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int size = flowerbed.size();
        int planted = n;
        int zerocount = 1;
        for (int i = 0; planted != 0 && i < size; ++i) {
            if (flowerbed[i] == 0) ++zerocount;
            else zerocount = 0;
            if (zerocount == 3){
                --planted;
                zerocount = 1;
            }
        }
        if (planted != 0 && zerocount == 2){
            --planted;
        }
        return (planted == 0);
    }
};
// @lc code=end

