#include<bits/stdc++.h>
using namespace std;

/*
130. Surrounded Regions
Companies
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
*/

class Solution {
    void dfs(int row, int col,vector<vector<char>>& board, vector<vector<bool>> &vis, vector<vector<bool>> &ans){
        vis[row][col] = true;
        int m = board.size(), n = board[0].size();
        int rdir[] = {1,-1,0,0}, cdir[] = {0,0,1,-1};
        for(int i = 0; i < 4; i++)
        {
            int r = row + rdir[i], c = col + cdir[i];
            if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O' && vis[r][c] == false){
                ans[r][c] = false;
                dfs(r,c,board,vis,ans);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false)), ans(m,vector<bool>(n,true));
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && vis[0][j] == false){
                ans[0][j] = false;
                dfs(0,j,board,vis,ans);
            }
            if(board[m-1][j] == 'O' && vis[m-1][j] == false){
                ans[m-1][j] = false;
                dfs(m-1,j,board,vis,ans);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && vis[i][0] == false){
                ans[i][0] = false;
                dfs(i,0,board,vis,ans);
            }
            if(board[i][n-1] == 'O' && vis[i][n-1] == false){
                ans[i][n-1] = false;
                dfs(i,n-1,board,vis,ans);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};