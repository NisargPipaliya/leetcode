#include<bits/stdc++.h>
using namespace std;


/*
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.

 

Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 



First find out the indexes of the element that is getting repeated.
suppose array be 1 1 2 3 1 4 1 1
                 i  j    k   l  m
now we are at k,
and we need to find the value then what we would do -> (k-i) + (k-j) -> 2*k -(i+j)
and add (l-k)+(m-k) -> (l+m) - 2*k to it.

therefore x -> how many times element occured.
ans = x*k - left  (left -> sum of all left indices in which this element occured)
ans += right - (n-x) *k (right -> sum of all right indices)
n-> total number of times element is repeated 
n-x -> number of times element is repeated on right hand side.


*/



class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long int,vector<long long> > m;
        int n = nums.size();
        vector<long long> ans(n,0);
        for(long long int i = 0; i <  n; i++)
        {
            m[nums[i]].emplace_back(i);
        }
        for(auto j : m)
        {
            int num = j.first;
            vector<long long> v = j.second;
            n = v.size();
            long long left = 0,right = 0, curr = 0, sum = 0;
            for(long long k : v)
            {
                sum += k;
            }
            right = sum;
            for(int i = 0; i < n; i++)
            {
                curr=0;
                curr += i*v[i]-left;
                curr += right - (n-i)*v[i];
                left += v[i];
                right -= v[i];
                ans[v[i]] = curr;
            }
            if(v.size() == 1)
                ans[v[0]] = 0;
        }
        return ans;
    }
};