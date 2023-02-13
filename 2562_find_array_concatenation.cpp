#include<bits/stdc++.h>
using namespace std;

/*
        WEEKLY contest -> 332
        
You are given a 0-indexed integer array nums.

The concatenation of two numbers is the number formed by concatenating their numerals.

For example, the concatenation of 15, 49 is 1549.
The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:

If there exists more than one number in nums, pick the first element and last element in nums respectively and add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
If one element exists, add its value to the concatenation value of nums, then delete it.
Return the concatenation value of the nums.


*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        map<int,int> m;
        
        for(const auto i : nums)
        {
            m[i]++;
        }
        
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int temp=nums[i]+nums[j];
                if(temp>=lower && temp<=upper)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};