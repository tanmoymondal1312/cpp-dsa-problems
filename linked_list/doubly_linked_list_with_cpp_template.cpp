#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node * nxt;
    node * prv;

};
template <class T>
class DoublyLinkedList
{
public:
    node<T> *head;
    int sz;
    DoublyLinkedList()
    {
        head =NULL;
        sz = 0;
    }
    //Creates A New Node With Given Data And Return It O(1)
    node<T> *CreateNewNode(T data)
    {
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->nxt  = NULL;
        return newnode;
    }
    //Insert A Node With Given Data At Head O(1)
    void InsertAtHead(int data)
    {
        sz++;
        node<T> *newnode = CreateNewNode(data);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node<T> *a =head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    //Deletes The Value At Head. O(1)
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        node<T> *a = head;
        node<T>*b = head->nxt;
        delete a;
        if(b!= NULL)
        {
            b->prv = NULL;
        }
        head = b;
        sz--;
    }
    void Traverse()
    {
        node<T>* a = head;
        while (a != NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }
};
int main()
{
    DoublyLinkedList<int> d;
    d.InsertAtHead(3);
    d.InsertAtHead(3);
    d.InsertAtHead(3);
    d.InsertAtHead(3);

    d.Traverse();

}
