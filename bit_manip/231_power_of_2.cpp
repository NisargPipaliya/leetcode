#include<bits/stdc++.h>
using namespace std;

/*
231. Power of Two
Easy
5.7K
373
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
*/
class Solution {
public:
    bool isPowerOfTwo(int n)
    {	
        // Write your code here.
        if(n == 1)
            return true;
        if(n==0)
            return false;
        int c1 = 0;
        while(n){
            int bit = n&1;
            if(bit and c1==0)
                c1=1;
            else if(c1>0)
                return false;
            n = n>>1;
        }
        return true;
    }
};