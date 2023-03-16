#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2)
            return false;
        int rows=nums.size(),cols=sum/2;
        vector<vector<bool>> dp(rows+1,vector<bool>(cols+1,false));
        
        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=cols;j++)
            {
                if(j==0)
                    dp[i][j]=true;
            }
        }

        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=cols;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-nums[i-1]];
                }else
                {
                    dp[i][j]=dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[rows][cols];
    }
};