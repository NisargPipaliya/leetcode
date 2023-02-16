#include<bits/stdc++.h>
using namespace std;

/*
213. House Robber II
Medium
7.8K
115
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.



*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        int n=nums.size();
        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);



        for(int i=1;i<n;i++)
        {
            int x=dp1[max(0,i-2)]+nums[i-1];
            int y=dp1[i-1];
            dp1[i]=max(x,y);
        }
        for(int i=2;i<=n;i++)
        {
            int x=nums[i-1]+dp2[i-2];
            int y=dp2[i-1];
            dp2[i]=max(x,y);
        }
        return max(dp1[n-1],dp2[n]);
    }
};



/////////////
/*

class Solution {
    int help(vector<int> &nums)
    {
        int prev=nums[0],prev2=0,n=nums.size();
        for(int i=1;i<=n;i++)
        {
            int take=nums[i-1],notTake=prev;
            if(i>1)
                take+=prev2;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        int n=nums.size();
        vector<int> t1,t2;
        for(int i=0;i<n;i++)
        {
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        return max(help(t1),help(t2));
    }
};
*/