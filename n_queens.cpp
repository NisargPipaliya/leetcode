#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,vector<string> board,int n)
{
    int itr=row,itc=0;
    for(;itc<col;itc++)
    {
     if(board[itr][itc]=='Q')
        {
            return false;
        }
    }

    itr=row;
    itc=col;
    while(itr>=0 && itc>=0)
    {
        if(board[itr][itc]=='Q')
            return false;
        itr--;
        itc--;
    }

    itr=row;
    itc=col;

    while(itc>=0 && itr<n)
    {
        if(board[itr][itc]=='Q')
            return false;
        itr++;
        itc--;
    }
    return true;
}


void solve(vector<vector<string>> &ans, vector<string> &board,int n ,int col,vector<int>&left,vector<int>&up,vector<int>&down)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        // if(isSafe(row,col,board,n))
        if(left[row]==0 && down[row+col]==0 && up[n-1 +col-row]==0)
        {   
            left[row]=1;
            up[n-1+col-row]=1;
            down[row+col]=1;
            board[row][col]='Q';
            solve(ans,board,n,col+1,left,up,down);
            board[row][col]='.';
            left[row]=0;
            up[n-1+col-row]=0;
            down[row+col]=0;
        }
    }
}

vector<vector<string>> nQueens(int n)
{
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> board(n,s);
    vector<int> leftRow(n,0),upperDiag(2*n-1,0),lowerDiag(2*n-1,0);

    solve(ans,board,n,0,leftRow,upperDiag,lowerDiag);
    return ans;
}

int main(void)
{
    int n=8;
    vector<vector<string>> ans=nQueens(n);

    for(auto i:ans)
    {
        cout<<endl<<"NEXT ANS"<<endl;
        for(int j=0;j<i.size();j++)
        {
            cout<<i[j]<<endl;
        }
    }
    return 0;
}