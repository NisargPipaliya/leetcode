#include<bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/studio/problems/bit-manipulation_8142533?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
*/
vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int> ans;
    int n = 1<<(i-1);
    n = n&num;
    n = n>>(i-1);
    if(n)
    {
        ans.emplace_back(1);
    }else{
        ans.emplace_back(0);
    }
    n = 1<<(i-1);
    ans.emplace_back(num|n);
    ans.emplace_back(num&(~n));
    return ans;
}