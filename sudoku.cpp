#include<bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<char>> &board)
{

}

vector<vector<char>> ans;
bool solve(vector<vector<char>>&board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]==' ')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isVal(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board))
                            return true;
                        board[i][j]=' ';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isVal(vector<vector<char>> &board,int row,int col,char c)
{
    for(int i=0;i<board.size();i++)
    {
        if(board[i][col]==c)
            return false;
        if(board[row][i]==c)
            return false;
        if(board[3*(row/3) + i/3][3*(col/3)+i%3]==c)
            return false;
    }
    return true;
}

