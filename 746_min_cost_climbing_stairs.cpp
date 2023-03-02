#include<bits/stdc++.h>
using namespace std;

/*
746. Min Cost Climbing Stairs
Easy
8.9K
1.4K
Companies
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.


*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        for(int i=2;i<=cost.size();i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp.back();
    }
};