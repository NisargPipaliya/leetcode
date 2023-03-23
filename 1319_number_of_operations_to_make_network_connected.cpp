#include<bits/stdc++.h>
using namespace std;

/*
1319. Number of Operations to Make Network Connected
Medium
3.3K
43
Companies
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.



DISJOINT SET DATAStrUCTURE :)
*/


//          My solution
class Union
{
    vector<int> parent;
    vector<int> rank;
public:
    Union(int n=0)
    {
        parent.resize(n,0);
        rank.resize(n,0);
    }
    void make_set(int x)
    {
        parent[x]=x;
    }

    int find(int x)
    {
        if(x!=parent[x])
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void union_set(int x,int y)
    {
        int rootx=find(x);
        int rooty=find(y);

        if(rootx==rooty)
            return;

        if( rank[rootx] > rank[rooty] )
            parent[rooty]=rootx;

        else
        {
            parent[rootx]=rooty;
            if( rank[rootx] == rank[rooty] )
                rank[rooty]++;
        }
    }

    int compc(int n)
    {
        int count=0;
        for(int i=0;i<n;++i)
        {
            cout<<i<<"  ";
            if(parent[i]==i)
            {
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Union obj(n);
        int size=connections.size(),extra_edges=0,ans=0;
        for(int i=0;i<n;++i)
        {
            obj.make_set(i);
        }
        for(int i=0;i<size;++i)
        {
            int x=connections[i][0],y=connections[i][1];
            if(obj.find(x) != obj.find(y))
            {
                obj.union_set(x,y);
            }
            else
                ++extra_edges;
        }
        ans=obj.compc(n);
        cout<<endl<<ans<<endl;
        ans=ans-1;
        if(extra_edges<ans && ans>0)
            ans=-1;
        return ans;
    }
};



// Optimized solution
int uf[100000], cnt;
int find(int i) {
    if (uf[i] != i) uf[i] = find(uf[i]);
    return uf[i];
}
void join(int a, int b) {
    int findA = find(a), findB = find(b);
    if (findA == findB) return;
    uf[findA] = findB;
    cnt--;
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        cnt = n;
        for (int i = 0; i < n; i++) uf[i] = i;
        for (vector<int>& c : connections) join(c[0], c[1]);
        return cnt - 1;
    }
};