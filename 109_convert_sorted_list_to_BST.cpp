#include<bits/stdc++.h>
using namespace std;
/*
109. Convert Sorted List to Binary Search Tree
Medium
5.8K
132
Companies
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
binary search tree.


2 approaches :
 1st AVLTree. -> according to me it will have extra overhead of rotation.
 2nd simple tree construction from inorder traversal. -> would be more efficient.



 100 -> questions completed
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x ):val(x),next(NULL){}
};
class TreeNode
{
public:
    int val;
    TreeNode* left,*right;
    TreeNode();
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
    vector<int> ll;
public:
    int len(ListNode*head)
    {
        ListNode*p=head;
        int count=0;
        while(p)
        {
            ll.push_back(p->val);
            p=p->next;
            count++;
        }
        return count;
    }
    void help(int lb,int ub,TreeNode*&root,vector<int> &ll)
    {
        if(lb>ub)
            return;
        // TreeNode*t;
        int mid=(lb+ub)/2;
        // t = new TreeNode(ll[mid]);
        if(ll[mid] > root->val)
        {
            root->right = new TreeNode(ll[mid]);
            help(lb,mid-1,root->right,ll);
            help(mid+1,ub,root->right,ll);
        }
        else
        {
            root->left = new TreeNode(ll[mid]);
            help(lb,mid-1,root->left,ll);
            help(mid+1,ub,root->left,ll);
        }
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        int l=len(head);
        int mid=(l/2);

        TreeNode*root = new TreeNode(ll[mid]);
        help(0,mid-1,root,ll);
        help(mid+1,l-1,root,ll);
        return root;
    }
};



/*
another approach 
without extra space
here the splitListInMiddle function is splitting the list in to two parts like in my above solution i am doing in "HELP" function with mid.
the slow pointer is at the middle position of the linked list.
but here problem is that, we will loose our original linked list as we are modifying prev->next to null.
so if we want to preserve our linked list then we need extra space to carry out operation or we need traverse again and again.
*/ 

class Solution3 {
    ListNode* splitListInMiddle(ListNode* nd)
    {
        ListNode* fast = nd;
        ListNode* slow = nd;
        ListNode* prev = NULL;
        while(slow && fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (prev != NULL) prev->next = NULL;
        
        return slow;
    }
public:
    TreeNode* sortedListToBST(ListNode* _head) {
        if (_head == NULL) return NULL;
        
        ListNode* mid = splitListInMiddle(_head);
        
        TreeNode* nd = new TreeNode(mid->val);
        if(_head == mid) return nd;
        
        nd->left = sortedListToBST(_head);
        nd->right = sortedListToBST(mid->next);
        
        return nd;
    }
};
