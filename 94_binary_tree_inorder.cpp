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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root==NULL)
        {
            return ans;
        }

        // st.push(root);
        TreeNode*temp=root;
        int flag=1;
        while(!st.empty() || temp)
        {
            
            if(temp!=NULL)
            {
                st.push(temp);
                temp=temp->left;
            }else
            {
                // if(st.empty())
                //     break;
                temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                temp=temp->right;
            }
        }
        
        return ans;
    }
};