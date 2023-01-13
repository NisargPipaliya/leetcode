class Solution {
public:
void swap(char &a,char&b)
{
    a+=b;
    b=a-b;
    a=a-b;
}
    string reverseWords(string s) {
        int size=s.size();
        string ans=s;
        int itr_f=0,itr_b,space=0;
        while(space<size)
        {
            if(ans[space]==' ')
            {
                itr_b=space-1;
                while(itr_f<itr_b)
                {
                    swap(ans[itr_f],ans[itr_b]);
                    itr_f++;
                    itr_b--;
                }
                itr_f=space+1;
                space++;
            }
            else
            {
                space++;
            }
        }
        itr_b=space-1;
                while(itr_f<itr_b)
                {
                    swap(ans[itr_f],ans[itr_b]);
                    itr_f++;
                    itr_b--;
                }
        return ans;
    }
};