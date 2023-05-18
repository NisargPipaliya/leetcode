#include<bits/stdc++.h>
using namespace std;

/*
145. Binary Tree Postorder Traversal
Easy
5.9K
173
Companies
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

};

class Solution {
    void postOrder(TreeNode* root, vector<int> &ans)
    {
        if(root == nullptr)
            return;
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.emplace_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
     vector<int> ans;
     postOrder(root,ans);
     return ans;
    }
};