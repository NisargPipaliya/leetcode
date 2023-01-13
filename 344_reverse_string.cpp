class Solution {
public:
    void swap(char &a,char&b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void reverseString(vector<char>& s) {
        int size=s.size();
        if(size==0||size==1)
            return;
        int itr_f=0,itr_b=size-1;
        while(itr_f<itr_b)
        {
            swap(s[itr_f],s[itr_b]);
            itr_f++;
            itr_b--;
        }
    }
};