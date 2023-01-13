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
class Solution {
public:
    int height(TreeNode*root)
    {
        if(root==NULL)
            return 0;
        int x=height(root->right);
        int y=height(root->left);
        if(abs(x-y)>1)
            return -1;
        if(x==-1 || y==-1)
            return -1;
        x = x > y ? x+1 : y+1;
        return x;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};