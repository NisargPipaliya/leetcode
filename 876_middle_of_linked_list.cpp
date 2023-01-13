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
    ListNode* middleNode(ListNode* head) {
        ListNode*p=head,*q;
        if(p->next==NULL)
            return p;
        q=p->next;
        while(q!=NULL)
        {
            p=p->next;
            q=q->next;
            if(q!=NULL)
                q=q->next;
        }
        return p;
    }
};