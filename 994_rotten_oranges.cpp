#include<bits/stdc++.h>
using namespace std;
/*
994. Rotting Oranges
Medium
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/


//MYsol

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0,cnt = 0, cntBad = 0, m = grid.size(), n = grid[0].size();
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push(make_tuple(i,j,0));
                }
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        vector<vector<int>> v = grid;

        int r[] = {1,-1,0,0}, c[] = {0,0,1,-1};
        while(!q.empty()){
            int row, col, time;
            tie(row,col,time) = q.front();
            q.pop();

            ans = max(ans,time);
            for(int i = 0; i < 4; i++){
                int j = row + r[i], k = col + c[i];
                if(j >= 0 && j < m && k >= 0 && k < n && v[j][k] == 1){
                    v[j][k] = 2;
                    q.push(make_tuple(j,k,time+1));
                    cntBad++;
                }
            }

        }
        if(cnt != cntBad)
            return -1;
        return ans;
    }
};