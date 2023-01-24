/*

                            most difficult to understand due to given matrix.
                            
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.




Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
*/


#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     int size;
//     bool flag=false;
//     void convert(vector<vector<int>> &board,vector<int> &nbd)
//     {
//         int index=size*size;
//         for(int i=0;i<size;i++)
//         {
//             if(i%2==0)
//             {
//                 for(int j=0;j<size;j++)
//                 {
//                     nbd[index]=board[i][j];
//                     index--;
//                 }
//             }else
//             {
//                 for(int j=size-1;j>=0;j--)
//                 {
//                     nbd[index]=board[i][j];
//                     index--;
//                 }
//             }
//         }
//     }
//     int getIndex(vector<int> &board,int cind)
//     {
//         int limit=min(cind+6,size*size);
//         int val=-1,index=limit;
//         if(flag)
//         {   
//             flag=false;
//             for(int i=cind+1;i<=limit;i++)
//             {
//                 if(val<board[i])
//                 {
//                     val=board[i];
//                     index=i;
//                 }
//             }
//         }
//         else
//         {
//             flag=false;
//             for(int i=cind;i<=limit;i++)
//             {
//                 if(val<board[i])
//                 {
//                     val=board[i];
//                     index=i;
//                     flag=true;
//                 }
//             }
//         }
//         return index;
//     }

// public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//          size=board.size();
//         vector<int> newBoard(size*size + 1,-1);
//         convert(board,newBoard);
//         int count=0;
//         for(int i=1;i<size*size;)
//         {
//             i=getIndex(newBoard,i);
//             if(!flag)
//                 count++;
//         }
//         return count;
//     }
// };

int size;
pair<int,int> con(int square)
{
    int row=(square-1)/size;
    int col=(square-1)%size;
    if(row%2)
    {
        col=size-1-col;
    }
    return make_pair(row,col);
}
int snakesLadders(vector<vector<int>> &board)
{
    int next=0;
    queue<pair<int,int>> q;
    q.push({1,0}); // vertex ,moves
    vector<bool> vis(size*size +1 ,false);
    for(int i=1;i<=6;i++)
    {
        auto j=q.front();
        q.pop();

        int nextSq=j.first+i;
        auto cor=con(nextSq);

        if(board[cor.first][cor.second]!=-1)
        {
            nextSq=board[cor.first][cor.second];
        }
        if(nextSq==size*size)
        {
            return j.second+1;
        }
        if(vis[nextSq]==false)
        {
            q.push({nextSq,j.second+1});
            vis[nextSq]=true;
        }
    }

    return -1;
}


//        CORRECT SOLUTION -> thanks to neetcode


class Solution {
    int size;
    int row,col;
    void  con(int square)
    {
         row=(square-1)/size;
         col=(square-1)%size;
        if(row%2)
        {
            col=size-1-col;
        }
    }

public: 
    int snakesAndLadders(vector<vector<int>> &board)
    {
        size=board.size();
        // cout<<size<<endl;
        queue<pair<int,int>> q;
        q.push(make_pair(1,0)); // vertex ,moves

        // board=rev(board);
        reverse(board.begin(),board.end());

        vector<bool> vis(size*size +1 ,false);
        int maxi=size*size;
        while(!q.empty())
        {
            auto j=q.front();
            int sq=j.first,mov=j.second;
            q.pop();


            for(int i=1;i<=6;i++)
            {                
                int nextSq=sq+i;
                nextSq=min(nextSq,maxi);
                con(nextSq);

                cout<<row<<col<<endl;

                if(board[row][col]!=-1)
                {
                    nextSq=board[row][col];
                    cout<<"next sq "<<nextSq<<endl;
                }
                if(nextSq==size*size)
                {
                    return mov+1;
                }
                if(vis[nextSq]==false)
                {
                    q.push({nextSq,mov+1});
                    vis[nextSq]=true;
                }
            }
        }
        return -1;
    }

};