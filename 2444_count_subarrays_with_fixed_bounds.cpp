#include<bits/stdc++.h>
using namespace std;

/*
2444. Count Subarrays With Fixed Bounds
Hard
829
19
Companies
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].


NO INTUTION :|

*/


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // minPosition, maxPosition: the MOST RECENT positions of minK and maxK.
        // leftBound: the MOST RECENT value outside the range [minK, maxK].
        long long answer = 0;
        int minPosition = -1, maxPosition = -1, leftBound = -1;
        
        // Iterate over nums, for each number at index i:
        for (int i = 0; i < nums.size(); ++i) {
            // If the number is outside the range [minK, maxK], update the most recent leftBound.
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            // If the number is minK or maxK, update the most recent position.
            if (nums[i] == minK) 
                minPosition = i;
            if (nums[i] == maxK)
                maxPosition = i;

            // The number of valid subarrays equals the number of elements between leftBound and 
            // the smaller of the two most recent positions (minPosition and maxPosition).
            answer += max(0, min(maxPosition, minPosition) - leftBound);
        }
        return answer;
    }
};