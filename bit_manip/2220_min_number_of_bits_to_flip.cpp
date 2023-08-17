#include<bits/stdc++.h>
using namespace std;

/*
2220. Minimum Bit Flips to Convert Number
Easy
679
14
Companies
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

 

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
*/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = (start^goal);
        int ans = 0;

        while(temp){
            if((temp&1))
            {
                ans++;
            }
            temp = temp>>1;
        }
        return ans;
    }
};

// most optimal
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int bit=0;bit<31;bit++){
            if(((start>>bit)&1)!=((goal>>bit)&1))ans++;
        }
        
        
        return ans;
    }
};