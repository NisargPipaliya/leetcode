#include<bits/stdc++.h>
using namespace std;

/*                                      😍😍😍😍INTERESTING😍😍😍😍                   
static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

This code defines an anonymous lambda function and initializes a static variable with it. When the program is executed, this lambda function is immediately invoked and its return value (which is always 0 in this case) is assigned to the static variable.

The lambda function itself performs two operations. First, it turns off the synchronization between the C++ standard input/output streams (i.e., std::cin, std::cout, std::cerr, etc.) and their respective C counterparts (stdin, stdout, stderr). This can improve the performance of I/O operations by avoiding the overhead of synchronizing the two streams.

Second, the lambda function "unties" the input and output streams, meaning that it disassociates std::cin from std::cout. This can also improve performance by reducing the overhead of flushing the output stream when input is requested, or vice versa.

The lambda function is defined as static auto, which means that it has internal linkage (i.e., it is only visible within the current translation unit) and that its return type is deduced automatically by the compiler. In this case, the return type is int because the lambda function returns 0.
*/



/*  
here first of all we know that if there is only one zero then we will have one subarray.
Now if we have 2 consicutive zeros, then we will have 1+1=2 -> subarrays of length 1 and 1 subarray of length 2.
so total 3 subarrays.

so here suppose we were having 2 zeros and now we add one zero making it 3 zeros.
so this newly added zero will introduce '3' new subarrays i.e 000 -> 1 of length 1
                                                                     1 of length 2
                                                                     1 of length 3
so we can say that if there are initially 'x' consicutive zeros and then we add one zero, making length of consecutive zeros 'x+1'
then this newly added array will introduce 'x+1' new subarrays, which we will add it to our result.

we only need to increment or maintain this length for consecutive zeros as soon as we find any non zero integer we will reset this length to 0 :)
*/



class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0,len=0;

        for(auto i:nums)   
        {
            if(i!=0)
            {
                len=0;
                continue;
            }
            else
            {
                len++;
                result+=len;
            }
        }
        return result;
    }
};