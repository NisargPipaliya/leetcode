#include<bits/stdc++.h>
using namespace std;

int ans=0,cv=0,cw=0,cap=0;
vector<int> ites;
vector<int> a;

void knap(vector<int> &v,vector<int> &w,int ind)
{
    if(ind==v.size())
    {
        if(ans<cv)
        {
            ans=cv;
            a=ites;
        }
        return;
    }
    if(cw+w[ind] <=cap)
    {
        cw+=w[ind];
        cv+=v[ind];
        ites[ind]=1;
        knap(v,w,ind+1);
        ites[ind]=0;
        cv-=v[ind];
        cw-=w[ind];
        knap(v,w,ind+1);
    }
    else
        knap(v,w,ind+1);
}
int main(void)
{
    vector<int> values={10,10,12,18},weights={2,4,6,9};
    ans=0;
    cap=15;
    ites.resize(values.size(),0);
    knap(values,weights,0);
    cout<<"Items Selected"<<endl;
    for(auto i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl<<"Max Profit "<<ans;
    
    return 0;
}