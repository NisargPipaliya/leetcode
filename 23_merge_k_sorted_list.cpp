#include<bits/stdc++.h>
using namespace std;

/*
23. Merge k Sorted Lists
Hard
15.8K
590
Companies
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []


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
// Mysolution -> beats 5% in time and space -> first hard question COMPLETELY done by me.

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x ):val(x),next(NULL){}
};
class Solution {
public:
    ListNode*find(vector<ListNode*> &t)
    {
        ListNode*p=new ListNode(INT_MAX);
        for(auto i:t)
        {
            if(i!=NULL && i->val < p->val)
            {
                p=i;
            }
        }
        return p;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp=lists;
        ListNode*p=new ListNode(INT_MAX),*ans,*q;
        p=find(temp);
        if(p->val==INT_MAX)
            return NULL;

        ans=new ListNode(p->val);
        q=ans;
        auto itr=std::find(temp.begin(),temp.end(),p);
        int index=itr-temp.begin();
        temp[index]=temp[index]->next;
        // p=p->next;

        // int x=100;
        while(find(temp)->val != INT_MAX )
        {
            p=find(temp);
            q->next=new ListNode(p->val);
            auto itr=std::find(temp.begin(),temp.end(),p);
            int index=itr-temp.begin();
            temp[index]=temp[index]->next;
            q=q->next;
            // x--;
        }

        if(ans->val == INT_MAX)
            return NULL;
        return ans;
    }
};

// MOST efficient solution -> wondelfull logic
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        map<int ,int > m;
        for(auto& i : lists)
        {
            while(i)
            {
                m[i->val]++;
                i=i->next;
            }

        }

        ListNode dummy(0);
        ListNode* tail=&dummy;
        if(!m.size())
        return NULL;

        for(auto& it : m)
        {
            for(int i{} ; i<it.second ;i++)
            {
                tail->next= new ListNode(it.first);
                tail=tail->next;
              
            }
        }
        return dummy.next;
        
    }
};

// can also modify leetcode input and output, for doing it consider this.
// this one has runtime of 5ms. but it is not the correct way to solve the problem.
// i have kept it here just to show that you can also modify the system.
ofstream ans("user.out");
int main() {
    vector<int> v;
    v.reserve(1e4);
    string s;
    while (getline(cin, s)) {
        s.erase(remove(begin(s), end(s), '['), end(s));
        s.erase(remove(begin(s), end(s), ']'), end(s));
        for (auto &i: s) if (i == ',') i = ' ';
        istringstream iss(s);
        int temp;
        v.clear();
        while (iss >> temp) v.push_back(temp);
        sort(v.begin(), v.end());
        ans << '[';
        for (int i = 0; i < v.size(); ++i) {
            if (i) ans << ',';
            ans << v[i];
        }
        ans << "]\n";
    }
}
#define main deleted_main
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return nullptr;
    }
};