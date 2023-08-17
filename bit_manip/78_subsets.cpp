#include<bits/stdc++.h>
using namespace std;

/*
78. Subsets
Medium
15.5K
226
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
class Solution {
    vector<vector<int>> ans;
    void help(int i,int n, vector<int> temp,vector<int>&nums){
        if(i==n)
        {
            ans.emplace_back(temp);
            return;
        }
        vector<int> t2 = temp;
        temp.push_back(nums[i]);
        vector<int> t1 = temp;
        help(i+1,n,t1,nums);
        help(i+1,n,t2,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        help(0,n,{},nums);
        return ans;
    }
};