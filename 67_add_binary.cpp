#include<bits/stdc++.h>
using namespace std;

/*
67. Add Binary
Easy
7.1K
721
Companies
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

beats 100%  in time ans 86.6% in space.

code is self explainatory

*/

class Solution {
public:
    string addBinary(string a, string b) {
     int n=a.size()-1,m=b.size()-1;
     string ans;
     int c=0;
     while(n>=0 && m>=0)
     {
         if(a[n]=='1' && b[m]=='1')
         {
             if(c==1)
             {
                 ans.push_back('1');
             }else
             {
                 ans.push_back('0');
                 c=1;
             }
         }else if(c==1){
             char demo=max(a[n],b[m]);
             if(demo=='1')
             {
                 ans.push_back('0');
             }else{
                 ans.push_back('1');
                 c=0;
             }
         }else
         {
             char demo=max(a[n],b[m]);
             ans.push_back(demo);
         }
         n--;
         m--;
     }

     while(n>=0)
     {
             if(a[n]=='1' && c==1)
             {
                 ans.push_back('0');
             }else if(c==1){
                 ans.push_back('1');
                 c=0;
             }else
             {
                 ans.push_back(a[n]);
             }
         n--;
     }

     while(m>=0)
     {
            if(b[m]=='1' && c==1)
             {
                 ans.push_back('0');
             }else if(c==1){
                 ans.push_back('1');
                 c=0;
             }else
             {
                 ans.push_back(b[m]);
             }
         m--;
     }
     if(c==1)
     {
         ans.push_back('1');
     }

     reverse(ans.begin(),ans.end());
     return ans;
    }
};