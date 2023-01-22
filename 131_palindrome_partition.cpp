#include<bits/stdc++.h>
using namespace std;

bool isPallin(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void solve(string s,vector<vector<string>> &ans,vector<string> &path,int index)
{
    if(index==s.size())
    {
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        if(isPallin(s,index,i))
        {
            path.push_back(s.substr(index,i-index+1));
            solve(s,ans,path,i+1);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> path;
    vector<vector<string>> ans;
    solve(s,ans,path,0);
    return ans;
}

int main(void)
{
    vector<vector<string>> ans=partition("aabb");
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
