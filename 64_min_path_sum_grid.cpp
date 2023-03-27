#include<bits/stdc++.h>
using namespace std;

/*
64. Minimum Path Sum
Medium
10.2K
135
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12



DID it recursively -> TLE :)
but found it difficult how to memoize
*/

//recursive solution
class Solution {
    void dfs(vector<vector<int>> &adj,int i,int j,int curr,int row,int col)
    {
        if(i>row || j>col)
            return;
        if(i==row && j==col)
        {
            curr+=adj[i][j];
            mini=min(mini,curr);
            // cout<<endl<<i<<" "<<j;
            return;
        }
        curr+=adj[i][j];
        // cout<<endl<<i<<" "<<j;
        dfs(adj,i+1,j,curr,row,col);
        dfs(adj,i,j+1,curr,row,col);
    }
public:
    int mini=INT_MAX;
    int minPathSum(vector<vector<int>>& grid) {
        int i=0,j=0,row=grid.size()-1,col=grid[0].size()-1;
        // cout<<row<<" "<<col<<endl;
        dfs(grid,0,0,0,row,col);
        return mini;
    }
};

// DP solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        dp[0][0]=grid[0][0];
        //first row fill up
        for(int p=1;p<col;p++){
            dp[0][p]=dp[0][p-1]+grid[0][p];
        }
        //first col fill up
        for(int p=1;p<row;p++){
            dp[p][0]=dp[p-1][0]+grid[p][0];
        }
        //fill up the rest
        for(int p=1;p<row;p++){
            for(int q=1;q<col;q++){
                dp[p][q]=grid[p][q]+min(dp[p][q-1],dp[p-1][q]);
            }
        }
        return dp[row-1][col-1];
    }
};