#include<bits/stdc++.h>
using namespace std;

/*
118. Pascal's Triangle
Easy
9.3K
304
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> dp;
     
     for(int row=0;row<numRows;row++)   
     {
        vector<int> v(row+1,1);
        for(int col=1;col<row;col++)
            v[col]=dp[row-1][col]+dp[row-1][col-1];
        dp.emplace_back(v);
     }
     return dp;
    }
};