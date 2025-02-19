#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
    node *prev;
};

node *createNode(int data)
{
    node *newnode =new node();
    newnode->data=data;
    newnode->prev=nullptr;
    newnode->next;
    return newnode;
}

struct ddl
{
    node *head= nullptr, *newnode;

    void insertAtBeginning(int data)
    {
        newnode= createNode(data);
        if (head==nullptr)
        {
            head=newnode;
            return;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }

    }
    void insertAtEnd(int data)
    {
        newnode=createNode(data);
        if (head==nullptr)
        {
            head=newnode;
            return;
        }
        else
        {
            node *temp= head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            newnode->prev=temp;
            temp->next=newnode;
        }
    }
    void insertAfter(int data, int value)
    {
        newnode=createNode(data);
        bool flag=false;
        if (head==nullptr)
        {
            cout<<"not possible!!";
            return;
        }
        node *temp= head;
        while (temp!=nullptr)
        {
            if (temp->data==value)
            {
                flag=true;
                break;
            }
            temp=temp->next;
        }
        if (flag)
        {
            temp->next->prev=newnode;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
            
        }
        else{
            cout<<"no node found with "<<value<<" value"<<endl;
        }

    }
    void insertBefore(int data, int value)
    {
        newnode=createNode(data);
        bool flag=false;
        node *temp= head;
        while(temp!=nullptr)
        {
            if (temp->data==value)
            {
                flag=true;
                break;
            }
            temp=temp->next;
        }
        if (flag )
        {
            if (temp->prev!=nullptr)
            {
                 temp->prev->next=newnode;
                 newnode->prev=temp->prev;
                 newnode->next=temp;
                 temp->prev=newnode;
            }
            else
            {
                insertAtBeginning(data);
            }
           
        }
        else
        {
            cout<<"No Node found with value "<<value <<" value."<<endl;
        }
    }
    
    void print()
    {
        node *temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


};
int main ()
{
    struct ddl d;
    d.insertAtBeginning(5);
    d.insertAtEnd(9);
    d.insertAfter(6,5);
    d.insertAfter(7,7);
    d.insertBefore(7,9);
    d.insertBefore(4,5);
    d.print();
    return 0;
}