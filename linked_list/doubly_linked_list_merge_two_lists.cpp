#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node * nxt;
    node * prv;

};
class DoublyLinkedList
{
public:
    node*head;
    node*tail;
    int sz;
    DoublyLinkedList()
    {
        head =NULL;
        tail =NULL;
        sz = 0;
    }
    node*CreateNewNode(int data)
    {
        node* newnode = new node;
        newnode->data = data;
        newnode->nxt  = NULL;
        newnode->prv  = NULL;
        return newnode;
    }
    //insertHead(value) :
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        node*a =head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    //insertTail(value) :
    void insertAtEnd(int val)
    {
        sz++;
        node* newNode = CreateNewNode(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->prv = tail;
            tail->nxt = newNode;
            tail = newNode;
        }
    }
    //insertMid(value) :
    void InsertAtMid(int value)
    {
        node* newnode = CreateNewNode(value);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
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
            a=a->nxt;
        }
        newnode->prv=a->prv;
        newnode->nxt=a;
        a->prv->nxt=newnode;
        a->prv=newnode;
        sz++;
        return;
    }
    int mid()
    {
        if(sz==0)
        {
            return 0;
        }
        if(sz==1)
        {
            return 1;
        }
        if(sz%2==0)
        {
            return sz/2;
        }
        return sz/2 +1;
    }
    //print() :
    void print()
    {
        node* a = head;
        while (a != NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }
    //merge(LinkedList a) :
    void mergeLinkedList(DoublyLinkedList x)
    {
        sz=sz+x.sz;
        node* y=x.head;
        node* z=tail;
        z->nxt = y;
        y->prv = z;
    }
};
int main()
{
    DoublyLinkedList d;
    DoublyLinkedList e;
    d.InsertAtHead(1);
    d.InsertAtHead(2);
    d.InsertAtHead(3);
    d.InsertAtHead(4);
    d.InsertAtHead(5);
    d.InsertAtHead(7);
    e.InsertAtHead(8);
    e.InsertAtHead(9);
    d.mergeLinkedList(e);
    d.print();

}
