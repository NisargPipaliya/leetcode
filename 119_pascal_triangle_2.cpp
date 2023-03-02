#include<bits/stdc++.h>
using namespace std;

/*
119. Pascal's Triangle II
Easy
3.6K
294
Companies
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<vector<int>> dp;

     int n=rowIndex+1;

     for(int row=0;row<n;row++)   
     {
        vector<int> v(row+1,1);
        for(int col=1;col<row;col++)
            v[col]=dp[row-1][col]+dp[row-1][col-1];
        dp.emplace_back(v);
     }
     return dp.back();
    }
};