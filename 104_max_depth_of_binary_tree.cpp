#include<bits/stdc++.h>
using namespace std;

/*
104. Maximum Depth of Binary Tree
Easy
9.8K
158
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


HEIGHT OF BINARY TREE. -> standard code.
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
    //REST IN LEETCODE. IT IS inbuilt in leetcode.

};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int rightHeight=maxDepth(root->right);
        int leftHeight=maxDepth(root->left);
        int maxH = rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
        return maxH;
    }
};