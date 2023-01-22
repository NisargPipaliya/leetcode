#include<bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int mid)
{
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
         long long int lower_bound=1,upper_bound=n,mid,mini=INT_MAX;
        
        while(lower_bound<=upper_bound)
        {
            mid=(lower_bound+upper_bound)/2;
        
            if(isBadVersion(mid))
            {
                mini=mini>mid?mid:mini;
                upper_bound=mid-1;
            }
            else
            {
                lower_bound=mid+1;
            }
        }
        return mini;
    }
};