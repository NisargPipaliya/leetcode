#include<bits/stdc++.h>
using namespace std;

/*
1523. Count Odd Numbers in an Interval Range
Easy
1.8K
119
Companies
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

solution is self exlainatory.

*/

class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high)
        {
            return high%2;
        }

        if(low%2==0)   
        {
            low++;
        }
        if(high%2==0)
        {
            high--;
        }
        return ceil( (double)((high-low)+1)/2 );
    }
};


// 100 % faster
class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2!=0 || high%2!=0)
        return ceil( (double)((high-low)+1)/2 );
        return (high-low)/2;
    }
};