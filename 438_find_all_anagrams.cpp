#include<bits/stdc++.h>
using namespace std;
/*

438. Find All Anagrams in a String
Medium
10K
297
Companies
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

 
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> m,n;
        for(auto i : p)
        {
            m[i]++;
        }
        int k=p.size(),i=0,j=0,limit=s.size();
        n[s[0]]++;
        while(j<limit)
        {
            if(j-i+1 < k)
            {
                j++;
                n[s[j]]++;
            }
            else
            {
                if(m==n)
                {
                    ans.push_back(i);
                }
                n[s[i]]--;
                if(n[s[i]] == 0)
                    n.erase(s[i]);
                i++;
                j++;
                n[s[j]]++;
            }
        }
        return ans;
    }
};