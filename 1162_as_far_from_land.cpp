#include<bits/stdc++.h>
using namespace std;
/*
    1162. As Far from Land as Possible
Medium
3.1K
81
Companies
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 
nai... huaa :(

    clearly i don't know about it :(
        it's leetcode's official solution.
*/
class Solution {
public:
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int visited[grid.size()][grid[0].size()];
        
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                visited[i][j] = grid[i][j];
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        int distance = -1;
        while (!q.empty()) {
            int qSize = q.size();
            
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                
                    for (pair<int, int> dir : direction) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            distance++;
        }
        return distance == 0 ? -1 : distance;
    }
};