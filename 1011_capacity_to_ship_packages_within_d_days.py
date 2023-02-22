"""
FIRST PYTHON CODE IN CP

1011. Capacity To Ship Packages Within D Days
Medium
6.8K
143
Companies
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.




THIS QUESTION INDIRECTLY FOLLOWS BINARY SEARCH APPROACH.
BUT HOW?

SO HERE THERE ARE FEW OBSERVATION TO BE NOTED THAT ARE:
1. MIN CAPACITY OF SHIP SHOULD BE GREATER OR EQUAL TO MAX WEIGHT OF PACKAGE (LOWER BOUND)
2. THE CAPACITY CAN NOT EXCEED THE SUM OF ALL WEIGHTS (UPPER BOUND)

SO NOW WE WILL TRY TO FIND AN APPROPRIATE ANS FROM THIS ANS SPACE I.E. FROM LOWER BOUND TO UPPER BOUND
AND FOR EACH MID WE WILL SEE THAT IF WE CAN SHIP WITH THAT CAPACITY
REFER canShip FUNCTION
"""

class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        left=max(weights)
        right=sum(weights)

        def canShip(cap):                        
            ships,currCap=1,cap         # ships = 1 as minimum we need 1 ship, current capacity=incoming capicity
            for w in weights:           # now we will traverse all weights and find the number of ships
                if(currCap - w < 0):    
                    ships+=1
                    currCap=cap         # if current capacity cannot hold the packages then we will increase number of ships i.e adding one more ship
                currCap-=w              # as we added one more ship so it's capacity would be equal to incoming capacity
            return ships <= days        # if number of calculated ships are less than days then we can else not

        res=right
        while left <= right:
            mid = (left+right) // 2
            if(canShip(mid)):
                res=min(res,mid)
                right=mid-1
            else:
                left=mid+1
        return res
