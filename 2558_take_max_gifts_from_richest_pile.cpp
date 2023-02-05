#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        vector<int> demo=gifts;
        long long ans=0;
        int n=gifts.size();
        n=n-1;
        for(int i=1;i<=k;i++)
        {
            sort(demo.begin(),demo.end());
            demo[n]=sqrt(demo[n]);
        }
        for(auto i : demo)
        {
            ans+=i;
        }
        
        return ans;
    }
};