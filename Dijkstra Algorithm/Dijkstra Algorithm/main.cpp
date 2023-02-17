//
//  main.cpp
//  Dijkstra Algorithm
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

void adjlistwt(int E, vector<vector<int> > adj[])
{
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
}
vector<int> dijkstra(int V, vector<vector<int>>adj[], int S)
{
    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgewt = it[1];
            int edgenode = it[0];
            if (dis + edgewt < dist[edgenode])
            {
                dist[edgenode] = edgewt+dis;
                pq.push({dist[edgenode], edgenode});
            }
        }
    }
    return dist
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
        vector<vector<int> > adj[V];
        adjlistwt(E, adj);
        vector<int> dijk;
        int S;
        cin >> S;
        dijk = dijkstra(V, adj, S);
        cout << "Shortest distence from their respctively nodes  : " << endl;
        display(dijk);

    
    return 0;
}
