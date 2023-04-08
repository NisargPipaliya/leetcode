#include<bits/stdc++.h>
using namespace std;

/*
133. Clone Graph
Medium
7.8K
3.2K
Companies
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

// beats 100% in time
*/



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    void dfs(Node* start,Node* &ans, Node* parent,unordered_map<Node*,Node*> &hs)
    {
        for(auto i : start->neighbors)
        {
            if(hs.find(i)==hs.end())
            {
                hs[i]=new Node(i->val);
                ans->neighbors.emplace_back(hs[i]);
                cout<<hs[i]->val<<endl;
                dfs(i,hs[i],start,hs);
            }else
                ans->neighbors.emplace_back(hs[i]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        unordered_map<Node*,Node*> hs;
        Node* ans = new Node(1);
        hs[node]=ans;
        dfs(node,ans,NULL,hs);
        hs.clear();
        return ans;
    }
};