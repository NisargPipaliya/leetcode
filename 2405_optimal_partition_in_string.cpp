#include<bits/stdc++.h>
using namespace std;


/*
2405. Optimal Partition of String
Medium
690
33
Companies
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

*/


// my solution

class Solution {
    bool isUnique(string &s,int i,int j)
    {
        // unordered_map<char,int> m;
        unordered_set<char> hs;
        for(int k=i;k<=j;k++)
        {
            // m[s[k]]++;
            // if(m[s[k]] > 1)
            // {
            //     return false;
            // }
            if(hs.find(s[k]) != hs.end())
            {
                return false;
            }   
            hs.insert(s[k]);
        }
        return true;
    }
public:
    int partitionString(string s) {
        int i=0,j=0,n=s.size();
        int count=0;
        while(j<n)
        {
            if(isUnique(s,i,j))
            {
                j++;
            }else{
                i=j;
                count++;
            }
        }
        if(isUnique(s,i,j-1))
            count++;
        return count;
    }
};




// most easy to understand and more efficient then my sol.
class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> umap;
        int ct=0;
        for(auto i:s){
            if(umap.count(i)==0)
            umap[i]++;
            else{
                ct+=1;
                umap.clear();
                umap[i]++;
            }
        }
        ct+=1;
        return ct;
    }
};


// solution of some MAD guy -> most optimal.
 int partitionString(string s) {
        int flag=0,ans=1;
        for(int i=0;i<s.size();i++)
        {
            int k=s[i]-'a';
            if(flag&(1<<k))
            {
                ans++;
                flag=0;
            }
            flag=flag|(1<<k);
        }
        return ans;
    }


// ultimate MAD guy.
// code not at all easy to understand

const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution
{
public:
	int partitionString(std::string const& s)
	{
		return std::accumulate(std::cbegin(s), std::cend(s), 1,
			[observed = std::array<int, 128>{0}](auto count, auto c) mutable
			{
				if (observed[c] == count) { ++count; }
				observed[c] = count;
				return count;
			});
	}
};