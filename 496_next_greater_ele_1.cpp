#include<bits/stdc++.h>
using namespace std;
/*
496. Next Greater Element I
Easy
6.1K
428
Companies
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

All integers in nums1 and nums2 are unique.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     stack<int> st;
     unordered_map<int,int> m;
     int n = nums2.size(), d = nums1.size();
     vector<int> ans(d,-1);
     for(int i = 0; i < d; i++)
     {
        m[nums1[i]] = i;
     }

     for(int i = n-1; i>=0; i--)   
     {
        int x = -1;
        if(st.empty())
            x = -1;
        else if(st.top() > nums2[i])
        {
            x = st.top();
        }else
        {
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            if(st.empty())
                x = -1;
            else
                x = st.top();
        }
        st.push(nums2[i]);

        if(m.find(nums2[i]) != m.end())
        {
            ans[m[nums2[i]]] = x;
        }
     }
    return ans;
    }
};


//                  Most Efficient
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        unordered_map<int,int>umap;
        for(int i=n-1;i>=0;i--)
        {
            int e=nums2[i];
            while(!st.empty() && st.top()<=e){
            st.pop();
            }
            int r=(st.empty())?-1:st.top();
            umap.insert({e,r});
            st.push(e);
        }
        vector<int>ans;
        for(auto it:nums1){
        ans.push_back(umap[it]);
       }
       return ans;

        
    }
};