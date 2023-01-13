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
    int maxi=INT_MIN;
    int findSum(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int srh=max(0,findSum(root->right));
        int slh=max(0,findSum(root->left));
        int curr_sum=srh+slh+root->val;
        maxi=max(maxi,curr_sum);
        return root->val + max(srh,slh);
    }
    int maxPathSum(TreeNode* root) {
        int sum=findSum(root);
        return maxi;
    }
};