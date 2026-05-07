#include<bits/stdc++.h>
using namespace std;
class MAXXH
{
public:
    vector<int> node;
    MAXXH()
    {

    }
    void INSERT(int data)
    {
        node.push_back(data);
        int index=node.size()-1;
        while(index>0 && node[index]> node[(index-1)/2])
        {
            swap(node[index],node[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void DELETE(int index)
    {
        if(index>=node.size())
        {
            return;
        }
        swap(node[index],node[node.size()-1]);
        node.pop_back();
        while(1)
        {
            int large=index;
            int l=2*index+1;
            int r=2*index+2;
            if(l<node.size()&& node[large]<node[l])
            {
                large=l;
            }
            if(r<node.size()&& node[large]<node[r])
            {
                large=r;
            }
            if(index==large)
            {
                break;
            }
            swap(node[index],node[large]);
            index=large;
        }
    }
    int MAXX()
    {
        return node[0];
    }
    void PRINTT()
    {
        for(int i=0; i<node.size(); i++)
        {
            cout<<(-1)*node[i]<<" ";
        }
    }
};
class minheap
{
public:
    MAXXH n;
    void INSERT(int x)
    {
        n.INSERT(-x);
    }
    int MINN()
    {
        return -n.MAXX();
    }
    void DELETE(int indx)
    {
        n.DELETE(indx);
    }
    void TRAVERSE()
    {
        n.PRINTT();
    }
};
int main()
{
    minheap n;
    n.INSERT(10);
    n.INSERT(9);
    n.INSERT(8);
    n.INSERT(7);
    n.DELETE(2);
    cout<<n.MINN();
    n.TRAVERSE();
    return 0;
}
