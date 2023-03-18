#include<bits/stdc++.h>
using namespace std;


/*
1472. Design Browser History
Medium
2.2K
143
Companies
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
*/
class BrowserHistory {
    stack<string>bck,fwd;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr=homepage;
    }
    
    void visit(string url) {
        bck.push(curr);
        curr=url;
        while(!fwd.empty())
            fwd.pop();
    }
    
    string back(int steps) {
        string temp=curr;
        fwd.push(curr);
        while(!bck.empty() && steps>0)
        {
            temp=bck.top();
            bck.pop();
            steps--;
            if(!bck.empty() && steps>0)
                fwd.push(temp);
            else
                break;
        }
        if(temp==curr)
            fwd.pop();
        curr=temp;
        return curr;
    }
    
    string forward(int steps) {
        string temp=curr;
        bck.push(curr);
        while(!fwd.empty() && steps>0)
        {
            temp=fwd.top();
            fwd.pop();
            steps--;
            if(!fwd.empty() && steps>0)
            {
                bck.push(temp);
            }
            else
                break;
        }
        if(temp==curr)
            bck.pop();
        curr=temp;
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//  OR can also go for doubly linked list approach -> more efficient than STACK


class Node{
public:
    string val;
    Node* next;
    Node* prev;

    Node(string url){
        this->val = url;
        next = NULL;
        prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* curr;

    BrowserHistory(string homepage) {
        head = new Node(homepage);        
        curr = head;
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    
    string back(int steps) {
        while(steps--){
            if(curr->prev == NULL)
                return curr->val;
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(curr->next == NULL)
                return curr->val;
            curr = curr->next;
        }
        return curr->val;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */