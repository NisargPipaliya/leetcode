#include<bits/stdc++.h>
using namespace std;

/*
Top View of Binary Tree
MediumAccuracy: 38.43%Submissions: 233K+Points: 4
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
*/


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
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
            if(m.find(cnt) == m.end())    
            {
                m[cnt] = dummy -> data;
            }
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