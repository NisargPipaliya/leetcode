#include<bits/stdc++.h>
using namespace std;

/*
516. Longest Palindromic Subsequence
Medium
7.8K
291
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        int rows = s.size()+1, cols = rows;
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(s2[i-1] == s[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};