#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct sll
{
    node *head=nullptr, *newnode;

    void insertAtBeginning(int item)
    {

        newnode=new node();
        newnode->data=item;
        if (head==nullptr)
        {
            head=newnode;
            newnode->next=nullptr;
        }
        
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }
    void insertAtEnd(int item)
    {
        node *p=head;
        newnode=new node();
        newnode->data=item;
        newnode->next=nullptr;
        if (head==nullptr)
        {
            head=newnode;
            return;
        }
        while (p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=newnode;

    }
    void insertAfter(int item, int value)
    {
        newnode = new node();
        newnode->data=item;
        node *temp =head ;
        int flag;
        while (temp!=nullptr)
        {
            if (temp->data==value)
            {
                flag=1;
                break;
            }
            temp=temp->next;

        }
        if (flag==1)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
        else{
            cout<<"No value "<<value<<" is found"<<endl;
        }


    }
    void insertBefore(int item, int val)
    {
        newnode= new node();
        newnode->data=item;
        node *temp= head, *prev;
        bool flag=false;
        while(temp!=nullptr)
        {
            if (temp->data ==val)
            {
                flag=true;
                break;
            }
            prev=temp;
            temp=temp->next;

        }
        if (flag)
        {
            prev->next=newnode;
            newnode->next=temp;
        }
        else{
            cout<<"node not found with "<<val<<" value"<<endl;
            delete newnode;
        }
        

    }
    void deleteFirst()
    {
        node *p=head;
        head=head->next;
        delete p;

    }
    void deleteLast()
    {
        if (head==nullptr)
        {
            cout<<"the list is empty";
        }

        if (head->next==nullptr)
        {
            delete head;
            head=nullptr;
        }
        else
            {
                 node *p=head;
                 while (p->next->next!=nullptr)
                {
                  p=p->next;
                 }
                 node *temp= p->next;
                 p->next=nullptr;
                 delete temp;
            } 

    }
    void deleteAfter(int value)
    {
        if (head->next==nullptr && head==nullptr)
        {
            cout<<"cannot delete";

        }
        else
        {
            bool flag=false;
            node *p =head;
            while (p!=nullptr)
            {
                if (p->data==value)
                {
                    flag=true;
                    break;
                }
                
                p=p->next;
            }
            if (flag)
            {
                node *temp=p->next;
                p->next=temp->next;
                delete temp;

            }
            else{
                cout<<"not found node with "<<value<<"data";
            }
            
        }


    }
    
    void print()
    {
        node *p=head;
        while(p !=nullptr)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;

    }

};
int main ()
{
    sll s;
    s.insertAtBeginning(3);
    s.insertAtBeginning(2);
    s.insertAtEnd(5);
    s.insertAtEnd(7);
    s.insertAfter(8,5);
    s.insertBefore(9,5);
    s.insertBefore(1,4);
    s.insertAfter(1,4);
    s.print();
   

    s.deleteFirst();
    s.deleteLast();
    s.deleteAfter(9);

    s.print();
    return 0;

}