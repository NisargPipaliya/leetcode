#include<bits/stdc++.h>
using namespace std;


/*
1317. Convert Integer to the Sum of Two No-Zero Integers
Easy
337
268
Companies
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 9 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104
*/


//My solution
class Solution {
    bool isNz(int n)
    {
        int r;
        while(n>0)
        {
            r=n%10;
            n/=10;
            if(r==0)
                return false;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++)
        {
            if(isNz(n-i)&isNz(i))
            {
                return {i,n-i};
            }
        }
        return {1,1};
    }
};