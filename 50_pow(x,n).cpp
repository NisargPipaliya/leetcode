#include<bits/stdc++.h>
using namespace std;

/*
50. Pow(x, n)
Medium
6.7K
7K
Companies
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000


*/


// My solution
class Solution {
public:
    double help(double x, int n)
    {
        double ans=1;
        while(n>0)
        {
            ans*=x;
            if(ans==0.0)
                return ans;
            if(ans==1.0)
            {
                if(x<0)
                    ans*=x;
                return ans;
            }
            n--;
        }
        return ans;
    }
    double myPow(double x, int n) {
        bool flag=false;
        if(n<0)
        {
            n+=1;
            flag=true;
            n*=(-1);
        }
        double ans=help(x,n);
        if(flag)
        {
            ans*=x;
            ans=(double)1/(double)ans;
        }
        return ans;
    }
};

//      Optimal Solution BY USING BINARY EXPONENTIATION
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        return 1;
        if(n==1)
        return x;
        double ans = myPow(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        else if(n%2==1){
            return x*ans*ans;
        }
        else{
            return 1/myPow(x,-n);
        }

    }
};