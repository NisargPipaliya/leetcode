#include<bits/stdc++.h>
using namespace std;
// what is the problem in this?
/*
official solution:
        class Solution {
        public:
            // Returns true if the intervals a and b have a common element.
            bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
                return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
            }
            
            // Return the interval having all the elements of intervals a and b.
            vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
                return {min(a[0], b[0]), max(a[1], b[1])};
            }

            // Insert the interval newInterval, into the list interval keeping the sorting order intact.
            void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
                int index = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
                
                if (index != intervals.size()) {
                    intervals.insert(intervals.begin() + index, newInterval);
                } else {
                    intervals.push_back(newInterval);
                }
            }
            
            vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
                // Insert the interval first before merge processing.
                insertInterval(intervals, newInterval);
                
                vector<vector<int>> answer;
                for (int i = 0; i < intervals.size(); i++) {
                    vector<int> currInterval = {intervals[i][0], intervals[i][1]};
                    // Merge until the list gets exhausted or no overlap is found.
                    while (i < intervals.size() && doesIntervalsOverlap(currInterval, intervals[i])) {
                        currInterval = mergeIntervals(currInterval, intervals[i]);
                        i++;
                    }
                    // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
                    i--;
                    answer.push_back(currInterval);
                }
                
                return answer;
            }
        };

solution:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < intervals.size()) {
        res.push_back(intervals[i++]);
    }
    return res;
}
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>  ans=intervals;
        int i=0,n=intervals.size(),flag=0;
        for( i=0;i<n;i++)
        {
            if(ans[i][0]>newInterval[0])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
           ans.push_back(newInterval);
        }
        else
        {
            ans.insert(ans.begin()+i,newInterval);
        }
        // for(auto i:ans)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for( i=0;i<ans.size()-1;i++)
        {
            if(ans[i][1]>ans[i+1][0])
            {
                vector<int> curr={min(intervals[i][0],intervals[i+1][0]),max(intervals[i][1],intervals[i+1][1])};
               ans[i]=curr;
               ans.erase(ans.begin()+i+1);
                i--;
            }else
            continue;
        }
        
        return ans;        
    }
};





class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>  ans=intervals;
        int i=0,n=intervals.size(),flag=0;
        for( i=0;i<n;i++)
        {
            if(ans[i][0]>newInterval[0])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
           ans.push_back(newInterval);
        }
        else
        {
            ans.insert(ans.begin()+i,newInterval);
        }
        // for(auto i:ans)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<ans.size();i++)
        // {
        //     for(int j=0;j<ans[i].size();j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for( i=1;i<ans.size();i++)
        {
        // for(auto i:ans)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
            if(ans[i-1][1]>ans[i][0])
            {
                cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
                cout<<ans[i-1][0]<<" "<<ans[i-1][1]<<endl;

                vector<int> curr={min(intervals[i-1][0],intervals[i][0]),max(intervals[i-1][1],intervals[i][1])};
               ans[i-1]=curr;
                // cout<<ans[i-1][0]<<" "<<ans[i-1][1]<<endl;

               ans.erase(ans.begin()+i);
                i--;
            }
        // for(auto i:ans)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        }   
        return ans;        
    }
};