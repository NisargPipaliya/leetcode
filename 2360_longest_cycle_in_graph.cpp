#include<bits/stdc++.h>
using namespace std;


/*
2360. Longest Cycle in a Graph
Hard
1.2K
21
Companies
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
*/



// My solution -> But it doesn't work when graph is disconnected

class Solution {
    int help(vector<int> &in)
    {
        for(int i=0;i<in.size();i++)
        {
            if(in[i]==0)
            {
                in[i]=-1;
                return i;
            }
        }
        return -1;
    }
    void topo(vector<int> &edges,vector<int> &in)
    {
        int u=help(in),v;
        while(u!=-1)
        {
            v=edges[u];
            if(v>0)
                in[v]--;
            u=help(in);
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                in[edges[i]]++;
            }
        }
        topo(edges,in);
        int len=0;
        for(int i:in)
        {
            if(i>0)
            {
                len++;
            }
        }
        if(len==0)
            return -1;
        return len;
    }
};



//      Not my solution
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for (int edge : edges)
            if (edge != -1)
                indegree[edge]++;
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (!indegree[i])
                q.push(i);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            int next = edges[curr];
            if (next == -1) continue;
            edges[curr] = -1; // could use visit separate arr also. but this will work as well. think through. cutting node from graph are islolaed ones, which are not part of cycle.
            if (!--indegree[next])
                q.push(next);
        }

        int cycle = -1;
        for (int start = 0; start < n; ++start) {
            if(edges[start] != -1) {
                int count = 1;
                int next = edges[start], k;
                edges[start] = -1;
                while(next != start) {
                    count++;
                    k = edges[next];
                    edges[next] = -1;
                    next = k;
                }
                cycle = max(cycle, count);
            }
        }
        return cycle;
    }
};