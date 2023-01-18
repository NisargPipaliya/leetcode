#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()<=1)
        {
            return s.length();
        }

        map<char,int> hash;
        int len=0;
        bool flag=false;
        for(auto i : s)
        {
            hash[i]++;
        }
        int largest_odd=0;
        for(auto i : hash)
        {
            if(i.second%2)
            {
                len+=i.second-1;
                largest_odd=max(largest_odd,i.second);
            }else
            {
                len+=i.second;
            }
        }
        if(largest_odd>0)
        {
            len+=1;
        }
        
        return len;
    }
};