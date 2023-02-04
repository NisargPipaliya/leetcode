#include<bits/stdc++.h>
using namespace std;


/*
567. Permutation in String
Medium
8.6K
280
Companies
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Input: s1 = "ab", s2 = "eidboaoo"
Output: false


explaination: here it is straight forward given that we need to find s1 inside s2.
-> so length(s1)<=length(s2)
now when s1<s2 we need to traverse s2 such a way that for window size equal to s1.length is should contain all the letters in s1
therefore we used map :)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1==s2)
            return true;
        if(s1.size() >  s2.size())
            return false;

        map<char,int> m,n;
        for(auto i : s1)
        {
            m[i]++;
        }
        int k=s1.size(),i=0,j=0,limit=s2.size();
        n[s2[0]]++;
        while(j<limit)
        {
            if(j-i+1 < k)
            {
                j++;
                n[s2[j]]++;
            }
            else
            {
                if(n.empty()==true)
                {
                    n[s2[i]]++;
                }
                if(m==n)
                    return true;
                n[s2[i]]--;
                if(n[s2[i]] == 0)
                    n.erase(s2[i]);
                    
                i++;
                j++;
                n[s2[j]]++;
            }
        }
        if(m==n)
            return true;
        return false;
    }
};