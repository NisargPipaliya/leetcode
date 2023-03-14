#include<bits/stdc++.h>
using namespace std;



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
    int help(TreeNode*root,int ans)
    {
        if(root==NULL)
            return 0;
        int temp1=0;
        int temp2=0;
        if(root->left==NULL && root->right==NULL)
        {
            return (ans*10 + root->val);
        }
        if(root->left!=NULL)
        {
            temp2=ans*10+root->val;
            cout<<temp2<<endl;
            temp2=help(root->left,temp2);
        }
         if(root->right!=NULL)
        {
            temp1=ans*10 + root->val;
            temp1=help(root->right,temp1);
            cout<<temp1<<endl;
        }
        return temp1+temp2;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans1=root->val;
        int ans2=root->val;

        ans1=help(root->left,ans1);
        ans2=help(root->right,ans2);
        if(ans1==0 && ans2==0)
            ans1=root->val;
        return (ans1+ans2);
    }
};