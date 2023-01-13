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
    // bool same=false;
    bool preorder(TreeNode* root1,TreeNode*root2)
    {
        if(root1==NULL && root2==NULL)
        {
            // same=true; 
            return true;
        }
        else if( root1==NULL && root2)
        {
            // same=false;
            return false;
        }else if(root1 && root2==NULL)
        {
            // same=false;
            return false;
        }
        if(root1->val!=root2->val)
        {
            // same=false;
            return false;
        }
        bool l=preorder(root1->left,root2->left);
        bool r=preorder(root1->right,root2->right);
        return l&r;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        // return  preorder(p,q);
        if(p==NULL || q==NULL)
        {
            return (p==q);
        }
            return (p->val==q->val)&isSameTree(p->left,q->left)&isSameTree(p->right,q->right);
    }
};