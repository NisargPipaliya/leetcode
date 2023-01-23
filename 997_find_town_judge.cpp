#include<bits/stdc++.h>
using namespace std;

/*
here we need to find the town judge. 
a judge is a person who does not trust anyone but "EVERYONE TRUST HIM"
so we are given array on n.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

so two conditions to check i.e. judge trust no one and n-1 peoples trust judge ( as we need to exclude judge himself from count)

so considere it as undirected graph.
so my approach is to do DFS from each vertex and if dfs from a vertex is not possible and n-1 people trust him then he is judge.
else not :)

*/

// my solution
// beats 5% in time
// time complexity O(n^2)
class Solution {
    void dfs(vector<list<int>> &adj, vector<int> &ans,int start,vector<bool> &visited)
    {
        visited[start]=true;
        ans.push_back(start);
        for(auto i:adj[start])
        {
            if(visited[i]==false)
                dfs(adj,ans,i,visited);
        }
    }
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==1)
        {
            return trust[0][1]; // if there is only one pair
        }
        vector<list<int>> adj(n+1);
        vector<int> trustCnt(n+1,0);  // array which keeps track of number of peoples who trust i;

        for(auto i:trust)
        {
            adj[i[0]].push_back(i[1]);
            trustCnt[i[1]]++;  // if 1 trust 2 then trut count of 2 is increased by 1.
        }

        for(int i=1;i<=n;i++)
        {
            vector<bool> visited(n+1,false);
            vector<int> ans;

            dfs(adj,ans,i,visited);
            if(ans.size()==1 && trustCnt[i]==n-1)
                return i;
        }
        return -1;
    }
};


// improved solution
// beats 75% in time
//time complexity O(n)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCnt(n+1,0);
        vector<bool> trustSomeone(n+1,false);

        for(auto i:trust)
        {
            trustSomeone[i[0]]=true;
            trustCnt[i[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(trustSomeone[i]==false && trustCnt[i]==n-1)
                return i;
        }
        return -1;
    }
};



