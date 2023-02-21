#include<bits/stdc++.h>
using namespace std;

/*
540. Single Element in a Sorted Array
Medium
7.2K
121
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Just a little modification in binary search algorithm.


*/

//  O(N) May be beats 86% in time 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int upper_bound=0,lower_bound=nums.size()-1;
        while(upper_bound<=lower_bound)
        {
            if(nums[upper_bound]==nums[upper_bound+1])
                upper_bound+=2;
            else
                return nums[upper_bound];
            if(nums[lower_bound]==nums[lower_bound-1])
                lower_bound-=2;
            else 
                return nums[lower_bound];
        }
        return -1;
    }
};

// O(n) solution as this too works here by beating 20% in time.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
};




// logn sol
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }
            else{
                if(nums[mid]!=nums[mid+1]){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }
        }
        return nums[l];
    }
};