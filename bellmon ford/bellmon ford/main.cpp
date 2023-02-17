//
//  main.cpp
//  bellmon ford
//
//  Created by Harsh Gupta on 02/12/22.
//
#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#define HEAD_HPP

using namespace std;

// void adjlistwt(int E, vector<vector<int> > adj[])
// {
//     for (int i = 0; i < E; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         vector<int> t1, t2;
//         t1.push_back(v);
//         t1.push_back(w);
//         adj[u].push_back(t1);
//         t2.push_back(u);
//         t2.push_back(w);
//         adj[v].push_back(t2);
//     }
// }
void buildedges(int E, vector<vector<int>>&edge){
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);
        edge.push_back(temp);
    }
}
vector<int> bellman(int V,vector<vector<int>>& edges, int S){
    vector<int>dist(V,1e8);
    dist[S]=0;
    for(int i=0;i<V-1;i++){
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=1e8 and dist[u]+w< dist[v])
                dist[v]=dist[u]+w;
        }
    }
    for(auto it: edges)
    {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=1e8 and dist[u]+w< dist[v])
            return {-1};
    }
    return dist;
}

void display(vector<int> &vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int E, V;
        cout << "Enter number of edages: ";
        cin >> E;
        cout << "Enter number of nodes: ";
        cin >> V;
        vector<vector<int> > edges;
        // adjlistwt(E, adj);
        buildedges(E,edges);
        vector<int> bell;
        int S;
        cin >> S;
        bell = bellman(V, edges, S);
        cout << "Shortest distence from their respctively nodes  : " << endl;
        display(bell);

    return 0;
}

//Enter number of edages: 4
//Enter number of nodes: 3
//1 0 3
//0 1 5
//2 0 1
//1 2 -1
//2
