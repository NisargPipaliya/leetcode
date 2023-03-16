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
    int search(vector<int>&in,int start,int end,int value)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==value)
                return i;
        }
        return in.size()-1;
    }
    TreeNode*build(vector<int>&in,vector<int>&pre,int start,int end,int &preInd)
    {
        // static int preInd=0;
        if(start>end)
            return NULL;
        TreeNode*temp=new TreeNode(pre[preInd++]);
        if(start==end)
            return temp;
        int index=search(in,start,end,temp->val);

        temp->left=build(in,pre,start,index-1,preInd);
        temp->right=build(in,pre,index+1,end,preInd);
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int x=0;
         TreeNode*root=build(inorder,preorder,0,inorder.size()-1,x);
         return root;
    }
};