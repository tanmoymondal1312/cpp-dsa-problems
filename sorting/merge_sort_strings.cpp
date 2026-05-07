#include <bits/stdc++.h>
using namespace std;
vector<string> msort(vector<string> a1)
{
    if(a1.size()<=1)
    {
        return a1;
    }
    int mid =a1.size()/2;
    vector<string> b;
    vector<string> c;
    for(int i=0; i<mid; i++)
    {
        b.push_back(a1[i]);
    }
    for(int i=mid; i<a1.size(); i++)c.push_back(a1[i]);
    {
        vector<string> sorted_b=msort(b) ;
        vector<string> sorted_c=msort(c);
        vector<string> sorted_a;
        int idx1=0;
        int idx2=0;
        for(int i=0; i<a1.size(); i++)
        {
            if(idx1==sorted_b.size())
            {
                sorted_a.push_back(sorted_c[idx2]);
                idx2++;
            }
            else if(idx2==sorted_c.size())
            {
                sorted_a.push_back(sorted_b[idx1]);
                idx1++;
            }
            else if(sorted_b[idx1]<sorted_c[idx2])
            {
                sorted_a.push_back(sorted_b[idx1]);
                idx1++;
            }
            else if(sorted_b[idx1]>=sorted_c[idx2])
            {
                sorted_a.push_back(sorted_c[idx2]);
                idx2++;
            }
        }
        return sorted_a;
    }
}
int main()
{
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector <string> b =msort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
