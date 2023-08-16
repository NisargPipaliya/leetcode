#include<bits/stdc++.h>
using namespace std;

/*
199. Binary Tree Right Side View
Medium
10.8K
674
Companies
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
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
    void help(TreeNode*root, vector<int> &ans){
        if(root==nullptr)
            return;
        ans.emplace_back(root->val);
        if(root->right != nullptr)
        {
            help(root->right,ans);
        }else if(root->left != nullptr){
            help(root->left,ans);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)   
            return ans;
        // help(root,ans);
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,int>m;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* dummy = q.front().first;
                int level = q.front().second;
                q.pop();
                m[level] = dummy->val;
                if(dummy->left != nullptr)
                    q.push({dummy->left,level+1});
                if(dummy->right != nullptr)
                    q.push({dummy->right,level+1});
            }
        }
        for(auto i : m){
            ans.emplace_back(i.second);
        }
        return ans;
    }
};



// recursive code
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};