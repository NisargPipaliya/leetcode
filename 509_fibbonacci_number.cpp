#include<bits/stdc++.h>
using namespace std;

/*
509. Fibonacci Number
Easy
6.3K
309
Companies
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

*/

class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int prev=1,prev2=0,curr=0;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};