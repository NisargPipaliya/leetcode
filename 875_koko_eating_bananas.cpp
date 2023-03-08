#include<bits/stdc++.h>
using namespace std;

/*
875. Koko Eating Bananas
Medium
6.9K
322
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4


*/


class Solution {
public:
    long long check(vector<int> &piles,int mid)
    {
       long long int time=0,n=piles.size();
       for(int i=0;i<n;i++)
       {
           time+=(piles[i]/mid)+((piles[i]%mid)!=0);
       }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,u=*max_element(piles.begin(),piles.end()),mid=0;
        int ans=0;
        while(l<=u)
        {
            mid=(l+u)/2;
            if(check(piles,mid) <= h)
            {
                ans=mid;
                u=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        // cout<<l<<"  "<<mid<<"  "<<u<<endl;
        return ans;
    }
};