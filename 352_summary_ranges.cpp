#include<bits/stdc++.h>
using namespace std;

/*
it a simple question but i don't why it is running fine in GDB but not on leetcode ??

Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

*/

class SummaryRanges {
    set<int> input;
    int firstEle=0,lastEle=-1;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(lastEle==-1)
        {
            firstEle=value;
        }
        input.insert(value);
        lastEle=value;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(int i=firstEle;i<=lastEle;i++)
        {
            if(input.find(i)==input.end())
                continue;
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(i);
            int j=1;
            int next=i;
            while(input.find(i+j) != input.end() )
            {
                j++;
                temp[1]=i+j-1;
                // cout<<"HELLO"<<endl;
                next=temp[1];
            }
            ans.push_back(temp);
            i=next;
            // cout<<"HI"<<endl;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */


class SummaryRanges {
    set<int> input;
    int firstEle=0,lastEle=-1;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(lastEle==-1)
        {
            firstEle=value;
        }
        input.insert(value);
        lastEle=value;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<bool> vis(lastEle,false);

        for(int i=firstEle;i<=lastEle+1;i++)
        {
            if(input.find(i)==input.end())
                continue;
            
            if(vis[i]==false){
                vis[i]=true;
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(i);
                int j=1;
                int next=i;
                while(input.find(i+j) != input.end())
                {
                    j++;
                    temp[1]=i+j-1;
                    vis[temp[1]]=true;
                    // cout<<"HELLO"<<endl;
                    // next=temp[1];
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


//      official solution
class SummaryRanges {
    set<int> input;
    int firstEle=0,lastEle=-1;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(lastEle==-1)
        {
            firstEle=value;
        }
        input.insert(value);
        lastEle=value;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int left=-1,right=-1;
        for(auto i : input)
        {
            if(left==-1)
            {
                left=right=i;
            }
            else if(i==right+1)
            {
                right=i;
            }
            else
            {
                ans.push_back({left,right});
                left=right=i;
            }
        }            
        ans.push_back({left,right});
        return ans;
    }
};
