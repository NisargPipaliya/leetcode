#include<bits/stdc++.h>
using namespace std;

/*
208. Implement Trie (Prefix Tree)
Medium
9.2K
113
Companies
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


*/
class trieNode{
public:
    trieNode* arr[26];
    bool flag=false;
    trieNode()
    {
        for(int i=0;i<26;i++)
            arr[i]=NULL;
    }

    bool contains(char a)
    {
        return (arr[a-'a']!=NULL);
    }
    void put(char a)
    {
        arr[a-'a']=new trieNode();
    }
    trieNode* get(char a)
    {
        return arr[a-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};


class Trie {
    trieNode* root=NULL;
public:
    Trie() {
         root=new trieNode();
    }
    
    void insert(string word) {
        trieNode*temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->contains(word[i]))
            {
                temp->put(word[i]);
            }
            temp=temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        trieNode*temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->contains(word[i]))
                return false;
            temp=temp->get(word[i]);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        trieNode*temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->contains(prefix[i]))
                return false;
            temp=temp->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



// a better way


// *** Design Problem
class TrieNode {
public:
    TrieNode *child[26]; // children for all the alphabets (a..z)
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix==false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */