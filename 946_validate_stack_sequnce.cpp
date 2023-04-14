#include<bits/stdc++.h>
using namespace std;


/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // if(pushed.size()!= poped.size())
        //     return false;
        stack<int> st;
        bool ans = true;
        int i = 0,j = 0, n = pushed.size(),m = popped.size();
        while(i <= n && j <= m)
        {
            if(!st.empty() && j < m && st.top() == popped[j])
            {
                st.pop();
                j++;
            }else{
                if(i < n)
                    st.push(pushed[i]);
                else if (!st.empty())
                {
                    ans = false;
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};