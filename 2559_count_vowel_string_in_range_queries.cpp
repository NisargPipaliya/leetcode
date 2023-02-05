#include<bits/stdc++.h>
using namespace std;

/*
2559. Count Vowel Strings in Ranges
Medium
78
2
Companies
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.


*/

class Solution {
    bool isVowel(string &s)
    {
        if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u') && (s.back()=='a'||s.back()=='e'||s.back()=='i'||s.back()=='o'||s.back()=='u'))
            return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=queries.size(),m=words.size(),temp=0;
        vector<int> ans,dp(m,-1);
                
        for(int i=0;i<m;i++)
        {
            if(isVowel(words[i]))
            {
                temp++;
            }
            dp[i]=temp;
        }
                // dp[0]=0;

        for(auto i:queries)
        {
            if(i[0]==0)
                ans.push_back(dp[i[1]]);              
            else if(i[1]!=i[0])
                ans.push_back(dp[i[1]] - dp[i[0]-1]);  
            else
                ans.push_back(dp[i[1]]-dp[i[1]-1]);
        }
        
        return ans;
    }
};