#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap(int &a,int&b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        int i=0,j=size-1;
        k=k%size;
       for(;i<j;i++,j--)
       {
           swap(nums[i],nums[j]);
       }
       for(i=0,j=k-1;i<j;i++,j--)
        swap(nums[i],nums[j]);

        for(i=k,j=size-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
    }
};