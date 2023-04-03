#include<bits/stdc++.h>
using namespace std;

/*
881. Boats to Save People
Medium
4.8K
114
Companies
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
didn't got this one :|🥲
*/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     sort(people.begin(),people.end());
     int res=0;
     int l=0,r=people.size()-1;
     while(l<=r)
     {
        int rem=limit-people[r];
        r--;
        res++;
        if(l<=r and rem>=people[l])
        {
            l++;
        }
     }
    return res;
    }
};