# include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int exp;
    node *next;

};
node *createNode(int data, int power)
{
    node *newnode = new node();
    newnode->data= data;
    newnode->exp=power;
    newnode->next=nullptr;
    return newnode;
}
void append (node *&head, int data, int power)
{
    node *newnode = createNode(data, power);
    if (head==nullptr)
    {
        head=newnode;
        return;
    }
    node *temp =head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    
}
node *substractPolynomials(node *P, node *Q)
{
    node *result=nullptr;
    node *temp=nullptr;
    while (P!=nullptr or Q !=nullptr)
    {
        int data, pow;
        if (Q==nullptr || (P!=nullptr && P->exp>Q->exp))
        {
            data=P->data;
            pow=P->exp;
            P=P->next;
        }
        else if (P==nullptr || (Q!=nullptr && P->exp<Q->exp))
        {
            data=-Q->data;
            pow=Q->exp;
            Q=Q->next;
        }
        else
        {
            data=P->data-Q->data;
            pow=Q->exp;
            P=P->next;
            Q=Q->next;
        }

        if (data!=0)
        {
            if (result==nullptr)
            {
                result=temp=createNode(data,pow);
            }
            else{
                temp->next=createNode(data,pow);
                temp=temp->next;
            }
        }

    }
    return result;

}
void Print(node *poly)
{
    while(poly!=nullptr)
    {
        cout<<poly->data<<"x^"<<poly->exp;
        if (poly->next!=nullptr){
            cout<<"+";
        }
        poly=poly->next;
    }
    cout<<endl;
}

int main()
{
    node *P=nullptr;
    node *Q=nullptr;

    append(P, 5, 3);
    append(P, 4, 2);
    append(P, 2, 0);
    
    append(Q, 3, 3);
    append(Q, 4, 1);
    append(Q, 1, 0);
    
    cout << "Polynomial 1: ";
    Print(P);
    cout << "Polynomial 2: ";
    Print(Q);
    
    node* result = substractPolynomials(P, Q);
    cout << "Result (Polynomial 1 - Polynomial 2): ";
    Print(result);
    
    return 0;
}