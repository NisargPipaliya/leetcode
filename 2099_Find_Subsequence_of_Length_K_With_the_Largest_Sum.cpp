#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // sort(begin(nums),end(nums));
        // vector<int> ans;
        // int n = nums.size();
        // while(k)
        // {
        //     k--;
        //     ans.emplace_back(nums[n-k-1]);
        // }
        // return ans;
        priority_queue<pii, vector<pii> ,greater<pii>> pq,pq2;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i],i});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty())
        {
            pq2.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        vector<int> ans;
        while(!pq2.empty())
        {
            ans.emplace_back(pq2.top().second);
            pq2.pop();
        }
        return ans;
    }
};