#include<bits/stdc++.h>
using namespace std;

/*
2218. Maximum Value of K Coins From Piles
Hard
924
14
Companies
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

 

Example 1:


Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
*/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        function<int(int,int)> f = [&](int i,int coins)
        {
            if(i == 0)
                return 0;
            if(dp[i][coins] != -1)
                return dp[i][coins];
            int cs = 0;
            for(int j = 0; j <= min((int)piles[i-1].size(),coins) ; j++)
            {
                if(j > 0)
                    cs +=piles[i-1][j-1];
                dp[i][coins] = max(dp[i][coins],dp[i-1][coins-j] != -1 ? (dp[i-1][coins-j]+cs):(f(i-1,coins-j)+cs));
            }
            return dp[i][coins];
        };
        return f(n,k);
    }
};