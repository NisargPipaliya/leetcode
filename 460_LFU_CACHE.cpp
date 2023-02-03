#include<bits/stdc++.h>
using namespace std;

/*

460. LFU Cache
Hard
4.8K
303
Companies
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3


for explaination refer striver's video :)
*/


class LFUCache {
    class node{
    public: 
        node*next;
        node*prev;
        int key;
        int val;
        int fre;
        node(int dk,int dv)
        {
            key=dk;
            val=dv;
            next=prev=NULL;
            fre=1;
        }
    };
    class dll{
    public:
        node *head;
        node *tail;
        int size;
        dll()
        {
            head=new node(-1,-1);
            tail=new node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void insert(node* ins)
        {
            node*temp=head->next;
            temp->prev=ins;
            ins->next=temp;
            ins->prev=head;
            head->next=ins;
            size++;
        }
        void remove(node* del)
        {
            node*temp=del->next;
            temp->prev=del->prev;
            del->prev->next=temp;
            delete(del);
            size--;
        }
    };
    
    int cap;
    int currcap;
    int minfreq;
    unordered_map<int,node*> nk;
    unordered_map<int,dll*> fn;

    void updateFreq(node* inco)
    {
        nk.erase(inco->key);
        int fr=inco->fre;
        int tk=inco->key,tv=inco->val;

        fn[fr]->remove(inco);
        if(fr==minfreq && fn[fr]->size==0)
        {
            minfreq++;
        }
        dll* nlist=new dll();
        if(fn.find(fr+1)!=fn.end())
        {
            nlist=fn[fr+1];
        }
        inco=new node(tk,tv);
        inco->fre=fr+1;
        nlist->insert(inco);
        fn[fr+1]=nlist;
        nk[tk]=inco;
    }
public:
    LFUCache(int capacity) {
        cap=capacity;
        currcap=0;
        minfreq=0;
    }
    
    int get(int key) {
        if(nk.find(key)!=nk.end())
        {
            node*temp=nk[key];
            int val=temp->val;
            // nk.erase(key);
            updateFreq(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0)
            return;
        if(nk.find(key)!=nk.end())
        {
            node*temp=nk[key];
            temp->val=value;
            updateFreq(temp);
        }
        else 
        {
            if(currcap==cap)
            {
                dll* list=fn[minfreq];
                nk.erase(list->tail->prev->key);
                fn[minfreq]->remove(list->tail->prev);
                currcap--;
            }
            currcap++;
            minfreq=1;
            dll* list=new dll();
            if(fn.find(minfreq)!=fn.end())
            {
                list=fn[minfreq];
            }
            node *temp=new node(key,value);
            list->insert(temp);
            nk[key]=temp;
            fn[minfreq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */