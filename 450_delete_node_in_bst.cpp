#include<bits/stdc++.h>
using namespace std;
/*
450. Delete Node in a BST
Medium
8.1K
211
Companies
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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
    TreeNode* find(TreeNode*root, int key){
        if(root == nullptr)
            return NULL;

        if(root->val == key)
            return root;
        if(root->val < key)
            return find(root->right,key);
        else{
            return find(root->left,key);
        }
        return NULL;
    }
    TreeNode* findParent(TreeNode* root, int key){
        if(root == nullptr)
            return nullptr;
        if(root->left != nullptr && root->val > key && root->left->val == key)
        {
            return root;
        }

        if(root->right != nullptr && root->val < key && root->right->val == key)
        {
            return root;
        }

        if(root->val > key)
            return findParent(root->left,key);
        else
            return findParent(root->right,key);
        return NULL;
    }
    TreeNode* findSuccessor(TreeNode*root){
        if(root->left == nullptr){
            return root;
        }
        return findSuccessor(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* kVal = find(root,key);
        if(kVal == nullptr)
            return root;
        TreeNode* parent = findParent(root,key);
        if(kVal->left==nullptr and kVal->right==nullptr){
            if(parent != nullptr){
                if(parent->val > key){
                    parent->left = NULL;
                }else{
                    parent->right=NULL;
                }
                return root;
            }else{
                return NULL;
            }
        }

        if(kVal->right == nullptr){
            if(parent != nullptr){
                if(parent->val > key){
                    parent->left=kVal->left;
                }else{
                    parent->right=kVal->left;
                }
                return root;
            }else{
                return kVal->left;
            }
        }

        if(kVal->left == nullptr){
            if(parent != nullptr){
                if(parent->val > key){
                    parent->left=kVal->right;
                }else{
                    parent->right=kVal->right;
                }
                return root;
            }else{
                return kVal->right;
            }
        }

        TreeNode*successor = findSuccessor(kVal->right);
        successor->left = kVal->left;
        if(parent!=nullptr){
            if(parent->val > key){
                parent->left = kVal->right;
                return root;
            }
            else{
                parent->right=kVal->right;
                return root;
            }
        }
        TreeNode* ans = kVal->right;
        return ans;
    }
};