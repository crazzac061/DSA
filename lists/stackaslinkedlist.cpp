#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct Stack
{
    node *TOS=nullptr, *newnode;

    void push(int value)
    {
        newnode=new node();
        newnode->data=value;
        if (TOS==nullptr)
        {
            TOS=newnode;
            newnode->next=nullptr;

        }
        else
        {
            newnode->next=TOS;
            TOS=newnode;
        }
    }
    int pop()
    {
        if (TOS==nullptr)
        {
            cout<<"cannot pop from the empty stack";
            return -1;
        }
        else
        {
            node *temp=TOS;
            TOS=TOS->next;
            int popedvalue= temp->data;
            delete temp;
            return popedvalue;
        }
    }

    void display()
    {
        node *p= TOS;
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

};

int main ()
{
    struct Stack st;
    st.push(3);
    st.push(5);
    st.push(9);
    st.display();

    cout<<"The popped value is "<<st.pop()<<endl;
    st.display();
    return 0;
    
}

