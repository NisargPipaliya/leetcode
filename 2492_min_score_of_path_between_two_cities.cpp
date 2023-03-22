#include<bits/stdc++.h>
using namespace std;


/*
2492. Minimum Score of a Path Between Two Cities
Medium
500
87
Companies
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.

Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.


*/



//My solution -> Brute Force

class Solution {
    void dfs(vector<list<pair<int,int>>> &adj,int &n,int &mini,int start,vector<bool> &vis)
    {
        vis[start]=true;
        for(auto i : adj[start])
        {
            mini=min(mini,i.second);
            if(vis[i.first]==false)
            {
                dfs(adj,n,mini,i.first,vis);
            }
        }
        cout<<mini<<endl;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector< list <pair<int,int> > > adj(n+1);

        for(int i=0;i<roads.size();++i)
        {
            adj[roads[i][0]].push_back(make_pair(roads[i][1],roads[i][2]));
            adj[roads[i][1]].push_back(make_pair(roads[i][0],roads[i][2]));
        }
        int mini=INT_MAX;
        vector<bool> vis(n+1,false);
        dfs(adj,n,mini,1,vis);
        return mini;
    }
};



/*

Approach : Union-find


Intuition
Another approach to solving questions based on graph connectivity is the union-find data structure. It can optimally determine which connected component a node or an edge belongs to. We can use the union-find data structure to solve the problem because our task is to find the minimum weight edge in our component containing node 1.

A disjoint-set data structure also called a union–find data structure or merge–find set, is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their union), and finding a representative member of a set. It implements two useful operations:

Find: Determine which subset a particular element is in. This can be used to determine if two elements are in the same subset.
Union: Join two subsets into a single subset.
If you are new to Union-Find, we suggest you read our Leetcode Explore Card. We will not talk about implementation details in this article, but only about the interface to the data structure.

We iterate through all of the edges, taking the union of the two nodes connected by the edge. This generates a graph by inserting all nodes into the components to which they belong.

As we know, our task is to find the minimum weight edge in the component containing nodes 1 and n. We iterate over all the edges again and for each edge that connects two nodes, say a and b, we check whether node a (or b) belongs to the same component as node 1 (or n). We don't need to check for node b separately because a and b are connected by an edge and thus both belong to the same component. The find operation can be used to inspect a node's component.

If node a belongs to the same component as node 1, we update our answer to the minimum of the answer till now and the weight of the edge connecting a andb. Otherwise, if node a does not belong to the same component as node 1, it is ignored.

Algorithm
Create an instance of UnionFind of size n + 1. In addition, create the answer variable set to the maximum integer value.
Iterate over all of the graph's edges, or roads, and perform a union of both nodes connected by an edge.
Iterate over all the edges again and for each road:
Determine whether a component of node 1 is the same as one of the ends of road. If both nodes belong to the same component, update answer to the minimum of answer up to this point and the weight of road. Otherwise, ignore edge road.
Return answer.
Implementation

Complexity Analysis
Here nnn is the number of nodes and eee is the total number edges.

Time complexity: O(n+e)O(n + e)O(n+e).

*/


class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind dsu(n + 1);
        int answer = numeric_limits<int>::max();

        for (auto& road : roads) {
            dsu.union_set(road[0], road[1]);
        }

        for (auto& road : roads) {
            if (dsu.find(1) == dsu.find(road[0])) {
                answer = min(answer, road[2]);
            }
        }

        return answer;
    }
};