#include<bits/stdc++.h>
using namespace std;

/*
987. Vertical Order Traversal of a Binary Tree
Hard
6.7K
4.2K
Companies
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        q.push(make_pair(root,0));
        while(!q.empty()){
            int size = q.size();
            map<int,vector<int>> mp; 
            for(int i = 0; i < size; i++){
                TreeNode* dummy = q.front().first;
                int cnt = q.front().second;
                q.pop();
                if(mp.find(cnt) == mp.end())
                {
                    mp[cnt] = {dummy->val};
                }else{
                    mp[cnt].push_back(dummy->val);
                }
                if(dummy->left)
                    q.push(make_pair(dummy->left,cnt-1));
                if(dummy->right)
                    q.push(make_pair(dummy->right,cnt+1));
            }
            for(auto i : mp){
                sort(i.second.begin(),i.second.end());
                if(m.find(i.first) == m.end()){
                    m[i.first] = i.second;
                }else{
                    for(int j : i.second)
                        m[i.first].push_back(j);
                }
            }
        }
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};