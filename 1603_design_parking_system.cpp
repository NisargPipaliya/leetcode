#include<bits/stdc++.h>
using namespace std;

/*
1603. Design Parking System
Easy
1.2K
383
Companies
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the ParkingSystem class:

ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
 

Example 1:

Input
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
Output
[null, true, true, false, false]

*/

class ParkingSystem {
    // unordered_map<int,int> mp;
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        // mp[1] = big;
        // mp[2] = medium;
        // mp[3] = small;
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        // if(mp[carType] > 0)
        // {
        //     mp[carType]--;
        //     return true;
        // }
        // return false;
        if(carType == 1 && b > 0)
        {
            b--;
            return true;
        }else if(carType == 2 && m > 0)
        {
            m--;
            return true;
        }else if(carType == 3 && s > 0)
        {
            s--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */