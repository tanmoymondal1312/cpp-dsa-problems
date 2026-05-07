#include<bits/stdc++.h>
using namespace std;


class Queue
{
public:
    int a[100];
    //int  array_cap;
    int  l,r;
    int  sz;

    Queue()
    {
        l=0;
        r = -1;
        sz = 0;
    }

    void enqueue(int value)
    {
        if(r+1 > 100)
        {
            cout<<"Queue Is Full\n";
        }

        r++;
        a[r] = value;
        sz++;
    }
    void dequeue()
    {
        if(l>r)
        {
            cout<<"Queue Is Empty\n";
            return;
        }
        l++;
        sz--;
    }
    int front()
    {
        if(sz==0)
        {
            cout<<"Queue Is Empty\n";
            return-1;
        }
        return a[l];
    }
    void GetSize()
    {
        cout<<sz<<"\n";
        return;
    }
};
int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.dequeue();
    cout<<q.front()<<"\n";

    q.GetSize();

    return 0;

}

