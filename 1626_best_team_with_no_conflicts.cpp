#include<bits/stdc++.h>
using namespace std;

/*
1626. Best Team With No Conflicts
Medium
2.5K
79
Companies
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.


first we sorted the input according to ages. so we can perform calcuations easily.
here first we initialised dp array with initial scores of all players and also found max score and stored it in ans var.

then we checked for all players that is there any player of lower age who have less score then we would include him in answer->
here also we have two choices that whether to include or not? so we have written:
 max(dp[i] , dum[i].second + dp[j]); here dp[i]-> is max score of the team till player i. dum[i].second -> score of player i, dp[j]-> max score of team till player j.



*/

class Solution {
public:
  
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> dum;
        int n=scores.size();
        for (int i = 0; i < n; i++) {
            dum.push_back({ages[i], scores[i]});
        }
        
        sort(dum.begin(),dum.end());

        int ans = 0;
        
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = dum[i].second;
            ans = max(ans, dp[i]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dum[i].second >= dum[j].second) {
                    dp[i] = max(dp[i], dum[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};