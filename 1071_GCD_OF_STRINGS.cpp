#include<bits/stdc++.h>
using namespace std;

/*
1071. Greatest Common Divisor of Strings
Easy
3.1K
476
Companies
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"


here first we need to check that the string that we are assuming to be our gcd it's length should be a factor of length of given 
two strings as then only the given two strings would be made up of gcd string.
then "index by index we would check that can this substring become our GCD?"

*/


class Solution {
public:
    bool valid(string str1, string str2, int k) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 % k > 0 || len2 % k > 0) {
            return false;
        } else {
            string base = str1.substr(0, k);
            int n1 = len1 / k, n2 = len2 / k;
            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
        }
    }
    string joinWords(string str, int k) {
        string ans = "";
        for (int i = 0; i < k; ++i) {
            ans += str;
        }
        return ans;
    }
    
    
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};