#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int data)
{
    node *newnode= new node();
    newnode->data=data;
    newnode->next=newnode;
    return newnode;
}
struct cll
{
    node *head=nullptr, *newnode;

    void insertAtBeginning(int data)
    {
         newnode=createNode(data);
         if (head==nullptr)
         {
            head=newnode;
            head->next=head;
            return;
         }
         else{
            node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            newnode->next=head;
            head=newnode;
            temp->next=head;
         }


    }
    void deleteBeginning()
    {
        node *temp=head;
        if (head==nullptr)
        {
            cout<<"cannot delete from empty list"<<endl;
        }
        if (head->next==head)
        {
            delete temp;
            head=nullptr;
        }
        else
        {
            node *p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            head=head->next;
            p->next=head;
            delete temp;

        }
        
        
    }
    void insertAtEnd(int data)
    {
        newnode=createNode(data);
        if (head==nullptr)
        {
            head=newnode;
            head->next=head;
            return;

        }
        else{
            node *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;

        }
    }
    void deleteEnd()
    {
        node *temp=head,*prev;
        if (head==nullptr)
        {
            cout<<"cannot delete form empty list"<<endl;
            return;

        }

        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;

        }
        prev->next=head;
        delete temp;

    }
    void print()
 {
    node *temp=head;
   do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
    cout<<endl;
    
 }
   
};

int main()
{
    struct cll c;
    c.insertAtBeginning(5);
    c.insertAtEnd(6);
    c.insertAtEnd(10);
    c.insertAtBeginning(2);
    c.print();
    c.deleteBeginning();
    c.deleteEnd();
    c.print();
    return 0;
}