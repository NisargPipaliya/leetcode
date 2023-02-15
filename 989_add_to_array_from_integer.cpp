#include<bits/stdc++.h>
using namespace std;

/*

989. Add to Array-Form of Integer
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

*/
        //brute force
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        long long int n=0;
        reverse(num.begin(),num.end());

        for(int i=0;i<num.size();i++)
        {
            n= n + num[i]*pow(10,i);
            // cout<<pow(10,i)<<endl;
            // cout<<n<<endl;
        }
        n+=k;
        // cout<<n<<endl;
        vector<int> ans;
        while(n>0)
        {
            ans.push_back(n%10);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Can have numbers that may go outside the range of long long int

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans(num);
        int n=k,c=0,i;

        for(i=num.size()-1;i>=0 ;i--)
        {
            ans[i]=ans[i]+n%10+c;
            n/=10;
            c=ans[i]/10;
            ans[i]=ans[i]%10;
        }
        int j=i;
        while(n>0)
        {
            int r=n%10+c;
            n/=10;
            c=r/10;
            r=r%10;
            ans.insert(ans.begin(),r);
        }
        if(c==1)
            ans.insert(ans.begin(),c);
        return ans;
    }
};