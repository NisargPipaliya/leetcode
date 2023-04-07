#include<bits/stdc++.h>
using namespace std;

/*
020. Number of Enclaves
Medium
2.5K
45
Companies
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

FLOOD FILL
*/

// class Solution {
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int count = 0;
//         vector<vector<bool>> visit(m, vector<bool>(n));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if( i==0 || j==0 || i==m-1 || j==n-1)
//                 {      
//                     if (grid[i][j] == 1 && !visit[i][j]) {
//                         dfs(i, j, m, n, grid, visit);
//                     }
//                 }
//             }
//         }
//         for(int i=0; i < m; i++){
//             for(int j=0; j < n; j++){
//                 if(grid[i][j] == 1 && visit[i][j] == false)
//                 {
//                     count++;
//                 }
//             }
//         }

//         return count;
        
//     }
// void  dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
       
//         visit[x][y] = true;
//         vector<int> dirx {0, 1, 0, -1};
//         vector<int> diry {-1, 0, 1, 0};

//         for (int i = 0; i < 4; i++) {
//             int r = x + dirx[i];
//             int c = y + diry[i];
//             if (r < 0 || r >= m || c < 0 || c >= n) {
//                 continue;
//             }
//             if (grid[r][c] == 0 || visit[r][c])
//                 continue;
//             dfs(r, c, m, n, grid, visit);
//         }
//     }
// };



class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        grid[i][j]=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        for(int k=0;k<4;k++)
        {
            int ni=i+dr[k],nj=j+dc[k];
            if(ni>=m||ni<0||nj>=n||nj<0||grid[ni][nj]==0)
                continue;
            dfs(ni,nj,grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0])
                dfs(i,0,grid);
            if(grid[i][n-1])
                dfs(i,n-1,grid);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i])
                dfs(0,i,grid);
            if(grid[m-1][i])
                dfs(m-1,i,grid);
        }
        int ans=0;
        for(auto &i : grid)
            for(int &j : i)
                if(j) ans++;
        return ans;
    }
};