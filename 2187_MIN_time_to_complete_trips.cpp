#include<bits/stdc++.h>
using namespace std;

/*
2187. Minimum Time to Complete Trips
Medium
1.2K
76
Companies
You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 

Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.



*/

//                  My Brute force solution ->> O(n^2)  ->> TLE

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long  t=0,ct=0,j=1;
        int i=0,n=time.size();

        while(true)
        {
            for(i=0;i<n;i++)
            {
                if(time[i] <= j)
                {
                    ct += j/time[i];
                }
            }
            if(ct >= totalTrips)
            {
                t=j;
                // if(ct==totalTrips)
                break;
            }
            ct=0;
            j++;
        }
        return t;
    }
};


// O(nlogn) -> passes all testcases

typedef long long ll;

class Solution {
public:
    bool check(vector<int> time,ll mid, int t)
    {
        ll ct=0;
        for(auto i :time)
        {
            ct+=mid/i;
            if(ct>=t) return true;
        }
        return false;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(),time.end());
        ll l= time[0];
        ll r = (ll)time[n-1] * (ll)totalTrips;
        while(l<r)
        {
            ll mid = (l+r)/2;

            if(check(time,mid,totalTrips))
            {
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};