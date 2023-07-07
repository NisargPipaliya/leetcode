#include<bits/stdc++.h>
using namespace std;

/*
2024. Maximize the Confusion of an Exam
Medium
1.9K
32
Companies
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.


Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

CONFUSED 🥹
*/

class Solution {
    int help(string str,char x, int k)
    {
        int i = 0,j = i, n = str.size();
        int ans = 0, curr = k;
        while( j < n)
        {
            // if it is not that we are maximizing then it will check that can it swap with other symbol that we are maximizing ?
            // this checking is done through curr
            if(str[j] == x)
            {
                
            }else if(curr > 0)
            {
                curr--;
            }else{
                curr=k;
                while(i < n && str[i] == x )
                    i++;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // One time maximizing TRUE, other time maximizing FALSE
        return max(help(answerKey,'T',k), help(answerKey,'F',k));
    }
};