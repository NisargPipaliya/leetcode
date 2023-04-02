#include<bits/stdc++.h>
using namespace std;


/*
2300. Successful Pairs of Spells and Potions
Medium
1.5K
35
Companies
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

 

Example 1:

Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

*/
// Leetcode solution 
//  mera dekhane layak nai hai
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array in increasing order.
        sort(potions.begin(), potions.end());
        vector<int> answer;
        
        int m = potions.size();
        int maxPotion = potions[m - 1];
        
        for (auto& spell : spells) {
            // Minimum value of potion whose product with current spell  
            // will be at least success or more.
            long long minPotion = ceil((1.0 * success) / spell);
            // Check if we don't have any potion which can be used.
            if (minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            // We can use the found potion, and all potion in its right 
            // (as the right potions are greater than the found potion).
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            answer.push_back(m - index);
        }
        
        return answer;
    }
};