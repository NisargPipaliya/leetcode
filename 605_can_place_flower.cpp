#include<bits/stdc++.h>
using namespace std;

/*
605. Can Place Flowers
Easy
3.8K
753
Companies
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // int i;
        if(n==0)
            return true;
        if(n>flowerbed.size())
            return false;
        if(flowerbed.size()<=1)
        {
            return (flowerbed[0]==0);
        }
        for(int i=0;i<flowerbed.size()-1 && n>0;i++)
        {
            if(flowerbed[i]==1)
                continue;
            if(i>0 && flowerbed[i-1]==1)
                continue;
            if(flowerbed[i+1]==1)
                continue;
            flowerbed[i]=1;
            n--;
        }
        if(flowerbed.back()==0 && n>0 && flowerbed[flowerbed.size()-2]!=1)
            n--;
        if(n==0)
            return true;
        return false;
    }
};
// Proper way to write it.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         if(n==0)
            return true;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){ 
                n--;
                if(n==0)
                    return true;
                flowerbed[i]=1; 
            }
        }
        return false;
    }
};