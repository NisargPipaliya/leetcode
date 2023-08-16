#include<bits/stdc++.h>
using namespace std;

/*
Bottom View of Binary Tree
MediumAccuracy: 54.18%Submissions: 184K+Points: 4
Done with this problem? Now use these skills to apply for a job in Job-A-Thon 21!

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.
*/


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>m;
        queue<pair<Node*,int>> q;
        if(root == nullptr){
            return {};
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            
            Node* dummy = q.front().first;
            int cnt = q.front().second;
            q.pop();
            m[cnt] = dummy -> data;
            if(dummy->left != nullptr){
                q.push(make_pair(dummy->left,cnt-1));
            }
            if(dummy->right != nullptr){
                q.push(make_pair(dummy->right,cnt+1));
            }
        }
        
        vector<int> ans;
        for(auto i : m){
            ans.emplace_back(i.second);
        }
        return ans;
    }
};