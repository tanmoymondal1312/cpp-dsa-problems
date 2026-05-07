#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;
};
class doubly_linked_list
{
public:
    node* head;
    node* tail;
    int sz;

    doubly_linked_list()
    {
        sz=0;
        head=NULL;
        tail=NULL;


    }
    node* creat_new_node(int value)
    {
        node* newnode=new node;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }
    void insertHead(int value)
    {
        node* a=creat_new_node(value);
        if(sz==0)
        {
            head=a;
            tail=a;

            sz++;
            return;
        }
        a->next=head;
        head->prev=a;
        head=a;
        sz++;
        return;
    }
    //insertMid(value) :
    void insertMid(int value)
    {
        node* n=creat_new_node(value);
        if(sz==0)
        {
            head=n;
            tail=n;
            sz++;
            return;
        }
        node* a=head;
        int m;
        if(mid()%2 ==0 && mid()!=1)
        {
            m=mid()+1;
        }
        else m=mid();
        for(int i=1; i<m; i++)
        {
            a=a->next;
        }
        n->prev=a->prev;
        n->next=a;
        a->prev->next=n;
        a->prev=n;
        sz++;
        return;
    }
    void insertTail(int value)
    {
        node* a=creat_new_node(value);
        if(sz==0)
        {
            head=a;
            tail=a;
            sz++;
            return;
        }
        a->prev=tail;
        tail->next=a;
        tail=a;
        sz++;
        return;
    }
    int mid()
    {
        if(sz==0)return 0;
        if(sz==1)return 1;
        if(sz%2==0)return sz/2;
        return sz/2 +1;
    }
    void prrint()
    {
        node* a=head;
        for(int i=1; i<=sz; i++)
        {
            cout<<" "<<a->data<<" " ;
            a=a->next;
        }
    }
    void marge_linked_list(doubly_linked_list a)
    {
        sz=sz+a.sz;
        node* l=tail;
        node* f=a.head;
        l->next=f;
        f->prev=l;
        tail=a.tail;

    }
};
int main()
{
    doubly_linked_list n;
    doubly_linked_list m;
    n.insertHead(4);
    n.insertHead(2);
    n.insertHead(0);
    n.insertMid(14);
    n.insertHead(4);
    n.insertHead(4);
    n.insertMid(15);
    n.insertMid(16);
    n.insertMid(17);
    n.insertMid(19);
    n.insertTail(20);
    n.insertHead(40);
    m.insertHead(50);
    m.insertHead(60);
    m.insertHead(70);
    m.insertTail(20);
    m.insertMid(16);
    cout<<"before marging"<<"\n";
    n.prrint();
    cout<<"\n";
    cout<<"after marging"<<"\n";
    n.marge_linked_list(m);
    n.prrint();
    return 0;
}
