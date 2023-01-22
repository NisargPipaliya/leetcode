#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        return -1;
    }
};