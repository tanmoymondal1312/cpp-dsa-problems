#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter Size Of First Set"<<"\n";
    cin>>n;
    int ar1[n];
    cout<<"Enter First Set Element"<<"\n";
    for(int i=0;i<n;i++)
    {
        cin>>ar1[i];
    }
    int m;
    cout<<"Enter Size Of Second Set"<<"\n";
    cin>>m;
    int ar2[m];
    cout<<"Enter Second Set Element"<<"\n";
    for(int i=0;i<m;i++)
    {
        cin>>ar2[i];
    }


    set<int> set1;
    set<int> set2;

    for (int i=0;i<n;i++)
    {
        set1.insert(ar1[i]);
    }

    for (int i=0;i<m;i++)
    {
        set2.insert(ar2[i]);
    }


    set<int> unionSet;

    for (auto itr = set1.begin(); itr != set1.end(); ++itr)
    {
        unionSet.insert(*itr);
    }

    for (auto itr = set2.begin(); itr != set2.end(); ++itr)
    {
        unionSet.insert(*itr);
    }
    cout<<"Union of The Two sets"<<"\n";
    for (auto itr = unionSet.begin(); itr != unionSet.end(); ++itr)
    {
        cout << *itr << " ";
    }

    return 0;
}

