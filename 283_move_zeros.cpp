class Solution {
public:
    void swap(int &a,int&b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return;
        int i=0,j=i+1;
        while(j<nums.size())
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[j]);
                    if(nums[i]!=0)
                        i++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
};