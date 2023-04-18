#include<bits/stdc++.h>
using namespace std;


/*
1768. Merge Strings Alternately
Easy
1.6K
25
Companies
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        bool flag=false;
        int i, j, n = word1.size(), m = word2.size(), k = 0;
        string ans;
        ans.reserve(m+n);
        for(i = 0,j=0; i < n && j < m;)
        {
            if(!flag)
            {
                ans.push_back(word1[i]);
                i++;
                flag=true;
            }else {
                ans.push_back(word2[j]);
                j++;
                flag=false;
            }
        }
        while(i < n)
        {
            ans.push_back(word1[i++]);
        }

        while(j < m)
        {
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};