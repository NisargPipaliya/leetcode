#include<bits/stdc++.h>
using namespace std;
/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

as array is sorted and we are given a target. 
and only one solution is possible i.e. by adding ONLY TWO NUMBERS
therefore we will go for two pointer technique

itrf->starting from 0
itrb-> starting from back

rest code is self explainatory
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        int size=numbers.size();
        int itr_f=0,itr_b=size-1;
        while(itr_f<itr_b)
        {
            int sum=numbers[itr_f]+numbers[itr_b];
            if(sum==target)
            {
                ans.push_back(itr_f+1);
                ans.push_back(itr_b+1);
                break;
            }
            else if(sum<target)
            {
                itr_f++;
            }else
            {
                itr_b--;
            }
        }
        return ans;
    }
};