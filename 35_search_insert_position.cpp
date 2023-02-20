#include<bits/stdc++.h>
using namespace std;
/*
35. Search Insert Position
Easy
12.3K
535
Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int lower_bound=0,upper_bound=nums.size()-1,mid;
        
        while(lower_bound<=upper_bound)
        {
            mid=(lower_bound+upper_bound)/2;
            if(nums[mid]==target)
                return mid;
            else if(target<nums[mid])
                upper_bound=mid-1;
            else
                lower_bound=mid+1;
        }
        if(target<nums[mid])
            return mid;
        else
            return mid+1;

    }
};