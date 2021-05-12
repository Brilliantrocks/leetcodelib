#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int size = flowerbed.size();
        if (size == 1) {
            if (flowerbed.front() == 1) return false;
            if (flowerbed.front() == 0) return true;
        }
        if (size < (2*n -1))
            return false;
        int planted = n;
        int zerocount = 1;
        for (auto cur = flowerbed.begin(); planted != 0 && cur != flowerbed.end(); ++cur) {
            if (*cur == 0) ++zerocount;
            else zerocount = 0;
            if (zerocount == 3){
                --planted;
                zerocount = 1;
            }
        }
        if (planted != 0 && zerocount == 2){
            auto cur2 = flowerbed.rbegin();
            if (*cur2 == 0){
                if(*++cur2 == 0){
                    --planted;
                }
            }
        }
        if (planted == 0) return true;
        else return false;
    }
};

main(){
    vector<int> fb = {1,0,0,0,1};
    Solution sl;
    bool ret = sl.canPlaceFlowers(fb,1);
    if (ret) cout<<"ok"<<endl;
    else cout<<"nop"<<endl;
    ret = sl.canPlaceFlowers(fb,2);
    if (ret) cout<<"ok"<<endl;
    else cout<<"nop"<<endl;
}