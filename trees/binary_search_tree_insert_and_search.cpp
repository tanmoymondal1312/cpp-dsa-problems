#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
    node * Left;
    node * Right;
    node * parent;
};
class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }
    node* CreatNewNode(int id)
    {
        node* newnode = new node;
        newnode->id = id;
        newnode->Left = NULL;
        newnode->Right = NULL;
        return newnode;
    }
    void Insert(int value)
    {
        node* newnode = CreatNewNode(value);
        if(root==NULL)
        {
            root = newnode;
            return;
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            if (a->Left != NULL)
            {
                q.push(a->Left);
            }
            else
            {
                a->Left = newnode;
                newnode->parent =a;
                return;
            }
            if (a->Right != NULL)
            {
                q.push(a->Right);
            }
            else
            {
                a->Right = newnode;
                newnode->parent =a;
            }
        }
    }
    bool Search(int value)
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a=q.front();
            q.pop();
            if(a->parent != NULL)
            {
                if(a->parent->id==value)
                {
                    return true;
                }
            }
            if(a->Left != NULL)
            {
                if(a->Left->id==value)
                {
                    return true;
                }
                q.push(a->Left);
            }

            if(a->Right != NULL)
            {
                if(a->Right->id==value)
                {
                    return true;
                }
                q.push(a->Right);
            }
        }
        return false;
    }


};
int main()
{

    BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);
    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //1
    cout<<bst.Search(60)<<"\n"; //0

    return 0;
}
