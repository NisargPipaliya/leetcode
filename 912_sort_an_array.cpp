#include<bits/stdc++.h>
using namespace std;

/*
912. Sort an Array
Medium
3.6K
631
Companies
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
*/


class Solution {
public:
    void merge(int lb,int mid,int ub,vector<int> &nums)
    {
        vector<int> b;
        int i=lb,j=mid+1,k;
        while(i<=mid && j<=ub)
        {
            if(nums[i] < nums[j])
            {
                b.emplace_back(nums[i++]);
            }else
                b.emplace_back(nums[j++]);
        }
        while(i <= mid)
            b.emplace_back(nums[i++]);
        while(j <= ub)
            b.emplace_back(nums[j++]);
        for(i=lb,k=0;i<=ub;i++,k++)
            nums[i]=b[k];
    }
    void merge_sort(int lb,int ub,vector<int> &nums)
    {
        if(lb>=ub)
            return;
        int mid=(lb+ub)/2;
        merge_sort(lb,mid,nums);
        merge_sort(mid+1,ub,nums);
        merge(lb,mid,ub,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums);
        merge_sort(0,ans.size()-1,ans);
        return ans;
    }
};