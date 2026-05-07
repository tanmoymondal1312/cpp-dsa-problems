#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        dq.push_back(arr[i]);
    }
    sort(dq.begin(), dq.end());
    for (int i = 0; i < n; i++)
    {
        arr[i] = dq.front();
        dq.pop_front();
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
