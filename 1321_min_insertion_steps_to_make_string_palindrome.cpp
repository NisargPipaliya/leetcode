#include<bits/stdc++.h>
using namespace std;


/*
1312. Minimum Insertion Steps to Make a String Palindrome
Hard
3K
35
Companies
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
*/

// my sol
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s1=s;
        reverse(s1.begin(),s1.end());
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};

// most optimized
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >=0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[0][n - 1];
    }
};