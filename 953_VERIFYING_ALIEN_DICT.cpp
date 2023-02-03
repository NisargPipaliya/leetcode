#include<bits/stdc++.h>
using namespace std;


/*
953. Verifying an Alien Dictionary
Easy
4.4K
1.4K
Companies
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.


*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<int,int> m;
        int n=order.size();

        for(int i=0;i<n;i++)
        {
            m[order[i]]=i;
        }
        int si=words.size();
        for(int i=0;i<si-1;i++)
        {
            string w1=words[i],w2=words[i+1];
            // if()
            for(int j=0;j<w1.size();j++)
            {
                if(j==w2.size())
                    return false;
                if(w1[j]!=w2[j])
                {
                    if(m[w1[j]] > m[w2[j]] )
                        return false;
                    else break;
                }
            }
        }
        return true;
    }
};
