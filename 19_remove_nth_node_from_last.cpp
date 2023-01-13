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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
        {
            head=NULL;
            return head;
        }
        ListNode* p,*q;
        p=head;
        q=NULL;
        int len=0;
        while(p)
        {
            len++;
            p=p->next;
        }
        p=head;
        len=len-n;
        if(len==0)
        {
            head=head->next;
            delete p;
            return head;
        }

        for(int i=0;i<len;i++)
        {
            q=p;
            p=p->next;
        }

        q->next=p->next;
        delete p;
        
        
        return head;
    }
};