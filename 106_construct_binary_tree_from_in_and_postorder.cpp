#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int search(vector<int> &in,int inStart,int inEnd,int value)
    {
        for(int i=inStart;i<=inEnd;i++)
        {
            if(in[i]==value)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &in,vector<int>&post,int Start,int End)
    {
        if(Start>End)
            return NULL;
        TreeNode*t=new TreeNode(post.back());
        post.pop_back();
        if(Start==End)
            return t;
        
        int index=search(in,Start,End,t->val);
        t->right=build(in,post,index+1,End);
        t->left=build(in,post,Start,index-1);
        return t;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode*root=build(inorder,postorder,0,inorder.size()-1);
        return root;
    }
};