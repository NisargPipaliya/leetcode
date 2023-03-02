#include<bits/stdc++.h>
using namespace std;

/*
338. Counting Bits
Easy
8.5K
406
Companies
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 
*/
class Solution {
public:
    vector<int> countBits(int n) {
     vector<int> ans(n+1,0);
     ans[0]=0;
     for(int i=1;i<=n;i++)   
     {
         if((i-1)%2 == 0)
            ans[i]=ans[i-1]+1;
         else
            ans[i]=ans[i/2];
     }
     return ans;
    }
};



// more optimized using inbuilt function

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for(int i=0;i<=n;i++)
        {
            bitset<64> x(i);
            ret.push_back(x.count());
        }
        return ret;
    }
};