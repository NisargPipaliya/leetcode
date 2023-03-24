#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj1[n];
        vector<int> adj2[n];
        for(auto x : connections){
            adj1[x[0]].push_back(x[1]);
            // x[0] -> x[1];

            adj2[x[1]].push_back(x[0]);
            // x[1] <- x[0];
        }

        vector<int> canVisit(n, 0);
        stack<int> st;
        st.push(0);
        canVisit[0] = 1;
        int res = 0;
        while(!st.empty()){
            int tmp = st.top();
            st.pop();

            for(auto x : adj1[tmp]){
                if(!canVisit[x]){
                    canVisit[x] = 1;
                    cout << x << endl;
                    res++;
                    st.push(x);
                }
            }
            for(auto x : adj2[tmp]){
                if(!canVisit[x]){
                    canVisit[x] = 1;
                    st.push(x);
                }
            }
        }
        return res;
    }
};