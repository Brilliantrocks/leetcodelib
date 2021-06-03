#include<vector>
#include<queue>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> graph(n);
        for(const auto &x : edges){
            graph[x[0]].emplace_back(pair<int,int>{x[1],x[2]+1});
            graph[x[1]].emplace_back(pair<int,int>{x[0],x[2]+1});
        }
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.emplace(0,0);
        while(!q.empty()){
            auto [curdis,index] = q.top();
            q.pop();
            if(curdis!=dis[index]) continue;
            for(const auto &x : graph[index]){
                int endv = x.first;
                int tempdis=x.second;
                if(dis[endv]>dis[index]+tempdis){
                    dis[endv]=dis[index]+tempdis;
                    q.emplace(dis[endv],endv);
                }
            }
        }
        int ans=0;
        vector<bool> vis(n,0);
        vis[0]=1;
        for(const auto &x :edges){
            int v1=x[0],v2=x[1],disv=x[2];
            if(dis[v1]<=maxMoves) vis[v1]=true;
            if(dis[v2]<=maxMoves) vis[v2]=true;
            ans +=min(max(maxMoves-dis[v1],0)+max(maxMoves-dis[v2],0),disv);
        }
        ans +=accumulate(vis.begin(),vis.end(),0);
        return ans;
    }
};

main(){
    vector<vector<int>> s ={{0,1,10},{0,2,1},{1,2,2}};
    Solution sl;
    auto ret = sl.reachableNodes(s,6,3);
    cout<<ret<<endl;
}