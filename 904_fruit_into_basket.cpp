#include<bits/stdc++.h>
using namespace std;

/*
904. Fruit Into Baskets
Medium
2.7K
204
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

IT IS A CLASSIC SLIDING WINDOW PROBLEM WHERE WE NEED TO RETURN MAXIMUM SIZE OF WINDOW BASED ON GIVEN CONSTRAINT.
CODE IS SELF EXPLAINATORY.

*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> hash;
        int ans=INT_MIN,i=0,j=0,limit=fruits.size();

        while(j<limit)
        {
            hash[fruits[j]]++;
            if(hash.size()<=2)
            {
                ans=max(ans,j-i+1);
            }else
            {
                hash[fruits[i]]--;
                if(hash[fruits[i]] == 0)
                    hash.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};