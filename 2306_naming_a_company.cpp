#include<iostream>  //SAY NO TO BITS :)
#include<vector>
#include<set>
using namespace std;

/*
2306. Naming a Company
Hard
1K
49
Companies
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

 

Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.


my solution initially was correct but getting TLE in 74TH test case :)

*/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long int ans=0;
        set<string> hash;
        for(auto i : ideas)
        {
            hash.insert(i);
        }

        for(int i=0;i<ideas.size()-1;i++)
        {
        
            for(int j=i+1;j<ideas.size();j++)
            {
                string s2=ideas[j],s1=ideas[i];
                char a=s1[0];
                s1[0]=s2[0];
                s2[0]=a;

                // cout<<s1<<" "<<s2<<endl;
                // cout<<endl<<ideas[i]<<" "<<ideas[j]<<endl;
                if(hash.find(s1)==hash.end() && hash.find(s2)==hash.end())
                {
                    ans+=2;
                }
            }
        }
        return ans;
    }
};


/*
                        correct solution
here approach is that we are grouping the words on basis of first letter of the string.
that is we are limiting the timecomplexity from O(n^2) O(26^2)
that is we are going to traverse this groups instead of traversing whole vector of ideas like above solution.
when we traverse this groups we will try to find the suffixes we saved previously in any other group
and increment an counter named as inter -> intersection 
then we will remove this intersection from actual length of this group then obtain the answer accouringly.
:| -> this optimization.....


it has one more solution which has bit manipulation involved... which at present i don't know
*/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        if(ideas.size()==0)
        {
            return 0;
        }
        long long int ans=0;
        set<string> hash[26];
        for(auto i : ideas)
        {
            hash[i[0]-'a'].insert(i.substr(1));
        }

        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int inter=0;
                for(auto k : hash[i])
                {
                    if(hash[j].find(k)!=hash[j].end())
                        inter++;
                }
                int l1=hash[i].size()-inter;
                int l2=hash[j].size()-inter;
                ans+= l1*l2*2;
            }
        }
        return ans;
    }
};