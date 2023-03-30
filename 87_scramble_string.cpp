#include<bits/stdc++.h>
using namespace std;

/*

87. Scramble String
Hard
2.2K
1K
Companies
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.



// watch scramble string video on youtube :)


*/

class Solution {
    map<string,bool> m;
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        if(s1==s2)
            return true;
        if(s1.size()<=1)
            return false;
        string key=s1+" "+s2;
        if(m.find(key)!=m.end())
        {
            return m[key];
        }
        int n=s1.size();

// Most imp step -> to avoid unwanted recursion calls
// here we are checking that is the string contains the character in same frequency or not. if frequency is not same then they are not scramble strings.
        map<char,int> m1,m2;
        for(int i=0;i<n;i++)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1!=m2)
        {
            m[key]=false;
            return false;
        }


        bool flag=false;
        for(int i=1;i<n;i++)
        {
            string s[6];
            s[0]=s1.substr(0,i);
            s[1]=s2.substr(n-i,i);
            s[2]=s1.substr(i,n-i);
            s[3]=s2.substr(0,n-i);
            s[4]=s2.substr(0,i);
            s[5]=s2.substr(i,n-i);
            bool c1,c2,c3,c4;

            string k=s[0]+" "+s[1];
            if(m.find(k)!=m.end())
                c1=m[k];
            else 
                c1=isScramble(s[0],s[1]); 
            m[k]=c1;

            k=s[2]+" "+s[3];
            if(m.find(k)!=m.end())
                c2=m[k];
            else 
                c2=isScramble(s[2],s[3]);
            m[k]=c2;
            
            k=s[0]+" "+s[4];
            if(m.find(k)!=m.end())
                c3=m[k];
            else 
                c3=isScramble(s[0],s[4]);
            m[k]=c3;

            k=s[2]+" "+s[5];
            if(m.find(k)!=m.end())
                c4=m[k];
            else
                c4=isScramble(s[2],s[5]);
            m[k]=c4;

            c1=c1&c2;
            c3=c3&c4;

            if(c1 || c3)
            {
                flag=true;
                break;
            }
        }
        return m[key]=flag;
    }
};



// most optimized
class Solution {
    unordered_map<string,bool> mp;
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        if(s1==s2){
            return true;
        }
        vector<int> a(26,0);
        vector<int> b(26,0);
        vector<int> c(26,0);
        if(mp.count(s1+s2)){
            return mp[s1+s2];
        }
        for(int i=1;i<=n-1;i++){
            int j=n-i;
            a[s1[i-1]-'a']++;
            b[s2[i-1]-'a']++;
            c[s2[j]-'a']++;
            
            if(a==b and isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i))){
                mp[s1+s2]=true;
                return true;
            }
            if(a==c and isScramble(s1.substr(0,i),s2.substr(j)) and isScramble(s1.substr(i),s2.substr(0,j))){
                mp[s1+s2]=true;
                return true;
            }
        }
        mp[s1+s2]=false;
        return false;
    }
};