#include<bits/stdc++.h>
using namespace std;

//solved using DSU/disjoint set union/union find


// at first what i thought
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // string eqi;

        // unordered_map<char,char> eqi;

        // set<char> s;

        // for(int i=0;i<s1.length();i++)
        // {
        //     int check=s1[i]-s2[i];
        //     if(check>0)
        //     {
        //         // eqi.push_back(s2[i]);
        //         // s.insert(s2[i]);
        //         if(eqi.find(s1[i])==eqi.end())
        //             eqi[s1[i]]=s2[i];
        //         else
        //         {
        //             char temp=eqi[s1[i]];
        //             check=temp-s2[i];
        //             if(check>0)
        //                 eqi[s1[i]]=temp;
        //         }
        //     }
        //     else
        //     {
        //         // eqi.push_back(s1[i]);
        //         if(eqi.find(s2[i])==eqi.end())
        //             eqi[s2[i]]=s1[i];
        //         else
        //         {
        //             char temp=eqi[s2[i]];
        //             if(temp>s1[i])
        //                 eqi[s2[i]]=temp;
        //         }
        //         // s.insert(s1[i]);
        //     }
        // }

        // string ans;
        // for(int i=0;i<baseStr.size();i++)
        // {
        //     if(eqi.find(baseStr[i])!=eqi.end())
        //         ans.push_back(eqi[baseStr[i]]);
        //     else
        //         ans.push_back(baseStr[i]);
        // }
        // return ans;

        vector<char>hash(26);
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]>s2[i])
            {
                if(hash[s1[i]-'a']=='\0')
                {
                    hash[s1[i]-'a']=s2[i];
                    char t2=hash[hash[s1[i]-'a']-'a'];
                    if(t2!='\0'&& t2<s2[i])
                        hash[s1[i]-'a']=t2;
                }else{
                    char temp=hash[s1[i]-'a'];
                    
                    char t2=hash[hash[s1[i]-'a']-'a'];
                    if(temp>s2[i] && (t2>s2[i] || t2=='\0'))
                    {
                        hash[s1[i]-'a']=s2[i];
                        hash[hash[s1[i]-'a']-'a']=s2[i];
                    }else if(t2<s2[i])
                    {
                        hash[s1[i]-'a']=t2;
                    }
                }
            }
            else{
                if(hash[s2[i]-'a']=='\0')
                {
                    hash[s2[i]-'a']=s1[i];
                    char t2=hash[hash[s2[i]-'a']-'a'];
                    if(t2!='\0'&& t2<s1[i])
                        hash[s2[i]-'a']=t2;

                }else{
                    char temp=hash[s2[i]-'a'];
                    char t2=hash[hash[s2[i]-'a']-'a'];
                    if(temp>s1[i] && (t2>s1[i] || t2=='\0'))
                    {
                        hash[s2[i]-'a']=s1[i];
                        hash[hash[s2[i]-'a']-'a']=s1[i];
                    }else if(t2<s1[i])
                    {
                        hash[s2[i]-'a']=t2;
                    }
                }
            }
        }
        string ans;
        for(int i=0;i<baseStr.size();i++)
        {
            if(hash[baseStr[i]-'a']!='\0')
            {
                ans.push_back(hash[baseStr[i]-'a']);
            }else
            {
                ans.push_back(baseStr[i]);
            }
        }
        return ans;

    }
};




// acutal solution