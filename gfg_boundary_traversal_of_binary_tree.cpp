#include<bits/stdc++.h>
using namespace std;
/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/

struct Node
{
    int data;
    Node* left, * right;
};
class Solution {
    void leftTraversal(Node*root, vector<int> &ans){
        if(root == nullptr || (root->left==nullptr and root->right==nullptr))
            return;
        
        ans.push_back(root->data);
        if(root->left){
            leftTraversal(root->left,ans);
        }
        else{
            leftTraversal(root->right,ans);
        }
    }
    
    void leafTraversal(Node*root, vector<int> &ans){
        if(root == nullptr)    
            return;
        if(root->left == nullptr and root->right == nullptr){
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
    }
    void rightTraversal(Node*root, vector<int> &ans){
        if(root == nullptr|| (root->left==nullptr and root->right==nullptr))
            return;
        if(root->right){
            rightTraversal(root->right,ans);
        }
        else{
            rightTraversal(root->left,ans);
        }
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == nullptr)
            return ans;
        ans.push_back(root->data);
        leftTraversal(root->left,ans);
        leafTraversal(root->left,ans);
        leafTraversal(root->right,ans);
        rightTraversal(root->right,ans);
        return ans;
    }
};