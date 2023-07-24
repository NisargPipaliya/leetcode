#include<bits/stdc++.h>
using namespace std;

/*
542. 01 Matrix
Medium
7.5K
343
Companies
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
	    int m = mat[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0)), dis(n,vector<int>(m,0));
	    queue<tuple<int,int,int>> q;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(mat[i][j] == 0){
	                q.push(make_tuple(i,j,0));
	                vis[i][j] = 1;
	                dis[i][j] = 0;
	            }
	        }
	    }
	    int row,col,step;
	    int r[] = {1,-1,0,0}, c[] = {0,0,1,-1};
	    while(!q.empty()){
	        tie(row,col,step) = q.front();
	        dis[row][col] = step;
	        q.pop();
	        for(int i = 0; i < 4; i++){
	            row += r[i];
	            col += c[i];
	            if( row >= 0 && row < n && col >=0 && col < m && vis[row][col] == 0){
	                vis[row][col] = 1;
	                q.push(make_tuple(row,col,step + 1));
	            }
	            row -= r[i];
	            col -= c[i];
	        }
	        
	    }
	    return dis;
    }
};