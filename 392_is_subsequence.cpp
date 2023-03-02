#include<bits/stdc++.h>
using namespace std;
/*
392. Is Subsequence
Easy
6.9K
398
Companies
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() >  t.size())
            return false;
        
        int n=s.size(),i=0,j=0,m=t.size();
        while(i<n && j<m)
        {
            if(s[i]==t[j])
                i++;
            j++;
        }
        return !(i<n);
    }
};