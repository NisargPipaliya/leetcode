#include<bits/stdc++.h>
using namespace std;
/*
2357. Make Array Zero by Subtracting Equal Amounts
Easy
867
33
Companies
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

 

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

*/



// my sol

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i : nums)
        {
            if( i > 0) pq.push(i);
        }
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            vector<int> temp;
            while(!pq.empty())
            {
                temp.emplace_back(pq.top() - x);
                pq.pop();
            }
            for(int i : temp)
                if(i > 0) pq.push(i);
            ans++;
        }
        return ans;
    }
};

// most optimal sol

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sub=0;
        int count=0;
        for (int i=0;i<nums.size();i++)
         {  
             nums[i]-=sub;
             if(nums[i]>0)
              {
                  sub+=nums[i];
                  count++;
              }
         }
        return count;
    }
};