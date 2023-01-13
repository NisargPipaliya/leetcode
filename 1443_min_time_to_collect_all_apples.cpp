class Solution {
public:
    int DFS(int start,vector<list<int>> &adj, vector<bool> &apple,vector<bool> &visited)
    {
        int time=0;
        visited[start]=true;
        for(auto i:adj[start])
        {
            if(visited[i]==false){
                // int temp=time;
                int temp=DFS(i,adj,apple,visited);
                if(temp != 0 || apple[i]==true)
                {
                    time=time+2+temp;
                }
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<list<int>> adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

            // cout<<endl;
        }
        // for(auto i:adj)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool> visited(n,false);
        int time = DFS(0,adj,hasApple,visited);
        return time;
    }
};