#include<bits/stdc++.h>
using namespace std;

/*
1025. Divisor Game
Easy
1.8K
3.7K
Companies
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.




For any number n,

it can be either even -
In this case, to satisfy the problem condition n%x==0, we have 2 choices,
either choose 1 because N%1 will always be 0
or choose N/2 ( eg 4%2 is 0, 10%5 is 0, 24%12 is 0)

You may say 24 has many options for x like 3, 4, 6, 8, 12. So why are we only considering N/2 in our choice.
To be more clear : The idea is to choose the largest possible x. Because it will cause N = N - x. Now why are we choosing the largest x ? Because we want to reduce the sample space for our opponent as much as possible. Thus, limiting his choices for x. If i choose any other random x, we are just giving our opponent more space to choose his x, and that won't be optimal for us.

or it can be odd,
In this case, to satisfy the problem condition n%x==0, we have only 1 choice,
choose 1 because N%1 will always be 0,
there is no other possible choice, ( eg 5%4 is 1 , 5%3 is 2, 5%2 is 1 ). It will never be 0

Now with this in mind,
Lets say i want to win, so i want to make my opponent loose, i want to limit his choices, so i can predict his move.
In this case, if alice succeds in sending odd number to Bob, she can predict that he will choose 1,
and because he received odd and odd-1 == even. Alice will again received even

so Alice plays optimally.
She limits her opponent's choices by sending him an odd number.
This send odd to opponent can only be ensured if she herself chooses 1 as x
Because if she chooses N/2 there's a risk that opponent will receive even number. ( eg N = 12 (even), 12/2 = 6 ( even ) `

So Alice always choose 1 as x and this forces her opponent to always choose 1 as x.

base cases are 2 always wins and 1 always loses.
Its pretty clear that if alice gets hold of even, she will make sure she always gets even, eventually reaching 2.

However, if alice receives odd number as input, she has only 1 choice. choose 1 as x.
Then her opponent will receive the even number. Then he will play optimally ( as explained above ) and make sure he wins.

I hope this clears it out. We do not really need to know game theory for this. It just needs some brainstorming.



*/


class Solution {
public:
    bool divisorGame(int n) {
        if(n%2 != 0)
            return false;
        return true;
    }
};