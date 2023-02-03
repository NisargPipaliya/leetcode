#include<bits/stdc++.h>
using namespace std;
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

here we found that the actual offset is (numRows-1)*2 when numrows > 1 and when row is not first or last then we need to insert characters that are coming in middle so for that we maintained j variable.


*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows >= s.size() || numRows==1)
        {
            return s;
        }
        int i=0,j=0,k=0,offset=(numRows-1)*2,n=s.size();

        string ans="";
        for(int i=0;i<numRows;i++)
        {
            ans.push_back(s[k]);
            int index=k+offset;
            while(index<n)
            {
                if(i!=0 && i!= numRows-1)
                {
                    ans.push_back(s[index-j]);
                }
                ans.push_back(s[index]);
                index+=offset;
            }

            while(index-j < n)
            {
               if(i!=0 && i!= numRows-1)
                {
                    ans.push_back(s[index-j]);
                }
                index+=offset;
            }
            j+=2;
            k++;
        }
        return ans;
    }
};