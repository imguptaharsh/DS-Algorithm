//
//  main.cpp
//  prims algorithem
//
//  Created by Harsh Gupta on 01/12/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mspan(int V,vector<vector<int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(V,0);
    int sum=0;
    pq.push({0,0});
    while (!pq.empty()) {
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node]==1)
            continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int adjwt=it[1];
            if(!vis[adjnode]){
                pq.push({adjwt,adjnode});
            }
        }
    }
    return sum;
}
vector<pair<int,int>> primspant(int V,vector<vector<int>>adj[]){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<pair<int,int>>ans;
    vector<int>vis(V,0);
    int sum=0;
    pq.push({0,{0,-1}});
    while (!pq.empty()) {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        pq.pop();
        if(vis[node]==1)
            continue;
        if(parent!=-1)
        ans.push_back({parent,node});
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int adjwt=it[1];
            if(!vis[adjnode]){
                pq.push({adjwt,{adjnode,node}});
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    int E,V;
    cin>>V>>E;
    vector<vector<int>>adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>temp1,temp2;
        temp1.push_back(u);
        temp1.push_back(w);
        adj[v].push_back(temp1);
        temp2.push_back(v);
        temp2.push_back(w);
        adj[u].push_back(temp2);
    }
    vector<pair<int,int>>mst;
     mst=primspant(V,adj);
    for(int i=0;i<mst.size();i++){
        int u,v;
     
        u=mst[i].first;
        v=mst[i].second;
        cout<<"("<<u<<", "<<v<<"), ";
    }
    cout<<endl;
    int sum=mspan(V,adj);
    cout<<"The sum of weight of edges of minimum spaning tree : "<<sum<<endl;
    return 0;
}
