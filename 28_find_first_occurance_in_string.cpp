#include<bits/stdc++.h>
using namespace std;

/*
28. Find the Index of the First Occurrence in a String
Medium
1.9K
119
Companies
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);           
    }
};