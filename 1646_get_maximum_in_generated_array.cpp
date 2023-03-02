#include<bits/stdc++.h>
using namespace std;

/*
1646. Get Maximum in Generated Array
Easy
583
786
Companies
You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.

Example 1:

Input: n = 7
Output: 3
Explanation: According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is max(0,1,1,2,1,3,2,3) = 3.

*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        int maxi=INT_MIN;
        // cout<<dp[0]<<" "<<dp[1]<<" ";
        for(int i=2;i<=n;i++)
        {
            if(i%2 == 0)
            {
                dp[i]=dp[i/2];
            }else
            {
                dp[i]=dp[i/2]+dp[i/2 + 1];
            }
            // cout<<dp[i]<<"  ";
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};