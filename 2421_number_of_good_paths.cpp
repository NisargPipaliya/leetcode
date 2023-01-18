// HARD -> GOOGLE
// solved using greedy and disjoint set union / union find data structure
//684
// how greedy?
/*
start with smallest value then to largest
then we will map it, i.e. we will keep a track that which node have which value.
then we will run union find algo for connecting this nodes with same value
and then we will check for "good paths"
*/
#include<bits/stdc++.h>
using namespace std;
class Union{
    vector<int> parent;
    vector<int> rank;
public:
    Union(int vals=0)
    {
        parent.resize(vals);
        rank.resize(vals);
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
};

class Solution
{
    
public:
    int numberOfGoodPaths(vector<int> vals, vector<vector<int>> edges)
    {
        vector<list<int>> adj;
        for(int i=0;i<vals.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        map<int,vector<int>> m; // for values to index i.e. keeping track of values possesed by nodes
        for(int i=0;i<vals.size();i++) 
        {
            m[vals[i]].push_back(i);
        }
        int result = 0;
        Union uf(vals.size());
        for(int i=0;i<vals.size();i++)
        {
            uf.make_set(i);
        }
        
        map<int,int> count;

        for(auto i : m)// get the vector
        {
            for(auto j: i.second)
            {
                for(auto k : adj[j])
                {
                    if(vals[k]<=vals[j])
                        uf.union_set(k,j);
                }
            }

            for(auto j:i.second)
            {
                count[uf.find(j)]++;
                result+=count[uf.find(j)];
            }

        }
        return result;
    }
};