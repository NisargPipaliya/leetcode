#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> ans(nums.size());
       int i=0,j=nums.size()-1,k=j;
       for(;i<=j;)
       {
           if(abs(nums[i])>abs(nums[j]))
           {
               ans[k]=nums[i]*nums[i];
               k--;
               i++;
           }else
           {
               ans[k--]=nums[j]*nums[j];
               j--;
           }
       }
       return ans;
    }
};