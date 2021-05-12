#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),cnt = 0;
        vector<int> head(n);
        for (int i = 0; i < n; ++i){
            head[i] = i;
        }
        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                if (isConnected[i][j]){
                    mergecity(head,i,j);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if (head[i] == i) ++cnt;
        }
        return cnt;
    }

    int find_head(vector<int> &head, int i){
        if (head[i] != i){
            head[i] = find_head(head,head[i]);
        }
        return head[i];
    }

    void mergecity(vector<int> &head, int i, int j){
        head[find_head(head,i)] = find_head(head,j);
    }
};

main(){
    vector<vector<int>> fb = {{1,0,0},{0,1,0},{0,0,1}};
    Solution sl;
    int ret = sl.findCircleNum(fb);
    cout<<ret<<endl;

}