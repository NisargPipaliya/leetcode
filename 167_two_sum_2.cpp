class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        int size=numbers.size();
        int itr_f=0,itr_b=size-1;
        while(itr_f<itr_b)
        {
            int sum=numbers[itr_f]+numbers[itr_b];
            if(sum==target)
            {
                ans.push_back(itr_f+1);
                ans.push_back(itr_b+1);
                break;
            }
            else if(sum<target)
            {
                itr_f++;
            }else
            {
                itr_b--;
            }
        }
        return ans;
    }
};