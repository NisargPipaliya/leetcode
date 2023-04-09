#include<bits/stdc++.h>
using namespace std;

/*
2614. Prime In Diagonal
User Accepted:9492
User Tried:11629
Total Accepted:9981
Total Submissions:36751
Difficulty:Easy
You are given a 0-indexed two-dimensional integer array nums.

Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

Note that:

An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
An integer val is on one of thediagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1]= val.


In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].

 

Example 1:

Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
Output: 11
Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals
*/

class Solution {
    bool isPrime(int n, vector<int> &prime)
    {
        if(prime[n]!=-1)
            return prime[n];
        if(n==1)
            return prime[n]=false;
        
        int x=sqrt(float(n));
        for(int i = 2; i <= x; i++ )
        {
            if(n % i == 0)
                return prime[n]=false;
        }
        return prime[n]=true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> prime(4000000,-1);
        int ans = 0, rows = nums.size();
        int r = 0;
        
        for(r=0; r < rows ; r++)
        {
            if(isPrime(nums[r][r], prime))
                ans = max(ans,nums[r][r]);
            if(isPrime(nums[r][rows-r-1], prime))
                ans=max(ans,nums[r][rows-r-1]);
        }
        return ans;
    }
};