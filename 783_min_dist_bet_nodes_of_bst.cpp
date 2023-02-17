#include<bits/stdc++.h>
using namespace std;

/*
783. Minimum Distance Between BST Nodes
Easy
2.5K
362
Companies
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Input: root = [4,2,6,1,3]
Output: 1

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    TreeNode * left;
    int val;
    //REST IN LEETCODE. IT IS inbuilt in leetcode.

};

class Solution {
    vector<int> ino;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        ino.emplace_back(root->val);
        inorder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right == NULL)
            return root->val;
        inorder(root);
        int mini=INT_MAX;

        for(int i=0;i<ino.size()-1;i++)
        {
            int temp=abs(ino[i+1]-ino[i]);
            mini=min(mini,temp);
        }
        return mini;
    }
};