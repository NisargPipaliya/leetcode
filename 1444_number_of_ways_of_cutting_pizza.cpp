#include<bits/stdc++.h>
using namespace std;



// My solution only passes 2 test cases :)

class Solution {
    bool isR(vector<string> &v,int row,int col)
    {
        for(int i=col;i<v[0].size();i++)
        {
            if(v[row][i]=='A')
                return true;
        }
        return false;
    }

    bool isC(vector<string> &v,int row,int col)
    {
        for(int i=row;i<v.size();i++)
        {
            if(v[i][col]=='A')
                return true;
        }
        return false;
    }

    bool help(vector<string> &v,int cr,int cc,int k, int s,int part)
    {
        // cout<<"Part : "<<part<<" "<<endl;
        if(part==k)
        {
            cout<<"cr : "<<cr<<"  cc : "<<cc<<endl;
            bool f=isR(v,cr,cc)|isC(v,cr,cc);
            cout<<"ret : "<<f<<endl<<endl;
            return f;
        }
        if(s==-1 and !isR(v,cr,cc))
            return false;
        if(s!=-1 and !isC(v,cr,cc))
            return false;

        if(s==-1)
        {
            cr++;
        }else
            cc++;
        
        bool flag=false;
        flag=help(v,cr,cc,k,-1,part+1);
        flag= flag|help(v,cr,cc,k,0,part+1);
        if(flag)
        {
            count=(count+1)%(int)mod;
        }
        return flag;
    }
public:
    int count=0;
    double mod=1e9+7;

    int ways(vector<string>& pizza, int k) {
        help(pizza,0,0,k,-1,0);
        help(pizza,0,0,k,0,0);
        return count;
    }
};




// leetcode official sol
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1));
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(rows, vector<int>(cols)));
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] +
                                   apples[row][col + 1] - apples[row + 1][col + 1];
                dp[0][row][col] = apples[row][col] > 0;
            }
        }
        const int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][next_row][col]) %= mod;
                        }
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0) {
                            (dp[remain][row][col] += dp[remain - 1][row][next_col]) %= mod;
                        }
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};