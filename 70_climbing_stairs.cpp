#include<bits/stdc++.h>
using namespace std;

/*
70. Climbing Stairs
Easy
17.1K
527
Companies
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int prev2=1,prev=2,ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=prev+prev2;
            prev2=prev;
            prev=ans;
        }
        return ans;
    }
};