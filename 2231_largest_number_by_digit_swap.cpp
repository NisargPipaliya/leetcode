#include<bits/stdc++.h>
using namespace std;
/*
2231. Largest Number After Digit Swaps by Parity
Easy
463
254
Companies
You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
*/

class Solution {
public:
    int largestInteger(int num) {
        vector<int> nu;
        int n = num;
        while(n)
        {
            nu.emplace_back(n%10);
            n/=10;
        }

        reverse(nu.begin(),nu.end());

        priority_queue<int> odd,even;
        vector<int> od,ev;
        for(int i = 0; i < nu.size(); i++)
        {
            if(nu[i]%2 == 0)
            {
                even.push(nu[i]);
                ev.push_back(i);
            }else
            {
                odd.push(nu[i]);
                od.push_back(i);
            }   
        }
        int i = 0;
        while(!odd.empty())
        {
            int x = odd.top();
            nu[od[i]] = x;
            i++;
            odd.pop();
        }
        i = 0;
        while(!even.empty())
        {
            int x = even.top();
            
            nu[ev[i]] = x;
            i++;
            even.pop();
        }
        int ans = 0;
        for(int j : nu)
        {
            ans = ans*10 + j;
        }
        return ans;
    }
};