class Solution {
public:
    vector<int> dfs(int start, int parent, vector<vector<int>>& adj, string& labels,vector<int>& ans) {
        vector<int> nCounts(26);
        nCounts[labels[start] - 'a'] = 1;

        for (auto& child : adj[start]) {
            if (child == parent) {
                continue;
            }
            vector<int> cCounts = dfs(child, start, adj, labels, ans);
            for (int i = 0; i < 26; i++) {
                nCounts[i] += cCounts[i];
            }
        }

        ans[start] = nCounts[labels[start] - 'a'];
        return nCounts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        dfs(0, -1, adj, labels, ans);

        return ans;
    }
};