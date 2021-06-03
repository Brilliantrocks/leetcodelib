/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <vector>
#include<numeric>
using namespace std;

class dsu
{
private:
    vector<int> f,size;
public:
    dsu(int n):f(n),size(n,1){
        iota(f.begin(),f.end(),0);
    };

    int find(int x){
        while (x!=f[x]){
            f[x]=f[f[x]];
            x=f[x];
        }
        return x;
    }

    void connect(int x, int y){
        int xr=find(x),yr=find(y);
        if(xr!=yr){
            if(size[xr]<size[yr]){
                f[xr]=yr;
                size[yr] +=size[xr];
            }
            else {
                f[yr]=xr;
                size[xr] +=size[yr];
            }
        }
    }

    bool isconnect(int x,int y){
        return find(x)==find(y);
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu dsus(n+1);
        for(const auto &x:edges){
            int v1=x[0],v2=x[1];
            if(dsus.isconnect(v1,v2)) return x;
            dsus.connect(v1,v2);
        }
        return vector<int>{-1,-1};
    }
};
// @lc code=end

