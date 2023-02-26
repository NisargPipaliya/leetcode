#include<bits/stdc++.h>
using namespace std;

/*
72. Edit Distance
Hard
11.8K
133
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];

        for (int i = 0; i<=m; i++)
            dp[0][i]=i;
        for (int i = 0; i<=n; i++)
            dp[i][0]=i;

        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if (word1[i-1] == word2[j-1])
                {  
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
            }
        }
        return dp[n][m];  
    }
};
