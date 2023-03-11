#include<bits/stdc++.h>
using namespace std;

/*
382. Linked List Random Node
Medium
2K
488
Companies
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
 

Example 1:


Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

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
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x ):val(x),next(NULL){}
};

//My sol -> beats 96%

class Solution {
    ListNode*start;
    int leng;
    vector<int> ll;
public:
    int len(ListNode* head)
    {
        if(head==NULL)
            return 0;
        ListNode* p=head;
        int count=0;
        while(p)
        {
            ll.push_back(p->val);
            count++;
            p=p->next;
        }
        return count;
    }
    Solution(ListNode* head) {
        start=head;
        leng=len(head);
    }
    
    int getRandom() {
        float r = (float)rand()/RAND_MAX;
        int index = r*leng;
        // index--;
        return ll[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */



// optimized sol beats 100 %
class Solution {
public:
    Solution(ListNode* head) : _head(head) {
        
    }
    
    int getRandom() {
        int res = 0;
        int i = 1;
        for(ListNode* h = _head; h; h = h->next, ++i) {
            if(rand() % i == 0)
                res = h->val;
        }
        return res;
    }


    ListNode* _head;
};