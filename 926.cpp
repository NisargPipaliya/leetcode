#include<bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s) 
{
    int ones=0,zeros=0;
    bool flag=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            flag=true;
            ones++;
        }else if(s[i]=='0' && flag==true)
        {
            zeros++;
        }
    }
    int ans=0;
    ans=min(ones,zeros);
    if(ones>(s.length()/2))
    {
        ans=s.length()-ones;
    }
    return ans;
}
int main(void)
{
    string s="00110";
    int len=minFlipsMonoIncr(s);
    return 0;
}