#include<bits/stdc++.h>
using namespace std;

/*
142. Linked List Cycle II
Medium
10.5K
772
Companies
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x ):val(x),next(NULL){}
};
class Solution {
public:
    bool cycP(ListNode* head)
    {
        ListNode*p=head,*q=head;
        do{
            p=p->next;
            q=q->next;
            q = q ==  NULL ? q : q->next;
        }while(p!=NULL && q!=NULL && p!=q);

        if(q==p && p!=NULL)
            return true;
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        if(!cycP(head))
        {
            cout<<"TRUE"<<endl;
            return NULL;
        }

        ListNode*p,*q,*r,*ans=NULL;
        p=q=r=head;
        bool flag=false;

        do{
            do{
                p=p->next;
                q=q->next;
                if(p->next == r || q->next == r)
                {
                    ans=r;
                    flag=true;
                    break;
                }
                q=q->next;
            }while(p!=q);

            if(flag==true)
            {
                break;
            }
            r=r->next;
            p=q=r;

        }while(true);

        return ans;
    }
};


// most optimized sol

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode*slow=head;
       ListNode*fast=head;
       ListNode*enter=head; 
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(enter!=slow)
                {
                    enter=enter->next;
                    slow=slow->next;
                }
                return slow;
            }

        }
        return NULL;
    }
};