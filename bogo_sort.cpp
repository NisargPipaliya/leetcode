#include<bits/stdc++.h>
using namespace std;

void bogo(auto begin,auto end,auto p)
{
    random_device rd;
    mt19937 generator(rd());

    while(!is_sorted(begin,end,p))
    {
        shuffle(begin,end,generator);
    }
}


void bogo_sort(auto begin,auto end)
{
    bogo(begin,end,less<int>());
}

int main()
{
    vector<int> a ={123,0,345,29,2,1,3242342,1,4,5};
    bogo_sort(begin(a),end(a));
    for(auto i :a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}