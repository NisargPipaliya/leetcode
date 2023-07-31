#include<bits/stdc++.h>
using namespace std;

/*
785. Is Graph Bipartite?
Medium
7.5K
334
Companies
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
*/

class Solution {
    bool bfs(int start,vector<vector<int>> &graph,vector<int> &color)
    {
        color[start] = 0;
        queue<pair<int,int>> q;
        q.push({start,0});
        while(!q.empty())
        {
            int vertex = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i : graph[vertex]){
                if(color[i] == -1)
                {
                    color[i] = col^1;
                    q.push({i,color[i]});
                }else if(color[i] == col)
                    return false;
            }
        }
        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                bool var = bfs(i,graph,color);
                if(!var)
                    return false;
            }
        }
        return true;
    }
};