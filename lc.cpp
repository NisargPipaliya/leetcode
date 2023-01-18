#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        // int maxSum=nums[0],start=1,size=nums.size(),currSum=nums[0],comSum=nums[0];
        // bool flag=true;
        // if(nums[0]<0)
        // {
        //     currSum=0;
        // }

        // while(flag)
        // {   
        //         currSum=currSum + nums[start];
        //     if(start!=0)
        //         comSum=comSum+nums[start];
        //     maxSum=max(maxSum,currSum);
        //     maxSum=max(maxSum,comSum);

        //     if(nums[start]<0)
        //     {
        //         currSum=0;
        //     }
        //     if(start==0)
        //     {
        //         flag=false;
        //     }
        //     start=(start+1)%size;
        // }
        // return maxSum;

        int minSum=INT_MAX,start=1,size=nums.size(),currSum=nums[0],totSum=nums[0];
        for(int i=1;i<size;i++)
        {
            currSum+=nums[i];
            minSum=min(minSum,nums[i]);
            minSum=min(minSum,currSum);
            if(nums[i]>0)
            {
                currSum=0;
            }
            totSum+=nums[i];
        }
        int result=totSum-minSum;
        return result;


    }
};