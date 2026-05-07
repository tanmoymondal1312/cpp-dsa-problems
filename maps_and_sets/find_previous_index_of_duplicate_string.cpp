#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string ara[n];
    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
    }
    map<int,string> x;
    stack<int> stk;
    for(int i=0; i<n; i++)
    {
        x[i]=ara[i];
    }
    for(auto it:x)
    {
        for(auto et:x)
        {
            if(it.second == et.second && it.first>et.first)
            {
                stk.push(et.first);
            }
        }
        if(!stk.empty())
        {
            cout<<stk.top()<<"\n";
            while(!stk.empty())
            {
                stk.pop();
            }
        }
        else
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}
