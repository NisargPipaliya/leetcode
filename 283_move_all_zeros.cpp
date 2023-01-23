#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

we will use two pointer approach 
pointer i-> it is the index at which value is zero
j-> any number
so we will start traversal from
    i=0,j=1;
        if a[i]==0 then 
            swap a[i],a[j]
                after swapping i  is not zero
                    i++
            j++
        else  (if i is not zero)
            i++
            j++
            
*/
class Solution {
public:
    void swap(int &a,int&b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return;
        int i=0,j=i+1;
        while(j<nums.size())
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[j]);
                    if(nums[i]!=0)
                        i++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
};