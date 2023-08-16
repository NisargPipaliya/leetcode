#include<bits/stdc++.h>
using namespace std;
/*
701. Insert into a Binary Search Tree
Medium
5.3K
163
Companies
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void insert(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == nullptr){
                root->left = new TreeNode(val);
                return;
            }
            insert(root->left,val);
        }
        else{
            if(root->right == nullptr){
                root->right = new TreeNode(val);
                return;
            }
            insert(root->right,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            root=new TreeNode(val);
            return root;
        }
        insert(root,val);
        return root;
    }
};