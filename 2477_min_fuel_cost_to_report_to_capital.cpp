#include<bits/stdc++.h>
using namespace std;

/*
2477. Minimum Fuel Cost to Report to the Capital
Medium
1K
35
Companies
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city

Input: roads = [[0,1],[0,2],[0,3]], seats = 5
Output: 3
Explanation: 
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum. 
It can be proven that 3 is the minimum number of liters of fuel needed.


Here we counted number of cars coming at each node and then to capital.
as number of cars = fuel used
so for any child node of 0 -> say 3 -> fuel required for childs of 3 say 4 and 5 to reach to capital 
can be calculated as, fuel required to reach to 3. then at 3 total people are 1+1+1 = 3 so now we need to return this number of people to parent of 3.
and fule consumed to reach to 3 by it's chile will be f=2;

f=ceil(peopleFromChild/seats) -> NOTE THAT HERE FIRST WE NEED TO MARK PEOPLE_FROM_CHILD AS DOUBLE AS WE NEED CEIL VALUE.
IF WE CARRY OUT WITH INTEGER THEN IT WOULD RESULT INTO INTEGER DIVISION.

*/

class Solution {
    long long int fuel=0;
    long long int dfs(map<int,list<int>> &adj, int start,int parent ,int seats)
    {
        long long int people=0;
        for(const auto &i:adj[start])
        {
            if(i!=parent)
            {
                long long int p = dfs(adj,i,start,seats);
                people+=p;
                fuel+=(ceil((double)p/seats));
            }
        }
        return people+1;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        map<int,list<int>> m;
        for(int i=0;i<roads.size();i++)
        {
            m[roads[i][0]].push_back(roads[i][1]);
            m[roads[i][1]].push_back(roads[i][0]);
        }
        long long int dem=dfs(m,0,-1,seats);
        return fuel;
    }
};