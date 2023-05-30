#include<bits/stdc++.h>
using namespace std;

/*
705. Design HashSet
Easy
2.8K
252
Companies
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

class MyHashSet {
    vector<int> v;
public:
    MyHashSet() {
        v.resize(1000001,-1);
    }
    
    void add(int key) {
        if(v[key] == -1)
            v[key] = key;
    }
    
    void remove(int key) {
        v[key] = -1;
    }
    
    bool contains(int key) {
        return v[key] == key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


// solution using hashing


#define TABLE_SIZE ((unsigned long)1e6 + 1ul)
#define TOTAL_ELEMS (TABLE_SIZE / (CHAR_BIT * sizeof(uint64_t)) + 1)
#define TOTAL_BITS (CHAR_BIT * TOTAL_ELEMS)

static uint64_t table[TOTAL_ELEMS];
static const int _=[](){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class MyHashSet {
public:
    MyHashSet() {
      memset(table, 0, sizeof(table));
    }
    
    void add(int key) {
      table[key >> 6] |= 1UL << (key & 63);
    }
    
    void remove(int key) {
      table[key >> 6] &= ~(1UL << (key & 63));
    }
    
    bool contains(int key) {
      return table[key >> 6] & 1UL << (key & 63);
    }
};