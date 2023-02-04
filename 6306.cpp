#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans,temp;
        for(auto i : nums)
        {
            int n=i;
            while(n>0)
            {
                temp.push_back(n%10);
                n=n/10;
            }
            reverse(temp.begin(),temp.end());
            for(auto j:temp)
            {
                ans.push_back(j);
            }
            temp.clear();
        }
        return ans;
        
    }
};