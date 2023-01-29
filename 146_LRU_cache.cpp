#include<bits/stdc++.h>
using namespace std;


/*
*******************************************************IMPORTANT*********************************************
*/
class LRUCache {
    class node{
    public: 
        node*next;
        node*prev;
        int key;
        int val;
        node(int dk,int dv)
        {
            key=dk;
            val=dv;
            next=prev=NULL;
        }
    };
    node *head=new node(-1,-1),*tail=new node(-1,-1);
    
    void insert(node* ins)
    {
        node*temp=head->next;
        temp->prev=ins;
        ins->next=temp;
        ins->prev=head;
        head->next=ins;
    }
    void remove(node* del)
    {
        node*temp=del->next;
        temp->prev=del->prev;
        del->prev->next=temp;
        delete(del);
    }

    int cap;
    unordered_map<int,node*> m;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node*del=m[key];
            m.erase(key);
            int tk=del->key,tv=del->val;
            remove(del);
            insert(new node(tk,tv));
            m[key]=head->next;
            return tv;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node*del=m[key];
            // int tk=key,tv=value;
            m.erase(key);
            remove(del);
        }
        else if(cap>0)
        {
            // node*ins=new node(key,value);
            // insert(ins);
            // m[key]=head->next;
            cap--;
        }
        else
        {
            node*del=tail->prev;
            int tk=del->key;
            m.erase(tk);
            remove(del);
            // insert(new node(key,value));
            // m[key]=head->next;
        }
            insert(new node(key,value));
            m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */