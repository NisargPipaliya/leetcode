#include<bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:


 bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;                // create a queue to hold the nodes in the binary tree
        q.push(root);                       // add the root node to the queue
        bool found_null = false;          // keep track of whether we've found a null node in the binary tree
        while (!q.empty()) {                // while there are still nodes in the queue
            TreeNode* node = q.front();     // get the next node in the queue
            q.pop();                        // remove it from the queue
            if (node == nullptr) {          // if the node is null
                found_null = true;          // set found_null to true
            } else {                        // otherwise, the node is not null
                if (found_null) {           // if we've already found a null node
                    return false;           // the binary tree is not complete
                }
                q.push(node->left);         // add the left child of the node to the queue
                q.push(node->right);        // add the right child of the node to the queue
            }
        }
        return true;                        // if we've made it this far, the binary tree is complete
    }
};