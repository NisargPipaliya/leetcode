class Solution {
    int maxi=INT_MIN;
    int DFS(vector<list<int>> &adj,string &s,int start,vector<bool> &visited)
    {
        // vector<int> cnt(26+1);

        // cnt[s[start]-'a']=1;
        // int  height=1;

        visited[start]=true;
        int longest=0,slongest=0;


        for(auto i : adj[start])
        {   
            int flag=0;
            

            if(visited[i]==false)
            {
                auto par=DFS(adj,s,i,visited);
                
                // vector<int> childCnt=par.second;
                // for(int j=0;j<s.length();j++)
                // {
                    // cnt[i]=cnt[i]+childCnt[i];
                    // if(childCnt[s[start]-'a']!=0)
                    // {
                    //     flag=1;
                    // }
                // }
                // if(!flag) 
                if(s[start]==s[i])
                    continue;
                    // height=max(height,par+height);
                    // longest=max(longest,par);
                    // slongest=max(slongest,par);
                    if(par>longest)
                    {
                        slongest=longest;
                        longest=par;
                    }else if(par>slongest)
                    {
                        slongest=par;
                    }
            }
        }
        maxi=max(maxi,longest+slongest+1);

        return longest+1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        vector<list<int>> adj(s.length());
        for(int i=1;i<s.length();i++)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
    vector<bool> visited(s.length());
        // visited.resize(s.length());
        auto result=DFS(adj,s,0,visited);
        // for(int i=0;i<s.length();i++)
        // {
        //     if(visited[i]==false)
        //     {
        //         result=DFS(adj,s,i,visited);
        //     }
        // }
       return  maxi;
    }
};