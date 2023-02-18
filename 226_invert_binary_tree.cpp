#include<bits/stdc++.h>
using namespace std;

/*
226. Invert Binary Tree
Easy
11.5K
162
Companies
Given the root of a binary tree, invert the tree, and return its root.

 Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

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
    TreeNode*right;
    TreeNode*left;
    int val;
    TreeNode();
    TreeNode(int x)
    {
        val=x;
    }

};

class Solution {
    void inv(TreeNode* root, TreeNode* &nroot)
    {
        if(root==NULL)
            return;
        
        nroot=new TreeNode(root->val);
        inv(root->left,nroot->right);
        inv(root->right,nroot->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode*ans;
        inv(root,ans);
        
        return ans;
    }
};